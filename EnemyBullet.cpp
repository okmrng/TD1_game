#include "EnemyBullet.h"
#include <Novice.h>

//������
void EnemyBullet::Initialize() {
	//�P���e
	/*enemyBullet_.isShot = false;
	enemyBullet_.radius = 8.0f;
	enemyBullet_.speed.X = 7.0f;
	enemyBullet_.speed.Y = 7.0f;
	coolTime_ = 0;*/

	//�����e
	/*for (int i = 0; i < 10; i++) {
		enemyBullets_.isShot[i] = false;
		enemyBullets_.radius[i] = 8.0f;
	}
	enemyBullets_.speed.X = 7.0f;
	enemyBullets_.speed.Y = 7.0f;
	sCoolTime_ = 0;*/
}

//�X�V����
void EnemyBullet::Update() {
	//�P���e
	//�ړ�
	//if (enemyBullet_.isShot == true) {
	//	enemyBullet_.pos.Y += enemyBullet_.speed.Y;

	//	//��ʊO�ɍs������t���O��false�ɂ���
	//	if (enemyBullet_.pos.X <= 317.0f || enemyBullet_.pos.X >= 963.0f || enemyBullet_.pos.Y <= -8.0f || enemyBullet_.pos.Y >= 728.0f) {
	//		enemyBullet_.isShot = false;
	//	}
	//}

	////�t���O��false�ɂȂ�����N�[���^�C�����J�E���g����
	//if (enemyBullet_.isShot == false) {
	//	if (coolTime_ <= 30) {
	//		coolTime_++;
	//	}

	//	//�N�[���^�C���̃J�E���g���I�������t���O�𗧂Ă�
	//	if (coolTime_ >= 30) {
	//		coolTime_ = 0;
	//		enemyBullet_.isShot = true;
	//	}
	//}

	//�����e
	//for (int i = 0; i < 10; i++) {
	//	if (enemyBullets_.isShot[i] == true) {
	//		//�ړ�
	//		enemyBullets_.pos[i].Y += enemyBullets_.speed.Y;

	//		//��ʊO�ɍs������t���O��false�ɂ���
	//		if (enemyBullets_.pos[i].X <= 317.0f || enemyBullets_.pos[i].X >= 963.0f || enemyBullets_.pos[i].Y <= -8.0f || enemyBullets_.pos[i].Y >= 728.0f) {
	//			enemyBullets_.isShot[i] = false;
	//		}
	//	}
	//}
}

//�����蔻��
void EnemyBullet::OnCollition() {
	//enemyBullet_.isShot = false;
}

//�`�揈��
void EnemyBullet::Draw() {
	//�P���e
	/*if (enemyBullet_.isShot == true) {
		Novice::DrawEllipse(enemyBullet_.pos.X, enemyBullet_.pos.Y, enemyBullet_.radius, enemyBullet_.radius, 0.0f, RED, kFillModeSolid);
	}*/

	//�����e
	/*for (int i = 0; i < 10; i++) {
		if (enemyBullets_.isShot[i] == true) {
			Novice::DrawEllipse(enemyBullets_.pos[i].X, enemyBullets_.pos[i].Y, enemyBullets_.radius[i], enemyBullets_.radius[i], 0.0f, RED, kFillModeSolid);
		}
	}*/
}