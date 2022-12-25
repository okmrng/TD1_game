#include <Novice.h>
#include "Player.h"
#include "PlayerBullet.h"
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

	//自機の弾
	PlayerBullet* playerBullet = new PlayerBullet();
	playerBullet->Initialize();

	int a = 0;

	float b = 0.0f;

	//敵
	Enemy* enemy = new Enemy();
	enemy->Initialize();

	//当たり判定
	float playerBullet_enemyX = 0.0f;
	float playerBullet_enemyY = 0.0f;
	float playerBullet_enemyDis = 0.0f;


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
		//自機と何もしない敵との当たり判定
		float player_enemyX = player->GetterPosX() - enemy->enemy_.pos.X;
		float player_enemyY = player->GetterPosY() - enemy->enemy_.pos.Y;
		float player_enemyDis = sqrtf(player_enemyX * player_enemyX + player_enemyY * player_enemyY);

		if (player_enemyDis < player->GetterRadius() + enemy->enemy_.radius) {
			player->OnCollision();
		}

		//自機の弾と何もしない敵との当たり判定
		/*for (int i = 0; i < 15; i++) {
			playerBullet_enemyX = playerBullet->bullet_.pos[i].X - enemy->enemy_.pos.X;
			playerBullet_enemyY = playerBullet->bullet_.pos[i].Y - enemy->enemy_.pos.Y;
			playerBullet_enemyDis = sqrtf(playerBullet_enemyX * playerBullet_enemyX + playerBullet_enemyY * playerBullet_enemyY);
		}

		if (playerBullet_enemyDis < playerBullet->bullet_.radius + enemy->enemy_.radius) {
			enemy->OnCollision(playerBullet->bullet_.attack);
			a = 1;
			b = 2.0f;
		}*/

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//フレーム
		Novice::DrawSprite(0.0f, 0.0f, frame, 1.0f, 1.0f, 0.0f, WHITE);

		//敵
		enemy->Draw();

		//自機
		player->Draw();

		Novice::ScreenPrintf(0, 0, "aaa:%d", a);
		Novice::ScreenPrintf(0, 80, "bbb:%0.0f", b);

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
