#pragma once
#include "BossBullet.h"

class Boss
{
public:
	//�����o�֐�
	void Initialeze();

	void Update();

	void Draw(int bossImage, int bossCore);

	//�����o�ϐ�
	struct Vector2 {
		float X;
		float Y;
	};

	struct boss {
		Vector2 pos;
		Vector2 speed;
		float radius; 
		int maxHP;          //�ő�HP
		int HP;             //���݂�HP
		bool isAlive; 
		int pattern;        //�U���p�^�[��
		unsigned int collor;
		unsigned int alpha; //�����x
		float theta;
		float amplitude;    //�U��
		int attackCount;    //�U���p�^�[�����ς��܂ł̃J�E���g
	};
	boss boss_;

	//�퓬�J�n�܂ł̃J�E���g
	bool onStartCount_;
	int startCount_;
	bool start_;

	//�{�X�e
	BossBullet* bossBullet_;
};