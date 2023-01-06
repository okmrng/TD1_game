#include "Tutorial.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
void Tutorial::Initialize() {
	//ステージ入場演出
	admission_ = new Admission();
	admission_->Initialize();

	//テキストフラグ
	text_ = 1;
	textDisplay_ = false;

	//テキスト位置
	textX_ = 350.0f;
	textY_ = 100.0f;

	//入力カウント
	pushCount_ = 0;

	//シーン遷移
	next_ = false;
}

//更新処理
void Tutorial::Update(char* keys, char* preKeys) {
	//ステージ入場演出
	admission_->Update();

	if (admission_->GetterPlayStart() == true) {
		textDisplay_ = true;
	}

	if (textDisplay_ == true) {
		//テキスト進める
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

		//シーン遷移
		if (text_ >= 1) {
			//次のシーンへ
			if (keys[DIK_ESCAPE] && preKeys[DIK_ESCAPE] == 0) {
				next_ = true;
				pushCount_ = 0;
			}
		}
	}
}

//描画処理
void Tutorial::Draw(int frameSide, int Plate, bool WASDStile_, bool directionStile_, int tutorialText1, int tutorialText2,
	int tutorialText3Direction, int tutorialText3WASD, int tutorialText4) {
	//ステージ入場演出
	admission_->Draw(frameSide, Plate);

	//テキスト
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