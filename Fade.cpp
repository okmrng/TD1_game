#include "Fade.h"
#include <Novice.h>

//初期化
void Fade::Initialize() {
	color_ = 0x00000000;
	fade_ = 0x00000000;
	onFade_ = false;
	nextCount_ = 0;
	next_ = false;
}

//更新処理
void Fade::Update() {
	//フェードイン
	if (onFade_ == true) {
		if (fade_ <= 0x000000FF) {
			fade_ += 0x00000004;
		}

		if (fade_ >= 0x000000FF) {
			fade_ = 0x000000FF;

			//シーン遷移
			if (nextCount_ <= 60) {
				nextCount_++;
			}
			if (nextCount_ >= 60) {
				next_ = true;
			}
		}
	}

	//リセット
	if (next_ == true) {
		fade_ = 0x00000000;
		onFade_ = false;
	}
}

//セッター関数
void Fade::SetOnFade(bool onFade) {
	onFade_ = onFade;
}

//描画処理
void Fade::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, color_ + fade_, kFillModeSolid);
	Novice::ScreenPrintf(0, 160, "%d", nextCount_);
}