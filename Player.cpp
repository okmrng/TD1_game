#include "Player.h"
#include <Novice.h>

//‰Šú‰»
void Player::Initialize() {
	//Ž©‹@
	player_.pos.X = 640.0f;
	player_.pos.Y = 660.0f;
	player_.speed.X = 8.0f;
	player_.speed.Y = 8.0f;
	player_.radius = 20.0f;
	player_.isAlive = true;
	player_.HP = 3;
	color = BLUE;
	collisionCount = 0;
	onCollision = false;

	//’e
	bullet_ = new PlayerBullet();
	bullet_->Initialize();
}

//XVˆ—
void Player::Update(char* keys) {
	if (player_.isAlive == true) {
		//ˆÚ“®
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

		//–³“GŽžŠÔ‚ðŒ¸‚ç‚·
		if (onCollision == true) {
			if (collisionCount > 0) {
				--collisionCount;
				color = RED;
				if (collisionCount <= 0) {
					collisionCount = 0;
					onCollision = false;
				}
			}
		}

		//–³“GŽžŠÔˆÈŠO‚Í’Êí‚ÌF‚É‚·‚é
		if (onCollision == false) {
			color = BLUE;
		}

		//ˆÚ“®”ÍˆÍ
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

		//’e‚ðŒ‚‚Â
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
						bullet_->bullet_.pos[i].Y = player_.pos.Y;

						break;
					}
				}
			}
		}

		bullet_->Update();
	}
}

//“–‚½‚è”»’è
void Player::OnCollision() {
	//HPŒ¸‚ç‚·
	if (collisionCount == 0) {
		player_.HP -= 1;
		collisionCount = 180;
		onCollision = true;
	}
}

//•`‰æˆ—
void Player::Draw() {
	if (player_.isAlive == true) {
		Novice::DrawEllipse(player_.pos.X, player_.pos.Y, player_.radius, player_.radius, 0.0f, color, kFillModeSolid);
	}

	bullet_->Draw();

	Novice::ScreenPrintf(0, 20, "%d", collisionCount);
}