cmake_minimum_required(VERSION 3.20)

project(openglhotreload CXX)

find_package(OpenGL)

add_executable(${PROJECT_NAME}
    main.cpp
    third/glad/src/glad.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${OPENGL_INCLUDE_DIR}/GL 
    third/glad/include
    third/glfw
    third/cr
)

target_link_directories(${PROJECT_NAME} PRIVATE
    third/glfw/libs
)

target_link_libraries(${PROJECT_NAME} opengl32 glfw3)


## Guest code
set(GAME_CODE game_code)

add_library(${GAME_CODE} SHARED cr_main.cpp third/glad/src/glad.cpp)

add_custom_command(TARGET ${GAME_CODE} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/Debug/${GAME_CODE}.dll ${CMAKE_BINARY_DIR}/${GAME_CODE}.dll
  COMMENT Run after build.
)

target_include_directories(${GAME_CODE} PRIVATE 
    third/glad/include 
    third/glfw
    third/cr
    )

target_link_directories(${GAME_CODE} PRIVATE third/glfw/libs)
target_link_libraries(${GAME_CODE} PUBLIC opengl32 glfw3)
