#include "Admission.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//������
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
	plateX4_ = 332.0f;
	plateX5_ = 332.0f;
	plateX6_ = 1280.0f;
	plateSpeedX_ = 0.2f;
	t1_ = 0.0f;
	t2_ = 0.0f;
	t3_ = 0.0f;
	onEase_ = true;
	onPlateEase1_ = false;
	onPlateEase2_ = false;
	onSlowly_ = false;
	playerY_ = 740.0f;
	playerY1_ = 740.0f;
	playerY2_ = 660.0f;
	plateEaseStartCount_ = 0;
	playStartCount_ = 0;
	playStart_ = false;
	playStartCountStart_ = false;
}

//�X�V����
void Admission::Update() {
	//�t���[���Ǝ��@�̃C�[�W���O
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

	//�v���[�g�̃C�[�W���O
	//�o��܂ł̃J�E���g
	if (onEase_ == false) {
		if (plateEaseStartCount_ <= 30) {
			plateEaseStartCount_++;
		}
		if (plateEaseStartCount_ >= 30) {
			onPlateEase1_ = true;
		}
	}

	//�o��C�[�W���O
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

	//�������ړ�
	if (onSlowly_ == true) {
		plateX3_ += plateSpeedX_;

		if (plateX3_ >= 332.0f) {
			onSlowly_ = false;
			onPlateEase2_ = true;
		}
	}

	//�ޏ�C�[�W���O
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
			playStartCountStart_ = true;
		}
	}

	//�v���C�J�n
	if (playStartCountStart_ == true) {
		if (playStartCount_ <= 30) {
			playStartCount_++;
		}
		if (playStartCount_ >= 30) {
			playStart_ = true;
		}
	}
}

//�`�揈��
void Admission::Draw(int frameSide, int Plate) {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);

	//���@
	Novice::DrawEllipse(640, playerY_, 20, 20, 0.0f, BLUE, kFillModeSolid);

	//�E�t���[��
	Novice::DrawSprite(frameRightX_, frameRightY_, frameSide, 1.0f, 1.0f, 0.0f, WHITE);

	//���t���[��
	Novice::DrawSprite(frameLeftX_, frameLeftY_, frameSide, 1.0f, 1.0f, 0.0f, WHITE);

	//�v���[�g
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