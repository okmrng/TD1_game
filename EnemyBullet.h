#pragma once
#include "Struct.h"

class EnemyBullet
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update();

	//�`�揈��
	void Draw(int enemyBulletImage);

	//�����o�ϐ�
	//�P���e�\����
	EBullet enemyBullet_;

	//�N�[���^�C��
	int coolTime_;

	//�����e�\����
	EBullets enemyBullets_;

	//�N�[���^�C��
	int sCoolTime_;

	//���{�X�e�\����
	EBullets miniBossBullet_;
};

