#include "Player.h"
#include <Novice.h>

//初期化
void Player::Initialize() {
	player_.pos.X = 640.0f;
	player_.pos.Y = 660.0f;
	player_.speed.X = 8.0f;
	player_.speed.Y = 8.0f;
	player_.radius = 20.0f;
	player_.isAlive = true;

	bullet_ = new PlayerBullet();
	bullet_->Initailize();
}

//更新処理
void Player::Update(char* keys) {
	if (player_.isAlive == true) {
		//移動
		if (keys[DIK_UP] || keys[DIK_W]) {
			player_.pos.Y -= player_.speed.Y;
		}
		if (keys[DIK_DOWN] || keys[DIK_S]) {
			player_.pos.Y += player_.speed.Y;
		}
		if (keys[DIK_LEFT] || keys[DIK_A]) {
			player_.pos.X -= player_.speed.X;
		}
		if (keys[DIK_RIGHT] || keys[DIK_D]) {
			player_.pos.X += player_.speed.X;
		}

		if (keys[DIK_A] || keys[DIK_LEFT] && (keys[DIK_W] || keys[DIK_UP] || keys[DIK_S] || keys[DIK_DOWN])) {
			player_.speed.X = 5.6f;
			player_.speed.Y = 5.6f;
		}
		else if (keys[DIK_D] || keys[DIK_RIGHT] && (keys[DIK_W] || keys[DIK_UP] || keys[DIK_S] || keys[DIK_DOWN])) {
			player_.speed.X = 5.6f;
			player_.speed.Y = 5.6f;
		}
		else {
			player_.speed.X = 8.0f;
			player_.speed.Y = 8.0f;
		}

		//移動範囲
		if (player_.pos.X <= 345.0f) {
			player_.pos.X = 345.0f;
		}
		if (player_.pos.X >= 935.0f) {
			player_.pos.X = 935.0f;
		}
		if (player_.pos.Y <= 20.0f) {
			player_.pos.Y = 20.0f;
		}
		if (player_.pos.Y >= 700.0f) {
			player_.pos.Y = 700.0f;
		}

		//弾を撃つ
		bullet_->bullet_.coolTime++;
		if (bullet_->bullet_.coolTime > 5) {
			bullet_->bullet_.coolTime = 0;
		}

		if (keys[DIK_SPACE]) {
			if (bullet_->bullet_.coolTime == 5) {
				for (int i = 0; i < 15; i++) {
					if (bullet_->bullet_.isShot[i] == 0) {
						bullet_->bullet_.isShot[i] = 1;
						bullet_->bullet_.pos[i].X = player_.pos.X;
						bullet_->bullet_.pos[i].Y = player_.pos.Y;

						break;
					}
				}
			}
		}

		bullet_->Update();
	}
}

//描画処理
void Player::Draw() {
	if (player_.isAlive == true) {
		Novice::DrawEllipse(player_.pos.X, player_.pos.Y, player_.radius, player_.radius, 0.0f, WHITE, kFillModeSolid);
	}

	bullet_->Draw();
}