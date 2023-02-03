#include "Stage1.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
void Stage1::Initialize() {
	admission_ = new Admission();
	admission_->Initialize();

	player_ = new Player();
	player_->Initialize();

	enemy_ = new Enemy();
	enemy_->Initialize();

	clear_ = new Clear();
	clear_->Initialize();
}

//更新処理
void Stage1::Update(char* keys, char* prekeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_,
	bool onBomb_, int scene, int text_) {
	//ステージ入場演出
	admission_->Update();

	if (admission_->GetterPlayStart() == true) {
		//自機操作
		player_->Update(keys, prekeys, WASDStile_, directionStile_, onPlayerMove_, onPlayerShot_, onBomb_);

		//敵
		enemy_->Update(scene, text_);

		//自機の弾との当たり判定
		//移動する敵
		for (int i = 0; i < 15; i++) {
			for (int j = 1; j < 5; j++) {
				float playerBullet_moveEnemyX_ = player_->bullet_->bullet_.pos[i].X - enemy_->moveEnemy_.pos[j].X;
				float playerBullet_moveEnemyY_ = player_->bullet_->bullet_.pos[i].Y - enemy_->moveEnemy_.pos[j].Y;
				float playerBullet_moveEnemyDis_ = sqrtf(playerBullet_moveEnemyX_ * playerBullet_moveEnemyX_ + playerBullet_moveEnemyY_ * playerBullet_moveEnemyY_);

				if (enemy_->moveEnemy_.isAlive[j] == true) {
					if (playerBullet_moveEnemyDis_ < 20.0f) {
						if (player_->bullet_->bullet_.isShot[i] == true) {
							if (enemy_->moveEnemy_.isAlive[j] == true) {
								enemy_->moveEnemy_.HP[j] -= player_->bullet_->bullet_.attack;
								enemy_->moveEnemy_.color[j] = RED;
								player_->bullet_->bullet_.isShot[i] = false;
							}
						}
						else { enemy_->moveEnemy_.color[j] = WHITE; }
					}
				}
			}
		}

		//単発弾を撃つ敵
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 8; j++) {
				float playerBullet_bulletEnemyX_ = player_->bullet_->bullet_.pos[i].X - enemy_->bulletEnemy_.pos[j].X;
				float playerBullet_bulletEnemyY_ = player_->bullet_->bullet_.pos[i].Y - enemy_->bulletEnemy_.pos[j].Y;
				float playerBullet_bulletEnemyDis_ = sqrtf(playerBullet_bulletEnemyX_ * playerBullet_bulletEnemyX_ + playerBullet_bulletEnemyY_ * playerBullet_bulletEnemyY_);

				if (enemy_->bulletEnemy_.isAlive[j] == true) {
					if (playerBullet_bulletEnemyDis_ < 20.0f) {
						if (player_->bullet_->bullet_.isShot[i] == true) {
							if (enemy_->bulletEnemy_.isAlive[j] == true) {
								enemy_->bulletEnemy_.HP[j] -= player_->bullet_->bullet_.attack;
								enemy_->bulletEnemy_.color[j] = RED;
								player_->bullet_->bullet_.isShot[i] = false;
							}
						}
						else { enemy_->bulletEnemy_.color[j] = WHITE; }
					}
				}
			}
		}

		//複数弾を撃つ敵
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 3; j++) {
				float playerBullet_bulletsEnemyX_ = player_->bullet_->bullet_.pos[i].X - enemy_->bulletsEnemy_.pos[j].X;
				float playerBullet_bulletsEnemyY_ = player_->bullet_->bullet_.pos[i].Y - enemy_->bulletsEnemy_.pos[j].Y;
				float playerBullet_bulletsEnemyDis_ = sqrtf(playerBullet_bulletsEnemyX_ * playerBullet_bulletsEnemyX_ + playerBullet_bulletsEnemyY_ * playerBullet_bulletsEnemyY_);

				if (enemy_->bulletsEnemy_.isAlive[j] == true) {
					if (playerBullet_bulletsEnemyDis_ < 20.0f) {
						if (player_->bullet_->bullet_.isShot[i] == true) {
							if (enemy_->bulletsEnemy_.isAlive[j] == true) {
								enemy_->bulletsEnemy_.HP[j] -= player_->bullet_->bullet_.attack;
								enemy_->bulletsEnemy_.color[j] = RED;
								player_->bullet_->bullet_.isShot[i] = false;
							}
						}
						else { enemy_->bulletsEnemy_.color[j] = WHITE; }
					}
				}
			}
		}

		//クリア
		for (int i = 3; i < 5; i++) {
			for (int j = 4; j < 8; j++) {
				for (int k = 1; k < 3; k++) {
					if (enemy_->moveEnemy_.isAlive[i] == false && enemy_->bulletEnemy_.isAlive[j] == false &&
						enemy_->bulletsEnemy_.isAlive[k] == false) {

					}
				}
			}
		}
	}
}

//描画処理
void Stage1::Draw(int frameRight, int frameLeft, int plate, int WASDStile_, int directionStule_, int playerWASD, int playerDirection,
	int playerCore, int bombBullet, bool directionStile_, int playerBullet, int scene, int enemytutorial, int enemyBulletImage) {

	//自機
	if (admission_->GetterPlayStart() == true) {
		player_->Draw(bombBullet, WASDStile_, directionStile_, playerWASD, playerDirection, playerCore, playerBullet);

		//敵
		enemy_->Draw(scene, enemytutorial, enemyBulletImage);
	}

	admission_->Draw(frameRight, frameLeft, plate, WASDStile_, directionStule_, playerWASD, playerDirection, playerCore);

}