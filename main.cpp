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
#include "StageSelect.h"
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

	//ステージセレクト
	StageSelect* stageSelect = new StageSelect();
	stageSelect->Initialize();

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
		STAGE1,
		STAGE2,
		STAGE3,
		STAGESELECT,
		GAMEOVER,
		CLEAR,
		RESET
	};

	int scene = TITLE;
	//int scene = TUTORIAL;

	//画像読み込み
	int title = Novice::LoadTexture("./Resources/Images/title.png");
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
				scene = STAGESELECT;
			}
		}

		//ステージ1
		if (scene == STAGE1) {
			stage1->Update(keys, preKeys, option->GetterWASDStaile(), option->GetterDirectionStaile(), tutorial->onPlayerMove_,
				tutorial->onPlayerShot_, tutorial->onBomb_, scene, tutorial->text_);

			if (stage1->clear_->next_ == true) {
				scene = RESET;
			}
		}

		//ステージ2
		if (scene == STAGE2) {
			stage2->Update(keys, preKeys, option->GetterWASDStaile(), option->GetterDirectionStaile(), tutorial->onPlayerMove_,
				tutorial->onPlayerShot_, tutorial->onBomb_, scene, tutorial->text_);

			if (stage2->clear_->next_ == true) {
				scene = RESET;
			}
		}

		//ステージ3
		if (scene == STAGE3) {
			stage3->Update(keys, preKeys, option->GetterWASDStaile(), option->GetterDirectionStaile(), tutorial->onPlayerMove_,
				tutorial->onPlayerShot_, tutorial->onBomb_, scene, tutorial->text_);

			if (stage3->clear_->next_ == true) {
				scene = RESET;
			}
		}

		//ステージセレクト
		if (scene == STAGESELECT) {
			stageSelect->Update(keys, preKeys);

			if (stageSelect->GetterBlackT() == 1.0f && stageSelect->GetterInStage1() == true) {
				scene = STAGE1;
			}
			if (stageSelect->GetterBlackT() == 1.0f && stageSelect->GetterInStage2() == true) {
				scene = STAGE2;
			}
			if (stageSelect->GetterBlackT() == 1.0f && stageSelect->GetterInStage3() == true) {
				scene = STAGE3;
			}
		}

		//リセット
		if (scene == RESET) {
			//自機
			player->Initialize();
			//敵
			enemy->Initialize();
			//クリア演出
			clear->Initialize();
			//ステージ1
			stage1->Initialize();
			//ステージ2
			stage2->Initialize();
			//ステージ3
			stage3->Initialize();
			//ステージセレクト
			stageSelect->Initialize();

			scene = STAGESELECT;
		}

		//当たり判定
		//敵の弾と自機の当たり判定
		

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

		//ステージセレクト
		if (scene == STAGESELECT) {
			stageSelect->Draw();
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
