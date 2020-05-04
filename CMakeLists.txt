cmake_minimum_required(VERSION 3.16)
project(Travellers)

set(CMAKE_CXX_STANDARD 20)

add_executable(Travellers main.cpp user.cpp user.h destination.cpp destination.h date.cpp date.h aplication.h readFile.h loggedIn.h)