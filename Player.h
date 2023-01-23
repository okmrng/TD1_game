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
	void Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_, bool onBomb_);

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
	bool GetterShotBomb() { return shotBomb_; }

	//セッター関数
	void SetterBombs(int bombs);

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

	//ボム個数
	int bombs_;

	int bombPushCount_;

	//ボム発動フラグ
	bool shotBomb_;

	//ボムfalseタイム
	//int offBombCount_;

	//ボム色
	unsigned int bombColor_;
	unsigned int bombFade_;

	//ボムフェードスタート
	bool onBombFade_;
	bool offBombFade_;
};

