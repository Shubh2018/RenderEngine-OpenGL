cmake_minimum_required(VERSION 3.25)

set(LINK_LIBS glad_gl_core_33 glfw window graphics shader texture)

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

add_executable(App ./main.cpp)

target_link_libraries(App PUBLIC ${LINK_LIBS})