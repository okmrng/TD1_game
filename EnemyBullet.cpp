#include "EnemyBullet.h"
#include <Novice.h>

//初期化
void EnemyBullet::Initialize() {
	//単発弾
	for (int i = 0; i < 14; i++) {
		enemyBullet_.isShot[i] = false;
		enemyBullet_.radius[i] = 10.0f;
		enemyBullet_.coolTime[i] = 0;
	}

	for (int i = 0; i < 6; i++) {
		enemyBullet_.speed[i].Y = 7.0f;
	}

	enemyBullet_.speed[0].X = 5.0f;
	enemyBullet_.speed[1].X = 3.0f;
	enemyBullet_.speed[2].X = -5.0f;
	enemyBullet_.speed[3].X = -3.0f;

	for (int i = 4; i < 6; i++) {
		enemyBullet_.speed[i].X = 0.0f;
	}

	for (int i = 6; i < 8; i++) {
		enemyBullet_.speed[i].Y = 0.0f;
	}
	enemyBullet_.speed[6].X = 7.0f;
	enemyBullet_.speed[7].X = -7.0f;

	for (int i = 8; i < 12; i++) {
		enemyBullet_.speed[i].X = 0.0f;
		enemyBullet_.speed[i].Y = 7.0f;
	}

	for (int i = 12; i < 14; i++) {
		enemyBullet_.speed[i].Y = 0.0f;
	}

	enemyBullet_.speed[12].X = 7.0f;
	enemyBullet_.speed[13].X = -7.0f;

	//複数弾
	for (int i = 0; i < 15; i++) {
		enemyBullets_.isShot[i] = false;
		enemyBullets_.radius[i] = 10.0f;
		enemyBullets_.speed[i].Y = 5.0f;
	}

	for (int i = 0; i < 3; i++) {
		enemyBullets_.speed[i].X = 1.0f;
	}

	for (int i = 3; i < 9; i++) {
		enemyBullets_.speed[i].X = 0.3f;
	}

	for (int i = 9; i < 15; i++) {
		enemyBullets_.speed[i].X = 0.3f;
	}

	for (int i = 15; i < 18; i++) {
		enemyBullets_.speed[i].X = 7.5f;
	}

	enemyBullets_.speed[15].Y = 0.0f;
	enemyBullets_.speed[16].Y = 2.0f;
	enemyBullets_.speed[17].Y = -2.0f;

	for (int i = 18; i < 21; i++) {
		enemyBullets_.speed[i].X = -7.5f;
	}

	enemyBullets_.speed[18].Y = 0.0f;
	enemyBullets_.speed[19].Y = 2.0f;
	enemyBullets_.speed[20].Y = -2.0f;

	for (int i = 21; i < 24; i++) {
		enemyBullets_.speed[i].Y = 7.5f;
	}

	enemyBullets_.speed[21].X = 0.0f;
	enemyBullets_.speed[22].X = 2.0f;
	enemyBullets_.speed[23].X = -2.0f;
}

//更新処理
void EnemyBullet::Update() {
	//単発弾
	for (int i = 0; i < 14; i++) {
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

	//複数弾
	for (int i = 0; i < 15; i++) {
		if (enemyBullets_.isShot[i] == true) {
			//移動
			enemyBullets_.pos[i].Y += enemyBullets_.speed[i].Y;

			enemyBullets_.pos[0].X -= enemyBullets_.speed[0].X;

			enemyBullets_.pos[2].X += enemyBullets_.speed[2].X;

			enemyBullets_.pos[3].X -= enemyBullets_.speed[3].X;

			enemyBullets_.pos[5].X += enemyBullets_.speed[5].X;

			enemyBullets_.pos[6].X -= enemyBullets_.speed[6].X;

			enemyBullets_.pos[8].X += enemyBullets_.speed[8].X;

			enemyBullets_.pos[9].X -= enemyBullets_.speed[9].X;

			enemyBullets_.pos[11].X += enemyBullets_.speed[11].X;

			enemyBullets_.pos[12].X -= enemyBullets_.speed[12].X;

			enemyBullets_.pos[14].X += enemyBullets_.speed[14].X;

			//画面外に行ったらフラグをfalseにする
			/*if (enemyBullets_.pos[i].X <= 317.0f || enemyBullets_.pos[i].X >= 963.0f || enemyBullets_.pos[i].Y <= -8.0f || enemyBullets_.pos[i].Y >= 728.0f) {
				enemyBullets_.isShot[i] = false;
			}*/
			if (enemyBullets_.pos[i].Y >= 728.0f) {
				enemyBullets_.isShot[i] = false;
			}
		}
	}

	for (int i = 15; i < 24; i++) {
		if (enemyBullets_.isShot[i] == true) {
			enemyBullets_.pos[i].X += enemyBullets_.speed[i].X;
			enemyBullets_.pos[i].Y += enemyBullets_.speed[i].Y;
		}
	}

	for (int i = 15; i < 18; i++) {
		if (enemyBullets_.pos[15].X >= 963.0f) {
			enemyBullets_.isShot[i] = false;
		}
	}

	for (int i = 18; i < 21; i++) {
		if (enemyBullets_.pos[18].X <= 317.0f) {
			enemyBullets_.isShot[i] = false;
		}
	}

	for (int i = 21; i < 24; i++) {
		if (enemyBullets_.pos[21].Y >= 728.0f) {
			enemyBullets_.isShot[i] = false;
		}
	}}

//描画処理
void EnemyBullet::Draw(int enemyBulletImage) {
	for (int i = 0; i < 14; i++) {
		if (enemyBullet_.isShot[i] == true) {
			Novice::DrawSprite(enemyBullet_.pos[i].X - 10.0f, enemyBullet_.pos[i].Y - 10.0f, enemyBulletImage, 1, 1, 0.0f, WHITE);
		}
	}

	//複数弾
	for (int i = 0; i < 24; i++) {
		if (enemyBullets_.isShot[i] == true) {
			Novice::DrawSprite(enemyBullets_.pos[i].X - 10.0f, enemyBullets_.pos[i].Y - 10.0f, enemyBulletImage, 1, 1, 0.0f, WHITE);
		}
	}
	Novice::ScreenPrintf(0, 60, "%d", enemyBullets_.pos[18].X);
	if (enemyBullets_.isShot[18] == true) {
		Novice::ScreenPrintf(0, 120, "true");
	}
	if (enemyBullets_.isShot[18] == false) {
		Novice::ScreenPrintf(0, 120, "false");
	}
}