#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Option.h"
#include "Fade.h"
#include "Tutorial.h"
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

	//オプション
	Option* option = new Option();
	option->Initialize();

	//フェード
	Fade* fade = new Fade();
	fade->Initialize();

	//チュートリアル
	Tutorial* tutorial = new Tutorial();
	tutorial->Initialize();

	//当たり判定
	//何もしない敵
	float playerBullet_enemyX = 0.0f;
	float playerBullet_enemyY = 0.0f;
	float playerBullet_enemyDis = 0.0f;

	//移動する敵
	float playerBullet_moveEnemyX = 0.0f;
	float playerBullet_moveEnemyY = 0.0f;
	float playerBullet_moveEnemyDis = 0.0f;

	//弾を撃つ敵
	float playerBullet_bulletEnemyX = 0.0f;
	float playerBullet_bulletEnemyY = 0.0f;
	float playerBullet_bulletEnemyDis = 0.0f;

	//複数弾を撃つ敵
	float playerBullet_bulletsEnemyX = 0.0f;
	float playerBullet_bulletsEnemyY = 0.0f;
	float playerBullet_bulletsEnemyDis = 0.0f;

	float enemyBullets_playerX = 0.0f;
	float enemyBullets_playerY = 0.0f;
	float enemyBullets_playerDis = 0.0f;

	//シーン
	enum scene {
		TITLE,
		OPTION,
		TUTORIAL,
		MAP,
		STAGE1,
		GAMEOVER,
		CLEAR
	};

	//int scene = TITLE;
	int scene = OPTION;

	//画像読み込み
	int frame = Novice::LoadTexture("./Resources/Images/frame.png");
	int frameSide = Novice::LoadTexture("./Resources/Images/frame_side.png");
	int wasd = Novice::LoadTexture("./Resources/Images/wasd.png");
	int wasdYellow = Novice::LoadTexture("./Resources/Images/wasd_yellow.png");
	int direction = Novice::LoadTexture("./Resources/Images/direction.png");
	int directionYellow = Novice::LoadTexture("./Resources/Images/direction_yellow.png");
	int tutorialPlate = Novice::LoadTexture("./Resources/Images/plate_tutorial.png");
	int tutorialText1 = Novice::LoadTexture("./Resources/Images/tutorial_text1.png");
	int tutorialText2 = Novice::LoadTexture("./Resources/Images/tutorial_text2.png");
	int tutorialText3Direction = Novice::LoadTexture("./Resources/Images/tutorial_text3_direction.png");
	int tutorialText3WASD = Novice::LoadTexture("./Resources/Images/tutorial_text3_wasd.png");
	int tutorialText4 = Novice::LoadTexture("./Resources/Images/tutorial_text4.png");

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

		//タイトル画面
		if (scene == TITLE) {
			//フェードインフラグをtrueにする
			if ((keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) || (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)) {
				fade->SetOnFade(true);
			}

			//フェードイン
			fade->Update();
			if (fade->GetterNext() == true) {
				scene = OPTION;
			}
		}

		//設定画面
		if (scene == OPTION) {
			option->Update(keys, preKeys);

			//フェードアウト
			if (option->GetterNext() == true) {
				scene = TUTORIAL;
			}
		}

		//チュートリアル
		if (scene == TUTORIAL) {
			tutorial->Update(keys, preKeys);

			if (tutorial->next_ == true) {
				scene = MAP;
			}

			//自機
			//player->Update(keys, option->GetterWASDStaile(), option->GetterDirectionStaile());
		}

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

		//弾を撃つ敵
		//自機との当たり判定
		float player_bulletEnemyX = player->GetterPosX() - enemy->bulletEnemy_.pos.X;
		float player_bulletEnemyY = player->GetterPosY() - enemy->bulletEnemy_.pos.Y;
		float player_bulletEnemyDis = sqrtf(player_bulletEnemyX * player_bulletEnemyX + player_bulletEnemyY * player_bulletEnemyY);

		if (enemy->bulletEnemy_.isAlive == true) {
			if (player_bulletEnemyDis < player->GetterRadius() + enemy->bulletEnemy_.radius) {
				player->OnCollision();
			}
		}

		//自機の弾との当たり判定
		for (int i = 0; i < 15; i++) {
			playerBullet_bulletEnemyX = player->bullet_->bullet_.pos[i].X - enemy->bulletEnemy_.pos.X;
			playerBullet_bulletEnemyY = player->bullet_->bullet_.pos[i].Y - enemy->bulletEnemy_.pos.Y;
			playerBullet_bulletEnemyDis = sqrtf(playerBullet_bulletEnemyX * playerBullet_bulletEnemyX + playerBullet_bulletEnemyY * playerBullet_bulletEnemyY);

			if (enemy->bulletEnemy_.isAlive == true) {
				if (playerBullet_bulletEnemyDis < player->bullet_->bullet_.radius[i] + enemy->bulletEnemy_.radius) {
					if (player->bullet_->bullet_.isShot[i] == true) {
						enemy->BulletEnemyOnCollision(player->bullet_->bullet_.attack);
					}
					player->bullet_->bullet_.isShot[i] = false;
				}
			}
		}

		//敵の弾と自機の当たり判定
		float enemyBullet_playerX = enemy->enemyBullet_->enemyBullet_.pos.X - player->GetterPosX();
		float enemyBullet_playerY = enemy->enemyBullet_->enemyBullet_.pos.Y - player->GetterPosY();
		float enemyBullet_playerDis = sqrtf(enemyBullet_playerX * enemyBullet_playerX + enemyBullet_playerY * enemyBullet_playerY);

		if (enemy->bulletEnemy_.isAlive == true) {
			if (enemyBullet_playerDis < player->GetterRadius() + enemy->enemyBullet_->enemyBullet_.radius) {
				if (player->GetterOnCollision() == false) {
					enemy->enemyBullet_->OnCollition();
				}
				player->OnCollision();
			}
		}

		//複数弾を撃つ敵
		//自機との当たり判定
		float player_bulletsEnemyX = player->GetterPosX() - enemy->bulletsEnemy_.pos.X;
		float player_bulletsEnemyY = player->GetterPosY() - enemy->bulletsEnemy_.pos.Y;
		float player_bulletsEnemyDis = sqrtf(player_bulletsEnemyX * player_bulletsEnemyX + player_bulletsEnemyY * player_bulletsEnemyY);

		if (enemy->bulletsEnemy_.isAlive == true) {
			if (player_bulletsEnemyDis < player->GetterRadius() + enemy->bulletsEnemy_.radius) {
				player->OnCollision();
			}
		}

		//自機の弾との当たり判定
		for (int i = 0; i < 15; i++) {
			playerBullet_bulletsEnemyX = player->bullet_->bullet_.pos[i].X - enemy->bulletsEnemy_.pos.X;
			playerBullet_bulletsEnemyY = player->bullet_->bullet_.pos[i].Y - enemy->bulletsEnemy_.pos.Y;
			playerBullet_bulletsEnemyDis = sqrtf(playerBullet_bulletsEnemyX * playerBullet_bulletsEnemyX + playerBullet_bulletsEnemyY * playerBullet_bulletsEnemyY);

			if (enemy->bulletsEnemy_.isAlive == true) {
				if (playerBullet_bulletsEnemyDis < player->bullet_->bullet_.radius[i] + enemy->bulletsEnemy_.radius) {
					if (player->bullet_->bullet_.isShot[i] == true) {
						enemy->BulletsEnemyOnCollision(player->bullet_->bullet_.attack);
					}
					player->bullet_->bullet_.isShot[i] = false;
				}
			}
		}

		//敵の弾と自機の当たり判定
		for (int i = 0; i < 10; i++) {
			enemyBullets_playerX = enemy->enemyBullet_->enemyBullets_.pos[i].X - player->GetterPosX();
			enemyBullets_playerY = enemy->enemyBullet_->enemyBullets_.pos[i].Y - player->GetterPosY();
			enemyBullets_playerDis = sqrtf(enemyBullets_playerX * enemyBullets_playerX + enemyBullets_playerY * enemyBullets_playerY);

			if (enemy->bulletsEnemy_.isAlive == true) {
				if (enemyBullets_playerDis < player->GetterRadius() + enemy->enemyBullet_->enemyBullets_.radius[i]) {
					if (player->GetterOnCollision() == false) {
						enemy->enemyBullet_->enemyBullets_.isShot[i] = false;
					}
					player->OnCollision();
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//タイトル
		if (scene == TITLE) {
			//フェード
			fade->Draw();
		}

		//オプション
		if (scene == OPTION) {
			option->Draw(wasd, wasdYellow, direction, directionYellow);
		}

		//敵
		enemy->Draw();

		//チュートリアル
		if (scene == TUTORIAL) {
			tutorial->Draw(frameSide, tutorialPlate, option->GetterWASDStaile(), option->GetterDirectionStaile(), tutorialText1, tutorialText2,
				tutorialText3Direction, tutorialText3WASD, tutorialText4);

			//自機
			//player->Draw();
		}
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		/*if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}*/
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
