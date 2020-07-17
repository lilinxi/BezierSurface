cmake_minimum_required(VERSION 3.15)
project(BezierSurface)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})


add_executable(BezierSurface main.cpp)
target_link_libraries(BezierSurface ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

add_executable(main_1 main_1.cpp)
target_link_libraries(main_1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
