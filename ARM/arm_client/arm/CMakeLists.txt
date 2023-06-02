cmake_minimum_required(VERSION 3.5)

project(arm VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        orderselector.ui
        orderselector.cpp
        orderselector.h
        wine.cpp
        wine.h
        wineservice.cpp
        wineservice.h
        wineserviceimpl.cpp
        wineserviceimpl.h
        wineorderservice.cpp
        wineorderservice.h
        wineorderserviceimpl.cpp
        wineorderserviceimpl.h
        finalorderdialog.cpp
        finalorderdialog.h
        finalorderdialog.ui
        mixselector.cpp
        mixselector.h
        mixselector.ui
        ingredient.cpp
        ingredient.h
        ingredientservice.cpp
        ingredientservice.h
        ingredientserviceimpl.cpp
        ingredientserviceimpl.h
        nothingdialog.cpp
        nothingdialog.h
        nothingdialog.ui
        mixorderservice.cpp
        mixorderservice.h
        mixorderserviceimpl.cpp
        mixorderserviceimpl.h
        storage.cpp
        storage.h
        storageservice.cpp
        storageservice.cpp
        storageserviceimpl.h
        storageserviceimpl.cpp
        storageview.cpp
        storageview.ui
        storageview.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(arm
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET arm APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(arm SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(arm
            ${PROJECT_SOURCES}
        )
    endif()
endif()
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(arm PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(arm PRIVATE cpr::cpr)
target_link_libraries(arm PRIVATE nlohmann_json::nlohmann_json)

set_target_properties(arm PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(arm)
endif()
