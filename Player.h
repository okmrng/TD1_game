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

	//当たり判定
	void OnCollision();

	//描画処理
	void Draw();

	//ゲッター関数
	float GetterPosX() { return player_.pos.X; }
	float GetterPosY() { return player_.pos.Y; }
	float GetterRadius() { return player_.radius; }
	bool GetterisAlive() { return player_.isAlive; }
	int GetterHP() { return player_.HP; }
	bool GetterOnCollision() { return onCollision_; }

	//メンバ変数
	//弾
	PlayerBullet* bullet_;

private:
	//自機構造体
	Chara player_;

	//自機の色
	unsigned int color_;

	//無敵時間
	int collisionCount_;

	//当たり判定が働いたときに立つフラグ
	bool onCollision_;
};

