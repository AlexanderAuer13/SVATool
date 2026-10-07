cmake_minimum_required(VERSION 3.16)

project(SVATool VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 COMPONENTS Core Quick REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

# Hier sämtliche src Dateien referenzieren (bis auf qml source dateien)
qt_add_executable(SVATool
    main.cpp

    src/Services/Login/LoginService.hpp
    src/Services/Login/LoginService.cpp
)


qt_add_qml_module(SVATool
    URI SVA

    QML_FILES
        views/Main.qml
        views/LoginPage.qml
        views/DashboardPage.qml

    SOURCES
        src/App/AppController.hpp
        src/App/AppController.cpp
)

target_include_directories(SVATool PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/App
)


target_link_libraries(SVATool PRIVATE
Qt6::Core
Qt6::Quick)