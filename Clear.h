#pragma once
/// <summary>
/// �N���A���o
/// </summary>
class Clear
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
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw(int clearPlate);

	//�Q�b�^�[�֐�
	bool GetterNext() { return next_; }

public:
	//�v���[�g
	float plateX_;  ///�����ʒu
	float plateX1_; ///�����ʒu
	float plateX2_; ///�Ō�̈ʒu
	float plateY_;
	float plateT_;

	//��
	int iCTime_;      ///inCurtain��true�ɂȂ�܂ł̎���
	bool inCurtain_;  ///����������t���O
	float curtainX_;
	float curtainY_;  ///�����ʒu
	float curtainY1_; ///�����ʒu
	float curtainY2_; ///�Ō�̈ʒu
	float curtainT_;

	//�V�[���J��
	int nextTime_;    ///���̃V�[���֑J�ڂ���܂ł̃J�E���g
	bool next_;
};