cmake_minimum_required(VERSION 2.8)

project(stb_rect_pack_example)

#GLM
add_definitions("-DGLM_FORCE_SIZE_T_LENGTH -DGLM_FORCE_RADIANS")
set(GLM_STATIC_LIBRARY_ENABLE TRUE)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../glm ${CMAKE_CURRENT_BINARY_DIR}/glm)

add_executable(${PROJECT_NAME} "main.cpp"
    stb_rect_pack.cpp
    Rectangle_Renderer.cpp)

target_link_libraries(${PROJECT_NAME}
GLESv2
glfw
)
