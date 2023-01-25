#pragma once
#include "Admission.h"
#include "Player.h"
#include "Enemy.h"
#include "Clear.h"

/// <summary>
/// �`���[�g���A��
/// </summary>
class Tutorial
{
public:
	//�����o�֐�
	
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="keys"></param>
	/// <param name="preKeys"></param>
	/// <param name="WASDStile_"></param>
	/// <param name="directionStile_"></param>
	/// <param name="scene"></param>
	void Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, int scene);

	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <param name="frameSide"></param>
	/// <param name="Plate"></param>
	/// <param name="WASDStile_"></param>
	/// <param name="directionStile_"></param>
	/// <param name="tutorialText1"></param>
	/// <param name="tutorialText2"></param>
	/// <param name="tutorialText3Direction"></param>
	/// <param name="tutorialText3WASD"></param>
	/// <param name="tutorialText4"></param>
	/// <param name="tutorialText5"></param>
	/// <param name="tutorialText7"></param>
	/// <param name="textBox"></param>
	/// <param name="tutorialText9"></param>
	/// <param name="tutorialText10Direction"></param>
	/// <param name="tutorialText10WASD"></param>
	/// <param name="scene"></param>
	/// <param name="tutorialBg"></param>
	void Draw(int frameSide, int Plate, bool WASDStile_, bool directionStile_, int tutorialText1, int tutorialText2,
		int tutorialText3Direction, int tutorialText3WASD, int tutorialText4, int tutorialText5, int tutorialText7, int textBox,
		int tutorialText9, int tutorialText10Direction, int tutorialText10WASD, int tutorialText11, int tutorialText12, 
		int tutorialText13, int tutorialText14, int scene, int tutorialBg,int bombBullet);

	//�����o�ϐ�
	//�X�e�[�W���ꉉ�o
	Admission* admission_;

	//���@
	Player* player_;

	//�G
	Enemy* enemy_;

	//�N���A���o
	Clear* clear_;

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