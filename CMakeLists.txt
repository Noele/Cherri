cmake_minimum_required(VERSION 3.10)

project(Dawn)

add_executable(Dawn main.cpp 
                Cherri.h 
                Cherri.cpp
                Toolbox.h
                Toolbox.cpp
                Config.h
                Config.cpp
                Economy.h
                Economy.cpp)

add_subdirectory(deps/sleepy-discord)
add_subdirectory(deps/fmt)

target_link_libraries(Dawn sleepy-discord)
target_link_libraries(Dawn fmt)
