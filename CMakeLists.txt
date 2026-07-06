cmake_minimum_required(VERSION 4.3)

project(cg_billboard_rain LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external")
set(IMGUI_DIR "${EXTERNAL_DIR}/imgui")

add_subdirectory(src)