include_directories(${Conway_SOURCE_DIR}/include)
include_directories(${GLUT_INCLUDE_DIRS} )

file(GLOB SOURCES "*.cpp")
add_executable(Conway ${SOURCES})
target_link_libraries(Conway OpenGL::OpenGL GLUT::GLUT GLU)
