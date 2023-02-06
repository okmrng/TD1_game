#pragma once
#include "Struct.h"
#include "PlayerBullet.h"
#include "BombParticle.h"

/// <summary>
/// ���@
/// </summary>
class Player
{
public:
	//�����o�֐�
	
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="keys"></param>
	/// <param name="preKeys"></param>
	/// <param name="WASDStile_"></param>
	/// <param name="directionStile_"></param>
	/// <param name="onPlayerMove_"></param>
	/// <param name="onPlayerShot_"></param>
	/// <param name="onBomb_"></param>
	void Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_, bool onBomb_);

	/// <summary>
	/// �����蔻��
	/// </summary>
	void OnCollision();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw(int bombBullet, bool WASDStile_, bool directionStile_, int playerWASD, int playerDirection, int playerCore, int playerBullet);

	//�Q�b�^�[�֐�
	float GetterPosX() { return player_.pos.X; }
	float GetterPosY() { return player_.pos.Y; }
	float GetterRadius() { return player_.radius; }
	bool GetterisAlive() { return player_.isAlive; }
	int GetterHP() { return player_.HP; }
	bool GetterOnCollision() { return onCollision_; }
	bool GetterShotBomb() { return shotBomb_; }
	int GetterBombs() { return bombs_; }

	//�Z�b�^�[�֐�
	void SetterBombs(int bombs);

	//�����o�ϐ�
	//�e
	PlayerBullet* bullet_;

	//�{��
	BombParticle* bombParticle_;

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

	//�{���F
	unsigned int bombColor_;
	unsigned int bombFade_;

	//�{���t�F�[�h�X�^�[�g
	bool onBombFade_;

	//�{���e
	bool onBombShot_;

	bool offBombCount_;
};