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

	//�`�揈��
	void Draw();

	//�Q�b�^�[�֐�
	float GetterPosX() { return enemy_.pos.X; }
	float GetterPosY() { return enemy_.pos.Y; }
	float GetterRadius() { return enemy_.radius; }
	bool GetterisAlive() { return enemy_.isAlive; }

private:
	//�����o�ϐ�
	//�G�\����
	//�������Ȃ��G
	Zako enemy_;
};

