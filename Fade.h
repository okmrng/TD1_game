#pragma once
class Fade
{
public:
	//�����o�֐�
	//������
	void Initialize();

	//�X�V����
	void Update();

	//�`�揈��
	void Draw();

	//�Q�b�^�[�֐�
	bool GetterNext() { return next_; }

	//�Z�b�^�[�֐�
	void SetOnFade(bool onFade);

private:
	//�����o�ϐ�
	//�F
	unsigned int color_;

	//�t�F�[�h
	unsigned int fade_;

	//�t�F�[�h�C���J�n�t���O
	bool onFade_;

	//�V�[���J�ڂ���܂ł̃J�E���g
	int nextCount_;

	//�V�[���J�ڃt���O
	bool next_;
};

