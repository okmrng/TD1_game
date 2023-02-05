#include "Enemy.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

//������
void Enemy::Initialize() {
	//�������Ȃ��G
	enemy_.HP[0] = 10;
	enemy_.isAlive[0] = true;
	enemy_.pos[0].X = 640.0f;
	enemy_.pos[0].Y = -40.0f;
	enemy_.radius[0] = 20.0f;
	enemy_.speed[0].X = 0.0f;
	enemy_.speed[0].Y = 10.0f;
	enemy_.color[0] = WHITE;

	//�ړ�����G
	moveEnemy_.HP[0] = 20;
	moveEnemy_.isAlive[0] = true;
	moveEnemy_.pos[0].X = -30.0f;
	moveEnemy_.pos[0].Y = 358.0f;
	moveEnemy_.radius[0] = 20.0f;
	moveEnemy_.speed[0].X = 5.0f;
	moveEnemy_.speed[0].Y = 3.0f;
	moveEnemy_.color[0] = WHITE;

	//����
	for (int i = 1; i < 9; i++) {
		moveEnemy_.isAlive[i] = true;
		moveEnemy_.radius[i] = 20.0f;
		moveEnemy_.color[i] = WHITE;
	}

	//�X�e�[�W1
	for (int i = 1; i < 5; i++) {
		moveEnemy_.HP[i] = 30;
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

	//�X�e�[�W2
	for (int i = 5; i < 9; i++) {
		moveEnemy_.HP[i] = 40;
		moveEnemy_.start[i] = false;
	}

	for (int i = 5; i < 7; i++) {
		moveEnemy_.speed[i].X = 0.0f;
	}

	moveEnemy_.pos[5].X = 355.0f;
	moveEnemy_.pos[5].Y = -40.0f;
	moveEnemy_.speed[5].Y = 5.0f;
	moveEnemy_.pos[6].X = 925.0f;
	moveEnemy_.pos[6].Y = 760.0f;
	moveEnemy_.speed[6].Y = -5.0f;

	for (int i = 7; i < 9; i++) {
		moveEnemy_.speed[i].Y = 0.0f;
	}

	moveEnemy_.pos[7].X = 305.0f;
	moveEnemy_.pos[7].Y = 100.0f;
	moveEnemy_.speed[7].X = 5.0f;
	moveEnemy_.pos[8].X = 975.0f;
	moveEnemy_.pos[8].Y = 150.0f;
	moveEnemy_.speed[8].X = -5.0f;

	//�P���e�����G
	//����
	for (int i = 0; i < 14; i++) {
		bulletEnemy_.isAlive[i] = true;
		bulletEnemy_.radius[i] = 20.0f;
		bulletEnemy_.color[i] = WHITE;
		bulletEnemy_.t[i] = 0.0f;
		bulletEnemy_.easedT[i] = 0.0f;
		bulletEnemy_.start[i] = false;
	}

	//�X�e�[�W1
	for (int i = 0; i < 8; i++) {
		bulletEnemy_.HP[i] = 50;
		bulletEnemy_.speed[i].X = 0.0f;
		bulletEnemy_.speed[i].Y = 0.0f;
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

	//�X�e�[�W2
	for (int i = 8; i < 14; i++) {
		bulletEnemy_.HP[i] = 60;
		bulletEnemy_.start[i] = false;
	}

	for (int i = 8; i < 12; i++) {
		bulletEnemy_.pos[i].Y = 200.0f;
	}

	bulletEnemy_.pos[8].X = 305.0f;
	bulletEnemy_.pos[9].X = 255.0f;

	for (int i = 8; i < 10; i++) {
		bulletEnemy_.speed[i].X = 5.0f;
	}

	bulletEnemy_.pos[10].X = 975.0f;
	bulletEnemy_.pos[11].X = 1025.0f;

	for (int i = 10; i < 12; i++) {
		bulletEnemy_.speed[i].X = -5.0f;
	}

	bulletEnemy_.pos[12].X = 345.0f;
	bulletEnemy_.pos[12].Y = -40.0f;
	bulletEnemy_.pos1[12].Y = -40.0f;
	bulletEnemy_.pos2[12].Y = 340.0f;
	bulletEnemy_.pos[13].X = 935.0f;
	bulletEnemy_.pos[13].Y = 760.0f;
	bulletEnemy_.pos1[13].Y = 760.0f;
	bulletEnemy_.pos2[13].Y = 560.0f;

	//�����e�����G
	//����
	for (int i = 0; i < 8; i++) {
		bulletsEnemy_.isAlive[i] = true;
		bulletsEnemy_.radius[i] = 20.0f;
		bulletsEnemy_.speed[i].X = 0.0f;
		bulletsEnemy_.speed[i].Y = 0.0f;
		bulletsEnemy_.color[i] = WHITE;
		bulletsEnemy_.t[i] = 0.0f;
		bulletsEnemy_.easedT[i] = 0.0f;
		bulletEnemy_.start[i] = false;
	}

	//�X�e�[�W1
	for (int i = 0; i < 3; i++) {
		bulletsEnemy_.HP[i] = 70;
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

	//�X�e�[�W2
	for (int i = 3; i < 8; i++) {
		bulletsEnemy_.HP[i] = 80;
		bulletsEnemy_.pos[i].Y = -40.0f;
		bulletsEnemy_.pos1[i].Y = -40.0f;
		bulletsEnemy_.pos2[i].Y = 350.0f;
	}

	bulletsEnemy_.pos[3].X = 600.0f;
	bulletsEnemy_.pos[4].X = 680.0f;

	for (int i = 5; i < 7; i++) {
		bulletsEnemy_.pos[i].Y = 400.0f;
		bulletsEnemy_.pos1[i].Y = 400.0f;
		bulletsEnemy_.pos2[i].Y = 400.0f;
	}

	bulletsEnemy_.pos[5].X = 305.0f;
	bulletsEnemy_.pos1[5].X = 305.0f;
	bulletsEnemy_.pos2[5].X = 450.0f;

	bulletsEnemy_.pos[6].X = 975.0f;
	bulletsEnemy_.pos1[6].X = 975.0f;
	bulletsEnemy_.pos2[6].X = 835.0f;

	bulletsEnemy_.pos[7].X = 640.0f;
	bulletsEnemy_.pos1[7].X = 640.0f;
	bulletsEnemy_.pos2[7].X = 640.0f;
	bulletsEnemy_.pos[7].Y = -40.0f;
	bulletsEnemy_.pos1[7].Y = -40.0f;
	bulletsEnemy_.pos2[7].Y = 150.0f;

	//�{���Q�b�g�ł���G
	bombEnemy_.HP[0] = 70;
	bombEnemy_.pos[0].X = 640.0f;
	bombEnemy_.pos[0].Y = -40.0f;
	bombEnemy_.speed[0].Y = 10.0f;
	bombEnemy_.theta[0] = 0.0f;
	bombEnemy_.amplitude[0] = 10.0f;
	bombEnemy_.start[0] = false;
	bombEnemy_.isAlive[0] = true;

	//�e
	enemyBullet_ = new EnemyBullet();
	enemyBullet_->Initialize();

	enemyCount_ = 0;
}

//�X�V����
void Enemy::Update(int scene, int text_) {
	//�`���[�g���A��
	if (scene == 2) {
		if (text_ >= 6) {
			if (moveEnemy_.isAlive[0] == true) {
				//�ړ�
				moveEnemy_.pos[0].X += moveEnemy_.speed[0].X;

				//�~�߂�
				if (moveEnemy_.pos[0].X >= 640.0f) {
					moveEnemy_.speed[0].X = 0.0f;
				}

				//HP��0�ȉ��ɂȂ����玀��
				if (moveEnemy_.HP[0] <= 0) {
					moveEnemy_.isAlive[0] = false;
				}
			}
		}
	}

	//�X�e�[�W1
	if (scene == 3) {
		enemyCount_++;

		//�t�F�[�Y1
		for (int i = 1; i < 3; i++) {
			//�ړ�����G
			if (moveEnemy_.isAlive[i] == true) {
				if (enemyCount_ >= 30) {
					//�ړ�
					moveEnemy_.pos[i].Y += moveEnemy_.speed[i].Y;
				}

				//�~�߂�
				if (moveEnemy_.pos[i].Y >= 150.0f) {
					moveEnemy_.speed[i].Y = 0.0f;
				}

				//HP��0�ȉ��ɂȂ����玀��
				if (moveEnemy_.HP[i] <= 0) {
					moveEnemy_.isAlive[i] = false;
				}
			}
		}

		//�t�F�[�Y2
		if (enemyCount_ >= 480) {
			//�P���e�����G
			for (int i = 0; i < 4; i++) {
				if (bulletEnemy_.isAlive[i] == true) {
					//�C�[�W���O
					if (bulletEnemy_.t[i] <= 1.0f) {
						bulletEnemy_.t[i] += 1.0f / 30.0f;
					}
					if (bulletEnemy_.t[i] > 1.0f) {
						bulletEnemy_.t[i] = 1.0f;
					}

					bulletEnemy_.easedT[i] = sqrt(1.0f - pow(bulletEnemy_.t[i] - 1.0f, 2.0f));

					bulletEnemy_.pos[i].X = (1.0f - bulletEnemy_.easedT[i]) * bulletEnemy_.pos1[i].X + bulletEnemy_.easedT[i] * bulletEnemy_.pos2[i].X;

					//�s���J�n�t���O��true�ɂ���
					if (bulletEnemy_.pos[0].X >= bulletEnemy_.pos2[0].X) {
						bulletEnemy_.start[i] = true;
					}

					//�s���J�n
					if (bulletEnemy_.start[i] == true) {
						//�e�̈ʒu�����킹��
						if (enemyBullet_->enemyBullet_.isShot[i] == false) {
							enemyBullet_->enemyBullet_.pos[i].X = bulletEnemy_.pos[i].X;
							enemyBullet_->enemyBullet_.pos[i].Y = bulletEnemy_.pos[i].Y;
							enemyBullet_->enemyBullet_.isShot[i] = true;
						}
					}

					//HP��0�ȉ��ɂȂ����玀��
					if (bulletEnemy_.HP[i] <= 0) {
						bulletEnemy_.isAlive[i] = false;
					}
				}
			}
		}

		//�t�F�[�Y3
		if (enemyCount_ >= 2160) {
			//�����e�����G
			if (bulletsEnemy_.isAlive[0] == true) {
				//�C�[�W���O
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

				//�s���J�n
				if (bulletsEnemy_.start[0] == true) {
					for (int i = 0; i < 3; i++) {
						if (enemyBullet_->enemyBullets_.isShot[i] == false) {
							enemyBullet_->enemyBullets_.pos[i].X = bulletsEnemy_.pos[0].X;
							enemyBullet_->enemyBullets_.pos[i].Y = bulletsEnemy_.pos[0].Y;
							enemyBullet_->enemyBullets_.isShot[i] = true;
						}
					}
				}

				//HP��0�ȉ��ɂȂ����玀��
				if (bulletsEnemy_.HP[0] <= 0) {
					bulletsEnemy_.isAlive[0] = false;
				}
			}
		}

		//�t�F�[�Y4
		if (enemyCount_ >= 2880) {
			//�P���e�����G
			for (int i = 12; i < 14; i++) {
				if (bulletEnemy_.isAlive[i] == true) {
					//�C�[�W���O
					if (bulletEnemy_.t[i] <= 1.0f) {
						bulletEnemy_.t[i] += 1.0f / 30.0f;
					}
					if (bulletEnemy_.t[i] > 1.0f) {
						bulletEnemy_.t[i] = 1.0f;
					}

					bulletEnemy_.easedT[i] = sqrt(1.0f - pow(bulletEnemy_.t[i] - 1.0f, 2.0f));

					bulletEnemy_.pos[i].Y = (1.0f - bulletEnemy_.easedT[i]) * bulletEnemy_.pos1[i].Y + bulletEnemy_.easedT[i] * bulletEnemy_.pos2[i].Y;


					if (bulletEnemy_.pos[13].Y >= bulletEnemy_.pos2[13].Y) {
						bulletEnemy_.start[i] = true;
					}

					//�s���J�n
					if (bulletEnemy_.start[i] == true) {
						//�e�̈ʒu�����킹��
						if (enemyBullet_->enemyBullet_.isShot[i] == false) {
							enemyBullet_->enemyBullet_.pos[i].X = bulletEnemy_.pos[i].X;
							enemyBullet_->enemyBullet_.pos[i].Y = bulletEnemy_.pos[i].Y;
							enemyBullet_->enemyBullet_.isShot[i] = true;
						}
					}
				}

				//HP��0�ȉ��ɂȂ����玀��
				if (bulletEnemy_.HP[i] <= 0) {
					bulletEnemy_.isAlive[i] = false;
				}
			}

			//�����e�����G
			for (int i = 5; i < 8; i++) {
				//�C�[�W���O
				if (bulletsEnemy_.t[i] <= 1.0f) {
					bulletsEnemy_.t[i] += 1.0f / 30.0f;
				}
				if (bulletsEnemy_.t[i] > 1.0f) {
					bulletsEnemy_.t[i] = 1.0f;
				}

				bulletsEnemy_.easedT[i] = sqrt(1.0f - pow(bulletsEnemy_.t[i] - 1.0f, 2.0f));

				bulletsEnemy_.pos[i].X = (1.0f - bulletsEnemy_.easedT[i]) * bulletsEnemy_.pos1[i].X + bulletsEnemy_.easedT[i] * bulletsEnemy_.pos2[i].X;
				bulletsEnemy_.pos[i].Y = (1.0f - bulletsEnemy_.easedT[i]) * bulletsEnemy_.pos1[i].Y + bulletsEnemy_.easedT[i] * bulletsEnemy_.pos2[i].Y;

				if (bulletsEnemy_.pos[7].Y == bulletsEnemy_.pos2[7].Y) {
					bulletsEnemy_.start[i] = true;
				}

				//�s���J�n
				if (bulletsEnemy_.start[i] == true) {
					if (bulletsEnemy_.isAlive[5] == true) {
						for (int j = 15; j < 18; j++) {
							if (enemyBullet_->enemyBullets_.isShot[j] == false) {
								enemyBullet_->enemyBullets_.pos[j].X = bulletsEnemy_.pos[5].X;
								enemyBullet_->enemyBullets_.pos[j].Y = bulletsEnemy_.pos[5].Y;
								enemyBullet_->enemyBullets_.isShot[j] = true;
							}
						}
					}

					if (bulletsEnemy_.isAlive[6] == true) {
						for (int j = 18; j < 21; j++) {
							if (enemyBullet_->enemyBullets_.isShot[j] == false) {
								enemyBullet_->enemyBullets_.pos[j].X = bulletsEnemy_.pos[6].X;
								enemyBullet_->enemyBullets_.pos[j].Y = bulletsEnemy_.pos[6].Y;
								enemyBullet_->enemyBullets_.isShot[j] = true;
							}
						}
					}

					if (bulletsEnemy_.isAlive[7] == true) {
						for (int j = 21; j < 24; j++) {
							if (enemyBullet_->enemyBullets_.isShot[j] == false) {
								enemyBullet_->enemyBullets_.pos[j].X = bulletsEnemy_.pos[7].X;
								enemyBullet_->enemyBullets_.pos[j].Y = bulletsEnemy_.pos[7].Y;
								enemyBullet_->enemyBullets_.isShot[j] = true;
							}
						}
					}
				}

				//HP��0�ȉ��ɂȂ����玀��
				if (bulletsEnemy_.HP[i] <= 0) {
					bulletsEnemy_.isAlive[i] = false;
				}
			}
		}
		
		if (enemyCount_ >= 5580) {
			if (enemy_.isAlive[0] == true) {
				//�ړ�
				enemy_.pos[0].Y += enemy_.speed[0].Y;

				//�~�߂�
				if (enemy_.pos[0].Y >= 100.0f) {
					enemy_.speed[0].Y = 0.0f;
				}
			}

			//HP��0�ȉ��ɂȂ����玀��
			if (enemy_.HP[0] <= 0) {
				enemy_.isAlive[0] = false;
			}
		}

	}

	//�X�e�[�W2
	if (scene == 4) {
		enemyCount_++;

		//�t�F�[�Y1
		//�ړ�����G
		for (int i = 5; i < 7; i++) {
			if (moveEnemy_.isAlive[i] == true) {
				//�ړ�
				moveEnemy_.pos[i].Y += moveEnemy_.speed[i].Y;

				//�s���J�n
				if (moveEnemy_.pos[5].Y >= 21.0f) {
					moveEnemy_.start[5] = true;
				}
				if (moveEnemy_.pos[6].Y <= 699.0f) {
					moveEnemy_.start[6] = true;
				}

				//���]
				if (moveEnemy_.start[i] == true) {
					if (moveEnemy_.pos[i].Y <= 20.0f || moveEnemy_.pos[i].Y >= 700.0f) {
						moveEnemy_.speed[i].Y *= -1;
					}
				}

				//HP��0�ȉ��ɂȂ����玀��
				if (moveEnemy_.HP[i] <= 0) {
					moveEnemy_.isAlive[i] = false;
				}
			}
		}

		for (int i = 7; i < 9; i++) {
			if (moveEnemy_.isAlive[i] == true) {
				//�ړ�
				moveEnemy_.pos[i].X += moveEnemy_.speed[i].X;

				//�s���J�n
				if (moveEnemy_.pos[7].X >= 346.0f) {
					moveEnemy_.start[7] = true;
				}
				if (moveEnemy_.pos[8].X <= 934.0f) {
					moveEnemy_.start[8] = true;
				}

				//���]
				if (moveEnemy_.start[i] == true) {
					if (moveEnemy_.pos[i].X <= 345.0f || moveEnemy_.pos[i].X >= 935.0f) {
						moveEnemy_.speed[i].X *= -1;
					}
				}

				//HP��0�ȉ��ɂȂ����玀��
				if (moveEnemy_.HP[i] <= 0) {
					moveEnemy_.isAlive[i] = false;
				}
			}
		}

		//�t�F�[�Y2
		if (enemyCount_ >= 2100) {
			//�{���Q�b�g�ł���G
			if (bombEnemy_.isAlive[0] == true) {
				//��ʓ��܂ňړ�
				if (bombEnemy_.start[0] == false) {
					bombEnemy_.pos[0].Y += bombEnemy_.speed[0].Y;

					if (bombEnemy_.pos[0].Y >= 100.0f) {
						bombEnemy_.speed[0].Y = 0.0f;
						bombEnemy_.start[0] = true;
					}
				}

				//�g
				if (bombEnemy_.start[0] == true) {
					bombEnemy_.pos[0].Y = sinf(bombEnemy_.theta[0]) * bombEnemy_.amplitude[0] + 100.0f;
					bombEnemy_.theta[0] += M_PI / 60.0f;
				}

				if (bombEnemy_.HP[0] <= 0) {
					bombEnemy_.isAlive[0] = false;
				}
			}

			//�P���e�����G
			for (int i = 8; i < 12; i++) {
				if (bulletEnemy_.isAlive[i] == true) {
					//�ړ�
					bulletEnemy_.pos[i].X += bulletEnemy_.speed[i].X;

					if (bulletEnemy_.pos[9].X >= 346.0f) {
						bulletEnemy_.start[i] = true;
					}

					//���]
					if (bulletEnemy_.start[i] == true) {
						if (bulletEnemy_.pos[i].X <= 345.0f || bulletEnemy_.pos[i].X >= 935.0f) {
							bulletEnemy_.speed[i].X *= -1;
						}
					}

					//�s���J�n
					if (bulletEnemy_.start[i] == true) {
						//�e�̈ʒu�����킹��
						if (enemyBullet_->enemyBullet_.isShot[i] == false) {
							enemyBullet_->enemyBullet_.pos[i].X = bulletEnemy_.pos[i].X;
							enemyBullet_->enemyBullet_.pos[i].Y = bulletEnemy_.pos[i].Y;
							enemyBullet_->enemyBullet_.isShot[i] = true;
						}
					}

					//HP��0�ȉ��ɂȂ����玀��
					if (bulletEnemy_.HP[i] <= 0) {
						bulletEnemy_.isAlive[i] = false;
					}
				}
			}
		}

		//�t�F�[�Y3
		if (enemyCount_ >= 4500) {
			//�����e�����G
			for (int i = 3; i < 5; i++) {
				//�C�[�W���O
				if (bulletsEnemy_.t[i] <= 1.0f) {
					bulletsEnemy_.t[i] += 1.0f / 30.0f;
				}
				if (bulletsEnemy_.t[i] > 1.0f) {
					bulletsEnemy_.t[i] = 1.0f;
				}

				bulletsEnemy_.easedT[i] = sqrt(1.0f - pow(bulletsEnemy_.t[i] - 1.0f, 2.0f));

				bulletsEnemy_.pos[i].Y = (1.0f - bulletsEnemy_.easedT[i]) * bulletsEnemy_.pos1[i].Y + bulletsEnemy_.easedT[i] * bulletsEnemy_.pos2[i].Y;

				if (bulletsEnemy_.pos[3].Y == bulletsEnemy_.pos2[3].Y) {
					bulletsEnemy_.start[i] = true;
				}

				//�s���J�n
				if (bulletsEnemy_.start[i] == true) {
					if (bulletsEnemy_.isAlive[3] == true) {
						for (int j = 9; j < 12; j++) {
							if (enemyBullet_->enemyBullets_.isShot[j] == false) {
								enemyBullet_->enemyBullets_.pos[j].X = bulletsEnemy_.pos[3].X;
								enemyBullet_->enemyBullets_.pos[j].Y = bulletsEnemy_.pos[3].Y;
								enemyBullet_->enemyBullets_.isShot[j] = true;
							}
						}
					}

					if (bulletsEnemy_.isAlive[4] == true) {
						for (int j = 12; j < 15; j++) {
							if (enemyBullet_->enemyBullets_.isShot[j] == false) {
								enemyBullet_->enemyBullets_.pos[j].X = bulletsEnemy_.pos[4].X;
								enemyBullet_->enemyBullets_.pos[j].Y = bulletsEnemy_.pos[4].Y;
								enemyBullet_->enemyBullets_.isShot[j] = true;
							}
						}
					}
				}

				//HP��0�ȉ��ɂȂ����玀��
				if (bulletsEnemy_.HP[i] <= 0) {
					bulletsEnemy_.isAlive[i] = false;
				}
			}
		}

		//�t�F�[�Y4
		if (enemyCount_ >= 5700) {
			//�ړ�����G
			for (int i = 3; i < 5; i++) {
				if (moveEnemy_.isAlive[i] == true) {
					//�ړ�
					moveEnemy_.pos[i].X += moveEnemy_.speed[i].X;

					//�s���J�n
					if (moveEnemy_.pos[3].X >= 346.0f) {
						moveEnemy_.start[3] = true;
					}
					if (moveEnemy_.pos[4].X <= 934.0f) {
						moveEnemy_.start[4] = true;
					}

					//���]
					if (moveEnemy_.start[i] == true) {
						if (moveEnemy_.pos[i].X <= 345.0f || moveEnemy_.pos[i].X >= 935.0f) {
							moveEnemy_.speed[i].X *= -1;
						}
					}

					//HP��0�ȉ��ɂȂ����玀��
					if (moveEnemy_.HP[i] <= 0) {
						moveEnemy_.isAlive[i] = false;
					}
				}
			}

			//�P���e�����G
			for (int i = 4; i < 8; i++) {
				if (bulletEnemy_.isAlive[i] == true) {
					//�C�[�W���O
					if (bulletEnemy_.t[i] <= 1.0f) {
						bulletEnemy_.t[i] += 1.0f / 30.0f;
					}
					if (bulletEnemy_.t[i] > 1.0f) {
						bulletEnemy_.t[i] = 1.0f;
					}

					bulletEnemy_.easedT[i] = sqrt(1.0f - pow(bulletEnemy_.t[i] - 1.0f, 2.0f));

					bulletEnemy_.pos[i].X = (1.0f - bulletEnemy_.easedT[i]) * bulletEnemy_.pos1[i].X + bulletEnemy_.easedT[i] * bulletEnemy_.pos2[i].X;
					bulletEnemy_.pos[i].Y = (1.0f - bulletEnemy_.easedT[i]) * bulletEnemy_.pos1[i].Y + bulletEnemy_.easedT[i] * bulletEnemy_.pos2[i].Y;

					//�s���J�n�t���O��true�ɂ���
					if (bulletEnemy_.pos[4].Y >= bulletEnemy_.pos2[4].Y) {
						bulletEnemy_.start[i] = true;
					}

					//�s���J�n
					if (bulletEnemy_.start[i] == true) {
						//�e�̈ʒu�����킹��
						if (enemyBullet_->enemyBullet_.isShot[i] == false) {
							enemyBullet_->enemyBullet_.pos[i].X = bulletEnemy_.pos[i].X;
							enemyBullet_->enemyBullet_.pos[i].Y = bulletEnemy_.pos[i].Y;
							enemyBullet_->enemyBullet_.isShot[i] = true;
						}
					}

					//HP��0�ȉ��ɂȂ����玀��
					if (bulletEnemy_.HP[i] <= 0) {
						bulletEnemy_.isAlive[i] = false;
					}
				}
			}

			//�����e�����G
			for (int i = 1; i < 3; i++) {
				//�C�[�W���O
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

				//�s���J�n
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

				//HP��0�ȉ��ɂȂ����玀��
				if (bulletsEnemy_.HP[i] <= 0) {
					bulletsEnemy_.isAlive[i] = false;
				}
			}
		}

		//�t�F�[�Y5
		if (enemyCount_ >= 9300) {

		}
	}

	enemyBullet_->Update();
}

//�`�揈��
void Enemy::Draw(int scene,int enemyTutorial,int enemyBulletImage) {

	//�`���[�g���A��
	if (scene == 2) {
		//�ړ�����G
		for (int i = 0; i < 1; i++) {
			if (moveEnemy_.isAlive[0] == true) {
				//Novice::DrawEllipse(moveEnemy_.pos[0].X, moveEnemy_.pos[0].Y, moveEnemy_.radius[0], moveEnemy_.radius[0], 0.0f, moveEnemy_.color[0], kFillModeSolid);
				Novice::DrawSprite(moveEnemy_.pos[0].X - 20, moveEnemy_.pos[0].Y - 20, enemyTutorial, 1, 1, 0.0f, moveEnemy_.color[0]);
			}
		}
	}

	//�X�e�[�W1
	if (scene == 3) {
		//�ړ�����G
		for (int i = 1; i < 5; i++) {
			if (moveEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(moveEnemy_.pos[i].X - 20, moveEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, moveEnemy_.color[i]);
			}
		}

		//�P���e�����G
		for (int i = 0; i < 4; i++) {
			if (bulletEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(bulletEnemy_.pos[i].X - 20, bulletEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, bulletEnemy_.color[i]);
			}
		}
		for (int i = 12; i < 14; i++) {
			if (bulletEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(bulletEnemy_.pos[i].X - 20, bulletEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, bulletEnemy_.color[i]);
			}
		}

		//�����e�����G
		if (bulletsEnemy_.isAlive[0] == true) {
			Novice::DrawSprite(bulletsEnemy_.pos[0].X - 20, bulletsEnemy_.pos[0].Y - 20, enemyTutorial, 1, 1, 0.0f, bulletsEnemy_.color[0]);
		}
		for (int i = 5; i < 8; i++) {
			if (bulletsEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(bulletsEnemy_.pos[i].X - 20, bulletsEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, bulletsEnemy_.color[i]);
			}
		}

		if (enemy_.isAlive[0] == true) {
			Novice::DrawSprite(enemy_.pos[0].X - 20, enemy_.pos[0].Y - 20, enemyTutorial, 1, 1, 0.0f, enemy_.color[0]);
		}
	}

	//�X�e�[�W2
	if (scene == 4) {
		//�ړ�����G
		for (int i = 3; i < 9; i++) {
			if (moveEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(moveEnemy_.pos[i].X - 20, moveEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, moveEnemy_.color[i]);
			}
		}

		//�P���e�����G
		for (int i = 4; i < 12; i++) {
			if (bulletEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(bulletEnemy_.pos[i].X - 20, bulletEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, bulletEnemy_.color[i]);
			}
		}

		//�����e�����G
		for (int i = 1; i < 5; i++) {
			if (bulletsEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(bulletsEnemy_.pos[i].X - 20, bulletsEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, bulletsEnemy_.color[i]);
			}
		}

		//�{���Q�b�g�ł���G
		for (int i = 0; i < 1; i++) {
			if (bombEnemy_.isAlive[i] == true) {
				Novice::DrawSprite(bombEnemy_.pos[i].X - 20, bombEnemy_.pos[i].Y - 20, enemyTutorial, 1, 1, 0.0f, bombEnemy_.color[i]);
			}
		}
	}

	//�e
	enemyBullet_->Draw(enemyBulletImage);

	/*if (bulletsEnemy_.start[6] == true) {
		Novice::ScreenPrintf(0, 20, "true");
	}
	if (bulletsEnemy_.start[6] == false) {
		Novice::ScreenPrintf(0, 20, "false");
	}*/
	
}