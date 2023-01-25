#include "BombParticle.h"
#include <Novice.h>
#include <math.h>

//初期化
void BombParticle::Initialize() {
	//パーティクル
	particleMax_ = 300;
	for (int i = 0; i < particleMax_; i++) {
		isActive_[i] = false;
		particleX_[i] = -100.0f;
		particleY_[i] = -100.0f;
		particleW_[i] = 50.0f;
		particleH_[i] = 50.0f;
		color_[i] = 0xff450000;
		fade_[i] = 0x000000ff;
		isActive_2[i] = false;
		particleX_2[i] = -100.0f;
		particleY_2[i] = -100.0f;
		particleW_2[i] = 80.0f;
		particleH_2[i] = 80.0f;
		color_2[i] = 0xff000000;
		fade_2[i] = 0x000000ff;
		isActive_3[i] = false;
		particleX_3[i] = -100.0f;
		particleY_3[i] = -100.0f;
		particleW_3[i] = 50.0f;
		particleH_3[i] = 50.0f;
		color_3[i] = 0xffd70000;
		fade_3[i] = 0x000000ff;
	}

	//エミッター
	emitterX_ = 550.0f;
	emitterY_ = 600.0f;
	emitterY1_ = 600.0f;
	emitterY2_ = -900.0f;
	emitterW_ = 120.0f;
	emitterH_ = 120.0f;

	//本体
	collisionX_ = 640.0f;
	collisionY_ = 690.0;
	collisionY1_ = 690.0;
	collisionY2_ = -840.0;
	collisionR_ = 60.0f;

	speed_ = 10.0f;

	t_ = 0.0f;
}

//更新処理
void BombParticle::Update() {
	if (t_ < 1.0f) {
		t_ += 1.0f / 90.0f;
	}
	if (t_ >= 1.0f) {
		t_ = 1.0f;
	}
	float easedT_ = t_ * t_ * t_;

	emitterY_ = (1.0f - easedT_) * emitterY1_ + easedT_ * emitterY2_;
	collisionY_ = (1.0 - easedT_) * collisionY1_ + easedT_ * collisionY2_;

	if (emitterY_ >= -900.0f) {
		for (int i = 0; i < particleMax_; i++) {
			if (isActive_[i] == false) {
				particleX_[i] = emitterX_ + rand() % emitterW_;
				particleY_[i] = emitterY_ + rand() % emitterH_;
				fade_[i] = 0x000000ff;
				isActive_[i] = true;

				break;
			}
			if (isActive_2[i] == false) {
				particleX_2[i] = emitterX_ + rand() % emitterW_;
				particleY_2[i] = emitterY_ + rand() % emitterH_;
				fade_2[i] = 0x000000ff;
				isActive_2[i] = true;

				break;
			}
			if (isActive_3[i] == false) {
				particleX_3[i] = emitterX_ + rand() % emitterW_;
				particleY_3[i] = emitterY_ + rand() % emitterH_;
				fade_3[i] = 0x000000ff;
				isActive_3[i] = true;

				break;
			}
		}
	}

	for (int i = 0; i < particleMax_; i++) {
		if (isActive_[i] == true) {
			if (fade_[i] >= 0x0000000f) {
				fade_[i] -= 0x00000010;
			}
			if (fade_[i] <= 0x0000000f) {
				fade_[i] = 0x00000000;
			}
			if (fade_[i] <= 0x00000000) {
				fade_[i] = 0x00000000;
				isActive_[i] = false;
			}
		}
		if (isActive_2[i] == true) {
			if (fade_2[i] >= 0x0000000f) {
				fade_2[i] -= 0x00000010;
			}
			if (fade_2[i] <= 0x0000000f) {
				fade_2[i] = 0x00000000;
			}
			if (fade_2[i] <= 0x00000000) {
				fade_2[i] = 0x00000000;
				isActive_2[i] = false;
			}
		}
		if (isActive_3[i] == true) {
			if (fade_3[i] >= 0x0000000f) {
				fade_3[i] -= 0x00000010;
			}
			if (fade_3[i] <= 0x0000000f) {
				fade_3[i] = 0x00000000;
			}
			if (fade_3[i] <= 0x00000000) {
				fade_3[i] = 0x00000000;
				isActive_3[i] = false;
			}
		}
	}
}

//描画処理
void BombParticle::Draw(int bombBullet) {
	//Novice::DrawBox(emitterX_, emitterY_, emitterW_, emitterH_, 0.0f, BLACK, kFillModeWireFrame);
	Novice::DrawSprite(collisionX_ - 60.0f, collisionY_ - 60.0f, bombBullet, 1, 1, 0.0f, WHITE);

	for (int i = 0; i < particleMax_; i++) {
		if (isActive_2[i] == true) {
			Novice::DrawBox(particleX_2[i], particleY_2[i], particleW_2[i], particleH_2[i], 0.0f, color_2[i] + fade_2[i], kFillModeSolid);
		}
		if (isActive_[i] == true) {
			Novice::DrawBox(particleX_[i], particleY_[i], particleW_[i], particleH_[i], 0.0f, color_[i] + fade_[i], kFillModeSolid);
		}
		//Novice::SetBlendMode(BlendMode::kBlendModeAdd);
		if (isActive_3[i] == true) {
			Novice::DrawBox(particleX_3[i], particleY_3[i], particleW_3[i], particleH_3[i], 0.0f, color_3[i] + fade_3[i], kFillModeSolid);
		}
	}

	//Novice::DrawEllipse(collisionX_, collisionY_, collisionR_, collisionR_, 0.0f, BLACK, kFillModeWireFrame);
	//Novice::SetBlendMode(BlendMode::kBlendModeAdd);
	//Novice::SetBlendMode(BlendMode::kBlendModeNone);

	Novice::ScreenPrintf(0, 500, "%d", emitterY_);
}