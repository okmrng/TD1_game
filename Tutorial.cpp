#include "Tutorial.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
void Tutorial::Initialize() {
	//ステージ入場演出
	admission_ = new Admission();
	admission_->Initialize();

	//自機
	player_ = new Player();
	player_->Initialize();

	//敵
	enemy_ = new Enemy();
	enemy_->Initialize();

	//テキストフラグ
	text_ = 1;
	textDisplay_ = false;

	//テキスト位置
	textX_ = 350.0f;
	textY_ = 100.0f;

	//入力カウント
	pushCount_ = 0;

	//シーン遷移
	next_ = false;

	//自機移動フラグ
	onPlayerMove_ = false;

	//自機弾発射フラグ
	onPlayerShot_ = false;
}

//更新処理
void Tutorial::Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, int scene) {
	//ステージ入場演出
	admission_->Update();

	if (admission_->GetterPlayStart() == true) {
		textDisplay_ = true;
	}

	if (textDisplay_ == true) {
		//テキスト進める
		if (text_ == 1) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 2;
					pushCount_ = 0;
				}
			}
		}
		if (text_ == 2) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 3;
					pushCount_ = 0;
				}
			}
		}
		if (text_ == 3) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 4;
					pushCount_ = 0;
				}
			}
		}
		if (text_ == 4) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 5;
					pushCount_ = 0;
				}
			}
		}
		if (text_ == 5) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 6;
					pushCount_ = 0;
				}
			}
		}
		if (text_ == 6) {
			if (enemy_->moveEnemy_.pos[0].X >= 640.0f) {
				text_ = 7;
			}
		}
		if (text_ == 7) {
			if (enemy_->moveEnemy_.isAlive[0] == false) {
				text_ = 8;
			}
		}
		if (text_ == 8) {

		}

		//シーン遷移
		if (text_ >= 1) {
			//次のシーンへ
			if (keys[DIK_ESCAPE] && preKeys[DIK_ESCAPE] == 0) {
				onPlayerMove_ = true;
				onPlayerShot_ = true;
				next_ = true;
			}
		}

		//自機移動フラグ
		//if (text_ >= 3) {
		//	onPlayerMove_ = true;
		//}

		//自機弾発射フラグ
		if (text_ >= 7) {
			onPlayerShot_ = true;
		}
	}

	//自機
	player_->Update(keys, WASDStile_, directionStile_, onPlayerMove_, onPlayerShot_);

	//敵
	enemy_->Update(scene, text_);

	//自機の弾との当たり判定
	for (int i = 0; i < 15; i++) {
		playerBullet_moveEnemyX_ = player_->bullet_->bullet_.pos[i].X - enemy_->moveEnemy_.pos[0].X;
		playerBullet_moveEnemyY_ = player_->bullet_->bullet_.pos[i].Y - enemy_->moveEnemy_.pos[0].Y;
		playerBullet_moveEnemyDis_ = sqrtf(playerBullet_moveEnemyX_ * playerBullet_moveEnemyX_ + playerBullet_moveEnemyY_ * playerBullet_moveEnemyY_);

		if (enemy_->moveEnemy_.isAlive[0] == true) {
			if (playerBullet_moveEnemyDis_ < 20.0f) {
				if (player_->bullet_->bullet_.isShot[i] == true) {
					//enemy->MoveEnemyOnCollision(player->bullet_->bullet_.attack);
					if (enemy_->moveEnemy_.isAlive[0] == true) {
						enemy_->moveEnemy_.HP[0] -= player_->bullet_->bullet_.attack;
						enemy_->moveEnemy_.color[0] = RED;
					}
				}
				player_->bullet_->bullet_.isShot[i] = false;
			}
		}
	}
}

//描画処理
void Tutorial::Draw(int frameSide, int Plate, bool WASDStile_, bool directionStile_, int tutorialText1, int tutorialText2,
	int tutorialText3Direction, int tutorialText3WASD, int tutorialText4, int tutorialText5, int tutorialText7, int textbox,
	int scene, int tutorialBg) {
	//背景
	Novice::DrawSprite(325, 0, tutorialBg, 1.0f, 1.0f, 0.0f, WHITE);

	//敵
	enemy_->Draw(scene);

	//ステージ入場演出
	admission_->Draw(frameSide, Plate);

	//自機
	if (admission_->GetterPlayStart() == true) {
		player_->Draw();
	}

	//テキスト
	if (textDisplay_ == true) {
		if (text_ == 1) {
			Novice::DrawSprite(textX_, textY_, tutorialText1, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 2) {
			Novice::DrawSprite(textX_, textY_, tutorialText2, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (directionStile_ == true) {
			if (text_ == 3) {
				Novice::DrawSprite(textX_, textY_, tutorialText3Direction, 1.0f, 1.0f, 0.0f, WHITE);
			}
		}
		if (WASDStile_ == true) {
			if (text_ == 3) {
				Novice::DrawSprite(textX_, textY_, tutorialText3WASD, 1.0f, 1.0f, 0.0f, WHITE);
			}
		}
		if (text_ == 4) {
			Novice::DrawSprite(textX_, textY_, tutorialText4, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 5) {
			Novice::DrawSprite(textX_, textY_, tutorialText5, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 6) {
			Novice::DrawSprite(textX_, textY_, textbox, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 7) {
			Novice::DrawSprite(textX_, textY_, tutorialText7, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 8) {
			Novice::DrawSprite(textX_, textY_, textbox, 1.0f, 1.0f, 0.0f, WHITE);
		}
	}
	Novice::ScreenPrintf(0, 80, "HP:%d", enemy_->moveEnemy_.HP[0]);
}