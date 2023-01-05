#pragma once
#include "Player.h"

class Tutorial
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update();

	//�`�揈��
	void Draw(int frameSide, int tutorialPlate);

	//�����o�ϐ�
	//�t���[���ʒu 
	float frameRightX_;
	float frameRightY_;
	float frameRightY1_;
	float frameRightY2_;

	float frameLeftX_;
	float frameLeftY_;
	float frameLeftY1_;
	float frameLeftY2_;
	
	//�v���[�g�ʒu
	float plateX_;
	float plateY_;

	//�C�[�W���O
	float t_;
	bool onEase_;

	//���@�ʒu
	float playerY_;
	float playerY1_;
	float playerY2_;

	//���@
	Player* player_;
};

