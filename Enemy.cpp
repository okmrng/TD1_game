#include "Enemy.h"
#include <Novice.h>

//������
void Enemy::Initialize() {
	//�������Ȃ��G
	/*enemy_.HP = 100;
	enemy_.isAlive = true;
	enemy_.pos.X = 640.0f;
	enemy_.pos.Y = 100.0f;
	enemy_.radius = 20.0f;
	enemy_.speed.X = 0.0f;
	enemy_.speed.Y = 0.0f;*/

	//�ړ�����G
	/*moveEnemy_.HP = 100;
	moveEnemy_.isAlive = true;
	moveEnemy_.pos.X = 300.0f;
	moveEnemy_.pos.Y = -30.0f;
	moveEnemy_.radius = 20.0f;
	moveEnemy_.speed.X = 5.0f;
	moveEnemy_.speed.Y = 3.0f;*/

	//�P���e�����G
	/*bulletEnemy_.HP = 100;
	bulletEnemy_.isAlive = true;
	bulletEnemy_.pos.X = 640.0f;
	bulletEnemy_.pos.Y = 100.0f;
	bulletEnemy_.radius = 20.0f;
	bulletEnemy_.speed.X = 0.0f;
	bulletEnemy_.speed.Y = 0.0f;*/

	////�����e�����G
	//bulletsEnemy_.HP = 100;
	//bulletsEnemy_.isAlive = true;
	//bulletsEnemy_.pos.X = 640.0f;
	//bulletsEnemy_.pos.Y = 100.0f;
	//bulletsEnemy_.radius = 20.0f;
	//bulletsEnemy_.speed.X = 0.0f;
	//bulletsEnemy_.speed.Y = 0.0f;

	//�e
	enemyBullet_ = new EnemyBullet();
	enemyBullet_->Initialize();
}

//�X�V����
void Enemy::Update() {
	//�������Ȃ��G
	/*if (enemy_.isAlive == true) {
	//HP��0�ȉ��ɂȂ����玀��
		if (enemy_.HP <= 0) {
			enemy_.isAlive = false;
		}
	}*/

	//�ړ�����G
	//if (moveEnemy_.isAlive == true) {
	//	//�ړ�
	//	moveEnemy_.pos.X += moveEnemy_.speed.X;
	//	moveEnemy_.pos.Y += moveEnemy_.speed.Y;

	//	//��ʊO�ɍs�����珉���ʒu�֖߂�
	//	if (moveEnemy_.pos.X >= 990.0f || moveEnemy_.pos.Y >= 740.0f) {
	//		moveEnemy_.pos.X = 300.0f;
	//		moveEnemy_.pos.Y = -30.0f;
	//	}

	//	//HP��0�ȉ��ɂȂ����玀��
	//	if (moveEnemy_.HP <= 0) {
	//		moveEnemy_.isAlive = false;
	//	}
	//}

	//�P���e�����G
	//if (bulletEnemy_.isAlive == true) {
	//	//�e�̈ʒu�����킹��
	//	if (enemyBullet_->enemyBullet_.isShot == false) {
	//		enemyBullet_->enemyBullet_.pos.X = bulletEnemy_.pos.X;
	//		enemyBullet_->enemyBullet_.pos.Y = bulletEnemy_.pos.Y;
	//	}
	//	enemyBullet_->Update();

	//	//HP��0�ȉ��ɂȂ����玀��
	//	if (bulletEnemy_.HP <= 0) {
	//		bulletEnemy_.isAlive = false;
	//	}
	//}

	//�����e�����G
	//if (bulletsEnemy_.isAlive == true) {
	//	enemyBullet_->sCoolTime_++;
	//	if (enemyBullet_->sCoolTime_ > 30) {
	//		enemyBullet_->sCoolTime_ = 0;
	//	}
	//	
	//	//�e�̈ʒu�����킹��
	//	if (enemyBullet_->sCoolTime_ == 30) {
	//		for (int i = 0; i < 10; i++) {
	//			if (enemyBullet_->enemyBullets_.isShot[i] == false) {
	//				enemyBullet_->enemyBullets_.isShot[i] = true;
	//				enemyBullet_->enemyBullets_.pos[i].X = bulletsEnemy_.pos.X;
	//				enemyBullet_->enemyBullets_.pos[i].Y = bulletsEnemy_.pos.Y;

	//				break;
	//			}
	//		}
	//	}
	//	enemyBullet_->Update();

	//	//HP��0�ȉ��ɂȂ����玀��
	//	if (bulletsEnemy_.HP <= 0) {
	//		bulletsEnemy_.isAlive = false;
	//		for (int i = 0; i < 10; i++) {
	//			enemyBullet_->enemyBullets_.isShot[i] = false;
	//		}
	//	}
	//}
}

//�����蔻��
//�������Ȃ��G
void Enemy::EnemyOnCollision(int playerBulletAttack) {
	/*if (enemy_.isAlive == true) {
		enemy_.HP -= playerBulletAttack;
	}*/
}

//�ړ�����G
void Enemy::MoveEnemyOnCollision(int playerBulletAttack) {
	/*if (moveEnemy_.isAlive == true) {
		moveEnemy_.HP -= playerBulletAttack;
	}*/
}

//�P���e�����G
void Enemy::BulletEnemyOnCollision(int playerBulletAttack) {
	/*if (bulletEnemy_.isAlive == true) {
		bulletEnemy_.HP -= playerBulletAttack;
	}*/
}

//�����e�����G
void Enemy::BulletsEnemyOnCollision(int playerBulletAttack) {/*
	if (bulletsEnemy_.isAlive == true) {
		bulletsEnemy_.HP -= playerBulletAttack;
	}*/
}

//�`�揈��
void Enemy::Draw() {
	//�������Ȃ��G
	/*if (enemy_.isAlive == true) {
		Novice::DrawEllipse(enemy_.pos.X, enemy_.pos.Y, enemy_.radius, enemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}*/

	//�ړ�����G
	/*if (moveEnemy_.isAlive == true) {
		Novice::DrawEllipse(moveEnemy_.pos.X, moveEnemy_.pos.Y, moveEnemy_.radius, moveEnemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}*/

	//�P���e�����G
	/*if (bulletEnemy_.isAlive == true) {
		Novice::DrawEllipse(bulletEnemy_.pos.X, bulletEnemy_.pos.Y, bulletEnemy_.radius, bulletEnemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}*/

	//�����e�����G
	/*if (bulletsEnemy_.isAlive == true) {
		Novice::DrawEllipse(bulletsEnemy_.pos.X, bulletsEnemy_.pos.Y, bulletsEnemy_.radius, bulletsEnemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}*/

	//�e
	enemyBullet_->Draw();

	Novice::ScreenPrintf(0, 40, "%0.0f", moveEnemy_.pos.X);
	Novice::ScreenPrintf(0, 60, "%0.0f", moveEnemy_.pos.Y);
	Novice::ScreenPrintf(0, 80, "HP:%d", bulletsEnemy_.HP);
	Novice::ScreenPrintf(0, 100, "time:%d", enemyBullet_->sCoolTime_);
}