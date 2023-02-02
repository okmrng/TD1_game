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

	for (int i = 0; i < 4; i++) {
		enemyBullet_.isShot[i] = false;
		enemyBullet_.radius[i] = 10.0f;
		enemyBullet_.speed[i].Y = 7.0f;
		enemyBullet_.coolTime[i] = 0;
	}
	enemyBullet_.speed[0].X = 5.0f;
	enemyBullet_.speed[1].X = 3.0f;
	enemyBullet_.speed[2].X = -5.0f;
	enemyBullet_.speed[3].X = -3.0f;

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
	for (int i = 0; i < 4; i++) {
		if (enemyBullet_.isShot[i] == true) {
			//移動
			enemyBullet_.pos[i].X += enemyBullet_.speed[i].X;
			enemyBullet_.pos[i].Y += enemyBullet_.speed[i].Y;

			//画面外に行ったらフラグをfalseにする
			if (enemyBullet_.pos[i].X <= 317.0f || enemyBullet_.pos[i].X >= 963.0f || enemyBullet_.pos[i].Y <= -8.0f || enemyBullet_.pos[i].Y >= 728.0f) {
				enemyBullet_.isShot[i] = false;
			}
		}
	}

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
void EnemyBullet::Draw(int enemyBulletImage) {
	//単発弾
	/*if (enemyBullet_.isShot == true) {
		Novice::DrawEllipse(enemyBullet_.pos.X, enemyBullet_.pos.Y, enemyBullet_.radius, enemyBullet_.radius, 0.0f, RED, kFillModeSolid);
	}*/
	for (int i = 0; i < 4; i++) {
		if (enemyBullet_.isShot[i] == true) {
			Novice::DrawSprite(enemyBullet_.pos[i].X - 10.0f, enemyBullet_.pos[i].Y - 10.0f, enemyBulletImage, 1, 1, 0.0f, WHITE);
		}
	}

	//複数弾
	/*for (int i = 0; i < 10; i++) {
		if (enemyBullets_.isShot[i] == true) {
			Novice::DrawEllipse(enemyBullets_.pos[i].X, enemyBullets_.pos[i].Y, enemyBullets_.radius[i], enemyBullets_.radius[i], 0.0f, RED, kFillModeSolid);
		}
	}*/
	Novice::ScreenPrintf(0, 60, "%d", enemyBullet_.pos[0].X);
}