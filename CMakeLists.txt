cmake_minimum_required(VERSION 3.14)
project(LeetCode)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

#if(MSVC)
#  add_compile_options(/W3 /WX)
#else()
#  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
#endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(CTest)
enable_testing()
include(GoogleTest)

add_subdirectory( utils )

add_subdirectory( add-two-numbers )
add_subdirectory( can-make-arithmetic-progression-from-sequence )
add_subdirectory( contains-duplicate )
add_subdirectory( roman-numerals )
add_subdirectory( kth-smallest-element-in-a-bst )
add_subdirectory( longest-substring-without-repeating-characters )
add_subdirectory( second-minimum-node-in-a-binary-tree )
add_subdirectory( top-k-frequent-elements )
add_subdirectory( two-sum )
add_subdirectory( valid-parentheses )
add_subdirectory( convert-1d-array-into-2d-array )
add_subdirectory( kth-largest-element-in-a-stream )
add_subdirectory( kth-largest-element-in-a-array )
add_subdirectory( wiggle-sort-ii )
add_subdirectory( longest-palindrome )
