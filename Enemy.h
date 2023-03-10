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

	//描画処理
	void Draw(int scene, int enemyTutorial, int enemyBulletImage, int miniBoss);

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

	//中ボス
	Zako miniBoss_;

	//弾
	EnemyBullet* enemyBullet_;

    //敵が現れるまでのカウント
	int enemyCount_;
};

