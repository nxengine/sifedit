cmake_minimum_required(VERSION 2.6)
include(CheckCXXCompilerFlag)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(sifedit)

set (sifedit_VERSION_MAJOR 2)
set (sifedit_VERSION_MINOR 0)
set (sifedit_VERSION_RELEASE 0)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

file(GLOB APP_SOURCES "src/[a-zA-Z]*.cpp")
file(GLOB CM_SOURCES "src/common/[a-zA-Z]*.cpp")
file(GLOB GUI_SOURCES "src/gui/[a-zA-Z]*.cpp")
file(GLOB SIF_SOURCES "src/siflib/[a-zA-Z]*.cpp")


include_directories(${sifedit_SOURCE_DIR})

set(SOURCES
    ${APP_SOURCES}
    ${CM_SOURCES}
    ${GUI_SOURCES}
    ${SIF_SOURCES}
)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
ENDIF()

add_definitions("-Wall -std=c++11")

add_executable(sifedit ${SOURCES})

target_link_libraries(sifedit ${wxWidgets_LIBRARIES})

