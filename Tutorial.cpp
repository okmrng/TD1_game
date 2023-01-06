#include "Tutorial.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//������
void Tutorial::Initialize() {
	//�X�e�[�W���ꉉ�o
	admission_ = new Admission();
	admission_->Initialize();

	//�e�L�X�g�t���O
	text_ = 1;
	textDisplay_ = false;

	//�e�L�X�g�ʒu
	textX_ = 350.0f;
	textY_ = 100.0f;

	//���̓J�E���g
	pushCount_ = 0;

	//�V�[���J��
	next_ = false;
}

//�X�V����
void Tutorial::Update(char* keys, char* preKeys) {
	//�X�e�[�W���ꉉ�o
	admission_->Update();

	if (admission_->GetterPlayStart() == true) {
		textDisplay_ = true;
	}

	if (textDisplay_ == true) {
		//�e�L�X�g�i�߂�
		if (text_ == 1) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 2;
					pushCount_ = 0;
				}
			}
		}
		if (text_ == 2) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 3;
					pushCount_ = 0;
				}
			}
		}
		if (text_ == 3) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 4;
					pushCount_ = 0;
				}
			}
		}
		if (text_ == 4) {
			if (pushCount_ <= 5) {
				pushCount_++;
			}
			if (pushCount_ >= 5) {
				if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
					text_ = 5;
					pushCount_ = 0;
				}
			}
		}

		//�V�[���J��
		if (text_ >= 1) {
			//���̃V�[����
			if (keys[DIK_ESCAPE] && preKeys[DIK_ESCAPE] == 0) {
				next_ = true;
				pushCount_ = 0;
			}
		}
	}
}

//�`�揈��
void Tutorial::Draw(int frameSide, int Plate, bool WASDStile_, bool directionStile_, int tutorialText1, int tutorialText2,
	int tutorialText3Direction, int tutorialText3WASD, int tutorialText4) {
	//�X�e�[�W���ꉉ�o
	admission_->Draw(frameSide, Plate);

	//�e�L�X�g
	if (textDisplay_ == true) {
		if (text_ == 1) {
			Novice::DrawSprite(textX_, textY_, tutorialText1, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (text_ == 2) {
			Novice::DrawSprite(textX_, textY_, tutorialText2, 1.0f, 1.0f, 0.0f, WHITE);
		}
		if (directionStile_ == true) {
			if (text_ == 3) {
				Novice::DrawSprite(textX_, textY_, tutorialText3Direction, 1.0f, 1.0f, 0.0f, WHITE);
			}
		}
		if (WASDStile_ == true) {
			if (text_ == 3) {
				Novice::DrawSprite(textX_, textY_, tutorialText3WASD, 1.0f, 1.0f, 0.0f, WHITE);
			}
		}
		if (text_ == 4) {
			Novice::DrawSprite(textX_, textY_, tutorialText4, 1.0f, 1.0f, 0.0f, WHITE);
		}
	}
}