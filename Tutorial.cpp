#include "Tutorial.h"
#include "Player.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
void Tutorial::Initialize() {
	frameRightX_ = 955.0f;
	frameRightY_ = -720.0f;
	frameRightY1_ = -720.0f;
	frameRightY2_ = 0.0f;
	frameLeftX_ = 0.0f;
	frameLeftY_ = -720.0f;
	frameLeftY1_ = -720.0f;
	frameLeftY2_ = 0.0f;
	t_ = 0.0f;
	onEase_ = true;
	playerY_ = 740.0f;
	playerY1_ = 740.0f;
	playerY2_ = 660.0f;

	//自機
	player_ = new Player();
	player_->Initialize();
}

//更新処理
void Tutorial::Update() {
	if (onEase_ == true) {
		if (t_ < 1.0f) {
			t_ += 1.0f / 30.0f;
		}
		if (t_ >= 1.0f) {
			t_ = 1.0f;
		}
		float easedT_ = sqrt(1.0f - pow(t_ - 1.0f, 2.0f));

		frameRightY_ = (1.0f - easedT_) * frameLeftY1_ + easedT_ * frameLeftY2_;
		frameLeftY_ = (1.0f - easedT_) * frameLeftY1_ + easedT_ * frameLeftY2_;
		playerY_ = (1.0f - easedT_) * playerY1_ + easedT_ * playerY2_;

		if (frameLeftY_ >= 0.0f) {
			onEase_ = false;
		}
	}
}

//描画処理
void Tutorial::Draw(int frameSide, int tutorialPlate) {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);

	//自機
	if (onEase_ == true) {
		Novice::DrawEllipse(640, playerY_, 20, 20, 0.0f, BLUE, kFillModeSolid);
	}
	if (onEase_ == false) {
		player_->Draw();
	}

	//右フレーム
	Novice::DrawSprite(frameRightX_, frameRightY_, frameSide, 1.0f, 1.0f, 0.0f, WHITE);

	//左フレーム
	Novice::DrawSprite(frameLeftX_, frameLeftY_, frameSide, 1.0f, 1.0f, 0.0f, WHITE);
}