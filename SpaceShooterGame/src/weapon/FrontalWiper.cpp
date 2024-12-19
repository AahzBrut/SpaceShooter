#include "weapon/FrontalWiper.h"
using enum SpaceShooter::CollisionLayers;

namespace SpaceShooter {
    FrontalWiper::FrontalWiper(Actor *actor, const float coolDownTime, const Vector2 &offsetPosition)
        : Shooter(actor),
          shooter1{actor, coolDownTime, PlayerBullet, Enemy | EnemyBullet},
          shooter2{actor, coolDownTime, PlayerBullet, Enemy | EnemyBullet},
          shooter3{actor, coolDownTime, PlayerBullet, Enemy | EnemyBullet},
          shooter4{actor, coolDownTime, PlayerBullet, Enemy | EnemyBullet},
          shooter5{actor, 0.1f, PlayerBullet, Enemy | EnemyBullet},
          shooter6{actor, 0.1f, PlayerBullet, Enemy | EnemyBullet} {
        shooter1.SetMuzzleOffset({offsetPosition.x - 50, offsetPosition.y});
        shooter1.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserGreen11.png");
        shooter2.SetMuzzleOffset({offsetPosition.x - 25, offsetPosition.y});
        shooter2.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
        shooter3.SetMuzzleOffset({offsetPosition.x + 25, offsetPosition.y});
        shooter3.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserBlue07.png");
        shooter4.SetMuzzleOffset({offsetPosition.x + 50, offsetPosition.y});
        shooter4.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserGreen11.png");
        shooter5.SetMuzzleOffset({offsetPosition.x + 60, offsetPosition.y});
        shooter5.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserGreen11.png");
        shooter5.SetMuzzleRotation(7.5f);
        shooter6.SetMuzzleOffset({offsetPosition.x - 60, offsetPosition.y});
        shooter6.SetBulletTexture("assets/SpaceShooterRedux/PNG/Lasers/laserGreen11.png");
        shooter6.SetMuzzleRotation(-7.5f);
    }

    void FrontalWiper::IncreaseLevel(const int amount) {
        Shooter::IncreaseLevel(amount);
        shooter1.IncreaseLevel(amount);
        shooter2.IncreaseLevel(amount);
        shooter3.IncreaseLevel(amount);
        shooter4.IncreaseLevel(amount);
        shooter5.IncreaseLevel(amount);
        shooter6.IncreaseLevel(amount);
    }

    void FrontalWiper::ShootImpl() {
        shooter1.Shoot();
        shooter2.Shoot();
        shooter3.Shoot();
        shooter4.Shoot();

        if (GetCurrentLevel() == GetMaxLevel()) {
            shooter5.Shoot();
            shooter6.Shoot();
        }
    }
}
