#include "BossBullet.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//‰Šú‰»
void BossBullet::Initialize() {
	bossBullet0 = Novice::LoadTexture("./Resources/Images/boss_bullet0.png");

	for (int i = 0; i < 9; i++) {
		pattern0_.speed[i].Y = 7.0f;
		pattern0_.radius[i] = 25.0f;
		pattern0_.isShot[i] = false;
	}
	pattern0_.speed[0].X = 0.0f;
	pattern0_.speed[1].X = 2.0f;
	pattern0_.speed[2].X = -2.0f;
	pattern0_.speed[3].X = 4.0f;
	pattern0_.speed[4].X = -4.0f;
	pattern0_.speed[5].X = 6.0f;
	pattern0_.speed[6].X = -6.0f;
	pattern0_.speed[7].X = 8.0f;
	pattern0_.speed[8].X = -8.0f;

	for (int i = 0; i < 5; i++) {
		pattern1_.speed[i].Y = 7.0f;
		pattern1_.radius[i] = 25.0f;
		pattern1_.isShot[i] = false;
	}

	pattern1_.theta[0] = 0.0f;
	pattern1_.amplitude[0] = 100.0f;

	pattern1_.speed[1].X = 3.0f;
	pattern1_.speed[2].X = -3.0f;
	pattern1_.speed[3].X = 5.0f;
	pattern1_.speed[4].X = -5.0f;

	for (int i = 0; i < 13; i++) {
		pattern2_.radius[i] = 25.0f;
		pattern2_.speed[i].X = 7.0f;
		pattern2_.speed[i].Y = 7.0f;
		pattern2_.theta[i] = (rand() % 720 - 360) / 100.0f;
		pattern2_.theta2[i] = (rand() % 150) / 100.0f;
		pattern2_.isShot[i] = false;
	}
}

//XVˆ—
void BossBullet::Update() {
	for (int i = 0; i < 9; i++) {
		if (pattern0_.isShot[i] == true) {
			pattern0_.pos[i].X += pattern0_.speed[i].X;
			pattern0_.pos[i].Y += pattern0_.speed[i].Y;

			if (pattern0_.pos[i].Y >= 750.0f) {
				pattern0_.isShot[i] = false;
			}
		}
	}

	if (pattern1_.isShot[0] == true) {
		pattern1_.pos[0].X = sinf(pattern1_.theta[0]) * pattern1_.amplitude[0] + pattern1_.pos1[0].X;
		pattern1_.theta[0] += M_PI / 30.0f;

		for (int i = 0; i < 5; i++) {
			pattern1_.pos[i].X += pattern1_.speed[i].X;
			pattern1_.pos[i].Y += pattern1_.speed[i].Y;

			if (pattern1_.pos[0].Y >= 750.0f) {
				pattern1_.isShot[i] = false;
			}
		}
	}

	for (int i = 0; i < 13; i++) {
		pattern2_.pos[i].X += sinf(pattern2_.theta[i]) * pattern2_.speed[i].X;
		pattern2_.pos[i].Y += cosf(pattern2_.theta2[i]) * pattern2_.speed[i].Y;

		/*if (pattern2_.pos[i].Y >= 750.0f || pattern2_.pos[i].Y <= -3.0f || pattern2_.pos[i].X >= 985.0f || pattern2_.pos[i].X <= 295.0f) {
			pattern2_.isShot[i] = false;
		}*/
		if (pattern2_.pos[i].X >= 925.0f || pattern2_.pos[i].X <= 355.0f) {
			pattern2_.speed[i].X *= -1;
		}

		if (pattern2_.pos[i].Y >= 750.0f) {
			pattern2_.isShot[i] = false;
		}
	}
}

//•`‰æˆ—
void BossBullet::Draw() {
	for (int i = 0; i < 9; i++) {
		if (pattern0_.isShot[i] == true) {
			//Novice::DrawEllipse(pattern0_.pos[i].X, pattern0_.pos[i].Y, pattern0_.radius[i], pattern0_.radius[i], 0.0f, WHITE, kFillModeSolid);
			Novice::DrawSprite(pattern0_.pos[i].X - 30, pattern0_.pos[i].Y - 30, bossBullet0, 1, 1, 0.0f, WHITE);
		}
	}

	for (int i = 0; i < 5; i++) {
		if (pattern1_.isShot[i] == true) {
			Novice::DrawSprite(pattern1_.pos[i].X - 30, pattern1_.pos[i].Y - 30, bossBullet0, 1, 1, 0.0f, WHITE);
			//Novice::DrawEllipse(pattern1_.pos[i].X, pattern1_.pos[i].Y, pattern1_.radius[i], pattern1_.radius[i], 0.0f, WHITE, kFillModeSolid);
		}
	}

	for (int i = 0; i < 13; i++) {
		if (pattern2_.isShot[i] == true) {
			Novice::DrawSprite(pattern2_.pos[i].X - 30, pattern2_.pos[i].Y - 30, bossBullet0, 1, 1, 0.0f, WHITE);
			//Novice::DrawEllipse(pattern2_.pos[i].X, pattern2_.pos[i].Y, pattern2_.radius[i], pattern2_.radius[i], 0.0f, WHITE, kFillModeSolid);
		}
	}
}