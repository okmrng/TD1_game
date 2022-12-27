#include "EnemyBullet.h"
#include <Novice.h>

//初期化
void EnemyBullet::Intialize() {
	enemyBullet_.isShot = false;
	enemyBullet_.radius = 8.0f;
	enemyBullet_.speed.X = 7.0f;
	enemyBullet_.speed.Y = 7.0f;
	coolTime = 0;
}

//更新処理
void EnemyBullet::Update() {
	//移動
	if (enemyBullet_.isShot == true) {
		enemyBullet_.pos.Y += enemyBullet_.speed.Y;

		//画面外に行ったらフラグをfalseにする
		if (enemyBullet_.pos.X <= 317.0f || enemyBullet_.pos.X >= 963.0f || enemyBullet_.pos.Y <= -8.0f || enemyBullet_.pos.Y >= 728.0f) {
			enemyBullet_.isShot = false;
		}
	}

	//フラグがfalseになったらクールタイムをカウントする
	if (enemyBullet_.isShot == false) {
		if (coolTime <= 30) {
			coolTime++;
		}

		//クールタイムのカウントが終わったらフラグを立てる
		if (coolTime >= 30) {
			coolTime = 0;
			enemyBullet_.isShot = true;
		}
	}
}

//当たり判定
void EnemyBullet::OnCollition() {
	enemyBullet_.isShot = false;
}

//描画処理
void EnemyBullet::Draw() {
	Novice::DrawEllipse(enemyBullet_.pos.X, enemyBullet_.pos.Y, enemyBullet_.radius, enemyBullet_.radius, 0.0f, RED, kFillModeSolid);
}