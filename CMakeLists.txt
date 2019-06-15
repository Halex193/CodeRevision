cmake_minimum_required(VERSION 3.13)
project(CodeRevision)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB headerFiles "*.h")
file(GLOB sourceFiles "*.cpp")
file(GLOB resourceFiles "*.qrc")
find_package(Qt5Widgets CONFIG REQUIRED)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}_autogen/include)

add_executable(${CMAKE_PROJECT_NAME}
        main.cpp
        ${sourceFiles}
        ${headerFiles}
        ${resourceFiles}
        )

target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets)