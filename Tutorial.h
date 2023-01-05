#pragma once
#include "Player.h"

class Tutorial
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update();

	//描画処理
	void Draw(int frameSide, int tutorialPlate);

	//メンバ変数
	//フレーム位置 
	float frameRightX_;
	float frameRightY_;
	float frameRightY1_;
	float frameRightY2_;

	float frameLeftX_;
	float frameLeftY_;
	float frameLeftY1_;
	float frameLeftY2_;
	
	//プレート位置
	float plateX_;
	float plateY_;

	//イージング
	float t_;
	bool onEase_;

	//自機位置
	float playerY_;
	float playerY1_;
	float playerY2_;

	//自機
	Player* player_;
};

