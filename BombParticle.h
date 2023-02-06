#pragma once

/// <summary>
/// ボム弾
/// </summary>
class BombParticle
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
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw(int bombBullet);

	//ゲッター関数
	float GetterCollisionX() { return collisionX_; }
	float GetterCollisionY() { return collisionY_; }
	float GetterCollisionR() { return collisionR_; }

	//メンバ変数
	//パーティクル
	int particleMax_; ///パーティクル最大値
	bool isActive_[300];
	float particleX_[300];
	float particleY_[300];
	float particleW_[300];
	float particleH_[300];
	unsigned int color_[300];
	unsigned int fade_[300];    ///透明度

	bool isActive_2[300];
	float particleX_2[300];
	float particleY_2[300];
	float particleW_2[300];
	float particleH_2[300];
	unsigned int color_2[300];
	unsigned int fade_2[300];    ///透明度

	bool isActive_3[300];
	float particleX_3[300];
	float particleY_3[300];
	float particleW_3[300];
	float particleH_3[300];
	unsigned int color_3[300];
	unsigned int fade_3[300];    ///透明度

	//エミッター
	int emitterX_;
	int emitterY_;
	int emitterY1_;
	int emitterY2_;
	int emitterW_;
	int emitterH_;

	//本体
	float collisionX_;
	float collisionY_;
	float collisionY1_;
	float collisionY2_;
	float collisionR_;

	float speed_;

	float t_;
};