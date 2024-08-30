cmake_minimum_required(VERSION 3.28)
project(httplibtest)

set(CMAKE_CXX_STANDARD 17)

add_executable(httplibtest main.cpp
        httplib.h
        json.hpp
        api.cpp
        api.h)
