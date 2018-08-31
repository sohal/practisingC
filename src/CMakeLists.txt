
set( HEADERS
  palindrome.h
  prime.h
  pyramid.h
  valley.h
)

set( PYRAMID_EXE    "pyramid.out" )
set( VALLEY_EXE     "valley.out" )
set( PRIME_EXE      "prime.out" )
set( PALINDROME_EXE "palindrome.out")

add_executable(
    ${PYRAMID_EXE}
    ${CMAKE_CURRENT_SOURCE_DIR}/pyramid.c
)

add_executable(
    ${VALLEY_EXE}
    ${CMAKE_CURRENT_SOURCE_DIR}/valley.c
)

add_executable(
    ${PRIME_EXE}
    ${CMAKE_CURRENT_SOURCE_DIR}/prime.c
)

add_executable(
    ${PALINDROME_EXE}
    ${CMAKE_CURRENT_SOURCE_DIR}/palindrome.c
)
