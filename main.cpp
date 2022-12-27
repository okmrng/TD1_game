#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "GC1A_06_オクムラ_ナギ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	const int kWindowWidth = 1280;
	const int kWindowHeight = 720;
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//初期化
	//自機
	Player* player = new Player();
	player->Initialize();

	//敵
	Enemy* enemy = new Enemy();
	enemy->Initialize();

	//当たり判定
	//何もしない敵
	float playerBullet_enemyX = 0.0f;
	float playerBullet_enemyY = 0.0f;
	float playerBullet_enemyDis = 0.0f;

	//移動する敵
	float playerBullet_moveEnemyX = 0.0f;
	float playerBullet_moveEnemyY = 0.0f;
	float playerBullet_moveEnemyDis = 0.0f;

	//画像読み込み
	int frame = Novice::LoadTexture("./Resources/Images/frame.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		//自機
		player->Update(keys);

		//敵
		enemy->Update();

		//当たり判定
		//何もしない敵
		//自機との当たり判定
		float player_enemyX = player->GetterPosX() - enemy->enemy_.pos.X;
		float player_enemyY = player->GetterPosY() - enemy->enemy_.pos.Y;
		float player_enemyDis = sqrtf(player_enemyX * player_enemyX + player_enemyY * player_enemyY);

		if (enemy->enemy_.isAlive == true) {
			if (player_enemyDis < player->GetterRadius() + enemy->enemy_.radius) {
				player->OnCollision();
			}
		}

		//自機の弾との当たり判定
		for (int i = 0; i < 15; i++) {
			playerBullet_enemyX = player->bullet_->bullet_.pos[i].X - enemy->enemy_.pos.X;
			playerBullet_enemyY = player->bullet_->bullet_.pos[i].Y - enemy->enemy_.pos.Y;
			playerBullet_enemyDis = sqrtf(playerBullet_enemyX * playerBullet_enemyX + playerBullet_enemyY * playerBullet_enemyY);

			if (enemy->enemy_.isAlive == true) {
				if (playerBullet_enemyDis < player->bullet_->bullet_.radius[i] + enemy->enemy_.radius) {
					if (player->bullet_->bullet_.isShot[i] == true) {
						enemy->EnemyOnCollision(player->bullet_->bullet_.attack);
					}
					player->bullet_->bullet_.isShot[i] = false;
				}
			}
		}

		//移動する敵
		//自機との当たり判定
		float player_moveEnemyX = player->GetterPosX() - enemy->moveEnemy_.pos.X;
		float player_moveEnemyY = player->GetterPosY() - enemy->moveEnemy_.pos.Y;
		float player_moveEnemyDis = sqrtf(player_moveEnemyX * player_moveEnemyX + player_moveEnemyY * player_moveEnemyY);

		if (enemy->moveEnemy_.isAlive == true) {
			if (player_moveEnemyDis < player->GetterRadius() + enemy->moveEnemy_.radius) {
				player->OnCollision();
			}
		}

		//自機の弾との当たり判定
		for (int i = 0; i < 15; i++) {
			playerBullet_moveEnemyX = player->bullet_->bullet_.pos[i].X - enemy->moveEnemy_.pos.X;
			playerBullet_moveEnemyY = player->bullet_->bullet_.pos[i].Y - enemy->moveEnemy_.pos.Y;
			playerBullet_moveEnemyDis = sqrtf(playerBullet_moveEnemyX * playerBullet_moveEnemyX + playerBullet_moveEnemyY * playerBullet_moveEnemyY);

			if (enemy->moveEnemy_.isAlive == true) {
				if (playerBullet_moveEnemyDis < player->bullet_->bullet_.radius[i] + enemy->moveEnemy_.radius) {
					if (player->bullet_->bullet_.isShot[i] == true) {
						enemy->MoveEnemyOnCollision(player->bullet_->bullet_.attack);
					}
					player->bullet_->bullet_.isShot[i] = false;
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//敵
		enemy->Draw();

		//フレーム
		Novice::DrawSprite(0.0f, 0.0f, frame, 1.0f, 1.0f, 0.0f, WHITE);

		//自機
		player->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
