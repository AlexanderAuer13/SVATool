cmake_minimum_required(VERSION 3.16)

project(SVATool VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 COMPONENTS Quick REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

# Hier sämtliche src Dateien referenzieren
qt_add_executable(SVATool
    main.cpp
    src/App/AppController.hpp
    src/App/AppController.cpp
)


qt_add_qml_module(SVATool
    URI SVA
    QML_FILES
        views/Main.qml
        views/LoginPage.qml
        views/Dashboard.qml
)


target_link_libraries(SVATool PRIVATE Qt6::Quick)