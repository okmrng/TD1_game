#pragma once
#include "Struct.h"
#include "PlayerBullet.h"

class Player
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update(char* keys);

	//�`�揈��
	void Draw();

	//�Q�b�^�[�֐�
	float GetterPosX() { return player_.pos.X; }
	float GetterPosY() { return player_.pos.Y; }
	float GetterRadius() { return player_.radius; }
	bool GetterisAlive() { return player_.isAlive; }

private:
	//�����o�ϐ�
	//���@�\����
	Chara player_;

	//�e
	PlayerBullet* bullet_;
};

