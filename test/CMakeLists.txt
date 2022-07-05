# aux_source_directory(. DIR_SRCS)

find_package(GTest REQUIRED)
# add_executable(unit_test ${DIR_SRCS})
# target_link_libraries(unit_test GTest::GTest GTest::Main)

add_executable(hello_gtest_01 hello_gtest_01.cpp)
target_link_libraries(hello_gtest_01 GTest::GTest GTest::Main)

add_executable(hello_gtest_02 hello_gtest_02.cpp)
target_link_libraries(hello_gtest_02 GTest::GTest GTest::Main)

add_executable(hello_gtest_03 hello_gtest_03.cpp)
target_link_libraries(hello_gtest_03 GTest::GTest GTest::Main)

add_executable(hello_gtest_04 hello_gtest_04.cpp)
target_link_libraries(hello_gtest_04 GTest::GTest GTest::Main)

link_directories(/usr/local/lib)

include_directories(${PROJECT_SOURCE_DIR}/src)
link_directories(${PROJECT_BINARY_DIR}/src)
add_executable(test_stack test_stack.cpp)
target_link_libraries(test_stack GTest::GTest GTest::Main libgmock.a -lstack)


add_executable(hello_gmock_01 hello_gmock_01.cpp)
target_link_libraries(hello_gmock_01 GTest::GTest GTest::Main libgmock.a)

add_executable(hello_gmock_02 hello_gmock_02.cpp)
target_link_libraries(hello_gmock_02 GTest::GTest GTest::Main libgmock.a)

add_executable(hello_gmock_03 hello_gmock_03.cpp)
target_link_libraries(hello_gmock_03 GTest::GTest GTest::Main libgmock.a)