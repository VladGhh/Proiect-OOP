cmake_minimum_required(VERSION 4.0)
project(Proiect_OOP)

set(CMAKE_CXX_STANDARD 20)


add_executable(Proiect_OOP
        main.cpp
        GameUtils.h
        Item.cpp
        Item.h
        Entity.cpp
        Entity.h
        Player.cpp
        Player.h
        Room.cpp
        Room.h
)