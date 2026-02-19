cmake_minimum_required(VERSION 3.25)

add_subdirectory(./GLFW)
add_subdirectory(./GLAD/cmake glad_cmake)

add_library(stb_image INTERFACE)
target_include_directories(stb_image INTERFACE ./stb_image)
target_compile_definitions(stb_image INTERFACE STB_IMAGE_IMPLEMENTATION)

glad_add_library(glad_gl_core_33 API gl:core=3.3)