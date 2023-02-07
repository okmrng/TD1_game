#include "Stage2.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
void Stage2::Initialize() {
	admission_ = new Admission();
	admission_->Initialize();

	player_ = new Player();
	player_->Initialize();

	enemy_ = new Enemy();
	enemy_->Initialize();

	clear_ = new Clear();
	clear_->Initialize();

	//ボム
	player_->SetterBombs(3);
}

//更新処理
void Stage2::Update(char* keys, char* prekeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_,
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
			for (int j = 3; j < 9; j++) {
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
			for (int j = 4; j < 12; j++) {
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
			for (int j = 1; j < 5; j++) {
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

		//中ボス
		for (int i = 0; i < 15; i++) {
			float playerBullet_miniBossX_ = player_->bullet_->bullet_.pos[i].X - enemy_->miniBoss_.pos[0].X;
			float playerBullet_miniBossY_ = player_->bullet_->bullet_.pos[i].Y - enemy_->miniBoss_.pos[0].Y;
			float playerBullet_miniBossDis_ = sqrtf(playerBullet_miniBossX_ * playerBullet_miniBossX_ + playerBullet_miniBossY_ * playerBullet_miniBossY_);

			if (enemy_->miniBoss_.isAlive[0] == true) {
				if (playerBullet_miniBossDis_ < 20.0f) {
					if (player_->bullet_->bullet_.isShot[i] == true) {
						if (enemy_->miniBoss_.isAlive[0] == true) {
							enemy_->miniBoss_.HP[0] -= player_->bullet_->bullet_.attack;
							enemy_->miniBoss_.color[0] = RED;
							player_->bullet_->bullet_.isShot[i] = false;
						}
					}
					else { enemy_->miniBoss_.color[0] = WHITE; }
				}
			}
		}

		//ボムと動く敵との当たり判定
		for (int i = 3; i < 9; i++) {
			float playerBomb_moveEnemyX_ = player_->bombParticle_->GetterCollisionX() - enemy_->moveEnemy_.pos[i].X;
			float playerBomb_moveEnemyY_ = player_->bombParticle_->GetterCollisionY() - enemy_->moveEnemy_.pos[i].Y;
			float playerBomb_moveEnemyDis_ = sqrtf(playerBomb_moveEnemyX_ * playerBomb_moveEnemyX_ + playerBomb_moveEnemyY_ * playerBomb_moveEnemyY_);

			if (enemy_->moveEnemy_.isAlive[i] == true) {
				if (playerBomb_moveEnemyDis_ < 60.0f) {
					if (player_->GetterShotBomb() == true) {
						if (enemy_->moveEnemy_.isAlive[i] == true) {
							enemy_->moveEnemy_.isAlive[i] = false;
						}
					}
				}
			}
		}

		//ボムと単発弾を撃つ敵
		for (int i = 4; i < 12; i++) {
			float playerBomb_bulletEnemyX_ = player_->bombParticle_->GetterCollisionX() - enemy_->bulletEnemy_.pos[i].X;
			float playerBomb_bulletEnemyY_ = player_->bombParticle_->GetterCollisionY() - enemy_->bulletEnemy_.pos[i].Y;
			float playerBomb_bulletEnemyDis_ = sqrtf(playerBomb_bulletEnemyX_ * playerBomb_bulletEnemyX_ + playerBomb_bulletEnemyY_ * playerBomb_bulletEnemyY_);

			if (enemy_->bulletEnemy_.isAlive[i] == true) {
				if (playerBomb_bulletEnemyDis_ < 60.0f) {
					if (player_->GetterShotBomb() == true) {
						if (enemy_->bulletEnemy_.isAlive[i] == true) {
							enemy_->bulletEnemy_.isAlive[i] = false;
						}
					}
				}
			}
		}

		//ボムと複数弾を撃つ敵
		for (int i = 1; i < 5; i++) {
			float playerBomb_bulletsEnemyX_ = player_->bombParticle_->GetterCollisionX() - enemy_->bulletsEnemy_.pos[i].X;
			float playerBomb_bulletsEnemyY_ = player_->bombParticle_->GetterCollisionY() - enemy_->bulletsEnemy_.pos[i].Y;
			float playerBomb_bulletsEnemyDis_ = sqrtf(playerBomb_bulletsEnemyX_ * playerBomb_bulletsEnemyX_ + playerBomb_bulletsEnemyY_ * playerBomb_bulletsEnemyY_);

			if (enemy_->bulletsEnemy_.isAlive[i] == true) {
				if (playerBomb_bulletsEnemyDis_ < 60.0f) {
					if (player_->GetterShotBomb() == true) {
						if (enemy_->bulletsEnemy_.isAlive[i] == true) {
							enemy_->bulletsEnemy_.isAlive[i] = false;
						}
					}
				}
			}
		}

		//ボムと中ボス
		float playerBomb_miniBossX_ = player_->bombParticle_->GetterCollisionX() - enemy_->miniBoss_.pos[0].X;
		float playerBomb_miniBossY_ = player_->bombParticle_->GetterCollisionY() - enemy_->miniBoss_.pos[0].Y;
		float playerBomb_miniBossDis_ = sqrtf(playerBomb_miniBossX_ * playerBomb_miniBossX_ + playerBomb_miniBossY_ * playerBomb_miniBossY_);

		if (enemy_->miniBoss_.isAlive[0] == true) {
			if (playerBomb_miniBossDis_ < 60.0f) {
				if (player_->GetterShotBomb() == true) {
					if (enemy_->miniBoss_.isAlive[0] == true) {
						enemy_->miniBoss_.HP[0] -= 2;
						enemy_->miniBoss_.isAlive[0] = false;
					}
				}
			}
		}

		//クリア
		if (enemy_->miniBoss_.isAlive[0] == false) {
			clear_->Update();
		}
	}
}

//描画処理
void Stage2::Draw(int frameRight, int frameLeft, int plate, int WASDStile_, int directionStule_, int playerWASD, int playerDirection,
	int playerCore, int bombBullet, bool directionStile_, int playerBullet, int scene, int enemytutorial, int enemyBulletImage,
	int clearPlate, int miniBoss) {

	if (admission_->GetterPlayStart() == true) {
		//自機
		player_->Draw(bombBullet, WASDStile_, directionStile_, playerWASD, playerDirection, playerCore, playerBullet);

		//敵
		enemy_->Draw(scene, enemytutorial, enemyBulletImage, miniBoss);
	}

	admission_->Draw(frameRight, frameLeft, plate, WASDStile_, directionStule_, playerWASD, playerDirection, playerCore);

	clear_->Draw(clearPlate);
	Novice::ScreenPrintf(0, 140, "%d", player_->GetterBombs());
}