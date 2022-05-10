cmake_minimum_required(VERSION 3.5)

project(maProc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(OPTIMIZATIONS ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(DEBUGGER OFF)
set(NO_FLAG OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

if(OPTIMIZATIONS)
    set(CMAKE_CXX_FLAGS "-mavx -fno-stack-protector -march=native -O2 -Os -fdelete-null-pointer-checks -fdelete-dead-exceptions")
        if(DEBUGGER)
            set(CMAKE_CXX_FLAGS "-g -gdwarf -gdwarf-version")
        endif()
    if(NO_FLAG)
        set(CMAKE_CXX_FLAGS " ")
    endif()
endif()


set(PROJECT_SOURCES

        example/main.cpp
        example/mainwindow.cpp
        example/mainwindow.hpp
        example/mainwindow.ui

        ../src/QHexView-ng.cpp
        ../src/include/QHexView-ng.hpp
)

add_executable(HexView
        ${PROJECT_SOURCES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QHexView-ng
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

endif()

target_link_libraries(HexView PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(HexView PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QHexView-ng)
endif()
