// sdl3-demo.cpp : Defines the entry point for the application.
//

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "sdl3-demo.h"

using namespace std;

// Type definitions for SDL state and assets
struct SDLState {
  SDL_Window* window;
  SDL_Renderer* renderer;
  int width = 1600;
  int height = 900;
  int logicalW = 640;
  int logicalH = 360;
};

struct SDLAssets {
  SDL_Texture* idleTexture = nullptr;
};

// Game Constants
constexpr float PLAYER_X_SPEED = 2.0f;
constexpr float PLAYER_Y_SPEED = 1.0f;
constexpr float spriteSize = 32.0f;

// Function declarations
int initialize(SDLState& state);
void cleanup(SDLState &state);
void cleanupAssets(SDLAssets& assets);


// Main entry point
int main(int argc, char* argv[])
{
  SDLState state;
  SDLAssets assets;
  int result = 0;

  if (result = initialize(state) != 0) {
    return result;
  }

  // Load game assets
  // SDL_Texture - memory residing on the GPU
  // SDL_Surface - memory residing in the system RAM
  assets.idleTexture = IMG_LoadTexture(state.renderer, "assets/idle.png");
  SDL_SetTextureScaleMode(assets.idleTexture, SDL_ScaleMode::SDL_SCALEMODE_NEAREST);
  if (!assets.idleTexture) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "IMG_LoadTexture Error", SDL_GetError(), nullptr);
    cleanup(state);
    return -4;
  }

  // setup game data
  const bool* keys = SDL_GetKeyboardState(nullptr);
  float playerPosX = 145.0f;
  float playerPosY = 100.0f;
  const float floor = static_cast<float>(state.logicalH);
  uint64_t prevTime = SDL_GetTicks();

  // Main loop
  bool running = true;
  while (running) {
    uint64_t nowTime = SDL_GetTicks();
    float deltaTime = static_cast<float>(nowTime - prevTime) / 1000.0f;

    // Check for events
    SDL_Event event{0};
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_EVENT_QUIT:
          running = false;
          break;

        case SDL_EVENT_WINDOW_RESIZED:
          state.width = event.window.data1;
          state.height = event.window.data2;
          break;

        default:
          break;
      }
    }

    // Handle movement
    float moveX = 0.0f;
    float moveY = 0.0f;
    if (keys[SDL_SCANCODE_A]) {
      moveX -= 50.0f;
    }
    if (keys[SDL_SCANCODE_D]) {
      moveX += 50.0f;
    }
    if (keys[SDL_SCANCODE_SPACE]) {
      moveY -= 50.0f;
    }
    else {
      moveY = 75.0f;
    }

    playerPosX += moveX * PLAYER_X_SPEED * deltaTime;
    playerPosY += moveY * PLAYER_Y_SPEED * deltaTime;
    if (playerPosY > floor - spriteSize) {
      playerPosY = floor - spriteSize;
    }

    // Perform drawing
    SDL_SetRenderDrawColor(state.renderer, 20, 10, 30, 255);
    SDL_RenderClear(state.renderer);

    SDL_FRect playerSpriteRect{ 0, 0, 32, 32 }; // x, y, width, height
    SDL_FRect playerDstRect{
      .x = playerPosX,
      .y = playerPosY,//floor - spriteSize,
      .w = spriteSize,
      .h = spriteSize
    }; // x, y, width, height

    SDL_RenderTexture(state.renderer, assets.idleTexture, &playerSpriteRect, &playerDstRect);

    // Swap buffers and present
    SDL_RenderPresent(state.renderer);

    prevTime = nowTime;
  }

  cleanupAssets(assets);
  cleanup(state);
  return 0;
}

int initialize(SDLState& state) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_Init Error", SDL_GetError(), nullptr);
    return -1;
  }

  int width = 1280;
  int height = 720;
  state.window = SDL_CreateWindow("My SDL3 Demo", width, height, 0 /*SDL_WINDOW_RESIZABLE*/);
  if (!state.window) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_CreateWindow Error", SDL_GetError(), nullptr);
    cleanup(state);
    return -2;
  }
  // Create a renderer
  state.renderer = SDL_CreateRenderer(state.window, nullptr);
  if (!state.renderer) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_CreateRenderer Error", SDL_GetError(), nullptr);
    cleanup(state);
    return -3;
  }

  // Configure presentation
  SDL_SetRenderLogicalPresentation(state.renderer, state.logicalW, state.logicalH, SDL_LOGICAL_PRESENTATION_LETTERBOX);
  return 0;
}

void cleanup(SDLState& state) {
  SDL_DestroyWindow(state.window);
  SDL_DestroyRenderer(state.renderer);
  SDL_Quit();
}

void cleanupAssets(SDLAssets &assets) {
  SDL_DestroyTexture(assets.idleTexture);
}
