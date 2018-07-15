cmake_minimum_required(VERSION 3.1)

project(battleship)

set (CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

QT5_WRAP_UI(UI_FILES main-window.ui)

add_subdirectory(tests)


set(SOURCES main.cpp
    business-logic-layer.hpp
    business-logic-layer.cpp
    main-window.hpp
    main-window.cpp
    field.hpp
    field.cpp
    ship.hpp
    ship.cpp
    square.hpp
    square.cpp
    )

set(RESOURCES
    images.qrc
    )

set(BOT_SOURCES bot.hpp bot.cpp)
add_library(bot STATIC ${BOT_SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES} ${UI_FILES} ${RESOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets bot)
