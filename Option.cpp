#include "Option.h"
#include <Novice.h>

//初期化
void Option::Initialize() {
	WASDStile_ = false;
	directionStile_ = false;
	choiceCount_ = 5;
	choice_ = false;
	white_ = 0xFFFFFF00;
	whiteBg_ = 0xFFFFFF00;
	fade_ = 0x00000000;
	fade2_ = 0x00000000;
	OnReturn_ = false;
	OffReturn_ = false;
	OnOperation_ = false;
	OnDisplay_ = true;
	next_ = false;
}

//更新処理
void Option::Update(char* keys, char* preKeys) {
	//フェードイン
	if (fade_ <= 0x000000FF) {
		fade_ += 0x00000004;
	}

	if (fade_ >= 0x000000FF) {
		fade_ = 0x000000FF;
		OnOperation_ = true;
	}

	if (OnOperation_ == true) {
		//操作選択
		if (choiceCount_ <= 5) {
			choiceCount_++;
		}
		if (choiceCount_ >= 5) {
			choice_ = true;
		}
		if (choice_ == true) {
			//WASD操作
			if (WASDStile_ == false) {
				if ((keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0) || (keys[DIK_A] && preKeys[DIK_A] == 0)) {
					choiceCount_ = 0;
					WASDStile_ = true;
					directionStile_ = false;
				}
			}

			//方向キー操作
			if (directionStile_ == false) {
				if ((keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0) || (keys[DIK_D] && preKeys[DIK_D] == 0)) {
					choiceCount_ = 0;
					directionStile_ = true;
					WASDStile_ = false;
				}
			}
		}

		//決定
		if (WASDStile_ == true || directionStile_ == true) {
			if (keys[DIK_RETURN]) {
				OnReturn_ = true;
			}

			//フェードイン
			if (OnReturn_ == true) {
				if (fade2_ <= 0x000000FF) {
					fade2_ += 0x00000040;
				}

				if (fade2_ >= 0x000000FF) {
					OffReturn_ = true;
					OnReturn_ = false;
					OnDisplay_ = false;
				}
			}

			//フェードアウト
			if (OffReturn_ == true) {
				if (fade2_ >= 0x00000000) {
					fade2_ -= 0x00000040;
				}
				if (fade2_ <= 0x00000000) {
					fade2_ = 0x00000000;
					OffReturn_ = false;
					next_ = true;
				}
			}
		}
	}
}

//描画処理
void Option::Draw(int wasd, int wasdYellow, int direction, int directionYellow) {
	//背景
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);

	//選択肢
	if (OnDisplay_ == true) {
		if (WASDStile_ == false) {
			Novice::DrawSprite(100, 100, wasd, 1.0f, 1.0f, 0.0f, white_ + fade_);
		}
		if (WASDStile_ == true) {
			Novice::DrawSprite(100, 100, wasdYellow, 1.0f, 1.0f, 0.0f, WHITE);
		}

		if (directionStile_ == false) {
			Novice::DrawSprite(690, 100, direction, 1.0f, 1.0f, 0.0f, white_ + fade_);
		}
		if (directionStile_ == true) {
			Novice::DrawSprite(690, 100, directionYellow, 1.0f, 1.0f, 0.0f, WHITE);
		}
	}

	//白背景
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, whiteBg_ + fade2_, kFillModeSolid);
}