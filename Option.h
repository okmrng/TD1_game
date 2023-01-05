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
	bool GetterDirectionStaile() { return directionStile_; }
	bool GetterNext() { return next_; }

private:
	//�����o�ϐ�
	//WASD����
	bool WASDStile_;

	//�����L�[����
	bool directionStile_;

	//�J�E���^�[
	int choiceCount_;
	bool choice_;

	//�F
	unsigned int white_;
	unsigned int whiteBg_;

	//�t�F�[�h
	unsigned int fade_;
	unsigned int fade2_;

	//Enter�t���O
	bool OnReturn_;
	bool OffReturn_;

	//����t���O
	bool OnOperation_;

	//�\���t���O
	bool OnDisplay_;

	//�V�[���J�ڃt���O
	bool next_;
};

