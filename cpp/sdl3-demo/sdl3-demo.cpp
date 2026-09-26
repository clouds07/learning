// sdl3-demo.cpp : Defines the entry point for the application.
//

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "sdl3-demo.h"

using namespace std;


struct SDLState {
  SDL_Window* window;
  SDL_Renderer* renderer;
};

struct SDLAssets {
  SDL_Texture* idleTexture;
};

void cleanup(SDLState &state);
void cleanupAssets(SDLAssets& assets);

int main(int argc, char* argv[])
{
  SDLState state;
  SDLAssets assets;

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_Init Error", SDL_GetError(), nullptr);
    return -1;
  }

  int width = 1280;
  int height = 720;
  state.window = SDL_CreateWindow("My SDL3 Demo", width, height, 0);
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

  // Load game assets
  // SDL_Texture - memory residing on the GPU
  // SDL_Surface - memory residing in the system RAM
  assets.idleTexture = IMG_LoadTexture(state.renderer, "assets/idle.png");
  if (!assets.idleTexture) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "IMG_LoadTexture Error", SDL_GetError(), nullptr);
    cleanup(state);
    return -4;
  }

  // Main loop
  bool running = true;
  while (running) {
    // Check for events
    SDL_Event event{0};
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        running = false;
        break;
      }
    }

    // Handle the events


    // Perform drawing
    SDL_SetRenderDrawColor(state.renderer, 255, 255, 255, 255);
    SDL_RenderClear(state.renderer);

    SDL_RenderTexture(state.renderer, assets.idleTexture, nullptr, nullptr);

    // Swap buffers and present
    SDL_RenderPresent(state.renderer);
  }

  cleanupAssets(assets);
  cleanup(state);
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
