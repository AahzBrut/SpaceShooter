cmake_minimum_required(VERSION 3.30)
project(SpaceShooterEngine)

set(CMAKE_CXX_STANDARD 23)

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
        include/framework/Transform.h
        src/framework/Transform.cpp
        include/framework/MathUtility.h
        src/framework/MathUtility.cpp
        include/framework/PhysicsSystem.h
        src/framework/PhysicsSystem.cpp
        include/framework/Delegate.h
        include/vfx/Particle.h
        src/vfx/Particle.cpp
        include/vfx/Explosion.h
        src/vfx/Explosion.cpp
)

target_link_libraries(SpaceShooterEngine PRIVATE box2d raylib)

target_include_directories(SpaceShooterEngine PUBLIC include)
