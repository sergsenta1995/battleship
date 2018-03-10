cmake_minimum_required(VERSION 3.1)

project(battleship)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

QT5_WRAP_UI(UI_FILES main-window.ui)


set(SOURCES main.cpp
    main-window.hpp
    main-window.cpp
    field.hpp
    field.cpp
    ship.hpp
    ship.cpp
    )

set(RESOURCES
    images.qrc
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${UI_FILES} ${RESOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)
