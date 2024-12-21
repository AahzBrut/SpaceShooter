#include "weapon/ThreeWayShooter.h"

using enum SpaceShooter::CollisionLayers;

namespace SpaceShooter {
    ThreeWayShooter::ThreeWayShooter(Actor *actor, const float coolDownTime, const Vector2 &localOffset)
        : Shooter(actor),
          leftShooter{actor, coolDownTime, PlayerBullet, Enemy | EnemyBullet},
          centerShooter{actor, coolDownTime, PlayerBullet, Enemy | EnemyBullet},
          rightShooter{actor, coolDownTime, PlayerBullet, Enemy | EnemyBullet},
          topLevelLeftShooter{actor, .1, PlayerBullet, Enemy | EnemyBullet},
          topLevelRightShooter{actor, .1, PlayerBullet, Enemy | EnemyBullet} {
        leftShooter.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserRed01.png");
        leftShooter.SetMuzzleOffset(localOffset);
        leftShooter.SetMuzzleRotation(-30);
        centerShooter.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserRed01.png");
        centerShooter.SetMuzzleOffset(localOffset);
        rightShooter.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserRed01.png");
        rightShooter.SetMuzzleOffset(localOffset);
        rightShooter.SetMuzzleRotation(30);
        topLevelLeftShooter.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserRed01.png");
        topLevelLeftShooter.SetMuzzleOffset(localOffset);
        topLevelLeftShooter.SetMuzzleRotation(15);
        topLevelRightShooter.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserRed01.png");
        topLevelRightShooter.SetMuzzleOffset(localOffset);
        topLevelRightShooter.SetMuzzleRotation(-15);
    }

    void ThreeWayShooter::IncreaseLevel(const int amount) {
        Shooter::IncreaseLevel(amount);
        leftShooter.IncreaseLevel(amount);
        rightShooter.IncreaseLevel(amount);
        centerShooter.IncreaseLevel(amount);
        topLevelLeftShooter.IncreaseLevel(amount);
        topLevelRightShooter.IncreaseLevel(amount);
    }

    void ThreeWayShooter::SetLevel(int amount) {
        Shooter::SetLevel(amount);
        leftShooter.SetLevel(amount);
        rightShooter.SetLevel(amount);
        centerShooter.SetLevel(amount);
        topLevelLeftShooter.SetLevel(amount);
        topLevelRightShooter.SetLevel(amount);
    }

    void ThreeWayShooter::SetLayers(const CollisionLayers selfLayer, const CollisionLayers otherLayer) {
        leftShooter.SetLayers(selfLayer, otherLayer);
        rightShooter.SetLayers(selfLayer, otherLayer);
        centerShooter.SetLayers(selfLayer, otherLayer);
        topLevelLeftShooter.SetLayers(selfLayer, otherLayer);
        topLevelRightShooter.SetLayers(selfLayer, otherLayer);
    }

    void ThreeWayShooter::ShootImpl() {
        leftShooter.Shoot();
        centerShooter.Shoot();
        rightShooter.Shoot();

        if (GetCurrentLevel() == GetMaxLevel()) {
            topLevelLeftShooter.Shoot();
            topLevelRightShooter.Shoot();
        }
    }
}
