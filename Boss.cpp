#include "Boss.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//������
void Boss::Initialeze() {
	boss_.pos.X = 640.0f;
	boss_.pos.Y = 100.0f;
	boss_.radius = 12.0f;
	boss_.maxHP = 200;
	boss_.HP = 200;
	boss_.pattern = 0;
	boss_.collor = 0xffffff00;
	boss_.alpha = 0x00000000;
	boss_.theta = 0.0f;
	boss_.amplitude = 50.0f;

	//�퓬�J�n�܂ł̃J�E���g
	onStartCount_ = false;
	startCount_ = 0;
	start_ = false;
}

//�X�V����
void Boss::Update() {
	//�t�F�[�h�C��
	if (boss_.alpha <= 0x000000ff) {
		boss_.alpha++;
	}
	if (boss_.alpha >= 0x000000ff) {
		boss_.alpha = 0x000000ff;
		onStartCount_ = true;
	}

	//�퓬�J�n�܂ł̃J�E���g
	if (onStartCount_ == true) {
		startCount_++;
	}
	if (startCount_ >= 30) {
		start_ = true;
	}

	//�퓬�J�n
	if (start_ == true) {

	}
}

//�`�揈��
void Boss::Draw(int bossImage, int bossCore) {
	//�{��
	Novice::DrawSprite(boss_.pos.X - 33, boss_.pos.Y - 70, bossImage, 1, 1, 0.0f, boss_.collor + boss_.alpha);

	//�����蔻��
	//Novice::DrawEllipse(boss1_.pos.X, boss1_.pos.Y, boss1_.radius, boss1_.radius, 0.0f, WHITE,kFillModeSolid);
	Novice::DrawSprite(boss_.pos.X - 13, boss_.pos.Y - 13, bossCore, 1, 1, 0.0f, WHITE);
}