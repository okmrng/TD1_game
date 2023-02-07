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
	isClear_ = false;

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
	nextTime_ = 0;
	pushEsc_ = false;

	//自機移動フラグ
	onPlayerMove_ = false;

	//自機弾発射フラグ
	onPlayerShot_ = false;

	//ボムフラグ
	onBomb_ = false;

	//幕
	iCTime_ = 0;
	inCurtain_ = false;
	curtainX_ = 0.0f;
	curtainY_ = -1280.0f;
	curtainY1_ = -1280.0f;
	curtainY2_ = 0.0f;
	curtainT_ = 0.0f;

	//アイコン
	HPY_ = -1377.0f;
	HPY1_ = -1377.0f;
	HPY2_ = 97.0f;

	bombY_ = -1491.0f;
	bombY1_ = -1491.0f;
	bombY2_ = 211.0f;

	t_ = 0.0f;

	HP_ = Novice::LoadTexture("./Resources/Images/HP.png");
	bomb_ = Novice::LoadTexture("./Resources/Images/bomb.png");
}

//更新処理
void Tutorial::Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, int scene) {
	//ステージ入場演出
	admission_->Update();

	if (t_ < 1.0f) {
		t_ += 1.0f / 30.0f;
	}
	if (t_ >= 1.0f) {
		t_ = 1.0f;
	}

	float easedT_ = sqrt(1.0f - pow(t_ - 1.0f, 2.0f));

	HPY_ = (1.0f - easedT_) * HPY1_ + easedT_ * HPY2_;
	bombY_ = (1.0f - easedT_) * bombY1_ + easedT_ * bombY2_;

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

						if (enemyBulletY_[i] >= 580.0f) {
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
					text_ = 15;
					isClear_ = true;
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
				pushEsc_ = true;
			}
		}

		//幕
	    //幕が下がるまでのカウント
		if (pushEsc_ == true) {
			if (iCTime_ <= 30) {
				iCTime_++;
			}
			if (iCTime_ >= 30) {
				inCurtain_ = true;
			}
		}

		if (inCurtain_ == true) {
			if (curtainT_ < 1.0f) {
				curtainT_ += 1.0f / 30.0f;
			}
			if (curtainT_ >= 1.0f) {
				curtainT_ = 1.0f;
			}

			float curtainEasedT_ = sqrt(1.0f - pow(curtainT_ - 1.0f, 2.0f));

			curtainY_ = (1.0f - curtainEasedT_) * curtainY1_ + curtainEasedT_ * curtainY2_;
		}

		//シーン遷移
		if (curtainY_ >= curtainY2_) {
			if (nextTime_ < 30) {
				nextTime_++;
			}
		}
		if (nextTime_ == 30) {
			next_ = true;
		}

		//クリア演出
		if (isClear_ == true) {
			clear_->Update();
		}

		if (clear_->GetterNext() == true) {
			next_ = true;
		}

		//自機移動フラグ
		if (text_ >= 15) {
			onPlayerMove_ = true;
		}

		//自機弾発射フラグ
		if (text_ >= 7) {
			onPlayerShot_ = true;
		}

		if (text_ >= 10) {
			onBomb_ = true;
		}
	}

	//自機
	if (isClear_ != true) {
		player_->Update(keys, preKeys, WASDStile_, directionStile_, onPlayerMove_, onPlayerShot_, onBomb_);

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
						if (enemy_->moveEnemy_.isAlive[0] == true) {
							enemy_->moveEnemy_.HP[0] -= player_->bullet_->bullet_.attack;
							enemy_->moveEnemy_.color[0] = RED;
						}
					}
					else { enemy_->moveEnemy_.color[0] = WHITE; }
					player_->bullet_->bullet_.isShot[i] = false;
				}
			}
		}
	}

	//ボム
	if (player_->GetterShotBomb() == true) {
		for (int i = 0; i < 5; i++) {
			if (isEnemyShot_[i] == true) {
				isEnemyShot_[i] = false;
			}
		}
	}
}

//描画処理
void Tutorial::Draw(int frameRight, int frameLeft, int Plate, bool WASDStile_, bool directionStile_, int tutorialText1, int tutorialText2,
	int tutorialText3Direction, int tutorialText3WASD, int tutorialText4, int tutorialText5, int tutorialText7, int textBox,
	int tutorialText9, int tutorialText10Direction, int tutorialText10WASD, int tutorialText11, int tutorialText12,
	int tutorialText13, int tutorialText14, int scene, int tutorialBg, int bombBullet, int clearPlate, int playerWASD,
	int playerDirection, int playerCore, int playerBullet, int enemyTutorial, int enemyBulletTutorial,int enemyBulletImage,
	int miniBoss) {
	//背景
	Novice::DrawSprite(325, 0, tutorialBg, 1.0f, 1.0f, 0.0f, WHITE);

	//敵
	enemy_->Draw(scene, enemyTutorial, enemyBulletImage, miniBoss);

	//自機
	if (admission_->GetterPlayStart() == true) {
		player_->Draw(bombBullet, WASDStile_, directionStile_, playerWASD, playerDirection, playerCore, playerBullet);
	}

	//弾
	for (int i = 0; i < 5; i++) {
		if (isEnemyShot_[i] == true) {
			//Novice::DrawEllipse(enemyBulletX_[i], enemyBulletY_[i], enemyBulletR_[i], enemyBulletR_[i], 0.0f, RED, kFillModeSolid);
			Novice::DrawSprite(enemyBulletX_[i] - 15, enemyBulletY_[i] - 15, enemyBulletTutorial, 1, 1, 0.0f, WHITE);
		}
	}

	//ステージ入場演出
	admission_->Draw(frameRight, frameLeft, Plate, WASDStile_, directionStile_, playerWASD, playerDirection, playerCore);

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
			Novice::DrawSprite(textX_, textY_, textBox, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 7) {
			Novice::DrawSprite(textX_, textY_, tutorialText7, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 8) {
			Novice::DrawSprite(textX_, textY_, textBox, 1.0f, 1.0f, 0.0f, WHITE);
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

	if (player_->GetterHP() >= 1) {
		Novice::DrawSprite(1209, HPY_, HP_, 1, 1, 0.0f, WHITE);
	}
	if (player_->GetterHP() >= 2) {
		Novice::DrawSprite(1129, HPY_, HP_, 1, 1, 0.0f, WHITE);
	}
	if (player_->GetterHP() >= 3) {
		Novice::DrawSprite(1049, HPY_, HP_, 1, 1, 0.0f, WHITE);
	}

	if (player_->GetterBombs() >= 1) {
		Novice::DrawSprite(1209, bombY_, bomb_, 1, 1, 0.0f, WHITE);
	}
	if (player_->GetterBombs() >= 2) {
		Novice::DrawSprite(1129, bombY_, bomb_, 1, 1, 0.0f, WHITE);
	}
	if (player_->GetterBombs() >= 3) {
		Novice::DrawSprite(1049, bombY_, bomb_, 1, 1, 0.0f, WHITE);
	}

	//幕
	Novice::DrawBox(curtainX_, curtainY_, 1280.0f, 720.0f, 0.0f, BLACK, kFillModeSolid);

	//クリア演出
	clear_->Draw(clearPlate);
}