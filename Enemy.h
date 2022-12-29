#pragma once
#include "Struct.h"
#include "EnemyBullet.h"

class Enemy
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update();

	//�����蔻��
	//�������Ȃ��G
	void EnemyOnCollision(int playerBulletAttack);

	//�ړ�����G
	void MoveEnemyOnCollision(int playerBulletAttack);

	//�P���e�����G
	void BulletEnemyOnCollision(int playerBulletAttack);

	//�����e�����G
	void BulletsEnemyOnCollision(int playerBulletAttack);

	//�`�揈��
	void Draw();

	//�����o�ϐ�
	//�G�\����
	//�������Ȃ��G
	Zako enemy_;

	//�ړ�����G
	Zako moveEnemy_;

	//�P���e�����G
	Zako bulletEnemy_;

	//�����e�����G
	Zako bulletsEnemy_;

	//�e
	EnemyBullet* enemyBullet_;
};

