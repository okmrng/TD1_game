#include "Gameover.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//èâä˙âª
void Gameover::Initialize() {
	gameover_ = Novice::LoadTexture("./Resources/Images/gameover.png");

	onEase_ = false;

	posX_ = 0.0f;
	posY_ = -1280.0f;
	posY1_ = -1280.0f;
	posY2_ = 0.0f;
	t_ = 0.0f;
	easedT_ = 0.0f;
}

//çXêVèàóù
void Gameover::Update(char* keys, char* preKeys) {
	if ((keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) || (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)) {
		onEase_ = true;
	}

	if (onEase_ == true) {
		if (t_ < 1.0f) {
			t_ += 1.0f / 30.0f;
		}
		if (t_ >= 1.0f) {
			t_ = 1.0f;
		}

		easedT_ = sqrt(1.0f - pow(t_ - 1.0f, 2.0f));

		posY_ = (1.0f - easedT_) * posY1_ + easedT_ * posY2_;
	}	
}

//ï`âÊèàóù
void Gameover::Draw() {
	Novice::DrawSprite(0, 0, gameover_, 1, 1, 0.0f, WHITE);

	Novice::DrawBox(posX_, posY_, 1280, 720, 0.0f, BLACK, kFillModeSolid);
}