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
	void OnCollision(int playerBulletAttack);

	//�`�揈��
	void Draw();

	//�����o�ϐ�
	//�G�\����
	//�������Ȃ��G
	Zako enemy_;
};

