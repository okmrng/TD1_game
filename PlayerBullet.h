#pragma once
#include "Struct.h"

class PlayerBullet
{
public:
	//メンバ関数
	void Initialize();

	void Update();

	void Draw();

	//メンバ変数
	//弾構造体
	Bullet bullet_;
};

