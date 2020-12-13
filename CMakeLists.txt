cmake_minimum_required(VERSION 3.10)

project(Cherri)

add_executable(Cherri main.cpp 
                Cherri.h 
                Cherri.cpp
                Toolbox.h
                Toolbox.cpp
                Config.h
                Config.cpp
                Economy.h
                Economy.cpp
                Response.h
                Command.h
                Avatar.h
                Avatar.cpp
                Daily.h
                Daily.cpp
                Balance.h
                Balance.cpp)

add_subdirectory(deps/sleepy-discord)
add_subdirectory(deps/fmt)

target_link_libraries(Cherri sleepy-discord)
target_link_libraries(Cherri fmt)
