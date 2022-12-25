#include "PlayerBullet.h"
#include <Novice.h>

//初期化
void PlayerBullet::Initialize() {
	for (int i = 0; i < 15; i++) {
		bullet_.isShot[i] = false;
	}
	bullet_.radius = 8.0f;
	bullet_.speed.X = 10.0f;
	bullet_.speed.Y = 10.0f;
	bullet_.attack = 1;
	bullet_.coolTime = 0;
}

//更新処理
void PlayerBullet::Update() {
	for (int i = 0; i < 15; i++) {
		if (bullet_.isShot[i] == true) {
			//移動
			bullet_.pos[i].Y -= bullet_.speed.Y;

			//画面外に行ったらフラグをfalseにする
			if (bullet_.pos[i].Y <= -10) {
				bullet_.isShot[i] = 0;
			}
		}
	}
}

//描画処理
void PlayerBullet::Draw() {
	for (int i = 0; i < 15; i++) {
		if (bullet_.isShot[i] == true) {
			Novice::DrawEllipse(bullet_.pos[i].X, bullet_.pos[i].Y, bullet_.radius, bullet_.radius, 0.0f, RED, kFillModeSolid);
		}
	}

	/*Novice::ScreenPrintf(0, 0, "%d", bullet_.isShot);
	Novice::ScreenPrintf(0, 20, "%0.0f", bullet_.pos.X);
	Novice::ScreenPrintf(0, 40, "%0.0f", bullet_.pos.Y);*/
}