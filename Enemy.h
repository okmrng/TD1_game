#pragma once
#include "Struct.h"
#include "EnemyBullet.h"

/// <summary>
/// �G
/// </summary>
class Enemy
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update(int scene, int text_);

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
	void Draw(int scene,int enemyTutorial);

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

    //�G�������܂ł̃J�E���g
	int enemyCount_;
};

