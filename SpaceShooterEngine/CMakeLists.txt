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
        include/framework/TimerManager.h
        src/framework/TimerManager.cpp
        include/gameplay/GameStage.h
        src/gameplay/GameStage.cpp
        include/widgets/HUD.h
        src/widgets/HUD.cpp
        include/widgets/Widget.h
        include/widgets/TextWidget.h
        src/widgets/TextWidget.cpp
        include/widgets/ProgressBar.h
        src/widgets/ProgressBar.cpp
        include/widgets/ImageWidget.h
        src/widgets/ImageWidget.cpp
        src/framework/Object.cpp
)

target_link_libraries(SpaceShooterEngine PRIVATE box2d raylib)

target_include_directories(SpaceShooterEngine PUBLIC include)
