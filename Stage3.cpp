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
	bg_ = Novice::LoadTexture("./Resources/Images/bossBg.png");
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
	for (int i = 0; i < 15; i++) {
		float playerBullet_bossX_ = (player_->bullet_->bullet_.pos[i].X - boss_->boss_.pos.X) * (player_->bullet_->bullet_.pos[i].X - boss_->boss_.pos.X);
		float playerBullet_bossY_ = (player_->bullet_->bullet_.pos[i].Y - boss_->boss_.pos.Y) * (player_->bullet_->bullet_.pos[i].Y - boss_->boss_.pos.Y);
		float playerBullet_bossR_ = (player_->bullet_->bullet_.radius[i] + boss_->boss_.radius) * (player_->bullet_->bullet_.radius[i] + boss_->boss_.radius);

		if (playerBullet_bossX_ + playerBullet_bossY_ < playerBullet_bossR_) {
			if (player_->bullet_->bullet_.isShot[i] == true) {
				boss_->boss_.HP -= 5;
				player_->bullet_->bullet_.isShot[i] = false;
			}
		}
	}

	//ボムとボスの当たり判定
	float playerBomb_bossX_ = (player_->bombParticle_->collisionX_ - boss_->boss_.pos.X) * (player_->bombParticle_->collisionX_ - boss_->boss_.pos.X);
	float playerBomb_bossY_ = (player_->bombParticle_->collisionY_ - boss_->boss_.pos.Y) * (player_->bombParticle_->collisionY_ - boss_->boss_.pos.Y);
	float playerBomb_bossR_ = (player_->bombParticle_->collisionR_ + boss_->boss_.radius) * (player_->bombParticle_->collisionR_ + boss_->boss_.radius);

	if (playerBomb_bossX_ + playerBomb_bossY_ < playerBomb_bossR_) {
		if (player_->GetterShotBomb() == true) {
			boss_->boss_.HP -= 10;
		}
	}

	//自機とボスの当たり判定
	float player_bossX_ = player_->GetterPosX() - boss_->boss_.pos.X;
	float player_bossY_ = player_->GetterPosY() - boss_->boss_.pos.Y;
	float player_bossDis_ = sqrtf(player_bossX_ * player_bossX_ + player_bossY_ * player_bossY_);

	if (player_bossDis_ < player_->GetterRadius() + boss_->boss_.radius) {
		player_->OnCollision();
	}

	//自機とボスの弾の当たり判定
	for (int i = 0; i < 9; i++) {
		float player_bossBullet0X_ = player_->GetterPosX() - boss_->bossBullet_->pattern0_.pos[i].X;
		float player_bossBullet0Y_ = player_->GetterPosY() - boss_->bossBullet_->pattern0_.pos[i].Y;
		float player_bossBullet0Dis_ = sqrtf(player_bossBullet0X_ * player_bossBullet0X_ + player_bossBullet0Y_ * player_bossBullet0Y_);

		if (player_bossBullet0Dis_ < (player_->GetterRadius() + boss_->bossBullet_->pattern0_.radius[i])) {
			if (boss_->bossBullet_->pattern0_.isShot[i] == true) {
				player_->OnCollision();
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		float player_bossBullet1X_ = player_->GetterPosX() - boss_->bossBullet_->pattern1_.pos[i].X;
		float player_bossBullet1Y_ = player_->GetterPosY() - boss_->bossBullet_->pattern1_.pos[i].Y;
		float player_bossBullet1Dis_ = sqrtf(player_bossBullet1X_ * player_bossBullet1X_ + player_bossBullet1Y_ * player_bossBullet1Y_);

		if (player_bossBullet1Dis_ < (player_->GetterRadius() + boss_->bossBullet_->pattern0_.radius[i])) {
			if (boss_->bossBullet_->pattern1_.isShot[i] == true) {
				player_->OnCollision();
			}
		}
	}
	for (int i = 0; i < 13; i++) {
		float player_bossBullet2X_ = player_->GetterPosX() - boss_->bossBullet_->pattern2_.pos[i].X;
		float player_bossBullet2Y_ = player_->GetterPosY() - boss_->bossBullet_->pattern2_.pos[i].Y;
		float player_bossBullet2Dis_ = sqrtf(player_bossBullet2X_ * player_bossBullet2X_ + player_bossBullet2Y_ * player_bossBullet2Y_);

		if (player_bossBullet2Dis_ < (player_->GetterRadius() + boss_->bossBullet_->pattern0_.radius[i])) {
			if (boss_->bossBullet_->pattern2_.isShot[i] == true) {
				player_->OnCollision();
			}
		}
	}
}

//描画処理
void Stage3::Draw(int frameRight, int frameLeft, int plate, int WASDStile_, int directionStule_, int playerWASD, int playerDirection,
	int playerCore, int bombBullet, bool directionStile_, int playerBullet, int scene, int enemytutorial, int enemyBulletImage,
	int clearPlate, int miniBoss, int bossImage, int bossCore) {
	Novice::DrawSprite(0, 0, bg_, 1, 1, 0.0f, WHITE);

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
	if (boss_->boss_.HP > 0) {
		Novice::DrawBox(20, 20, 200 * boss_->boss_.HP / boss_->boss_.maxHP, 30, 0.0f, GREEN, kFillModeSolid);
	}	

	Novice::ScreenPrintf(0, 220, "%d", boss_->boss_.HP);
}