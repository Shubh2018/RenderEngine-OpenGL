cmake_minimum_required(VERSION 3.25)

add_library(GLWindow ./src/GLWindow.cpp)
add_library(GLGraphics ./src/Graphics.cpp)
add_library(shader ./src/shader.cpp)

target_include_directories(GLWindow 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(GLGraphics
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(shader
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(GLWindow PUBLIC glad_gl_core_33 glfw)
target_link_libraries(GLGraphics PUBLIC glad_gl_core_33 glfw)
target_link_libraries(shader PUBLIC glad_gl_core_33 glfw)