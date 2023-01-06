#pragma once
#include "Admission.h"

class Tutorial
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update(char* keys, char* preKeys);

	//�`�揈��
	void Draw(int frameSide, int Plate, bool WASDStile_, bool directionStile_, int tutorialText1, int tutorialText2,
		int tutorialText3Direction, int tutorialText3WASD, int tutorialText4);

	//�����o�ϐ�
	//�X�e�[�W���ꉉ�o
	Admission* admission_;

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
};

