#pragma once
#include "Struct.h"
#include "PlayerBullet.h"

class Player
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update(char* keys);

	//描画処理
	void Draw();

	//ゲッター関数
	float GetterPosX() { return player_.pos.X; }
	float GetterPosY() { return player_.pos.Y; }
	float GetterRadius() { return player_.radius; }
	bool GetterisAlive() { return player_.isAlive; }

private:
	//メンバ変数
	//自機構造体
	Chara player_;

	//弾
	PlayerBullet* bullet_;
};

