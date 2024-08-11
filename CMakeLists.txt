cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

set(PROJECT_NAME BattleShip)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.c
                               src/render/shader.c
                               src/render/shader.h
                               external/stb_image.h
                               src/render/textures.c
                               src/render/textures.h
                               src/render/renderUtils.c
                               src/render/renderUtils.h
                               src/render/sprite.c
                               src/render/sprite.h
                               src/render/AnimSprite.c
                               src/render/AnimSprite.h
                               src/render/text.c
                               src/render/text.h
                               src/scenes/scenesRendering.c
                               src/scenes/scenesRendering.h
                               src/scenes/scenesInitial.c
                               src/scenes/scenesInitial.h
                               src/scenes/processingUtils.c
                               src/scenes/processingUtils.h
                               src/game/ShipBase.c
                               src/game/ShipBase.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/cglm)
target_link_libraries(${PROJECT_NAME} cglm)
include_directories(external/cglm)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

add_subdirectory(external/freetype)
target_link_libraries(${PROJECT_NAME} freetype)
include_directories(external/freetype)