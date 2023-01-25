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

	player_->SetterBombs(1);

	//敵
	enemy_ = new Enemy();
	enemy_->Initialize();

	//クリア演出
	clear_ = new Clear();
	clear_-> Initialize();

	//弾
	shotTime_ = 0;
	for (int i = 0; i < 5; i++) {
		isEnemyShot_[i] = false;
		isEnemyMove_[i] = true;
		enemyBulletY_[i] = -8.0f;
		enemyBulletR_[i] = 15.0f;
		enmeyBulletSpeed_ = 10.0f;
	}
	enemyBulletX_[0] = 560.0f;
	enemyBulletX_[1] = 600.0f;
	enemyBulletX_[2] = 640.0f;
	enemyBulletX_[3] = 680.0f;
	enemyBulletX_[4] = 720.0f;

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

	//ボムフラグ
	onBomb_ = false;
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
			if (shotTime_ <= 45) {
				shotTime_++;
			}
			for (int i = 0; i < 5; i++) {
				if (shotTime_ >= 45) {
					isEnemyShot_[i] = true;
				}

				if (isEnemyShot_[i] == true) {
					if (isEnemyMove_[i] == true) {
						enemyBulletY_[i] += enmeyBulletSpeed_;

						if (enemyBulletY_[i] >= 600.0f) {
							isEnemyMove_[i] = false;
						}
					}
				}

				if (isEnemyMove_[i] == false) {
					text_ = 9;
				}
			}
		}

		if (text_ == 9) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 10;
					pushCount_ = 0;
				}
			}
		}

		if (text_ == 10) {
			for (int i = 0; i < 5; i++) {
				if (isEnemyShot_[i] == false) {
					if (player_->GetterShotBomb() == false) {
						text_ = 11;
					}					
				}
			}
		}

		if (text_ == 11) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 12;
					pushCount_ = 0;
				}
			}
		}

		if (text_ == 12) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 13;
					pushCount_ = 0;
				}
			}
		}

		if (text_ == 13) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 14;
					pushCount_ = 0;
				}
			}
		}

		if (text_ == 14) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					next_ = true;
				}
			}
		}

		//シーン遷移
		if (text_ >= 1) {
			//次のシーンへ
			if (keys[DIK_ESCAPE] && preKeys[DIK_ESCAPE] == 0) {
				onPlayerMove_ = true;
				onPlayerShot_ = true;
				onBomb_ = true;
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

		if (text_ >= 10) {
			onBomb_ = true;
		}
	}

	//自機
	player_->Update(keys, preKeys, WASDStile_, directionStile_, onPlayerMove_, onPlayerShot_, onBomb_);

	//ボム
	if (player_->GetterShotBomb() == true) {
		for (int i = 0; i < 5; i++) {
			if (isEnemyShot_[i] == true) {
				isEnemyShot_[i] = false;
			}
		}
	}

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
	int tutorialText9, int tutorialText10Direction, int tutorialText10WASD, int tutorialText11, int tutorialText12,
	int tutorialText13, int tutorialText14, int scene, int tutorialBg,int bombBullet) {
	//背景
	Novice::DrawSprite(325, 0, tutorialBg, 1.0f, 1.0f, 0.0f, WHITE);

	//敵
	enemy_->Draw(scene);

	//弾
	for (int i = 0; i < 5; i++) {
		if (isEnemyShot_[i] == true) {
			Novice::DrawEllipse(enemyBulletX_[i], enemyBulletY_[i], enemyBulletR_[i], enemyBulletR_[i], 0.0f, RED, kFillModeSolid);
		}
	}

	//ステージ入場演出
	admission_->Draw(frameSide, Plate);

	//自機
	if (admission_->GetterPlayStart() == true) {
		player_->Draw(bombBullet);
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
			if (text_ == 10) {
				Novice::DrawSprite(textX_, textY_, tutorialText10Direction, 1.0f, 1.0f, 0.0f, WHITE);
			}
		}
		if (WASDStile_ == true) {
			if (text_ == 3) {
				Novice::DrawSprite(textX_, textY_, tutorialText3WASD, 1.0f, 1.0f, 0.0f, WHITE);
			}
			if (text_ == 10) {
				Novice::DrawSprite(textX_, textY_, tutorialText10WASD, 1.0f, 1.0f, 0.0f, WHITE);
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
		if (text_ == 9) {
			Novice::DrawSprite(textX_, textY_, tutorialText9, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 11) {
			Novice::DrawSprite(textX_, textY_, tutorialText11, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 12) {
			Novice::DrawSprite(textX_, textY_, tutorialText12, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 13) {
			Novice::DrawSprite(textX_, textY_, tutorialText13, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 14) {
			Novice::DrawSprite(textX_, textY_, tutorialText14, 1.0f, 1.0f, 0.0f, WHITE);
		}
	}
	Novice::ScreenPrintf(0, 80, "HP:%d", enemy_->moveEnemy_.HP[0]);
}