#pragma once
#include "Player.h"

class Admission
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update();

	//描画処理
	void Draw(int frameSide, int Plate, int tutorialSkip);

private:
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
	float plateX1_;
	float plateX2_;
	float plateX3_;
	float plateX4_;
	float plateX5_;
	float plateX6_;

	//プレート速度
	float plateSpeedX_;

	//イージング
	float t1_;
	float t2_;
	float t3_;
	bool onEase_;
	bool onPlateEase1_;
	bool onPlateEase2_;
	bool onSlowly_;

	//自機位置
	float playerY_;
	float playerY1_;
	float playerY2_;

	//カウント
	int plateEaseStartCount_;

	//スキップフラグ
	bool skipDirection_;
	bool next_;

	//自機
	Player* player_;
};

