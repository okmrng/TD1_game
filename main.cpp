#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Option.h"
#include "Fade.h"
#include "Tutorial.h"
#include "Clear.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Boss.h"
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

	//クリア演出
	Clear* clear = new Clear();
	clear->Initialize();

	//ステージ1
	Stage1* stage1 = new Stage1();
	stage1->Initialize();

	//ステージ2
	Stage2* stage2 = new Stage2();
	stage2->Initialize();

	//ステージ3
	Stage3* stage3 = new Stage3();
	stage3->Initialize();

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
		//STAGESELECT,
		STAGE1,
		STAGE2,
		STAGE3,
		GAMEOVER,
		CLEAR,
		RESET
	};

	int scene = TITLE;
	//int scene = STAGE1;

	//画像読み込み
	int title = Novice::LoadTexture("./Resources/Images/title.png");
	int frame = Novice::LoadTexture("./Resources/Images/frame.png");
	int frameRight = Novice::LoadTexture("./Resources/Images/frame_right.png");
	int frameLeft = Novice::LoadTexture("./Resources/Images/frame_left.png");
	int wasd = Novice::LoadTexture("./Resources/Images/wasd.png");
	int wasdYellow = Novice::LoadTexture("./Resources/Images/wasd_yellow.png");
	int direction = Novice::LoadTexture("./Resources/Images/direction.png");
	int directionYellow = Novice::LoadTexture("./Resources/Images/direction_yellow.png");
	int tutorialPlate = Novice::LoadTexture("./Resources/Images/plate_tutorial.png");
	int stage1Plate = Novice::LoadTexture("./Resources/Images/plate_stage1.png");
	int stage2Plate = Novice::LoadTexture("./Resources/Images/plate_stage2.png");
	int stage3Plate = Novice::LoadTexture("./Resources/Images/plate_stage3.png");
	int clearPlate = Novice::LoadTexture("./Resources/Images/plate_clear.png");
	int tutorialText1 = Novice::LoadTexture("./Resources/Images/tutorial_text1.png");
	int tutorialText2 = Novice::LoadTexture("./Resources/Images/tutorial_text2.png");
	int tutorialText3Direction = Novice::LoadTexture("./Resources/Images/tutorial_text3_direction.png");
	int tutorialText3WASD = Novice::LoadTexture("./Resources/Images/tutorial_text3_wasd.png");
	int tutorialText4 = Novice::LoadTexture("./Resources/Images/tutorial_text4.png");
	int tutorialText5 = Novice::LoadTexture("./Resources/Images/tutorial_text5.png");
	int tutorialText7 = Novice::LoadTexture("./Resources/Images/tutorial_text7.png");
	int tutorialText9 = Novice::LoadTexture("./Resources/Images/tutorial_text9.png");
	int tutorialText10Direction = Novice::LoadTexture("./Resources/Images/tutorial_text10_direction.png");
	int tutorialText10WASD = Novice::LoadTexture("./Resources/Images/tutorial_text10_wasd.png");
	int tutorialText11 = Novice::LoadTexture("./Resources/Images/tutorial_text11.png");
	int tutorialText12 = Novice::LoadTexture("./Resources/Images/tutorial_text12.png");
	int tutorialText13 = Novice::LoadTexture("./Resources/Images/tutorial_text13.png");
	int tutorialText14 = Novice::LoadTexture("./Resources/Images/tutorial_text14.png");
	int tutorialTextbox = Novice::LoadTexture("./Resources/Images/tutorial_textbox.png");
	int tutorialBg = Novice::LoadTexture("./Resources/Images/bg_tutorial.png");
	int bombBullet = Novice::LoadTexture("./Resources/Images/bombBullet.png");
	int playerWASD = Novice::LoadTexture("./Resources/Images/playerWASD.png");
	int playerDirection = Novice::LoadTexture("./Resources/Images/playerDirection.png");
	int playerCore = Novice::LoadTexture("./Resources/Images/player_core.png");
	int playerBullet = Novice::LoadTexture("./Resources/Images/playerBullet.png");
	int enemyTutorial = Novice::LoadTexture("./Resources/Images/enemy_tutorial.png");
	int miniBoss = Novice::LoadTexture("./Resources/Images/enemy_miniboss.png");
	int bossImage = Novice::LoadTexture("./Resources/Images/boss.png");
	int bossCore = Novice::LoadTexture("./Resources/Images/boss_core.png");
	int enemyBulletTutorial = Novice::LoadTexture("./Resources/Images/enemyBullet_tutorial.png");
	int enemyBulletImage = Novice::LoadTexture("./Resources/Images/enemyBullet.png");
	int mapFrameX = Novice::LoadTexture("./Resources/Images/map_frameX.png");
	int mapFrameY = Novice::LoadTexture("./Resources/Images/map_frameY.png");

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
			tutorial->Update(keys, preKeys, option->GetterWASDStaile(), option->GetterDirectionStaile(), scene);

			if (tutorial->next_ == true) {
				//scene = STAGESELECT;
				scene = STAGE3;
			}
		}

		//ステージ1
		if (scene == STAGE1) {
			stage1->Update(keys, preKeys, option->GetterWASDStaile(), option->GetterDirectionStaile(), tutorial->onPlayerMove_,
				tutorial->onPlayerShot_, tutorial->onBomb_, scene, tutorial->text_);

			if (stage1->clear_->next_ == true) {
				//scene = TITLE;
			}
		}

		//ステージ2
		if (scene == STAGE2) {
			stage2->Update(keys, preKeys, option->GetterWASDStaile(), option->GetterDirectionStaile(), tutorial->onPlayerMove_,
				tutorial->onPlayerShot_, tutorial->onBomb_, scene, tutorial->text_);

			if (stage2->clear_->next_ == true) {
				//scene = TITLE;
			}
		}

		//ステージ3
		if (scene == STAGE3) {
			stage3->Update(keys, preKeys, option->GetterWASDStaile(), option->GetterDirectionStaile(), tutorial->onPlayerMove_,
				tutorial->onPlayerShot_, tutorial->onBomb_, scene, tutorial->text_);

			if (stage3->clear_->next_ == true) {
				//scene = TITLE;
			}
		}

		//敵
		//enemy->Update(scene);

		//当たり判定
		//何もしない敵
		//自機との当たり判定
		//float player_enemyX = player->GetterPosX() - enemy->enemy_.pos.X;
		//float player_enemyY = player->GetterPosY() - enemy->enemy_.pos.Y;
		//float player_enemyDis = sqrtf(player_enemyX * player_enemyX + player_enemyY * player_enemyY);

		//if (enemy->enemy_.isAlive == true) {
		//	if (player_enemyDis < player->GetterRadius() + enemy->enemy_.radius) {
		//		player->OnCollision();
		//	}
		//}

		////自機の弾との当たり判定
		//for (int i = 0; i < 15; i++) {
		//	playerBullet_enemyX = player->bullet_->bullet_.pos[i].X - enemy->enemy_.pos.X;
		//	playerBullet_enemyY = player->bullet_->bullet_.pos[i].Y - enemy->enemy_.pos.Y;
		//	playerBullet_enemyDis = sqrtf(playerBullet_enemyX * playerBullet_enemyX + playerBullet_enemyY * playerBullet_enemyY);

		//	if (enemy->enemy_.isAlive == true) {
		//		if (playerBullet_enemyDis < player->bullet_->bullet_.radius[i] + enemy->enemy_.radius) {
		//			if (player->bullet_->bullet_.isShot[i] == true) {
		//				enemy->EnemyOnCollision(player->bullet_->bullet_.attack);
		//			}
		//			player->bullet_->bullet_.isShot[i] = false;
		//		}
		//	}
		//}

		////移動する敵
		////自機との当たり判定
		//float player_moveEnemyX = player->GetterPosX() - enemy->moveEnemy_.pos.X;
		//float player_moveEnemyY = player->GetterPosY() - enemy->moveEnemy_.pos.Y;
		//float player_moveEnemyDis = sqrtf(player_moveEnemyX * player_moveEnemyX + player_moveEnemyY * player_moveEnemyY);

		//if (enemy->moveEnemy_.isAlive == true) {
		//	if (player_moveEnemyDis < player->GetterRadius() + enemy->moveEnemy_.radius) {
		//		player->OnCollision();
		//	}
		//}

		////自機の弾との当たり判定
		//for (int i = 0; i < 15; i++) {
		//	playerBullet_moveEnemyX = player->bullet_->bullet_.pos[i].X - enemy->moveEnemy_.pos.X;
		//	playerBullet_moveEnemyY = player->bullet_->bullet_.pos[i].Y - enemy->moveEnemy_.pos.Y;
		//	playerBullet_moveEnemyDis = sqrtf(playerBullet_moveEnemyX * playerBullet_moveEnemyX + playerBullet_moveEnemyY * playerBullet_moveEnemyY);

		//	if (enemy->moveEnemy_.isAlive == true) {
		//		if (playerBullet_moveEnemyDis < player->bullet_->bullet_.radius[i] + enemy->moveEnemy_.radius) {
		//			if (player->bullet_->bullet_.isShot[i] == true) {
		//				enemy->MoveEnemyOnCollision(player->bullet_->bullet_.attack);
		//			}
		//			player->bullet_->bullet_.isShot[i] = false;
		//		}
		//	}
		//}

		////弾を撃つ敵
		////自機との当たり判定
		//float player_bulletEnemyX = player->GetterPosX() - enemy->bulletEnemy_.pos.X;
		//float player_bulletEnemyY = player->GetterPosY() - enemy->bulletEnemy_.pos.Y;
		//float player_bulletEnemyDis = sqrtf(player_bulletEnemyX * player_bulletEnemyX + player_bulletEnemyY * player_bulletEnemyY);

		//if (enemy->bulletEnemy_.isAlive == true) {
		//	if (player_bulletEnemyDis < player->GetterRadius() + enemy->bulletEnemy_.radius) {
		//		player->OnCollision();
		//	}
		//}

		////自機の弾との当たり判定
		//for (int i = 0; i < 15; i++) {
		//	playerBullet_bulletEnemyX = player->bullet_->bullet_.pos[i].X - enemy->bulletEnemy_.pos.X;
		//	playerBullet_bulletEnemyY = player->bullet_->bullet_.pos[i].Y - enemy->bulletEnemy_.pos.Y;
		//	playerBullet_bulletEnemyDis = sqrtf(playerBullet_bulletEnemyX * playerBullet_bulletEnemyX + playerBullet_bulletEnemyY * playerBullet_bulletEnemyY);

		//	if (enemy->bulletEnemy_.isAlive == true) {
		//		if (playerBullet_bulletEnemyDis < player->bullet_->bullet_.radius[i] + enemy->bulletEnemy_.radius) {
		//			if (player->bullet_->bullet_.isShot[i] == true) {
		//				enemy->BulletEnemyOnCollision(player->bullet_->bullet_.attack);
		//			}
		//			player->bullet_->bullet_.isShot[i] = false;
		//		}
		//	}
		//}

		////敵の弾と自機の当たり判定
		//float enemyBullet_playerX = enemy->enemyBullet_->enemyBullet_.pos.X - player->GetterPosX();
		//float enemyBullet_playerY = enemy->enemyBullet_->enemyBullet_.pos.Y - player->GetterPosY();
		//float enemyBullet_playerDis = sqrtf(enemyBullet_playerX * enemyBullet_playerX + enemyBullet_playerY * enemyBullet_playerY);

		//if (enemy->bulletEnemy_.isAlive == true) {
		//	if (enemyBullet_playerDis < player->GetterRadius() + enemy->enemyBullet_->enemyBullet_.radius) {
		//		if (player->GetterOnCollision() == false) {
		//			enemy->enemyBullet_->OnCollition();
		//		}
		//		player->OnCollision();
		//	}
		//}

		////複数弾を撃つ敵
		////自機との当たり判定
		//float player_bulletsEnemyX = player->GetterPosX() - enemy->bulletsEnemy_.pos.X;
		//float player_bulletsEnemyY = player->GetterPosY() - enemy->bulletsEnemy_.pos.Y;
		//float player_bulletsEnemyDis = sqrtf(player_bulletsEnemyX * player_bulletsEnemyX + player_bulletsEnemyY * player_bulletsEnemyY);

		//if (enemy->bulletsEnemy_.isAlive == true) {
		//	if (player_bulletsEnemyDis < player->GetterRadius() + enemy->bulletsEnemy_.radius) {
		//		player->OnCollision();
		//	}
		//}

		////自機の弾との当たり判定
		//for (int i = 0; i < 15; i++) {
		//	playerBullet_bulletsEnemyX = player->bullet_->bullet_.pos[i].X - enemy->bulletsEnemy_.pos.X;
		//	playerBullet_bulletsEnemyY = player->bullet_->bullet_.pos[i].Y - enemy->bulletsEnemy_.pos.Y;
		//	playerBullet_bulletsEnemyDis = sqrtf(playerBullet_bulletsEnemyX * playerBullet_bulletsEnemyX + playerBullet_bulletsEnemyY * playerBullet_bulletsEnemyY);

		//	if (enemy->bulletsEnemy_.isAlive == true) {
		//		if (playerBullet_bulletsEnemyDis < player->bullet_->bullet_.radius[i] + enemy->bulletsEnemy_.radius) {
		//			if (player->bullet_->bullet_.isShot[i] == true) {
		//				enemy->BulletsEnemyOnCollision(player->bullet_->bullet_.attack);
		//			}
		//			player->bullet_->bullet_.isShot[i] = false;
		//		}
		//	}
		//}

		////敵の弾と自機の当たり判定
		//for (int i = 0; i < 10; i++) {
		//	enemyBullets_playerX = enemy->enemyBullet_->enemyBullets_.pos[i].X - player->GetterPosX();
		//	enemyBullets_playerY = enemy->enemyBullet_->enemyBullets_.pos[i].Y - player->GetterPosY();
		//	enemyBullets_playerDis = sqrtf(enemyBullets_playerX * enemyBullets_playerX + enemyBullets_playerY * enemyBullets_playerY);

		//	if (enemy->bulletsEnemy_.isAlive == true) {
		//		if (enemyBullets_playerDis < player->GetterRadius() + enemy->enemyBullet_->enemyBullets_.radius[i]) {
		//			if (player->GetterOnCollision() == false) {
		//				enemy->enemyBullet_->enemyBullets_.isShot[i] = false;
		//			}
		//			player->OnCollision();
		//		}
		//	}
		//}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//タイトル
		if (scene == TITLE) {
			Novice::DrawSprite(0, 0, title, 1.0f, 1.0f, 0.0f, WHITE);
			//フェード
			fade->Draw();
		}

		//オプション
		if (scene == OPTION) {
			option->Draw(wasd, wasdYellow, direction, directionYellow);
		}

		//敵
		//enemy->Draw();

		//チュートリアル
		if (scene == TUTORIAL) {
			tutorial->Draw(frameRight, frameLeft, tutorialPlate, option->GetterWASDStaile(), option->GetterDirectionStaile(), tutorialText1, tutorialText2,
				tutorialText3Direction, tutorialText3WASD, tutorialText4, tutorialText5, tutorialText7, tutorialTextbox,
				tutorialText9, tutorialText10Direction, tutorialText10WASD, tutorialText11, tutorialText12, tutorialText13,
				tutorialText14, scene, tutorialBg, bombBullet, clearPlate, playerWASD, playerDirection, playerCore, playerBullet,
				enemyTutorial, enemyBulletTutorial, enemyBulletImage, miniBoss);
		}

		//ステージ1
		if (scene == STAGE1) {
			stage1->Draw(frameRight, frameLeft, stage1Plate, option->GetterWASDStaile(), option->GetterDirectionStaile(),
				playerWASD, playerDirection, playerCore, bombBullet, option->GetterDirectionStaile(), playerBullet, scene,
				enemyTutorial, enemyBulletImage, clearPlate, miniBoss);
		}

		//ステージ2
		if (scene == STAGE2) {
			stage2->Draw(frameRight, frameLeft, stage2Plate, option->GetterWASDStaile(), option->GetterDirectionStaile(),
				playerWASD, playerDirection, playerCore, bombBullet, option->GetterDirectionStaile(), playerBullet, scene,
				enemyTutorial, enemyBulletImage, clearPlate, miniBoss);
		}

		//ステージ3
		if (scene == STAGE3) {
			stage3->Draw(frameRight, frameLeft, stage3Plate, option->GetterWASDStaile(), option->GetterDirectionStaile(),
				playerWASD, playerDirection, playerCore, bombBullet, option->GetterDirectionStaile(), playerBullet, scene,
				enemyTutorial, enemyBulletImage, clearPlate, miniBoss, bossImage, bossCore);
		}

		Novice::ScreenPrintf(0, 0, "scene:%d", scene);
		if (stage2->admission_->GetterPlayStart() == true) {
			Novice::ScreenPrintf(0, 80, "true");
		}
		if (stage2->admission_->GetterPlayStart() == false) {
			Novice::ScreenPrintf(0, 80, "false");
		}
		Novice::ScreenPrintf(0, 100, "%d", stage2->admission_->GetterPlayStartCount());
		
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
