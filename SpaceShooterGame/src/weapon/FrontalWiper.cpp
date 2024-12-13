#include "weapon/FrontalWiper.h"
using enum SpaceShooter::CollisionLayers;

namespace SpaceShooter {
    FrontalWiper::FrontalWiper(Actor *actor, float coolDownTime, const Vector2 &offsetPosition)
        : Shooter(actor),
          shooter1{actor, coolDownTime, PlayerBullet, Enemy},
          shooter2{actor, coolDownTime, PlayerBullet, Enemy},
          shooter3{actor, coolDownTime, PlayerBullet, Enemy},
          shooter4{actor, coolDownTime, PlayerBullet, Enemy} {
        shooter1.SetMuzzleOffset({offsetPosition.x - 50, offsetPosition.y});
        shooter1.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserGreen11.png");
        shooter2.SetMuzzleOffset({offsetPosition.x - 25, offsetPosition.y});
        shooter2.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
        shooter3.SetMuzzleOffset({offsetPosition.x + 25, offsetPosition.y});
        shooter3.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
        shooter4.SetMuzzleOffset({offsetPosition.x + 50, offsetPosition.y});
        shooter4.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserGreen11.png");
    }

    void FrontalWiper::ShootImpl() {
        shooter1.Shoot();
        shooter2.Shoot();
        shooter3.Shoot();
        shooter4.Shoot();
    }
}
