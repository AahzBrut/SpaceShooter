cmake_minimum_required(VERSION 3.30)
project(SpaceShooterGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(SpaceShooterGame
        include/gameFramework/GameApplication.h
        src/gameFramework/GameApplication.cpp
        include/spaceShip/SpaceShip.h
        src/spaceShip/SpaceShip.cpp
        include/player/PlayerSpaceShip.h
        src/player/PlayerSpaceShip.cpp
        include/weapon/Shooter.h
        src/weapon/Shooter.cpp
        include/weapon/BulletShooter.h
        src/weapon/BulletShooter.cpp
        include/weapon/Bullet.h
        src/weapon/Bullet.cpp
        include/gameplay/HealthComponent.h
        src/gameplay/HealthComponent.cpp
)

target_link_libraries(SpaceShooterGame PRIVATE SpaceShooterEngine raylib box2d)

target_include_directories(SpaceShooterGame PUBLIC include)

file(COPY ${CMAKE_CURRENT_LIST_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})