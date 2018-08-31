
enable_testing()

add_test( test_PrimeOK ${CMAKE_BINARY_DIR}/src/prime.out 5)
set_tests_properties(test_PrimeOK PROPERTIES PASS_REGULAR_EXPRESSION ":2::3::5:")

add_test( test_PrimeUsage ${CMAKE_BINARY_DIR}/src/prime.out)
set_tests_properties( test_PrimeUsage PROPERTIES PASS_REGULAR_EXPRESSION "")

add_test( test_Prime1 ${CMAKE_BINARY_DIR}/src/prime.out 1)
set_tests_properties( test_Prime1 PROPERTIES PASS_REGULAR_EXPRESSION "")

add_test( test_Primetext ${CMAKE_BINARY_DIR}/src/prime.out sohal)
set_tests_properties( test_Primetext PROPERTIES PASS_REGULAR_EXPRESSION "")
