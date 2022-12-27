#include "EnemyBullet.h"
#include <Novice.h>

//������
void EnemyBullet::Intialize() {
	enemyBullet_.isShot = false;
	enemyBullet_.radius = 8.0f;
	enemyBullet_.speed.X = 7.0f;
	enemyBullet_.speed.Y = 7.0f;
	coolTime = 0;
}

//�X�V����
void EnemyBullet::Update() {
	//�ړ�
	if (enemyBullet_.isShot == true) {
		enemyBullet_.pos.Y += enemyBullet_.speed.Y;

		//��ʊO�ɍs������t���O��false�ɂ���
		if (enemyBullet_.pos.X <= 317.0f || enemyBullet_.pos.X >= 963.0f || enemyBullet_.pos.Y <= -8.0f || enemyBullet_.pos.Y >= 728.0f) {
			enemyBullet_.isShot = false;
		}
	}

	//�t���O��false�ɂȂ�����N�[���^�C�����J�E���g����
	if (enemyBullet_.isShot == false) {
		if (coolTime <= 30) {
			coolTime++;
		}

		//�N�[���^�C���̃J�E���g���I�������t���O�𗧂Ă�
		if (coolTime >= 30) {
			coolTime = 0;
			enemyBullet_.isShot = true;
		}
	}
}

//�����蔻��
void EnemyBullet::OnCollition() {
	enemyBullet_.isShot = false;
}

//�`�揈��
void EnemyBullet::Draw() {
	Novice::DrawEllipse(enemyBullet_.pos.X, enemyBullet_.pos.Y, enemyBullet_.radius, enemyBullet_.radius, 0.0f, RED, kFillModeSolid);
}