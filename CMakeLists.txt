cmake_minimum_required( VERSION 3.9 )
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

project( "CExcercises" )
include(CTest)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE ON)
enable_language( C )

# Subdirectory
#
set( HEADER_PATH
  "${CMAKE_SOURCE_DIR}/src"
)

add_subdirectory( src )
add_subdirectory( test )
add_subdirectory( src_coverage )
