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
	void Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_, bool onBomb_);

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
	bool GetterShotBomb() { return shotBomb_; }

	//�Z�b�^�[�֐�
	void SetterBombs(int bombs);

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

	//�{����
	int bombs_;

	int bombPushCount_;

	//�{�������t���O
	bool shotBomb_;

	//�{��false�^�C��
	//int offBombCount_;

	//�{���F
	unsigned int bombColor_;
	unsigned int bombFade_;

	//�{���t�F�[�h�X�^�[�g
	bool onBombFade_;
	bool offBombFade_;
};

