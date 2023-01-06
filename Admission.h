#pragma once

class Admission
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update();

	//�Q�b�^�[�֐�
	bool GetterPlayStart() { return playStart_; }

	//�`�揈��
	void Draw(int frameSide, int Plate);

private:
	//�����o�ϐ�
	//�t���[���ʒu 
	float frameRightX_;
	float frameRightY_;
	float frameRightY1_;
	float frameRightY2_;

	float frameLeftX_;
	float frameLeftY_;
	float frameLeftY1_;
	float frameLeftY2_;
	
	//�v���[�g�ʒu
	float plateX_;
	float plateY_;
	float plateX1_;
	float plateX2_;
	float plateX3_;
	float plateX4_;
	float plateX5_;
	float plateX6_;

	//�v���[�g���x
	float plateSpeedX_;

	//�C�[�W���O
	float t1_;
	float t2_;
	float t3_;
	bool onEase_;
	bool onPlateEase1_;
	bool onPlateEase2_;
	bool onSlowly_;

	//���@�ʒu
	float playerY_;
	float playerY1_;
	float playerY2_;

	//�J�E���g
	int plateEaseStartCount_;

	//�v���C�J�n
	int playStartCount_;
	bool playStart_;
	bool playStartCountStart_;

	//�F
	unsigned int color_;
	unsigned int fade_;

	//�t�F�[�h�A�E�g�t���O
	bool onFade_;
};

