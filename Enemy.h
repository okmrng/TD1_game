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

	//描画処理
	void Draw();

	//ゲッター関数
	float GetterPosX() { return enemy_.pos.X; }
	float GetterPosY() { return enemy_.pos.Y; }
	float GetterRadius() { return enemy_.radius; }
	bool GetterisAlive() { return enemy_.isAlive; }

private:
	//メンバ変数
	//敵構造体
	//何もしない敵
	Zako enemy_;
};

