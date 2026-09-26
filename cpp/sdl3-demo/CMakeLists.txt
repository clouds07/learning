# CMakeList.txt : CMake project for sdl3-demo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("sdl3-demo")

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

# Add source to this project's executable.
add_executable (sdl3-demo "sdl3-demo.cpp" "sdl3-demo.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET sdl3-demo PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
target_link_libraries(sdl3-demo PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)
