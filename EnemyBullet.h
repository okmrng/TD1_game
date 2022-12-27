#pragma once
#include "Struct.h"

class EnemyBullet
{
public:
	//メンバ関数
	//初期化
	void Intialize();

	//更新処理
	void Update();

	//当たり判定
	void OnCollition();

	//描画処理
	void Draw();

	//メンバ変数
	//弾構造体
	EBullet enemyBullet_;

	//クールタイム
	int coolTime;
};

