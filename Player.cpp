#include "Player.h"
#include <Novice.h>

//������
void Player::Initialize() {
	//���@
	player_.pos.X = 640.0f;
	player_.pos.Y = 660.0f;
	player_.speed.X = 8.0f;
	player_.speed.Y = 8.0f;
	player_.radius = 20.0f;
	player_.isAlive = true;
	player_.HP = 3;
	color_ = BLUE;
	collisionCount_ = 0;
	onCollision_ = false;

	//�e
	bullet_ = new PlayerBullet();
	bullet_->Initialize();
}

//�X�V����
void Player::Update(char* keys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_) {
	if (player_.isAlive == true) {
		//�ړ�
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

			//�����L�[
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

		//�ړ��͈�
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

		if (onPlayerShot_ == true) {
			//�e������
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

		//���G���Ԃ����炷
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

		//���G���ԈȊO�͒ʏ�̐F�ɂ���
		if (onCollision_ == false) {
			color_ = BLUE;
		}
	}
}

//�����蔻��
void Player::OnCollision() {
	//HP���炷
	if (collisionCount_ == 0) {
		player_.HP -= 1;
		collisionCount_ = 180;
		onCollision_ = true;
	}
}

//�`�揈��
void Player::Draw() {
	if (player_.isAlive == true) {
		Novice::DrawEllipse(player_.pos.X, player_.pos.Y, player_.radius, player_.radius, 0.0f, color_, kFillModeSolid);
	}

	bullet_->Draw();

	Novice::ScreenPrintf(0, 20, "%d", collisionCount_);
}