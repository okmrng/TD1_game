#include "Boss.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
void Boss::Initialeze() {
	boss_.pos.X = 640.0f;
	boss_.pos.Y = 100.0f;
	boss_.speed.X = 7.0f;
	boss_.radius = 12.0f;
	boss_.maxHP = 200;
	boss_.HP = 200;
	boss_.pattern = 0;
	boss_.collor = 0xffffff00;
	boss_.alpha = 0x00000000;
	boss_.theta = 0.0f;
	boss_.amplitude = 50.0f;
	boss_.attackCount = 0;

	//戦闘開始までのカウント
	onStartCount_ = false;
	startCount_ = 0;
	start_ = false;

	bossBullet_ = new BossBullet();
	bossBullet_->Initialize();
}

//更新処理
void Boss::Update() {
	//フェードイン
	if (boss_.alpha <= 0x000000ff) {
		boss_.alpha++;
	}
	if (boss_.alpha >= 0x000000ff) {
		boss_.alpha = 0x000000ff;
		onStartCount_ = true;
	}

	//戦闘開始までのカウント
	if (onStartCount_ == true) {
		startCount_++;
	}
	if (startCount_ >= 30) {
		start_ = true;
	}

	//戦闘開始
	if (start_ == true) {
		boss_.pos.Y = sinf(boss_.theta) * boss_.amplitude + 100.0f;
		boss_.theta += M_PI / 60.0f;

		boss_.pos.X += boss_.speed.X;
		if (boss_.pos.X >= 955.0f || boss_.pos.X<=325.0f) {
			boss_.speed.X *= -1;
		}

		boss_.attackCount++;

		if (boss_.attackCount == 600) {
			boss_.pattern = 1;
		}
		if (boss_.attackCount == 1200) {
			boss_.pattern = 2;
		}
		if (boss_.attackCount == 1800) {
			boss_.pattern = 0;
			boss_.attackCount = 0;
		}

		if (boss_.pattern == 0) {
			for (int i = 0; i < 9; i++) {
				if (bossBullet_->pattern0_.isShot[i] == false) {
					bossBullet_->pattern0_.pos[i].X = boss_.pos.X;
					bossBullet_->pattern0_.pos[i].Y = boss_.pos.Y;
					bossBullet_->pattern0_.isShot[i] = true;
				}
			}
		}

		if (boss_.pattern == 1) {
			for (int i = 0; i < 5; i++) {
				if (bossBullet_->pattern1_.isShot[i] == false) {
					bossBullet_->pattern1_.pos[i].X = boss_.pos.X;
					bossBullet_->pattern1_.pos1[0].X = boss_.pos.X;
					bossBullet_->pattern1_.pos[i].Y = boss_.pos.Y;
					bossBullet_->pattern1_.isShot[i] = true;
				}
			}
		}

		if (boss_.pattern == 2) {
			for (int i = 0; i < 13; i++) {
				if (bossBullet_->pattern2_.isShot[i] == false) {
					bossBullet_->pattern2_.pos[i].X = boss_.pos.X;
					bossBullet_->pattern2_.pos[i].Y = boss_.pos.Y;
					bossBullet_->pattern2_.isShot[i] = true;
				}
			}
		}

		bossBullet_->Update();
	}
}

//描画処理
void Boss::Draw(int bossImage, int bossCore) {
	//本体
	Novice::DrawSprite(boss_.pos.X - 33, boss_.pos.Y - 70, bossImage, 1, 1, 0.0f, boss_.collor + boss_.alpha);

	//当たり判定
	//Novice::DrawEllipse(boss1_.pos.X, boss1_.pos.Y, boss1_.radius, boss1_.radius, 0.0f, WHITE,kFillModeSolid);
	Novice::DrawSprite(boss_.pos.X - 13, boss_.pos.Y - 13, bossCore, 1, 1, 0.0f, WHITE);

	bossBullet_->Draw();

	Novice::ScreenPrintf(0, 200, "%d", boss_.pattern);
}