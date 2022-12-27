#include "Enemy.h"
#include <Novice.h>

//初期化
void Enemy::Initialize() {
	//何もしない敵
	/*enemy_.HP = 100;
	enemy_.isAlive = true;
	enemy_.pos.X = 640.0f;
	enemy_.pos.Y = 100.0f;
	enemy_.radius = 20.0f;
	enemy_.speed.X = 0.0f;
	enemy_.speed.Y = 0.0f;*/

	//移動する敵
	moveEnemy_.HP = 100;
	moveEnemy_.isAlive = true;
	moveEnemy_.pos.X = 300.0f;
	moveEnemy_.pos.Y = -30.0f;
	moveEnemy_.radius = 20.0f;
	moveEnemy_.speed.X = 5.0f;
	moveEnemy_.speed.Y = 3.0f;
}

//更新処理
void Enemy::Update() {
	//何もしない敵
	/*if (enemy_.isAlive == true) {
	//HPが0以下になったら死ぬ
		if (enemy_.HP <= 0) {
			enemy_.isAlive = false;
		}
	}*/

	//移動する敵
	if (moveEnemy_.isAlive == true) {
		//移動
		moveEnemy_.pos.X += moveEnemy_.speed.X;
		moveEnemy_.pos.Y += moveEnemy_.speed.Y;

		//画面外に行ったら初期位置へ戻す
		if (moveEnemy_.pos.X >= 990.0f || moveEnemy_.pos.Y >= 740.0f) {
			moveEnemy_.pos.X = 300.0f;
			moveEnemy_.pos.Y = -30.0f;
		}

		//HPが0以下になったら死ぬ
		if (moveEnemy_.HP <= 0) {
			moveEnemy_.isAlive = false;
		}
	}
}

//当たり判定
//何もしない敵
void Enemy::EnemyOnCollision(int playerBulletAttack) {
	/*if (enemy_.isAlive == true) {
		enemy_.HP -= playerBulletAttack;
	}*/
}

//移動する敵
void Enemy::MoveEnemyOnCollision(int playerBulletAttack) {
	if (moveEnemy_.isAlive == true) {
		moveEnemy_.HP -= playerBulletAttack;
	}
}

//描画処理
void Enemy::Draw() {
	//何もしない敵
	/*if (enemy_.isAlive == true) {
		Novice::DrawEllipse(enemy_.pos.X, enemy_.pos.Y, enemy_.radius, enemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}*/

	//移動する敵
	if (moveEnemy_.isAlive == true) {
		Novice::DrawEllipse(moveEnemy_.pos.X, moveEnemy_.pos.Y, moveEnemy_.radius, moveEnemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}

	Novice::ScreenPrintf(0, 40, "%0.0f", moveEnemy_.pos.X);
	Novice::ScreenPrintf(0, 60, "%0.0f", moveEnemy_.pos.Y);
	Novice::ScreenPrintf(0, 80, "HP:%d", moveEnemy_.HP);
}