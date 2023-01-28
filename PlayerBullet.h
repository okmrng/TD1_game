#pragma once
#include "Struct.h"

class PlayerBullet
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update();

	//描画処理
	void Draw(int playerBullet);

	//メンバ変数
	//弾構造体
	Bullet bullet_;
};

