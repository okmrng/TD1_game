#pragma once
#include "Struct.h"

class PlayerBullet
{
public:
	//メンバ関数
	void Initailize();

	void Update();

	void Draw();

public:
	//メンバ変数
	//弾構造体
	Bullet bullet_a;
};

