#pragma once
#include "Admission.h"
#include "Player.h"
#include "Boss.h"
#include "Clear.h"

class Stage3
{
public:
	//�����o�֐�

	void Initialize();

	void Update(char* keys, char* prekeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_,
		bool onBomb_, int scene, int text_);

	void Draw(int frameRight, int frameLeft, int plate, int WASDStile_, int directionStule_, int playerWASD, int playerDirection,
		int playerCore, int bombBullet, bool directionStile_, int playerBullet, int scene, int enemytutorial, int enemyBulletImage,
		int clearPlate, int miniBoss, int bossImage, int bossCore);

	//�����o�ϐ�
	Admission* admission_; //���ꉉ�o

	Player* player_;

	Boss* boss_;

	Clear* clear_;         //�N���A���o
};