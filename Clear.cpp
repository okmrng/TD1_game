#include "Clear.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//������
void Clear::Initialize() {
	//�v���[�g
	plateX_ = 1280.0f + 640.0f;
	plateX1_ = 1280.0f + 640.0f;
	plateX2_ = 320.0f;
	plateY_ = 284.0f;
	plateT_ = 0.0f;

	//��
	iCTime_ = 0;
	inCurtain_ = false;
	curtainX_ = 0.0f;
	curtainY_ = -1280.0f;
	curtainY1_ = -1280.0f;
	curtainY2_ = 0.0f;
	curtainT_ = 0.0f;
}

//�X�V����
void Clear::Update() {
	//�v���[�g
	if (plateT_ < 1.0f) {
		plateT_ += 1.0f / 30.0f;
	}
	if (plateT_ >= 1.0f) {
		plateT_ = 1.0f;
	}

	float plateEasedT_ = sqrt(1.0f - pow(plateT_ - 1.0f, 2.0f));

	plateX_ = (1.0 - plateEasedT_) * plateX1_ + plateEasedT_ * plateX2_;
}

//�`�揈��
void Clear::Draw(int clearPlate) {
	Novice::DrawSprite(plateX_, plateY_, clearPlate, 1, 1, 0.0f, WHITE);
}