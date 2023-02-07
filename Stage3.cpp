#include "Stage3.h"
#include <Novice.h>

//初期化
void Stage3::Initialize() {
	admission_ = new Admission();
	admission_->Initialize();

	player_ = new Player();
	player_->Initialize();

	boss_ = new Boss();
	boss_->Initialeze();

	clear_ = new Clear();
	clear_->Initialize();

	//ボム
	player_->SetterBombs(3);
}

//更新処理
void Stage3::Update(char* keys, char* prekeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_,
	bool onBomb_, int scene, int text_) {
	//ステージ入場演出
	admission_->Update();

	if (admission_->GetterPlayStart() == true) {
		boss_->Update();

		if (boss_->start_ == true) {
			player_->Update(keys, prekeys, WASDStile_, directionStile_, onPlayerMove_, onPlayerShot_, onBomb_);
		}
	}
}

//描画処理
void Stage3::Draw(int frameRight, int frameLeft, int plate, int WASDStile_, int directionStule_, int playerWASD, int playerDirection,
	int playerCore, int bombBullet, bool directionStile_, int playerBullet, int scene, int enemytutorial, int enemyBulletImage,
	int clearPlate, int miniBoss, int bossImage, int bossCore) {
	if (admission_->GetterPlayStart() == true) {
		//自機
		player_->Draw(bombBullet, WASDStile_, directionStile_, playerWASD, playerDirection, playerCore, playerBullet);

		//ボス
		boss_->Draw(bossImage, bossCore);
	}

	admission_->Draw(frameRight, frameLeft, plate, WASDStile_, directionStule_, playerWASD, playerDirection, playerCore);
}