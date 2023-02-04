#pragma once
#include "Admission.h"
#include "Player.h"
#include "Enemy.h"
#include "Clear.h"

class Stage1
{
public:
	//�����o�֐�
	
	void Initialize();

	void Update(char* keys, char* prekeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_,
		bool onBomb_, int scene, int text_);

	void Draw(int frameRight, int frameLeft, int plate, int WASDStile_, int directionStule_, int playerWASD, int playerDirection,
		int playerCore, int bombBullet, bool directionStile_, int playerBullet, int scene, int enemytutorial, int enemyBulletImage,
		int clearPlate);

	//�����o�ϐ�
	Admission* admission_; //���ꉉ�o

	Player* player_;

	Enemy* enemy_;

	Clear* clear_;         //�N���A���o

	bool isClear_;
};

