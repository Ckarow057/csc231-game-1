project(engine)

# set path to SDL include directory
set(SDL2_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/include")

# set path to SDL and SDL_Image libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

message(STATUS "Found SDL2 = ${SDL2_LIBRARIES}")
message(STATUS "Found SDL2_image = ${SDL2_IMAGE_LIBRARIES}")

add_subdirectory(util)
add_subdirectory(graphics)
add_subdirectory(map)
add_subdirectory(input)

add_library(engine
  action.cpp
  actor.cpp
  hero.cpp
  herotype.cpp
  monster.cpp
  monstertype.cpp
  weapon.cpp
  actors.cpp
  camera.cpp
  event.cpp
  events.cpp
  settings.cpp
  engine.cpp)

target_compile_features(engine PUBLIC cxx_std_17)
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(engine PUBLIC util graphics map input SDL2::SDL2 SDL2_image::SDL2_image)