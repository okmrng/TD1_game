#pragma once
#include "Admission.h"
#include "Player.h"
#include "Enemy.h"
#include "Clear.h"

class Stage1
{
public:
	//メンバ関数
	
	void Initialize();

	void Update(char* keys, char* prekeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_,
		bool onBomb_, int scene, int text_);

	void Draw(int frameRight, int frameLeft, int plate, int WASDStile_, int directionStule_, int playerWASD, int playerDirection,
		int playerCore, int bombBullet, bool directionStile_, int playerBullet, int scene, int enemytutorial, int enemyBulletImage,
		int clearPlate);

	//メンバ変数
	Admission* admission_; //入場演出

	Player* player_;

	Enemy* enemy_;

	Clear* clear_;         //クリア演出

	bool isClear_;
};

