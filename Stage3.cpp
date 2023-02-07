#include "Stage3.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
void Stage3::Initialize() {
	admission_ = new Admission();
	admission_->Initialize();

	player_ = new Player();
	player_->Initialize();

	boss_ = new Boss();
	boss_->Initialeze();

	clear_ = new Clear();
	clear_->Initialize();

	//ボム
	player_->SetterBombs(3);

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
void Stage3::Update(char* keys, char* prekeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_,
	bool onBomb_, int scene, int text_) {
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
		boss_->Update();

		if (boss_->start_ == true) {
			player_->Update(keys, prekeys, WASDStile_, directionStile_, onPlayerMove_, onPlayerShot_, onBomb_);
		}		
	}

	//当たり判定
	//自機の弾とボスの当たり判定
	if (boss_->boss_.isAlive == true) {
		for (int i = 0; i < 15; i++) {
			float playerBullet_bossX_ = (player_->bullet_->bullet_.pos[i].X - boss_->boss_.pos.X) * (player_->bullet_->bullet_.pos[i].X - boss_->boss_.pos.X);
			float playerBullet_bossY_ = (player_->bullet_->bullet_.pos[i].Y - boss_->boss_.pos.Y) * (player_->bullet_->bullet_.pos[i].Y - boss_->boss_.pos.Y);
			float playerBullet_bossR_ = (player_->bullet_->bullet_.radius[i] + boss_->boss_.radius) * (player_->bullet_->bullet_.radius[i] + boss_->boss_.radius);

			if (playerBullet_bossX_ + playerBullet_bossY_ < playerBullet_bossR_) {
				if (player_->bullet_->bullet_.isShot[i] == true) {
					boss_->boss_.HP -= player_->bullet_->bullet_.attack;
					player_->bullet_->bullet_.isShot[i] = false;
				}
			}
		}
	}
}

//描画処理
void Stage3::Draw(int frameRight, int frameLeft, int plate, int WASDStile_, int directionStule_, int playerWASD, int playerDirection,
	int playerCore, int bombBullet, bool directionStile_, int playerBullet, int scene, int enemytutorial, int enemyBulletImage,
	int clearPlate, int miniBoss, int bossImage, int bossCore) {
	if (admission_->GetterPlayStart() == true) {
		//ボス
		Novice::DrawSprite(boss_->boss_.pos.X - 33, boss_->boss_.pos.Y - 70, bossImage, 1, 1, 0.0f, boss_->boss_.collor + boss_->boss_.alpha);

		//自機
		player_->Draw(bombBullet, WASDStile_, directionStile_, playerWASD, playerDirection, playerCore, playerBullet);

		//ボス
		boss_->Draw(bossImage, bossCore);
	}

	admission_->Draw(frameRight, frameLeft, plate, WASDStile_, directionStule_, playerWASD, playerDirection, playerCore);

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

	//ボスHPバー
	Novice::DrawBox(20, 20, 200, 30, 0.0f, RED, kFillModeSolid);
	Novice::DrawBox(20, 20, 200 * boss_->boss_.HP / boss_->boss_.maxHP, 30, 0.0f, GREEN, kFillModeSolid);

	Novice::ScreenPrintf(0, 220, "%d", boss_->boss_.HP);
}