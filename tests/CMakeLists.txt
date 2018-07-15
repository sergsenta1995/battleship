cmake_minimum_required(VERSION 3.1)

project(test-bot)

enable_testing()

set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_SOURCE_DIR})
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Test REQUIRED)

add_executable(test-bot test-bot.cpp)
add_test(test-bot test-bot)

target_link_libraries(test-bot Qt5::Test bot)
