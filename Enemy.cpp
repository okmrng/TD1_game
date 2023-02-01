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
	moveEnemy_.HP[0] = 20;
	moveEnemy_.isAlive[0] = true;
	moveEnemy_.pos[0].X = -30.0f;
	moveEnemy_.pos[0].Y = 358.0f;
	moveEnemy_.radius[0] = 20.0f;
	moveEnemy_.speed[0].X = 5.0f;
	moveEnemy_.speed[0].Y = 3.0f;
	moveEnemy_.color[0] = WHITE;

	for (int i = 1; i < 3; i++) {
		moveEnemy_.HP[i] = 30;
		moveEnemy_.isAlive[i] = true;
		moveEnemy_.pos[i].Y = -20.0f;
		moveEnemy_.radius[i] = 20.0f;
		moveEnemy_.speed[i].X = 0.0f;
		moveEnemy_.speed[i].Y = 5.0f;
		moveEnemy_.color[i] = WHITE;
	}

	moveEnemy_.pos[1].X = 610.0f;
	moveEnemy_.pos[2].X = 670.0f;

	//�P���e�����G
	bulletEnemy_.HP[0] = 100;
	bulletEnemy_.isAlive[0] = true;
	bulletEnemy_.pos[0].X = 640.0f;
	bulletEnemy_.pos[0].Y = 100.0f;
	bulletEnemy_.radius[0] = 20.0f;
	bulletEnemy_.speed[0].X = 0.0f;
	bulletEnemy_.speed[0].Y = 0.0f;

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

	enemyCount_ = 0;
}

//�X�V����
void Enemy::Update(int scene, int text_) {
	//�`���[�g���A��
	if (scene == 2) {
		if (text_ >= 6) {
			if (moveEnemy_.isAlive[0] == true) {
				//�ړ�
				moveEnemy_.pos[0].X += moveEnemy_.speed[0].X;

				//�~�߂�
				if (moveEnemy_.pos[0].X >= 640.0f) {
					moveEnemy_.speed[0].X = 0.0f;
				}

				//HP��0�ȉ��ɂȂ����玀��
				if (moveEnemy_.HP[0] <= 0) {
					moveEnemy_.isAlive[0] = false;
				}
			}
		}
		if (text_ >= 8) {
			//�P���e�����G
			if (bulletEnemy_.isAlive[0] == true) {
				//�e�̈ʒu�����킹��
				if (enemyBullet_->enemyBullet_.isShot == false) {
					enemyBullet_->enemyBullet_.pos.X = bulletEnemy_.pos[0].X;
					enemyBullet_->enemyBullet_.pos.Y = bulletEnemy_.pos[0].Y;
				}
				enemyBullet_->Update();

				//HP��0�ȉ��ɂȂ����玀��
				if (bulletEnemy_.HP[0] <= 0) {
					bulletEnemy_.isAlive[0] = false;
				}
			}
		}
	}

	if (scene == 3) {
		enemyCount_++;

		for (int i = 1; i < 3; i++) {
			//�ړ�����G
			if (moveEnemy_.isAlive[i] == true) {
				if (enemyCount_ >= 30) {
					//�ړ�
					moveEnemy_.pos[i].Y += moveEnemy_.speed[i].Y;
				}

				//�~�߂�
				if (moveEnemy_.pos[i].Y >= 150.0f) {
					moveEnemy_.speed[i].Y = 0.0f;
				}
			}
		}
	}

	//�������Ȃ��G
	/*if (enemy_.isAlive == true) {
	//HP��0�ȉ��ɂȂ����玀��
		if (enemy_.HP <= 0) {
			enemy_.isAlive = false;
		}
	}*/

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
void Enemy::Draw(int scene,int enemyTutorial) {
	//�������Ȃ��G
	/*if (enemy_.isAlive == true) {
		Novice::DrawEllipse(enemy_.pos.X, enemy_.pos.Y, enemy_.radius, enemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}*/

	//�ړ�����G
	if (scene == 2) {
		for (int i = 0; i < 1; i++) {
			if (moveEnemy_.isAlive[0] == true) {
				//Novice::DrawEllipse(moveEnemy_.pos[0].X, moveEnemy_.pos[0].Y, moveEnemy_.radius[0], moveEnemy_.radius[0], 0.0f, moveEnemy_.color[0], kFillModeSolid);
				Novice::DrawSprite(moveEnemy_.pos[0].X - 20, moveEnemy_.pos[0].Y - 20, enemyTutorial, 1, 1, 0.0f, moveEnemy_.color[0]);
			}
		}
	}

	if (scene == 3) {
		for (int i = 1; i < 3; i++) {
			if (moveEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(moveEnemy_.pos[i].X - 20, moveEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, moveEnemy_.color[i]);
			}
		}
	}

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
}