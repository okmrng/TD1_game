#include "EnemyBullet.h"
#include <Novice.h>

//初期化
void EnemyBullet::Initialize() {
	//単発弾
	/*enemyBullet_.isShot = false;
	enemyBullet_.radius = 8.0f;
	enemyBullet_.speed.X = 7.0f;
	enemyBullet_.speed.Y = 7.0f;
	coolTime_ = 0;*/

	//複数弾
	/*for (int i = 0; i < 10; i++) {
		enemyBullets_.isShot[i] = false;
		enemyBullets_.radius[i] = 8.0f;
	}
	enemyBullets_.speed.X = 7.0f;
	enemyBullets_.speed.Y = 7.0f;
	sCoolTime_ = 0;*/
}

//更新処理
void EnemyBullet::Update() {
	//単発弾
	//移動
	//if (enemyBullet_.isShot == true) {
	//	enemyBullet_.pos.Y += enemyBullet_.speed.Y;

	//	//画面外に行ったらフラグをfalseにする
	//	if (enemyBullet_.pos.X <= 317.0f || enemyBullet_.pos.X >= 963.0f || enemyBullet_.pos.Y <= -8.0f || enemyBullet_.pos.Y >= 728.0f) {
	//		enemyBullet_.isShot = false;
	//	}
	//}

	////フラグがfalseになったらクールタイムをカウントする
	//if (enemyBullet_.isShot == false) {
	//	if (coolTime_ <= 30) {
	//		coolTime_++;
	//	}

	//	//クールタイムのカウントが終わったらフラグを立てる
	//	if (coolTime_ >= 30) {
	//		coolTime_ = 0;
	//		enemyBullet_.isShot = true;
	//	}
	//}

	//複数弾
	//for (int i = 0; i < 10; i++) {
	//	if (enemyBullets_.isShot[i] == true) {
	//		//移動
	//		enemyBullets_.pos[i].Y += enemyBullets_.speed.Y;

	//		//画面外に行ったらフラグをfalseにする
	//		if (enemyBullets_.pos[i].X <= 317.0f || enemyBullets_.pos[i].X >= 963.0f || enemyBullets_.pos[i].Y <= -8.0f || enemyBullets_.pos[i].Y >= 728.0f) {
	//			enemyBullets_.isShot[i] = false;
	//		}
	//	}
	//}
}

//当たり判定
void EnemyBullet::OnCollition() {
	//enemyBullet_.isShot = false;
}

//描画処理
void EnemyBullet::Draw() {
	//単発弾
	/*if (enemyBullet_.isShot == true) {
		Novice::DrawEllipse(enemyBullet_.pos.X, enemyBullet_.pos.Y, enemyBullet_.radius, enemyBullet_.radius, 0.0f, RED, kFillModeSolid);
	}*/

	//複数弾
	/*for (int i = 0; i < 10; i++) {
		if (enemyBullets_.isShot[i] == true) {
			Novice::DrawEllipse(enemyBullets_.pos[i].X, enemyBullets_.pos[i].Y, enemyBullets_.radius[i], enemyBullets_.radius[i], 0.0f, RED, kFillModeSolid);
		}
	}*/
}