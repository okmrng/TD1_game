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
	//�e�\����
	EBullet enemyBullet_;

	//�N�[���^�C��
	int coolTime;
};

