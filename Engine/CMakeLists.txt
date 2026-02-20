cmake_minimum_required(VERSION 3.25)

set(dependencies glad_gl_core_33 glfw)

add_library(window ./src/window.cpp)
add_library(graphics ./src/graphics.cpp)
add_library(shader ./src/shader.cpp)
add_library(texture ./src/texture.cpp)

target_include_directories(window 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(graphics
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(shader
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(texture
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(window PUBLIC ${dependencies})
target_link_libraries(graphics PUBLIC ${dependencies})
target_link_libraries(shader PUBLIC ${dependencies})
target_link_libraries(texture PUBLIC ${dependencies} stb_image)