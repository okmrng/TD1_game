#pragma once
#include "Struct.h"

class EnemyBullet
{
public:
	//�����o�֐�
	//������
	void Intialize();

	//�X�V����
	void Update();

	//�����蔻��
	void OnCollition();

	//�`�揈��
	void Draw();

	//�����o�ϐ�
	//�P���e�\����
	EBullet enemyBullet_;

	//�N�[���^�C��
	int coolTime_;

	//�����e�\����
	EBullets enemyBullets_;

	//�N�[���^�C��
	int sCoolTime_;
};

