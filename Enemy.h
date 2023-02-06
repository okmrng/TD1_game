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

	//�`�揈��
	void Draw(int scene, int enemyTutorial, int enemyBulletImage, int miniBoss);

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

	//���{�X
	Zako miniBoss_;

	//�e
	EnemyBullet* enemyBullet_;

    //�G�������܂ł̃J�E���g
	int enemyCount_;
};

