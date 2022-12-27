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
	moveEnemy_.HP = 100;
	moveEnemy_.isAlive = true;
	moveEnemy_.pos.X = 300.0f;
	moveEnemy_.pos.Y = -30.0f;
	moveEnemy_.radius = 20.0f;
	moveEnemy_.speed.X = 5.0f;
	moveEnemy_.speed.Y = 3.0f;
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
	if (moveEnemy_.isAlive == true) {
		//�ړ�
		moveEnemy_.pos.X += moveEnemy_.speed.X;
		moveEnemy_.pos.Y += moveEnemy_.speed.Y;

		//��ʊO�ɍs�����珉���ʒu�֖߂�
		if (moveEnemy_.pos.X >= 990.0f || moveEnemy_.pos.Y >= 740.0f) {
			moveEnemy_.pos.X = 300.0f;
			moveEnemy_.pos.Y = -30.0f;
		}

		//HP��0�ȉ��ɂȂ����玀��
		if (moveEnemy_.HP <= 0) {
			moveEnemy_.isAlive = false;
		}
	}
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
	if (moveEnemy_.isAlive == true) {
		moveEnemy_.HP -= playerBulletAttack;
	}
}

//�`�揈��
void Enemy::Draw() {
	//�������Ȃ��G
	/*if (enemy_.isAlive == true) {
		Novice::DrawEllipse(enemy_.pos.X, enemy_.pos.Y, enemy_.radius, enemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}*/

	//�ړ�����G
	if (moveEnemy_.isAlive == true) {
		Novice::DrawEllipse(moveEnemy_.pos.X, moveEnemy_.pos.Y, moveEnemy_.radius, moveEnemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}

	Novice::ScreenPrintf(0, 40, "%0.0f", moveEnemy_.pos.X);
	Novice::ScreenPrintf(0, 60, "%0.0f", moveEnemy_.pos.Y);
	Novice::ScreenPrintf(0, 80, "HP:%d", moveEnemy_.HP);
}