#include "weapon/ThreeWayShooter.h"

using enum SpaceShooter::CollisionLayers;

namespace SpaceShooter {
    ThreeWayShooter::ThreeWayShooter(Actor *actor, const float coolDownTime, const Vector2 &localOffset)
        : Shooter(actor),
    leftShooter{actor, coolDownTime, PlayerBullet, Enemy},
    centerShooter{actor, coolDownTime, PlayerBullet, Enemy},
    rightShooter{actor, coolDownTime, PlayerBullet, Enemy} {
        leftShooter.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserRed01.png");
        leftShooter.SetMuzzleOffset(localOffset);
        leftShooter.SetMuzzleRotation(-30);
        centerShooter.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserRed01.png");
        centerShooter.SetMuzzleOffset(localOffset);
        rightShooter.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserRed01.png");
        rightShooter.SetMuzzleOffset(localOffset);
        rightShooter.SetMuzzleRotation(30);
    }

    void ThreeWayShooter::ShootImpl() {
        leftShooter.Shoot();
        centerShooter.Shoot();
        rightShooter.Shoot();
    }
}
