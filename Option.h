#pragma once
class Option
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update(char* keys, char* preKeys);

	//�`�揈��
	void Draw(int wasd,int wasdYellow,int direction,int directionYellow);

	//�Q�b�^�[�֐�
	bool GetterWASDStaile() { return WASDStile_; }
	bool GetterdirectionStaile() { return directionStile_; }

private:
	//�����o�ϐ�
	//WASD����
	bool WASDStile_;

	//�����L�[����
	bool directionStile_;

	//�J�E���^�[
	int choiceCount_;
	bool choice_;
};

