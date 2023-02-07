#include "StageSelect.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
void StageSelect::Initialize() {
	mapFrameX = Novice::LoadTexture("./Resources/Images/map_frameX.png");
	mapFrameY = Novice::LoadTexture("./Resources/Images/map_frameY.png");

	stage1 = Novice::LoadTexture("./Resources/Images/plate_stage1_select.png");
	stage2 = Novice::LoadTexture("./Resources/Images/plate_stage2_select.png");
	stage3 = Novice::LoadTexture("./Resources/Images/plate_stage3_select.png");

	stageSelect = Novice::LoadTexture("./Resources/Images/stageselect.png");

	//フレーム
	frameX_.pos.X = -1280.0f;
	frameX_.pos1.X = -1280.0f;
	frameX_.pos2.X = 0.0f;
	frameX_.pos.Y = 0.0f;
	frameX_.t = 0.0f;
	frameX_.easedT = 0.0f;

	frameY_.pos.X = 0.0f;
	frameY_.pos.Y = -720.0f;
	frameY_.pos1.Y = -720.0f;
	frameY_.pos2.Y = 0.0f;
	frameY_.t = 0.0f;
	frameY_.easedT = 0.0f;

	//プレート
	stage1_.pos.X = 1280.0f;
	stage1_.pos1.X = 1280.0f;
	stage1_.pos2.X = 320.0f;
	stage1_.pos.Y = 200.0f;
	stage1_.t = 0.0f;
	stage1_.easedT = 0.0f;

	stage2_.pos.X = 1280.0f;
	stage2_.pos1.X = 1280.0f;
	stage2_.pos2.X = 320.0f;
	stage2_.pos.Y = 346.0f;
	stage2_.t = 0.0f;
	stage2_.easedT = 0.0f;

	stage3_.pos.X = 1280.0f;
	stage3_.pos1.X = 1280.0f;
	stage3_.pos2.X = 320.0f;
	stage3_.pos.Y = 492.0f;
	stage3_.t = 0.0f;
	stage3_.easedT = 0.0f;

	//文字
	stageSelect_.pos.X = 241.0f;
	stageSelect_.pos.Y = -78.0f;
	stageSelect_.pos1.Y = -78.0f;
	stageSelect_.pos2.Y = 80.0f;
	stageSelect_.t = 0.0f;
	stageSelect_.easedT = 0.0f;

	black_.pos.X = 0.0f;
	black_.pos.Y = -720.0f;
	black_.pos1.Y = -720.0f;
	black_.pos2.Y = 0.0f;
	black_.t = 0.0f;
	black_.easedT = 0.0f;
	startEaseCount_ = 0;
	onEase_ = false;

	//カーソル
	cursor_.pos.X = 250.0f;
	cursor_.pos.Y = 0.0f;
	cursor_.radius = 20.0f;

	//選択
	onSelect_ = false;
	selectStage1_ = true;
	selectStage2_ = false;
	selectStage3_ = false;
	pushCount_ = 5;
	inStage1_ = false;
	inStage2_ = false;
	inStage3_ = false;
}

//更新処理
void StageSelect::Update(char* keys, char* preKeys) {
	//フレーム
	if (frameX_.t < 1.0f) {
		frameX_.t += 1.0f / 30.0f;
	}
	if (frameX_.t >= 1.0f) {
		frameX_.t = 1.0f;
	}

	frameX_.easedT = sqrt(1.0f - pow(frameX_.t - 1.0f, 2.0f));

	frameX_.pos.X = (1.0 - frameX_.easedT) * frameX_.pos1.X + frameX_.easedT * frameX_.pos2.X;

	if (frameY_.t < 1.0f) {
		frameY_.t += 1.0f / 30.0f;
	}
	if (frameY_.t >= 1.0f) {
		frameY_.t = 1.0f;
	}

	frameY_.easedT = sqrt(1.0f - pow(frameY_.t - 1.0f, 2.0f));

	frameY_.pos.Y = (1.0 - frameY_.easedT) * frameY_.pos1.Y + frameY_.easedT * frameY_.pos2.Y;

	//プレート
	if (stage1_.t < 1.0f) {
		stage1_.t += 1.0f / 60.0f;
	}
	if (stage1_.t >= 1.0f) {
		stage1_.t = 1.0f;
	}

	stage1_.easedT = sqrt(1.0f - pow(stage1_.t - 1.0f, 2.0f));

	stage1_.pos.X = (1.0 - stage1_.easedT) * stage1_.pos1.X + stage1_.easedT * stage1_.pos2.X;

	if (stage2_.t < 1.0f) {
		stage2_.t += 1.0f / 75.0f;
	}
	if (stage2_.t >= 1.0f) {
		stage2_.t = 1.0f;
	}

	stage2_.easedT = sqrt(1.0f - pow(stage2_.t - 1.0f, 2.0f));

	stage2_.pos.X = (1.0 - stage2_.easedT) * stage2_.pos1.X + stage2_.easedT * stage2_.pos2.X;

	if (stage3_.t < 1.0f) {
		stage3_.t += 1.0f / 90.0f;
	}
	if (stage3_.t >= 1.0f) {
		stage3_.t = 1.0f;
	}

	stage3_.easedT = sqrt(1.0f - pow(stage3_.t - 1.0f, 2.0f));

	stage3_.pos.X = (1.0 - stage3_.easedT) * stage3_.pos1.X + stage3_.easedT * stage3_.pos2.X;

	//文字
	if (stageSelect_.t < 1.0f) {
		stageSelect_.t += 1.0f / 30.0f;
	}
	if (stageSelect_.t >= 1.0f) {
		stageSelect_.t = 1.0f;
	}

	stageSelect_.easedT = sqrt(1.0f - pow(stageSelect_.t - 1.0f, 2.0f));

	stageSelect_.pos.Y = (1.0 - stageSelect_.easedT) * stageSelect_.pos1.Y + stageSelect_.easedT * stageSelect_.pos2.Y;

	if (stage3_.t == 1.0f) {
		onSelect_ = true;
	}

	//選択
	if (onSelect_ == true) {
		if (pushCount_ <= 5) {
			pushCount_++;
		}

		if (selectStage1_ == true) {
			if (pushCount_ >= 5) {
				if ((keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0) || (keys[DIK_S] && preKeys[DIK_S] == 0)) {
					selectStage2_ = true;
					pushCount_ = 0;
					selectStage1_ = false;
				}

				if ((keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) || (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)) {
					inStage1_ = true;
				}
			}

			cursor_.pos.Y = stage1_.pos.Y + 58.0f;
		}

		if (selectStage2_ == true) {
			if (pushCount_ >= 5) {
				if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0 || (keys[DIK_S] && preKeys[DIK_S] == 0)) {
					selectStage3_ = true;
					pushCount_ = 0;
					selectStage2_ = false;
				}
				if (keys[DIK_UP] && preKeys[DIK_UP] == 0 || (keys[DIK_W] && preKeys[DIK_W] == 0)) {
					selectStage1_ = true;
					pushCount_ = 0;
					selectStage2_ = false;
				}

				if ((keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) || (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)) {
					inStage2_ = true;
				}
			}

			cursor_.pos.Y = stage2_.pos.Y + 58.0f;
		}

		if (selectStage3_ == true) {
			if (pushCount_ >= 5) {
				if (keys[DIK_UP] && preKeys[DIK_UP] == 0 || (keys[DIK_W] && preKeys[DIK_W] == 0)) {
					selectStage2_ = true;
					pushCount_ = 0;
					selectStage3_ = false;
				}

				if ((keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) || (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)) {
					inStage3_ = true;
				}
			}

			cursor_.pos.Y = stage3_.pos.Y + 58.0f;
		}
	}

	if (inStage1_ == true || inStage2_ == true || inStage3_ == true) {
		onSelect_ = false;
		if (startEaseCount_ <= 30) {
			startEaseCount_++;
		}
		if (startEaseCount_ >= 30) {
			onEase_ = true;
		}

		if (onEase_ == true) {
			if (black_.t < 1.0f) {
				black_.t += 1.0f / 30.0f;
			}
			if (black_.t >= 1.0f) {
				black_.t = 1.0f;
			}

			black_.easedT = sqrt(1.0f - pow(black_.t - 1.0f, 2.0f));

			black_.pos.Y = (1.0 - black_.easedT) * black_.pos1.Y + black_.easedT * black_.pos2.Y;
		}
	}
}

//描画処理
void StageSelect::Draw() {
	//背景
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);

	//フレーム
	Novice::DrawSprite(frameX_.pos.X, frameX_.pos.Y, mapFrameX, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(frameY_.pos.X, frameY_.pos.Y, mapFrameY, 1, 1, 0.0f, WHITE);

	//プレート
	Novice::DrawSprite(stage1_.pos.X, stage1_.pos.Y, stage1, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(stage2_.pos.X, stage2_.pos.Y, stage2, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(stage3_.pos.X, stage3_.pos.Y, stage3, 1, 1, 0.0f, WHITE);

	//カーソル
	if (onSelect_ == true) {
		Novice::DrawEllipse(cursor_.pos.X, cursor_.pos.Y, cursor_.radius, cursor_.radius, 0.0f, BLUE, kFillModeSolid);
	}

	//文字
	Novice::DrawSprite(stageSelect_.pos.X, stageSelect_.pos.Y, stageSelect, 1, 1, 0.0f, WHITE);

	Novice::DrawBox(black_.pos.X, black_.pos.Y, 1280, 720, 0.0f, BLACK, kFillModeSolid);
}