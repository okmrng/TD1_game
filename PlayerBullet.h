#pragma once
#include "Struct.h"

class PlayerBullet
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update();

	//�`�揈��
	void Draw(int playerBullet);

	//�����o�ϐ�
	//�e�\����
	Bullet bullet_;
};

