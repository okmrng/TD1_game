#include "Stage1.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//‰Šú‰»
void Stage1::Initialize() {
	admission_ = new Admission();
	admission_->Initialize();

	player_ = new Player();
	player_->Initialize();

	enemy_ = new Enemy();
	enemy_->Initialize();

	clear_ = new Clear();
	clear_->Initialize();

	//ƒ{ƒ€
	player_->SetterBombs(3);

	//ƒAƒCƒRƒ“
	HPY_ = -1377.0f;
	HPY1_ = -1377.0f;
	HPY2_ = 97.0f;

	bombY_ = -1491.0f;
	bombY1_ = -1491.0f;
	bombY2_ = 211.0f;

	t_ = 0.0f;

	HP_ = Novice::LoadTexture("./Resources/Images/HP.png");
	bomb_ = Novice::LoadTexture("./Resources/Images/bomb.png");
}

//XVˆ—
void Stage1::Update(char* keys, char* prekeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_,
	bool onBomb_, int scene, int text_) {
	//ƒXƒe[ƒW“üê‰‰o
	admission_->Update();

	if (t_ < 1.0f) {
		t_ += 1.0f / 30.0f;
	}
	if (t_ >= 1.0f) {
		t_ = 1.0f;
	}

	float easedT_ = sqrt(1.0f - pow(t_ - 1.0f, 2.0f));

	HPY_ = (1.0f - easedT_) * HPY1_ + easedT_ * HPY2_;
	bombY_ = (1.0f - easedT_) * bombY1_ + easedT_ * bombY2_;

	if (admission_->GetterPlayStart() == true) {
		//©‹@‘€ì
		player_->Update(keys, prekeys, WASDStile_, directionStile_, onPlayerMove_, onPlayerShot_, onBomb_);

		//“G
		enemy_->Update(scene, text_);

		//ƒ{ƒ€’†’e‚ğÁ‚·
		if (player_->GetterShotBomb() == true) {
			for (int i = 0; i < 8; i++) {
				enemy_->enemyBullet_->enemyBullet_.isShot[i] = false;
			}
			for (int i = 12; i < 14; i++) {
				enemy_->enemyBullet_->enemyBullet_.isShot[i] = false;
			}
			for (int i = 0; i < 3; i++) {
				enemy_->enemyBullet_->enemyBullets_.isShot[i] = false;
			}
			for (int i = 15; i < 24; i++) {
				enemy_->enemyBullet_->enemyBullets_.isShot[i] = false;
			}
			
		}

		//©‹@‚Ì’e‚Æ‚Ì“–‚½‚è”»’è
		//ˆÚ“®‚·‚é“G
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

		//’P”­’e‚ğŒ‚‚Â“G
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

			for (int j = 12; j < 14; j++) {
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

		//•¡”’e‚ğŒ‚‚Â“G
		for (int i = 0; i < 15; i++) {
			float playerBullet_bulletsEnemyX_ = player_->bullet_->bullet_.pos[i].X - enemy_->bulletsEnemy_.pos[0].X;
			float playerBullet_bulletsEnemyY_ = player_->bullet_->bullet_.pos[i].Y - enemy_->bulletsEnemy_.pos[0].Y;
			float playerBullet_bulletsEnemyDis_ = sqrtf(playerBullet_bulletsEnemyX_ * playerBullet_bulletsEnemyX_ + playerBullet_bulletsEnemyY_ * playerBullet_bulletsEnemyY_);

			if (enemy_->bulletsEnemy_.isAlive[0] == true) {
				if (playerBullet_bulletsEnemyDis_ < 20.0f) {
					if (player_->bullet_->bullet_.isShot[i] == true) {
						if (enemy_->bulletsEnemy_.isAlive[0] == true) {
							enemy_->bulletsEnemy_.HP[0] -= player_->bullet_->bullet_.attack;
							enemy_->bulletsEnemy_.color[0] = RED;
							player_->bullet_->bullet_.isShot[i] = false;
						}
					}
					else { enemy_->bulletsEnemy_.color[0] = WHITE; }
				}
			}

			for (int j = 5; j < 8; j++) {
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


		for (int i = 0; i < 15; i++) {
			float playerBullet_enemyX_ = player_->bullet_->bullet_.pos[i].X - enemy_->enemy_.pos[0].X;
			float playerBullet_enemyY_ = player_->bullet_->bullet_.pos[i].Y - enemy_->enemy_.pos[0].Y;
			float playerBullet_enemyDis_ = sqrtf(playerBullet_enemyX_ * playerBullet_enemyX_ + playerBullet_enemyY_ * playerBullet_enemyY_);

			if (enemy_->enemy_.isAlive[0] == true) {
				if (playerBullet_enemyDis_ < 20.0f) {
					if (player_->bullet_->bullet_.isShot[i] == true) {
						if (enemy_->enemy_.isAlive[0] == true) {
							enemy_->enemy_.HP[0] -= player_->bullet_->bullet_.attack;
							enemy_->enemy_.color[0] = RED;
							player_->bullet_->bullet_.isShot[i] = false;
						}
					}
					else { enemy_->enemy_.color[0] = WHITE; }
				}
			}
		}

		//ƒ{ƒ€‚Æ“®‚­“G‚Æ‚Ì“–‚½‚è”»’è
		for (int i = 1; i < 5; i++) {
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

		//ƒ{ƒ€‚Æ’P”­’e‚ğŒ‚‚Â“G
		for (int i = 0; i < 8; i++) {
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

		for (int i = 12; i < 14; i++) {
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

		//ƒ{ƒ€‚Æ•¡”’e‚ğŒ‚‚Â“G
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
		float playerBomb_bulletsEnemyX_ = player_->bombParticle_->GetterCollisionX() - enemy_->bulletsEnemy_.pos[0].X;
		float playerBomb_bulletsEnemyY_ = player_->bombParticle_->GetterCollisionY() - enemy_->bulletsEnemy_.pos[0].Y;
		float playerBomb_bulletsEnemyDis_ = sqrtf(playerBomb_bulletsEnemyX_ * playerBomb_bulletsEnemyX_ + playerBomb_bulletsEnemyY_ * playerBomb_bulletsEnemyY_);

		if (enemy_->bulletsEnemy_.isAlive[0] == true) {
			if (playerBomb_bulletsEnemyDis_ < 60.0f) {
				if (player_->GetterShotBomb() == true) {
					if (enemy_->bulletsEnemy_.isAlive[0] == true) {
						enemy_->bulletsEnemy_.isAlive[0] = false;
					}
				}
			}
		}

		for (int j = 5; j < 8; j++) {
			float playerBomb_bulletsEnemyX_ = player_->bombParticle_->GetterCollisionX() - enemy_->bulletsEnemy_.pos[j].X;
			float playerBomb_bulletsEnemyY_ = player_->bombParticle_->GetterCollisionY() - enemy_->bulletsEnemy_.pos[j].Y;
			float playerBomb_bulletsEnemyDis_ = sqrtf(playerBomb_bulletsEnemyX_ * playerBomb_bulletsEnemyX_ + playerBomb_bulletsEnemyY_ * playerBomb_bulletsEnemyY_);

			if (enemy_->bulletsEnemy_.isAlive[j] == true) {
				if (playerBomb_bulletsEnemyDis_ < 60.0f) {
					if (player_->GetterShotBomb() == true) {
						if (enemy_->bulletsEnemy_.isAlive[j] == true) {
							enemy_->bulletsEnemy_.isAlive[j] = false;
						}
					}
				}
			}
		}

		//©‹@‚Æ“G‚Æ‚Ì“–‚½‚è”»’è
		//“®‚­“G
		for (int i = 1; i < 5; i++) {
			float player_moveEnemyX = player_->GetterPosX() - enemy_->moveEnemy_.pos[i].X;
			float player_moveEnemyY = player_->GetterPosY() - enemy_->moveEnemy_.pos[i].Y;
			float player_moveEnemyDis = sqrtf(player_moveEnemyX * player_moveEnemyX + player_moveEnemyY * player_moveEnemyY);

			if (enemy_->moveEnemy_.isAlive[i] == true) {
				if (player_moveEnemyDis < player_->GetterRadius() + enemy_->moveEnemy_.radius[i]) {
					player_->OnCollision();
				}
			}
		}

		//’P”­’e‚ğŒ‚‚Â“G
		for (int i = 0; i < 8; i++) {
			float player_bulletEnemyX = player_->GetterPosX() - enemy_->bulletEnemy_.pos[i].X;
			float player_bulletEnemyY = player_->GetterPosY() - enemy_->bulletEnemy_.pos[i].Y;
			float player_bulletEnemyDis = sqrtf(player_bulletEnemyX * player_bulletEnemyX + player_bulletEnemyY * player_bulletEnemyY);

			if (enemy_->bulletEnemy_.isAlive[i] == true) {
				if (player_bulletEnemyDis < player_->GetterRadius() + enemy_->bulletEnemy_.radius[i]) {
					player_->OnCollision();
				}
			}
		}
		for (int i = 12; i < 14; i++) {
			float player_bulletEnemyX = player_->GetterPosX() - enemy_->bulletEnemy_.pos[i].X;
			float player_bulletEnemyY = player_->GetterPosY() - enemy_->bulletEnemy_.pos[i].Y;
			float player_bulletEnemyDis = sqrtf(player_bulletEnemyX * player_bulletEnemyX + player_bulletEnemyY * player_bulletEnemyY);

			if (enemy_->bulletEnemy_.isAlive[i] == true) {
				if (player_bulletEnemyDis < player_->GetterRadius() + enemy_->bulletEnemy_.radius[i]) {
					player_->OnCollision();
				}
			}
		}

		//“G‚Ì’e
		for (int i = 0; i < 8; i++) {
			float enemyBullet_playerX = enemy_->enemyBullet_->enemyBullet_.pos[i].X - player_->GetterPosX();
			float enemyBullet_playerY = enemy_->enemyBullet_->enemyBullet_.pos[i].Y - player_->GetterPosY();
			float enemyBullet_playerDis = sqrtf(enemyBullet_playerX * enemyBullet_playerX + enemyBullet_playerY * enemyBullet_playerY);

			if (enemyBullet_playerDis < player_->GetterRadius() + enemy_->enemyBullet_->enemyBullet_.radius[i]) {
				if (enemy_->enemyBullet_->enemyBullet_.isShot[i] == true) {
					player_->OnCollision();
				}
			}
		}
		for (int i = 12; i < 14; i++) {
			float enemyBullet_playerX = enemy_->enemyBullet_->enemyBullet_.pos[i].X - player_->GetterPosX();
			float enemyBullet_playerY = enemy_->enemyBullet_->enemyBullet_.pos[i].Y - player_->GetterPosY();
			float enemyBullet_playerDis = sqrtf(enemyBullet_playerX * enemyBullet_playerX + enemyBullet_playerY * enemyBullet_playerY);

			if (enemyBullet_playerDis < player_->GetterRadius() + enemy_->enemyBullet_->enemyBullet_.radius[i]) {
				if (enemy_->enemyBullet_->enemyBullet_.isShot[i] == true) {
					player_->OnCollision();
				}
			}
		}

		//•¡”’e‚ğŒ‚‚Â“G
		for (int i = 0; i < 5; i++) {
			float player_bulletsEnemyX = player_->GetterPosX() - enemy_->bulletsEnemy_.pos[i].X;
			float player_bulletsEnemyY = player_->GetterPosY() - enemy_->bulletsEnemy_.pos[i].Y;
			float player_bulletsEnemyDis = sqrtf(player_bulletsEnemyX * player_bulletsEnemyX + player_bulletsEnemyY * player_bulletsEnemyY);

			if (enemy_->bulletsEnemy_.isAlive[i] == true) {
				if (player_bulletsEnemyDis < player_->GetterRadius() + enemy_->bulletsEnemy_.radius[i]) {
					player_->OnCollision();
				}
			}
		}
		for (int i = 5; i < 8; i++) {
			float player_bulletsEnemyX = player_->GetterPosX() - enemy_->bulletsEnemy_.pos[i].X;
			float player_bulletsEnemyY = player_->GetterPosY() - enemy_->bulletsEnemy_.pos[i].Y;
			float player_bulletsEnemyDis = sqrtf(player_bulletsEnemyX * player_bulletsEnemyX + player_bulletsEnemyY * player_bulletsEnemyY);

			if (enemy_->bulletsEnemy_.isAlive[i] == true) {
				if (player_bulletsEnemyDis < player_->GetterRadius() + enemy_->bulletsEnemy_.radius[i]) {
					player_->OnCollision();
				}
			}
		}

		//•¡”’e
		for (int i = 0; i < 3; i++) {
			float enemyBullets_playerX = enemy_->enemyBullet_->enemyBullets_.pos[i].X - player_->GetterPosX();
			float enemyBullets_playerY = enemy_->enemyBullet_->enemyBullets_.pos[i].Y - player_->GetterPosY();
			float enemyBullets_playerDis = sqrtf(enemyBullets_playerX * enemyBullets_playerX + enemyBullets_playerY * enemyBullets_playerY);

			if (enemyBullets_playerDis < player_->GetterRadius() + enemy_->enemyBullet_->enemyBullets_.radius[i]) {
				if (enemy_->enemyBullet_->enemyBullets_.isShot[i] == true) {
					player_->OnCollision();
				}
			}
		}
		for (int i = 15; i < 24; i++) {
			float enemyBullets_playerX = enemy_->enemyBullet_->enemyBullets_.pos[i].X - player_->GetterPosX();
			float enemyBullets_playerY = enemy_->enemyBullet_->enemyBullets_.pos[i].Y - player_->GetterPosY();
			float enemyBullets_playerDis = sqrtf(enemyBullets_playerX * enemyBullets_playerX + enemyBullets_playerY * enemyBullets_playerY);

			if (enemyBullets_playerDis < player_->GetterRadius() + enemy_->enemyBullet_->enemyBullets_.radius[i]) {
				if (enemy_->enemyBullet_->enemyBullets_.isShot[i] == true) {
					player_->OnCollision();
				}
			}
		}

		float player_enemyX = player_->GetterPosX() - enemy_->enemy_.pos[0].X;
		float player_enemyY = player_->GetterPosY() - enemy_->enemy_.pos[0].Y;
		float player_enemyDis = sqrtf(player_enemyX * player_enemyX + player_enemyY * player_enemyY);

		if (enemy_->enemy_.isAlive[0] == true) {
			if (player_enemyDis < player_->GetterRadius() + enemy_->enemy_.radius[0]) {
				player_->OnCollision();
			}
		}

		//ƒNƒŠƒA
		if (enemy_->enemy_.isAlive[0] == false) {
			clear_->Update();
		}
	}
}

//•`‰æˆ—
void Stage1::Draw(int frameRight, int frameLeft, int plate, int WASDStile_, int directionStule_, int playerWASD, int playerDirection,
	int playerCore, int bombBullet, bool directionStile_, int playerBullet, int scene, int enemytutorial, int enemyBulletImage,
	int clearPlate, int miniBoss) {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x191970ff, kFillModeSolid);

	//©‹@
	if (admission_->GetterPlayStart() == true) {
		player_->Draw(bombBullet, WASDStile_, directionStile_, playerWASD, playerDirection, playerCore, playerBullet);

		//“G
		enemy_->Draw(scene, enemytutorial, enemyBulletImage, miniBoss);
	}

	admission_->Draw(frameRight, frameLeft, plate, WASDStile_, directionStule_, playerWASD, playerDirection, playerCore);

	if (player_->GetterHP() >= 1) {
		Novice::DrawSprite(1209, HPY_, HP_, 1, 1, 0.0f, WHITE);
	}
	if (player_->GetterHP() >= 2) {
		Novice::DrawSprite(1129, HPY_, HP_, 1, 1, 0.0f, WHITE);
	}
	if (player_->GetterHP() >= 3) {
		Novice::DrawSprite(1049, HPY_, HP_, 1, 1, 0.0f, WHITE);
	}

	if (player_->GetterBombs() >= 1) {
		Novice::DrawSprite(1209, bombY_, bomb_, 1, 1, 0.0f, WHITE);
	}
	if (player_->GetterBombs() >= 2) {
		Novice::DrawSprite(1129, bombY_, bomb_, 1, 1, 0.0f, WHITE);
	}
	if (player_->GetterBombs() >= 3) {
		Novice::DrawSprite(1049, bombY_, bomb_, 1, 1, 0.0f, WHITE);
	}

	clear_->Draw(clearPlate);
}