#pragma once
#include "Struct.h"

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

	//�`�揈��
	void Draw();

	//�����o�ϐ�
	//�G�\����
	//�������Ȃ��G
	Zako enemy_;

	//�ړ�����G
	Zako moveEnemy_;
};

