#include "Option.h"
#include <Novice.h>

//ú»
void Option::Initialize() {
	WASDStile_ = false;
	directionStile_ = false;
	choiceCount_ = 5;
	choice_ = false;
}

//XV
void Option::Update(char* keys, char* preKeys) {

	//ìIð
	if (choiceCount_ <= 5) {
		choiceCount_++;
	}
	if (choiceCount_ >= 5) {
		choice_ = true;
	}
	if (choice_ == true) {
		//WASDì
		if (WASDStile_ == false) {
			if ((keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) || (keys[DIK_A] && preKeys[DIK_A] == 0)) {
				choiceCount_ = 0;
				WASDStile_ = true;
				directionStile_ = false;
			}
		}

		//ûüL[ì
		if (directionStile_ == false) {
			if ((keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) || (keys[DIK_D] && preKeys[DIK_D] == 0)) {
				choiceCount_ = 0;
				directionStile_ = true;
				WASDStile_ = false;
			}
		}
	}
}

//`æ
void Option::Draw(int wasd, int wasdYellow, int direction, int directionYellow) {
	//wi
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);

	//Ið
	if (WASDStile_ == false) {
		Novice::DrawSprite(100, 100, wasd, 1.0f, 1.0f, 0.0f, WHITE);
	}
	if (WASDStile_ == true) {
		Novice::DrawSprite(100, 100, wasdYellow, 1.0f, 1.0f, 0.0f, WHITE);
	}

	if (directionStile_ == false) {
		Novice::DrawSprite(690, 100, direction, 1.0f, 1.0f, 0.0f, WHITE);
	}
	if (directionStile_ == true) {
		Novice::DrawSprite(690, 100, directionYellow, 1.0f, 1.0f, 0.0f, WHITE);
	}
}