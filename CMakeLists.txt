cmake_minimum_required(VERSION 3.10)
project(OpenGLApp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY ${CMAKE_SOURCE_DIR}/shaders
     DESTINATION ${CMAKE_BINARY_DIR})

add_executable(app
    src/main.cpp
    src/glad.c
    src/shader.cpp
    src/window.cpp
    src/mesh.cpp
    src/transform.cpp
    src/cube.cpp
)

target_include_directories(app PRIVATE include)

# Copy shaders to build directory after build
add_custom_command(TARGET app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders
        ${CMAKE_BINARY_DIR}/shaders
    COMMENT "Copying shaders to build directory"
)

target_link_libraries(app glfw GL)
