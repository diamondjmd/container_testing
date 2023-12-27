
# Add the path to your custom libraries
find_package(GTest CONFIG REQUIRED)
enable_testing()

set (target "containers_tests")
add_executable(${target} vector_tests.cpp list_tests.cpp)


if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${target} PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    target_compile_options(${target} PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(${target} PUBLIC cxx_std_17)
target_link_libraries(${target} PRIVATE GTest::gtest GTest::gtest_main)
target_include_directories(${target} PRIVATE ${CMAKE_SOURCE_DIR}/src)  
