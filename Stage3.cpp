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
}

//更新処理
void Stage3::Update(char* keys, char* prekeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_,
	bool onBomb_, int scene, int text_) {
	//ステージ入場演出
	admission_->Update();

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

	//ボスHPバー
	Novice::DrawBox(20, 20, 200, 30, 0.0f, RED, kFillModeSolid);
	Novice::DrawBox(20, 20, 200 * boss_->boss_.HP / boss_->boss_.maxHP, 30, 0.0f, GREEN, kFillModeSolid);

	Novice::ScreenPrintf(0, 220, "%d", boss_->boss_.HP);
}