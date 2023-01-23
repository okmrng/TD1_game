#pragma once
#include "Admission.h"
#include "Player.h"
#include "Enemy.h"

class Tutorial
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, int scene);

	//�`�揈��
	void Draw(int frameSide, int Plate, bool WASDStile_, bool directionStile_, int tutorialText1, int tutorialText2,
		int tutorialText3Direction, int tutorialText3WASD, int tutorialText4, int tutorialText5, int tutorialText7, int textBox,
		int tutorialText9, int tutorialText10Direction, int tutorialText10WASD, int scene, int tutorialBg);

	//�����o�ϐ�
	//�X�e�[�W���ꉉ�o
	Admission* admission_;

	//���@
	Player* player_;

	//�G
	Enemy* enemy_;

	//�e
	int shotTime_;
	bool isEnemyShot_[5];
	bool isEnemyMove_[5];
	float enemyBulletX_[5];
	float enemyBulletY_[5];
	float enemyBulletR_[5];
	float enmeyBulletSpeed_;

	//�e�L�X�g�t���O
	int text_;
	bool textDisplay_;

	//�e�L�X�g�ʒu
	float textX_;
	float textY_;

	//���̓J�E���g
	int pushCount_;

	//�V�[���J��
	bool next_;

	//���@�ړ��t���O
	bool onPlayerMove_;

	//���@�e���˃t���O
	bool onPlayerShot_;

	//�{���t���O
	bool onBomb_;

	//�����蔻��
	float playerBullet_moveEnemyX_;
	float playerBullet_moveEnemyY_;
	float playerBullet_moveEnemyDis_;

};

