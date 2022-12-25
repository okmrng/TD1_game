#pragma once
#include "Struct.h"

class Enemy
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update();

	//当たり判定
	void OnCollision(int playerBulletAttack);

	//描画処理
	void Draw();

	//メンバ変数
	//敵構造体
	//何もしない敵
	Zako enemy_;
};

