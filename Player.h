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

	//�����蔻��
	void OnCollision();

	//�`�揈��
	void Draw();

	//�Q�b�^�[�֐�
	float GetterPosX() { return player_.pos.X; }
	float GetterPosY() { return player_.pos.Y; }
	float GetterRadius() { return player_.radius; }
	bool GetterisAlive() { return player_.isAlive; }
	int GetterHP() { return player_.HP; }
	bool GetterOnCollision() { return onCollision_; }

	//�����o�ϐ�
	//�e
	PlayerBullet* bullet_;

private:
	//���@�\����
	Chara player_;

	//���@�̐F
	unsigned int color_;

	//���G����
	int collisionCount_;

	//�����蔻�肪�������Ƃ��ɗ��t���O
	bool onCollision_;
};

