#include "Enemy.h"
#include <Novice.h>

//初期化
void Enemy::Initialize() {
	//何もしない敵
	enemy_.HP = 100;
	enemy_.isAlive = true;
	enemy_.pos.X = 640.0f;
	enemy_.pos.Y = 100.0f;
	enemy_.radius = 20.0f;
	enemy_.speed.X = 0.0f;
	enemy_.speed.Y = 0.0f;
}

//更新処理
void Enemy::Update() {
	if (enemy_.isAlive == true) {
		if (enemy_.HP <= 0) {
			enemy_.isAlive = false;
		}
	}
}

//当たり判定
void Enemy::OnCollision(int playerBulletAttack) {
	if (enemy_.isAlive == true) {
		enemy_.HP -= playerBulletAttack;
	}
}

//描画処理
void Enemy::Draw() {
	if (enemy_.isAlive == true) {
		Novice::DrawEllipse(enemy_.pos.X, enemy_.pos.Y, enemy_.radius, enemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}

	Novice::ScreenPrintf(0, 40, "%d", enemy_.HP);
}