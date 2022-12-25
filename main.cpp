#include <Novice.h>
#include "Player.h"
#include "PlayerBullet.h"
#include "Enemy.h"

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
	Player* player = new Player;
	player->Initialize();

	//敵
	Enemy* enemy = new Enemy;
	enemy->Initialize();

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
