#include "Admission.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
void Admission::Initialize() {
	frameRightX_ = 955.0f;
	frameRightY_ = -720.0f;
	frameRightY1_ = -720.0f;
	frameRightY2_ = 0.0f;
	frameLeftX_ = 0.0f;
	frameLeftY_ = -720.0f;
	frameLeftY1_ = -720.0f;
	frameLeftY2_ = 0.0f;
	plateX_ = -1280.0f;
	plateY_ = 284.0f;
	plateX1_ = -1280.0f;
	plateX2_ = 320.0f;
	plateX3_ = 320.0f;
	plateX4_ = 350.0f;
	plateX5_ = 350.0f;
	plateX6_ = 1280.0f;
	plateSpeedX_ = 0.5f;
	t1_ = 0.0f;
	t2_ = 0.0f;
	t3_ = 0.0f;
	onEase_ = true;
	onPlateEase1_ = false;
	onPlateEase2_ = false;
	onSlowly_ = false;
	playerY_ = 740.0f;
	playerY1_ = 740.0f;
	playerY2_ = 668.0f;
	plateEaseStartCount_ = 0;
	playStartCount_ = 0;
	playStart_ = false;
	playStartCountStart_ = false;
	color_ = 0x00000000;
	fade_ = 0x000000FF;
	onFade_ = false;
}

//更新処理
void Admission::Update() {
	//フレームと自機のイージング
	if (onEase_ == true) {
		if (t1_ < 1.0f) {
			t1_ += 1.0f / 30.0f;
		}
		if (t1_ >= 1.0f) {
			t1_ = 1.0f;
		}
		float easedT_ = sqrt(1.0f - pow(t1_ - 1.0f, 2.0f));

		frameRightY_ = (1.0f - easedT_) * frameLeftY1_ + easedT_ * frameLeftY2_;
		frameLeftY_ = (1.0f - easedT_) * frameLeftY1_ + easedT_ * frameLeftY2_;
		playerY_ = (1.0f - easedT_) * playerY1_ + easedT_ * playerY2_;

		if (frameLeftY_ >= 0.0f) {
			onEase_ = false;
		}
	}

	//プレートのイージング
	//登場までのカウント
	if (onEase_ == false) {
		if (plateEaseStartCount_ <= 30) {
			plateEaseStartCount_++;
		}
		if (plateEaseStartCount_ >= 30) {
			onPlateEase1_ = true;
		}
	}

	//登場イージング
	if (onPlateEase1_ == true) {
		if (t2_ < 1.0f) {
			t2_ += 1.0f / 30.0f;
		}
		if (t2_ >= 1.0f) {
			t2_ = 1.0f;
		}
		float easedT_ = sqrt(1.0f - pow(t2_ - 1.0f, 2.0f));

		plateX_ = (1.0f - easedT_) * plateX1_ + easedT_ * plateX2_;

		if (plateX_ >= 320.0f) {
			onSlowly_ = true;
			onPlateEase1_ = false;
		}
	}

	//ゆっくり移動
	if (onSlowly_ == true) {
		plateX3_ += plateSpeedX_;

		if (plateX3_ >= 350.0f) {
			onSlowly_ = false;
			onPlateEase2_ = true;
		}
	}

	//退場イージング
	if (onPlateEase2_ == true) {
		if (t3_ < 1.0f) {
			t3_ += 1.0f / 30.0f;
		}
		if (t3_ >= 1.0f) {
			t3_ = 1.0f;
		}
		float easedT_ = t3_ * t3_ * t3_;

		plateX4_ = (1.0f - easedT_) * plateX5_ + easedT_ * plateX6_;

		if (plateX4_ >= 1280.0f) {
			onPlateEase2_ = false;
			onFade_ = true;
			//playStartCountStart_ = true;
		}
	}

	//フェードアウト
	if (onFade_ == true) {
		/*if (fade_ >= 0x00000000) {
			fade_ -= 0x00000004;
		}
		if (fade_ <= 0x00000000) {
			fade_ = 0x00000000;
			playStartCountStart_ = true;
			onFade_ = false;
		}*/
		if (fade_ >= 0x00000003) {
			fade_ -= 0x00000006;
		}
		if (fade_ <= 0x00000003) {
			fade_ -= 0x00000001;
		}
		if (fade_ <= 0x00000000) {
			fade_ = 0x00000000;
			playStartCountStart_ = true;
			onFade_ = false;
		}
	}

	//プレイ開始
	if (playStartCountStart_ == true) {
		if (playStartCount_ <= 30) {
			playStartCount_++;
		}
		if (playStartCount_ >= 30) {
			playStart_ = true;
		}
	}
}

//描画処理
void Admission::Draw(int frameRight, int frameLeft, int Plate, bool WASDStile_, bool directionStile_, int playerWASD, int playerDirection, int playerCore) {
	//背景
	if (playStartCountStart_ == false) {
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, color_ + fade_, kFillModeSolid);
	}

	//自機
	if (playStart_ == false) {
		if (WASDStile_ == true) {
			Novice::DrawSprite(607, playerY_ - 65, playerWASD, 1, 1, 0.0f, WHITE);
		}
		if (directionStile_ == true) {
			Novice::DrawSprite(607, playerY_ - 65, playerDirection, 1, 1, 0.0f, WHITE);
		}
		//Novice::DrawEllipse(648, playerY_, 12, 12, 0.0f, BLUE, kFillModeSolid);
		Novice::DrawSprite(627, playerY_ - 13, playerCore, 1, 1, 0.0f, WHITE);
	}

	//右フレーム
	Novice::DrawSprite(frameRightX_, frameRightY_, frameRight, 1.0f, 1.0f, 0.0f, WHITE);

	//左フレーム
	Novice::DrawSprite(frameLeftX_, frameLeftY_, frameLeft, 1.0f, 1.0f, 0.0f, WHITE);

	//プレート
	if (onPlateEase1_ == true) {
		Novice::DrawSprite(plateX_, plateY_, Plate, 1.0f, 1.0f, 0.0f, WHITE);
	}
	if (onSlowly_ == true) {
		Novice::DrawSprite(plateX3_, plateY_, Plate, 1.0f, 1.0f, 0.0f, WHITE);
	}
	if (onPlateEase2_ == true) {
		Novice::DrawSprite(plateX4_, plateY_, Plate, 1.0f, 1.0f, 0.0f, WHITE);
	}
}