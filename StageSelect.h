#pragma once
class StageSelect
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
	void Draw(int mapFrameX, int mapFrameY);

private:
	//�����o�ϐ�

	//�t���[��
	float frameXX_;  
	float frameXY_;  
	float frameXY1_; ///�����ʒu
	float frameXY2_; ///�Ō�̈ʒu
	float frameXT_;

	float frameYX_;
	float frameYX1_; ///�����ʒu
	float frameYX2_; ///�Ō�̈ʒu
	float frameYY_;
	float frameYT_;
};

