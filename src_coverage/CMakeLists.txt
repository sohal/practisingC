

set(PRIME_OBJECT_DIR ${CMAKE_BINARY_DIR}/src/CMakeFiles/prime.out.dir)

add_custom_target(gcov_prime
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_command(TARGET gcov_prime
    COMMAND echo "--------------------GCOV----------------------"
    COMMAND gcov ${CMAKE_SOURCE_DIR}/src/prime.c -o ${PRIME_OBJECT_DIR} | grep -A 5 "prime.c" > CoverageSummary.tmp
    COMMAND cat CoverageSummary.tmp
    COMMAND echo "-- Coverage Files have been output to ${CMAKE_BINARY_DIR}/coverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
)


set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)

add_custom_target(target_scrub
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${PRIME_OBJECT_DIR}/*.gcno
    COMMAND rm -f ${PRIME_OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
