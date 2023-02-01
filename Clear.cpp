#include "Clear.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
void Clear::Initialize() {
	//プレート
	plateX_ = 1280.0f + 640.0f;
	plateX1_ = 1280.0f + 640.0f;
	plateX2_ = 320.0f;
	plateY_ = 284.0f;
	plateT_ = 0.0f;

	//幕
	iCTime_ = 0;
	inCurtain_ = false;
	curtainX_ = 0.0f;
	curtainY_ = -1280.0f;
	curtainY1_ = -1280.0f;
	curtainY2_ = 0.0f;
	curtainT_ = 0.0f;

	//シーン遷移
	nextTime_ = 0;
	next_ = false;
}

//更新処理
void Clear::Update() {
	//プレート
	if (plateT_ < 1.0f) {
		plateT_ += 1.0f / 30.0f;
	}
	if (plateT_ >= 1.0f) {
		plateT_ = 1.0f;
	}

	float plateEasedT_ = sqrt(1.0f - pow(plateT_ - 1.0f, 2.0f));

	plateX_ = (1.0 - plateEasedT_) * plateX1_ + plateEasedT_ * plateX2_;

	//幕
	//幕が下がるまでのカウント
	if (plateX_ <= plateX2_) {
		if (iCTime_ <= 60) {
			iCTime_++;
		}
		if (iCTime_ >= 60) {
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
}

//描画処理
void Clear::Draw(int clearPlate) {
	//プレート
	Novice::DrawSprite(plateX_, plateY_, clearPlate, 1, 1, 0.0f, WHITE);

	//幕
	Novice::DrawBox(curtainX_, curtainY_, 1280.0f, 720.0f, 0.0f, BLACK, kFillModeSolid);
}