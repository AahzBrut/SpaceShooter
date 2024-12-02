cmake_minimum_required(VERSION 3.30)
project(SpaceShooterEngine)

set(CMAKE_CXX_STANDARD 23)
include(FetchContent)

add_library(SpaceShooterEngine STATIC
        src/EntryPoint.cpp
        include/framework/Application.h
        src/framework/Application.cpp
        include/EntryPoint.h
        include/framework/Core.h
        src/framework/Core.cpp
        src/framework/World.cpp
        include/framework/World.h
        include/framework/Actor.h
        src/framework/Actor.cpp
        include/framework/Object.h
        src/framework/Object.cpp
        include/framework/AssetsManager.h
        src/framework/AssetsManager.cpp
)

target_link_libraries(SpaceShooterEngine PRIVATE box2d raylib)

target_include_directories(SpaceShooterEngine PUBLIC
        include
)
