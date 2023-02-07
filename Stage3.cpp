#include "Stage3.h"
#include <Novice.h>

//������
void Stage3::Initialize() {
	admission_ = new Admission();
	admission_->Initialize();

	player_ = new Player();
	player_->Initialize();

	boss_ = new Boss();
	boss_->Initialeze();

	clear_ = new Clear();
	clear_->Initialize();

	//�{��
	player_->SetterBombs(3);
}

//�X�V����
void Stage3::Update(char* keys, char* prekeys, bool WASDStile_, bool directionStile_, bool onPlayerMove_, bool onPlayerShot_,
	bool onBomb_, int scene, int text_) {
	//�X�e�[�W���ꉉ�o
	admission_->Update();

	if (admission_->GetterPlayStart() == true) {
		boss_->Update();

		if (boss_->start_ == true) {
			player_->Update(keys, prekeys, WASDStile_, directionStile_, onPlayerMove_, onPlayerShot_, onBomb_);
		}
	}
}

//�`�揈��
void Stage3::Draw(int frameRight, int frameLeft, int plate, int WASDStile_, int directionStule_, int playerWASD, int playerDirection,
	int playerCore, int bombBullet, bool directionStile_, int playerBullet, int scene, int enemytutorial, int enemyBulletImage,
	int clearPlate, int miniBoss, int bossImage, int bossCore) {
	if (admission_->GetterPlayStart() == true) {
		//���@
		player_->Draw(bombBullet, WASDStile_, directionStile_, playerWASD, playerDirection, playerCore, playerBullet);

		//�{�X
		boss_->Draw(bossImage, bossCore);
	}

	admission_->Draw(frameRight, frameLeft, plate, WASDStile_, directionStule_, playerWASD, playerDirection, playerCore);
}