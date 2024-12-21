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
        include/enemy/EnemySpaceship.h
        src/enemy/EnemySpaceship.cpp
        include/enemy/Vanguard.h
        src/enemy/Vanguard.cpp
        include/levels/GameLevelOne.h
        src/levels/GameLevelOne.cpp
        include/enemy/VanguardStage.h
        src/enemy/VanguardStage.cpp
        include/enemy/TweenBlade.h
        src/enemy/TweenBlade.cpp
        include/enemy/TweenBladeStage.h
        src/enemy/TweenBladeStage.cpp
        include/gameplay/WaitStage.h
        src/gameplay/WaitStage.cpp
        include/enemy/Hexagon.h
        src/enemy/Hexagon.cpp
        include/enemy/HexagonStage.h
        src/enemy/HexagonStage.cpp
        include/enemy/UFO.h
        src/enemy/UFO.cpp
        include/enemy/UFOStage.h
        src/enemy/UFOStage.cpp
        include/weapon/ThreeWayShooter.h
        src/weapon/ThreeWayShooter.cpp
        include/weapon/FrontalWiper.h
        src/weapon/FrontalWiper.cpp
        include/player/Reward.h
        src/player/Reward.cpp
        include/player/Player.h
        src/player/Player.cpp
        include/player/PlayerManager.h
        src/player/PlayerManager.cpp
        include/widgets/GameHUD.h
        src/widgets/GameHUD.cpp
        include/levels/MainMenu.h
        src/levels/MainMenu.cpp
        include/widgets/MainMenuHUD.h
        src/widgets/MainMenuHUD.cpp
)

target_link_libraries(SpaceShooterGame PRIVATE SpaceShooterEngine raylib box2d)

target_include_directories(SpaceShooterGame PUBLIC include)

file(COPY ${CMAKE_CURRENT_LIST_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})