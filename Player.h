#pragma once
#include "Struct.h"
#include "PlayerBullet.h"
#include "BombParticle.h"

/// <summary>
/// 自機
/// </summary>
class Player
{
public:
	//メンバ関数
	
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="keys"></param>
	/// <param name="preKeys"></param>
	/// <param name="WASDStile_"></param>
	/// <param name="directionStile_"></param>
	/// <param name="onPlayerMove_"></param>
	/// <param name="onPlayerShot_"></param>
	/// <param name="onBomb_"></param>
	void Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_, bool onBomb_);

	/// <summary>
	/// 当たり判定
	/// </summary>
	void OnCollision();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw(int bombBullet, bool WASDStile_, bool directionStile_, int playerWASD, int playerDirection, int playerCore, int playerBullet);

	//ゲッター関数
	float GetterPosX() { return player_.pos.X; }
	float GetterPosY() { return player_.pos.Y; }
	float GetterRadius() { return player_.radius; }
	bool GetterisAlive() { return player_.isAlive; }
	int GetterHP() { return player_.HP; }
	bool GetterOnCollision() { return onCollision_; }
	bool GetterShotBomb() { return shotBomb_; }
	int GetterBombs() { return bombs_; }

	//セッター関数
	void SetterBombs(int bombs);

	//メンバ変数
	//弾
	PlayerBullet* bullet_;

	//ボム
	BombParticle* bombParticle_;

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

	//ボム色
	unsigned int bombColor_;
	unsigned int bombFade_;

	//ボムフェードスタート
	bool onBombFade_;

	//ボム弾
	bool onBombShot_;

	bool offBombCount_;
};