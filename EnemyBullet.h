#pragma once
#include "Struct.h"

class EnemyBullet
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update();

	//当たり判定
	void OnCollition();

	//描画処理
	void Draw(int enemyBulletImage);

	//メンバ変数
	//単発弾構造体
	EBullet enemyBullet_;

	//クールタイム
	int coolTime_;

	//複数弾構造体
	EBullets enemyBullets_;

	//クールタイム
	int sCoolTime_;
};

