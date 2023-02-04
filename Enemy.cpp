#include "Enemy.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//初期化
void Enemy::Initialize() {
	//何もしない敵
	enemy_.HP[0] = 10;
	enemy_.isAlive[0] = true;
	enemy_.pos[0].X = 640.0f;
	enemy_.pos[0].Y = -40.0f;
	enemy_.radius[0] = 20.0f;
	enemy_.speed[0].X = 0.0f;
	enemy_.speed[0].Y = 10.0f;
	enemy_.color[0] = WHITE;

	//移動する敵
	moveEnemy_.HP[0] = 20;
	moveEnemy_.isAlive[0] = true;
	moveEnemy_.pos[0].X = -30.0f;
	moveEnemy_.pos[0].Y = 358.0f;
	moveEnemy_.radius[0] = 20.0f;
	moveEnemy_.speed[0].X = 5.0f;
	moveEnemy_.speed[0].Y = 3.0f;
	moveEnemy_.color[0] = WHITE;

	for (int i = 1; i < 5; i++) {
		moveEnemy_.HP[i] = 30;
		moveEnemy_.isAlive[i] = true;
		moveEnemy_.radius[i] = 20.0f;
		moveEnemy_.color[i] = WHITE;
	}

	for (int i = 1; i < 3; i++) {
		moveEnemy_.pos[i].Y = -40.0f;
		moveEnemy_.speed[i].X = 0.0f;
		moveEnemy_.speed[i].Y = 5.0f;
	}

	moveEnemy_.pos[1].X = 610.0f;
	moveEnemy_.pos[2].X = 670.0f;

	for (int i = 3; i < 5; i++) {
		moveEnemy_.speed[i].Y = 0.0f;
		moveEnemy_.start[i] = false;
	}

	moveEnemy_.pos[3].X = 305.0f;
	moveEnemy_.pos[3].Y = 300.0f;
	moveEnemy_.speed[3].X = 5.0f;
	moveEnemy_.pos[4].X = 975.0f;
	moveEnemy_.pos[4].Y = 350.0f;
	moveEnemy_.speed[4].X = -5.0f;

	//単発弾を撃つ敵
	for (int i = 0; i < 8; i++) {
		bulletEnemy_.HP[i] = 50;
		bulletEnemy_.isAlive[i] = true;
		bulletEnemy_.radius[i] = 20.0f;
		bulletEnemy_.speed[i].X = 0.0f;
		bulletEnemy_.speed[i].Y = 0.0f;
		bulletEnemy_.color[i] = WHITE;
		bulletEnemy_.t[i] = 0.0f;
		bulletEnemy_.easedT[i] = 0.0f;
		bulletEnemy_.start[i] = false;
	}
	
	bulletEnemy_.pos[0].X = -20.0f;
	bulletEnemy_.pos1[0].X = -20.0f;
	bulletEnemy_.pos2[0].X = 355.0f;
	bulletEnemy_.pos[0].Y = 150.0f;

	bulletEnemy_.pos[1].X = -20.0f;
	bulletEnemy_.pos1[1].X = -20.0f;
	bulletEnemy_.pos2[1].X = 455.0f;
	bulletEnemy_.pos[1].Y = 250.0f;

	bulletEnemy_.pos[2].X = 1220.0f;
	bulletEnemy_.pos1[2].X = 1220.0f;
	bulletEnemy_.pos2[2].X = 925.0f;
	bulletEnemy_.pos[2].Y = 150.0f;

	bulletEnemy_.pos[3].X = 1220.0f;
	bulletEnemy_.pos1[3].X = 1220.0f;
	bulletEnemy_.pos2[3].X = 825.0f;
	bulletEnemy_.pos[3].Y = 250.0f;

	for (int i = 4; i < 6; i++) {
		bulletEnemy_.pos[i].Y = -20.0f;
		bulletEnemy_.pos1[i].Y = -20.0f;
		bulletEnemy_.pos2[i].Y = 250.0f;
	}

	bulletEnemy_.pos[4].X = 540.0f;
	bulletEnemy_.pos1[4].X = 540.0f;
	bulletEnemy_.pos2[4].X = 540.0f;

	bulletEnemy_.pos[5].X = 740.0f;
	bulletEnemy_.pos1[5].X = 740.0f;
	bulletEnemy_.pos2[5].X = 740.0f;

	bulletEnemy_.pos[6].X = 305.0f;
	bulletEnemy_.pos1[6].X = 305.0f;
	bulletEnemy_.pos2[6].X = 345.0f;
	bulletEnemy_.pos[6].Y = 500.0f;
	bulletEnemy_.pos1[6].Y = 500.0f;
	bulletEnemy_.pos2[6].Y = 500.0f;

	bulletEnemy_.pos[7].X = 975.0f;
	bulletEnemy_.pos1[7].X = 975.0f;
	bulletEnemy_.pos2[7].X = 935.0f;
	bulletEnemy_.pos[7].Y = 550.0f;
	bulletEnemy_.pos1[7].Y = 550.0f;
	bulletEnemy_.pos2[7].Y = 550.0f;

	//複数弾を撃つ敵
	for (int i = 0; i < 3; i++) {
		bulletsEnemy_.HP[i] = 70;
		bulletsEnemy_.isAlive[i] = true;
		bulletsEnemy_.radius[i] = 20.0f;
		bulletsEnemy_.speed[i].X = 0.0f;
		bulletsEnemy_.speed[i].Y = 0.0f;
		bulletsEnemy_.color[i] = WHITE;
		bulletsEnemy_.t[i] = 0.0f;
		bulletsEnemy_.easedT[i] = 0.0f;
		bulletEnemy_.start[i] = false;
	}

	bulletsEnemy_.pos[0].X = 640.0f;
	bulletsEnemy_.pos[0].Y = -40.0f;
	bulletsEnemy_.pos1[0].Y = -40.0f;
	bulletsEnemy_.pos2[0].Y = 300.0f;

	for (int i = 1; i < 3; i++) {
		bulletsEnemy_.pos[i].Y = -40.0f;
		bulletsEnemy_.pos1[i].Y = -40.0f;
		bulletsEnemy_.pos2[i].Y = 150.0f;
	}

	bulletsEnemy_.pos[1].X = 600.0f;
	bulletsEnemy_.pos[2].X = 680.0f;

	//弾
	enemyBullet_ = new EnemyBullet();
	enemyBullet_->Initialize();

	enemyCount_ = 0;
}

//更新処理
void Enemy::Update(int scene, int text_) {
	//チュートリアル
	if (scene == 2) {
		if (text_ >= 6) {
			if (moveEnemy_.isAlive[0] == true) {
				//移動
				moveEnemy_.pos[0].X += moveEnemy_.speed[0].X;

				//止める
				if (moveEnemy_.pos[0].X >= 640.0f) {
					moveEnemy_.speed[0].X = 0.0f;
				}

				//HPが0以下になったら死ぬ
				if (moveEnemy_.HP[0] <= 0) {
					moveEnemy_.isAlive[0] = false;
				}
			}
		}
	}

	//ステージ1
	if (scene == 3) {
		enemyCount_++;

		//フェーズ1
		for (int i = 1; i < 3; i++) {
			//移動する敵
			if (moveEnemy_.isAlive[i] == true) {
				if (enemyCount_ >= 30) {
					//移動
					moveEnemy_.pos[i].Y += moveEnemy_.speed[i].Y;
				}

				//止める
				if (moveEnemy_.pos[i].Y >= 150.0f) {
					moveEnemy_.speed[i].Y = 0.0f;
				}

				//HPが0以下になったら死ぬ
				if (moveEnemy_.HP[i] <= 0) {
					moveEnemy_.isAlive[i] = false;
				}
			}
		}

		//フェーズ2
		if (enemyCount_ >= 480) {
			//単発弾を撃つ敵
			for (int i = 0; i < 4; i++) {
				if (bulletEnemy_.isAlive[i] == true) {
					//イージング
					if (bulletEnemy_.t[i] <= 1.0f) {
						bulletEnemy_.t[i] += 1.0f / 30.0f;
					}
					if (bulletEnemy_.t[i] > 1.0f) {
						bulletEnemy_.t[i] = 1.0f;
					}

					bulletEnemy_.easedT[i] = sqrt(1.0f - pow(bulletEnemy_.t[i] - 1.0f, 2.0f));

					bulletEnemy_.pos[i].X = (1.0f - bulletEnemy_.easedT[i]) * bulletEnemy_.pos1[i].X + bulletEnemy_.easedT[i] * bulletEnemy_.pos2[i].X;

					//行動開始フラグをtrueにする
					if (bulletEnemy_.pos[0].X >= bulletEnemy_.pos2[0].X) {
						bulletEnemy_.start[i] = true;
					}

					//行動開始
					if (bulletEnemy_.start[i] == true) {
						//弾の位置を合わせる
						if (enemyBullet_->enemyBullet_.isShot[i] == false) {
							enemyBullet_->enemyBullet_.pos[i].X = bulletEnemy_.pos[i].X;
							enemyBullet_->enemyBullet_.pos[i].Y = bulletEnemy_.pos[i].Y;
							enemyBullet_->enemyBullet_.isShot[i] = true;
						}
					}

					//HPが0以下になったら死ぬ
					if (bulletEnemy_.HP[i] <= 0) {
						bulletEnemy_.isAlive[i] = false;
					}
				}
			}
		}

		//フェーズ3
		if (enemyCount_ >= 2160) {
			//複数弾を撃つ敵
			if (bulletsEnemy_.isAlive[0] == true) {
				//イージング
				if (bulletsEnemy_.t[0] <= 1.0f) {
					bulletsEnemy_.t[0] += 1.0f / 30.0f;
				}
				if (bulletsEnemy_.t[0] > 1.0f) {
					bulletsEnemy_.t[0] = 1.0f;
				}

				bulletsEnemy_.easedT[0] = sqrt(1.0f - pow(bulletsEnemy_.t[0] - 1.0f, 2.0f));

				bulletsEnemy_.pos[0].Y = (1.0f - bulletsEnemy_.easedT[0]) * bulletsEnemy_.pos1[0].Y + bulletsEnemy_.easedT[0] * bulletsEnemy_.pos2[0].Y;

				if (bulletsEnemy_.pos[0].Y == bulletsEnemy_.pos2[0].Y) {
					bulletsEnemy_.start[0] = true;
				}

				//行動開始
				if (bulletsEnemy_.start[0] == true) {
					for (int i = 0; i < 3; i++) {
						if (enemyBullet_->enemyBullets_.isShot[i] == false) {
							enemyBullet_->enemyBullets_.pos[i].X = bulletsEnemy_.pos[0].X;
							enemyBullet_->enemyBullets_.pos[i].Y = bulletsEnemy_.pos[0].Y;
							enemyBullet_->enemyBullets_.isShot[i] = true;
						}
					}
				}

				//HPが0以下になったら死ぬ
				if (bulletsEnemy_.HP[0] <= 0) {
					bulletsEnemy_.isAlive[0] = false;
				}
			}
		}

		//フェーズ4
		if (enemyCount_ >= 2880) {
			//移動する敵
			for (int i = 3; i < 5; i++) {
				if (moveEnemy_.isAlive[i] == true) {
					//移動
					moveEnemy_.pos[i].X += moveEnemy_.speed[i].X;

					//行動開始
					if (moveEnemy_.pos[3].X >= 346.0f) {
						moveEnemy_.start[3] = true;
					}
					if (moveEnemy_.pos[4].X <= 934.0f) {
						moveEnemy_.start[4] = true;
					}

					//反転
					if (moveEnemy_.start[i] == true) {
						if (moveEnemy_.pos[i].X <= 345.0f || moveEnemy_.pos[i].X >= 935.0f) {
							moveEnemy_.speed[i].X *= -1;
						}
					}

					//HPが0以下になったら死ぬ
					if (moveEnemy_.HP[i] <= 0) {
						moveEnemy_.isAlive[i] = false;
					}
				}
			}

			//単発弾を撃つ敵
			for (int i = 4; i < 8; i++) {
				if (bulletEnemy_.isAlive[i] == true) {
					//イージング
					if (bulletEnemy_.t[i] <= 1.0f) {
						bulletEnemy_.t[i] += 1.0f / 30.0f;
					}
					if (bulletEnemy_.t[i] > 1.0f) {
						bulletEnemy_.t[i] = 1.0f;
					}

					bulletEnemy_.easedT[i] = sqrt(1.0f - pow(bulletEnemy_.t[i] - 1.0f, 2.0f));

					bulletEnemy_.pos[i].X = (1.0f - bulletEnemy_.easedT[i]) * bulletEnemy_.pos1[i].X + bulletEnemy_.easedT[i] * bulletEnemy_.pos2[i].X;
					bulletEnemy_.pos[i].Y = (1.0f - bulletEnemy_.easedT[i]) * bulletEnemy_.pos1[i].Y + bulletEnemy_.easedT[i] * bulletEnemy_.pos2[i].Y;

					//行動開始フラグをtrueにする
					if (bulletEnemy_.pos[4].Y >= bulletEnemy_.pos2[4].Y) {
						bulletEnemy_.start[i] = true;
					}

					//行動開始
					if (bulletEnemy_.start[i] == true) {
						//弾の位置を合わせる
						if (enemyBullet_->enemyBullet_.isShot[i] == false) {
							enemyBullet_->enemyBullet_.pos[i].X = bulletEnemy_.pos[i].X;
							enemyBullet_->enemyBullet_.pos[i].Y = bulletEnemy_.pos[i].Y;
							enemyBullet_->enemyBullet_.isShot[i] = true;
						}
					}

					//HPが0以下になったら死ぬ
					if (bulletEnemy_.HP[i] <= 0) {
						bulletEnemy_.isAlive[i] = false;
					}
				}
			}

			//複数弾を撃つ敵
			for (int i = 1; i < 3; i++) {
				//イージング
				if (bulletsEnemy_.t[i] <= 1.0f) {
					bulletsEnemy_.t[i] += 1.0f / 30.0f;
				}
				if (bulletsEnemy_.t[i] > 1.0f) {
					bulletsEnemy_.t[i] = 1.0f;
				}

				bulletsEnemy_.easedT[i] = sqrt(1.0f - pow(bulletsEnemy_.t[i] - 1.0f, 2.0f));

				bulletsEnemy_.pos[i].Y = (1.0f - bulletsEnemy_.easedT[i]) * bulletsEnemy_.pos1[i].Y + bulletsEnemy_.easedT[i] * bulletsEnemy_.pos2[i].Y;

				if (bulletsEnemy_.pos[1].Y == bulletsEnemy_.pos2[1].Y) {
					bulletsEnemy_.start[i] = true;
				}

				//行動開始
				if (bulletsEnemy_.start[i] == true) {
					if (bulletsEnemy_.isAlive[1] == true) {
						for (int j = 3; j < 6; j++) {
							if (enemyBullet_->enemyBullets_.isShot[j] == false) {
								enemyBullet_->enemyBullets_.pos[j].X = bulletsEnemy_.pos[1].X;
								enemyBullet_->enemyBullets_.pos[j].Y = bulletsEnemy_.pos[1].Y;
								enemyBullet_->enemyBullets_.isShot[j] = true;
							}
						}
					}

					if (bulletsEnemy_.isAlive[2] == true) {
						for (int j = 6; j < 9; j++) {
							if (enemyBullet_->enemyBullets_.isShot[j] == false) {
								enemyBullet_->enemyBullets_.pos[j].X = bulletsEnemy_.pos[2].X;
								enemyBullet_->enemyBullets_.pos[j].Y = bulletsEnemy_.pos[2].Y;
								enemyBullet_->enemyBullets_.isShot[j] = true;
							}
						}
					}
				}

				//HPが0以下になったら死ぬ
				if (bulletsEnemy_.HP[i] <= 0) {
					bulletsEnemy_.isAlive[i] = false;
				}
			}
		}

		if (enemyCount_ >= 6480) {
			if (enemy_.isAlive[0] == true) {
				//移動
				enemy_.pos[0].Y += enemy_.speed[0].Y;

				//止める
				if (enemy_.pos[0].Y >= 100.0f) {
					enemy_.speed[0].Y = 0.0f;
				}
			}

			//HPが0以下になったら死ぬ
			if (enemy_.HP[0] <= 0) {
				enemy_.isAlive[0] = false;
			}
		}

		//ステージ2
		if (scene == 4) {

		}

		enemyBullet_->Update();
	}

	//何もしない敵
	/*if (enemy_.isAlive == true) {
	//HPが0以下になったら死ぬ
		if (enemy_.HP <= 0) {
			enemy_.isAlive = false;
		}
	}*/

	//複数弾を撃つ敵
	//if (bulletsEnemy_.isAlive == true) {
	//	enemyBullet_->sCoolTime_++;
	//	if (enemyBullet_->sCoolTime_ > 30) {
	//		enemyBullet_->sCoolTime_ = 0;
	//	}
	//	
	//	//弾の位置を合わせる
	//	if (enemyBullet_->sCoolTime_ == 30) {
	//		for (int i = 0; i < 10; i++) {
	//			if (enemyBullet_->enemyBullets_.isShot[i] == false) {
	//				enemyBullet_->enemyBullets_.isShot[i] = true;
	//				enemyBullet_->enemyBullets_.pos[i].X = bulletsEnemy_.pos.X;
	//				enemyBullet_->enemyBullets_.pos[i].Y = bulletsEnemy_.pos.Y;

	//				break;
	//			}
	//		}
	//	}
	//	enemyBullet_->Update();

	//	//HPが0以下になったら死ぬ
	//	if (bulletsEnemy_.HP <= 0) {
	//		bulletsEnemy_.isAlive = false;
	//		for (int i = 0; i < 10; i++) {
	//			enemyBullet_->enemyBullets_.isShot[i] = false;
	//		}
	//	}
	//}
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
	/*if (moveEnemy_.isAlive == true) {
		moveEnemy_.HP -= playerBulletAttack;
	}*/
}

//単発弾を撃つ敵
void Enemy::BulletEnemyOnCollision(int playerBulletAttack) {
	/*if (bulletEnemy_.isAlive == true) {
		bulletEnemy_.HP -= playerBulletAttack;
	}*/
}

//複数弾を撃つ敵
void Enemy::BulletsEnemyOnCollision(int playerBulletAttack) {/*
	if (bulletsEnemy_.isAlive == true) {
		bulletsEnemy_.HP -= playerBulletAttack;
	}*/
}

//描画処理
void Enemy::Draw(int scene,int enemyTutorial,int enemyBulletImage) {
	//何もしない敵
	/*if (enemy_.isAlive == true) {
		Novice::DrawEllipse(enemy_.pos.X, enemy_.pos.Y, enemy_.radius, enemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}*/

	//移動する敵
	if (scene == 2) {
		for (int i = 0; i < 1; i++) {
			if (moveEnemy_.isAlive[0] == true) {
				//Novice::DrawEllipse(moveEnemy_.pos[0].X, moveEnemy_.pos[0].Y, moveEnemy_.radius[0], moveEnemy_.radius[0], 0.0f, moveEnemy_.color[0], kFillModeSolid);
				Novice::DrawSprite(moveEnemy_.pos[0].X - 20, moveEnemy_.pos[0].Y - 20, enemyTutorial, 1, 1, 0.0f, moveEnemy_.color[0]);
			}
		}
	}

	if (scene == 3) {
		//移動する敵
		for (int i = 1; i < 5; i++) {
			if (moveEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(moveEnemy_.pos[i].X - 20, moveEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, moveEnemy_.color[i]);
			}
		}

		//単発弾を撃つ敵
		for (int i = 0; i < 8; i++) {
			if (bulletEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(bulletEnemy_.pos[i].X - 20, bulletEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, bulletEnemy_.color[i]);
			}
		}

		//複数弾を撃つ敵
		for (int i = 0; i < 3; i++) {
			if (bulletsEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(bulletsEnemy_.pos[i].X - 20, bulletsEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, bulletsEnemy_.color[i]);
			}
		}

		if (enemy_.isAlive[0] == true) {
			Novice::DrawSprite(enemy_.pos[0].X - 20, enemy_.pos[0].Y - 20, enemyTutorial, 1, 1, 0.0f, enemy_.color[0]);
		}
	}

	//単発弾を撃つ敵
	/*if (bulletEnemy_.isAlive == true) {
		Novice::DrawEllipse(bulletEnemy_.pos.X, bulletEnemy_.pos.Y, bulletEnemy_.radius, bulletEnemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}*/

	//複数弾を撃つ敵
	/*if (bulletsEnemy_.isAlive == true) {
		Novice::DrawEllipse(bulletsEnemy_.pos.X, bulletsEnemy_.pos.Y, bulletsEnemy_.radius, bulletsEnemy_.radius, 0.0f, WHITE, kFillModeSolid);
	}*/

	//弾
	enemyBullet_->Draw(enemyBulletImage);

	Novice::ScreenPrintf(0, 0, "%0.0f", bulletEnemy_.pos[0].X);
	Novice::ScreenPrintf(0, 20, "%0.0f", bulletsEnemy_.pos[1].Y);
	if (bulletEnemy_.start[4] == false) {
		Novice::ScreenPrintf(0, 40, "false");
	}
	if (bulletEnemy_.start[4] == true) {
		Novice::ScreenPrintf(0, 40, "true");
	}
}