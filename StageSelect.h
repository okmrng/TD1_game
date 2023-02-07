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
	void Update(char *keys, char* preKeys);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	//�Q�b�^�[�֐�
	bool GetterInStage1() { return inStage1_; }
	bool GetterInStage2() { return inStage2_; }
	bool GetterInStage3() { return inStage3_; }
	float GetterBlackT() { return black_.t; }

private:
	//�����o�ϐ�
	int mapFrameX;
	int mapFrameY;

	int stage1;
	int stage2;
	int stage3;

	int stageSelect;

	//�\����
	struct Vector2 {
		float X;
		float Y;
	};
	struct object {
		Vector2 pos;
		Vector2 pos1; //�����ʒu
		Vector2 pos2; //�ŏI�I�Ȉʒu
		float radius;
		float t;
		float easedT;
	};

	//�t���[��
	object frameX_;
	object frameY_;

	//�v���[�g
	object stage1_;
	object stage2_;
	object stage3_;

	//����
	object stageSelect_;

	//�J�[�\��
	object cursor_;

	object black_;
	int startEaseCount_;
	bool onEase_;

	//�I��
	bool onSelect_;
	bool selectStage1_;
	bool selectStage2_;
	bool selectStage3_;
	int pushCount_;
	bool inStage1_;
	bool inStage2_;
	bool inStage3_;
};

