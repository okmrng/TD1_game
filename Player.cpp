#include "Player.h"
#include <Novice.h>

//初期化
void Player::Initialize() {
	//自機
	player_.pos.X = 640.0f;
	player_.pos.Y = 668.0f;
	player_.speed.X = 8.0f;
	player_.speed.Y = 8.0f;
	player_.radius = 12.0f;
	player_.isAlive = true;
	player_.HP = 3;
	color_ = BLUE;
	collisionCount_ = 0;
	onCollision_ = false;

	//ボム
	bombParticle_ = new BombParticle();
	bombParticle_->Initialize();

	//ボム個数
	bombs_ = 0;

	bombPushCount_ = 5;

	//ボム発動フラグ
	shotBomb_ = false;

	//ボムfalseフラグ
	offBombCount_ = 0;

	//ボム色
	bombColor_ = 0xafeeee00;
	bombFade_ = 0x00000000;

	//ボムフェードスタート
	onBombFade_ = false;

	//ボム弾
	onBombShot_ = false;

	//弾
	bullet_ = new PlayerBullet();
	bullet_->Initialize();
}

//更新処理
void Player::Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_, bool onBomb_) {
	if (player_.isAlive == true) {
		//移動
		//WASD
		if (onPlayerMove_ == true) {
			if (WASDStile_ == true) {
				if (keys[DIK_W]) {
					player_.pos.Y -= player_.speed.Y;
				}
				if (keys[DIK_S]) {
					player_.pos.Y += player_.speed.Y;
				}
				if (keys[DIK_A]) {
					player_.pos.X -= player_.speed.X;
				}
				if (keys[DIK_D]) {
					player_.pos.X += player_.speed.X;
				}

				if (keys[DIK_A] && (keys[DIK_W] || keys[DIK_S])) {
					player_.speed.X = 5.6f;
					player_.speed.Y = 5.6f;
				}
				else if (keys[DIK_D] && (keys[DIK_W] || keys[DIK_S])) {
					player_.speed.X = 5.6f;
					player_.speed.Y = 5.6f;
				}
				else {
					player_.speed.X = 8.0f;
					player_.speed.Y = 8.0f;
				}
			}

			//方向キー
			if (directionStile_ == true) {
				if (keys[DIK_UP]) {
					player_.pos.Y -= player_.speed.Y;
				}
				if (keys[DIK_DOWN]) {
					player_.pos.Y += player_.speed.Y;
				}
				if (keys[DIK_LEFT]) {
					player_.pos.X -= player_.speed.X;
				}
				if (keys[DIK_RIGHT]) {
					player_.pos.X += player_.speed.X;
				}

				if (keys[DIK_LEFT] && (keys[DIK_UP] || keys[DIK_DOWN])) {
					player_.speed.X = 5.6f;
					player_.speed.Y = 5.6f;
				}
				else if (keys[DIK_RIGHT] && (keys[DIK_UP] || keys[DIK_DOWN])) {
					player_.speed.X = 5.6f;
					player_.speed.Y = 5.6f;
				}
				else {
					player_.speed.X = 8.0f;
					player_.speed.Y = 8.0f;
				}
			}
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
		if (onPlayerShot_ == true) {
			bullet_->bullet_.coolTime++;
			if (bullet_->bullet_.coolTime > 5) {
				bullet_->bullet_.coolTime = 0;
			}

			if (keys[DIK_SPACE]) {
				if (bullet_->bullet_.coolTime == 5) {
					for (int i = 0; i < 15; i++) {
						if (bullet_->bullet_.isShot[i] == false) {
							bullet_->bullet_.isShot[i] = true;
							bullet_->bullet_.pos[i].X = player_.pos.X;
							bullet_->bullet_.pos[i].Y = player_.pos.Y - 50.0f;

							break;
						}
					}
				}
			}

			bullet_->Update();
		}

		//ボム
		if (onBomb_ == true) {
			if (bombPushCount_ <= 5) {
				bombPushCount_++;
			}

			//ボム発動
			if (bombs_ > 0) {
				if (shotBomb_ == false) {
					bombParticle_->collisionX_ = player_.pos.X;
					bombParticle_->collisionY_ = player_.pos.Y;
					bombParticle_->collisionY1_ = player_.pos.Y;
					bombParticle_->emitterX_ = player_.pos.X - 80.0f;
					bombParticle_->emitterY_ = player_.pos.Y - 20.0f;
					bombParticle_->emitterY1_ = player_.pos.Y - 20.0f;

					if (bombPushCount_ >= 5) {
						//WASD
						if (WASDStile_ == true) {
							if (keys[DIK_M] && preKeys[DIK_M] == 0) {
								onBombFade_ = true;
								shotBomb_ = true;
								bombs_ -= 1;
							}
						}

						//方向キー
						if (directionStile_ == true) {
							if (keys[DIK_Z] && preKeys[DIK_Z] == 0) {
								onBombFade_ = true;
								shotBomb_ = true;
								bombs_ -= 1;
							}
						}
					}

					//offBombCount_ = 0; 
					/*bombParticle_->collisionY_ = 690.0f;
					bombParticle_->emitterY_ = 600.0f;*/
					bombParticle_->t_ = 0.0f;
				}
			}

			if (onBombFade_ == true) {
				if (bombFade_ <= 0x000000FF) {
					bombFade_ += 0x00000040;
				}
				if (bombFade_ >= 0x000000FF) {
					onBombShot_ = true;
					onBombFade_ = false;
				}
			}
			else { bombFade_ = 0x00000000; }

			if (onBombShot_ == true) {
				bombParticle_->Update();

				if (bombParticle_->emitterY_ <= -900.0f) {
					onBombShot_ = false;
					shotBomb_ = false;
				}
			}
		}

		//無敵時間を減らす
		if (onCollision_ == true) {
			if (collisionCount_ > 0) {
				--collisionCount_;
				color_ = RED;
				if (collisionCount_ <= 0) {
					collisionCount_ = 0;
					onCollision_ = false;
				}
			}
		}

		//無敵時間以外は通常の色にする
		if (onCollision_ == false) {
			color_ = BLUE;
		}
	}
}

//セッター関数
void Player::SetterBombs(int bombs) {
	bombs_ = bombs;
}

//当たり判定
void Player::OnCollision() {
	//HP減らす
	if (collisionCount_ == 0) {
		player_.HP -= 1;
		collisionCount_ = 180;
		onCollision_ = true;
	}
}

//描画処理
void Player::Draw(int bombBullet, bool WASDStile_, bool directionStile_, int playerWASD, int playerDirection, int playerCore, int playerBullet) {
	//弾
	bullet_->Draw(playerBullet);

	if (player_.isAlive == true) {
		//自機
		if (WASDStile_ == true) {
			Novice::DrawSprite(player_.pos.X - 33, player_.pos.Y - 65, playerWASD, 1, 1, 0.0f, WHITE);
		}
		if (directionStile_ == true) {
			Novice::DrawSprite(player_.pos.X - 33, player_.pos.Y - 65, playerDirection, 1, 1, 0.0f, WHITE);
		}

		//自機当たり判定
		//Novice::DrawEllipse(player_.pos.X, player_.pos.Y, player_.radius, player_.radius, 0.0f, color_, kFillModeSolid);
		Novice::DrawSprite(player_.pos.X - 13, player_.pos.Y - 13, playerCore, 1, 1, 0.0f, WHITE);
	}

	Novice::DrawBox(325.0f, 0.0f, 630.0f, 720.0f, 0.0f, bombColor_ + bombFade_, kFillModeSolid);

	if (shotBomb_ == true) {
		bombParticle_->Draw(bombBullet);
	}
}