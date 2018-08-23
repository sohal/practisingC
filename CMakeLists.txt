
cmake_minimum_required( VERSION 3.10 )
# best practices CMake:
# http://de.slideshare.net/DanielPfeifer1/cmake-48475415
#################################################################
# Check for in-source build
#################################################################
if( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( "
In-source builds are disallowed. They are a source of infinite pain,
- cluttering up the source folder
- causing cmake to silently refuse creating out-of-source builds
- overwriting the root Makefile (which contains cleaninsourcebuild)
To perform an out-of-source build,
- mkdir Build; cd Build; cmake ..
You may need to remove CMakeCache.txt and CMakeFiles.
    " )
    message(FATAL_ERROR "aborting")
endif()

project( "PyramidInC")

set( EXECUTABLE_NAME "${PROJECT_NAME}.out" )

enable_language( C )

set( SRC_ROOT_FILES
    ${CMAKE_SOURCE_DIR}/src/main.c
)

add_executable(
    ${EXECUTABLE_NAME}
    ${SRC_ROOT_FILES}
)