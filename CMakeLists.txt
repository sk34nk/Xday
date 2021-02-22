cmake_minimum_required(VERSION 3.5)

project(XdayXray LANGUAGES C)

find_package(X11)

add_executable(XdayXray main.c)

target_link_libraries(XdayXray -lX11)
