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

project( "CExcercises")
include(CTest)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE ON)
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/prime.out.dir/src)
set( PYRAMID_EXE    "pyramid.out" )
set( VALLEY_EXE     "valley.out" )
set( PRIME_EXE      "prime.out" )

enable_language( C )

add_executable(
    ${PYRAMID_EXE}
    ${CMAKE_SOURCE_DIR}/src/pyramid.c
)

add_executable(
    ${VALLEY_EXE}
    ${CMAKE_SOURCE_DIR}/src/valley.c
)

add_executable(
    ${PRIME_EXE}
    ${CMAKE_SOURCE_DIR}/src/prime.c
)

add_custom_target(gcov
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BIN_DIR}
)

add_custom_command(TARGET gcov
    COMMAND echo "--------------------GCOV----------------------"
    COMMAND gcov ${CMAKE_SOURCE_DIR}/src/prime.c -o ${OBJECT_DIR} | grep -A 5 "prime.c" > CoverageSummary.tmp
    COMMAND cat CoverageSummary.tmp
    COMMAND echo "-- Coverage Files have been output to ${CMAKE_BINARY_DIR}/coverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
)


set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)

add_custom_target(scrub
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

enable_testing()

add_test( test_PrimeOK ${CMAKE_CURRENT_BINARY_DIR}/prime.out 5)
set_tests_properties(test_PrimeOK PROPERTIES PASS_REGULAR_EXPRESSION ":2::3::5:")

add_test( test_PrimeUsage ${CMAKE_CURRENT_BINARY_DIR}/prime.out)
set_tests_properties( test_PrimeUsage PROPERTIES PASS_REGULAR_EXPRESSION "")

add_test( test_Prime1 ${CMAKE_CURRENT_BINARY_DIR}/prime.out 1)
set_tests_properties( test_Prime1 PROPERTIES PASS_REGULAR_EXPRESSION "")
