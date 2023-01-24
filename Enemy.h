#pragma once
#include "Struct.h"
#include "EnemyBullet.h"

/// <summary>
/// 敵
/// </summary>
class Enemy
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update(int scene, int text_);

	//当たり判定
	//何もしない敵
	void EnemyOnCollision(int playerBulletAttack);

	//移動する敵
	void MoveEnemyOnCollision(int playerBulletAttack);

	//単発弾を撃つ敵
	void BulletEnemyOnCollision(int playerBulletAttack);

	//複数弾を撃つ敵
	void BulletsEnemyOnCollision(int playerBulletAttack);

	//描画処理
	void Draw(int scene);

	//メンバ変数
	//敵構造体
	//何もしない敵
	Zako enemy_;

	//移動する敵
	Zako moveEnemy_;

	//単発弾を撃つ敵
	Zako bulletEnemy_;

	//複数弾を撃つ敵
	Zako bulletsEnemy_;

	//弾
	EnemyBullet* enemyBullet_;
};

