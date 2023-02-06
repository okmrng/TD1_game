#pragma once

/// <summary>
/// �{���e
/// </summary>
class BombParticle
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
	void Draw(int bombBullet);

	//�Q�b�^�[�֐�
	float GetterCollisionX() { return collisionX_; }
	float GetterCollisionY() { return collisionY_; }
	float GetterCollisionR() { return collisionR_; }

	//�����o�ϐ�
	//�p�[�e�B�N��
	int particleMax_; ///�p�[�e�B�N���ő�l
	bool isActive_[300];
	float particleX_[300];
	float particleY_[300];
	float particleW_[300];
	float particleH_[300];
	unsigned int color_[300];
	unsigned int fade_[300];    ///�����x

	bool isActive_2[300];
	float particleX_2[300];
	float particleY_2[300];
	float particleW_2[300];
	float particleH_2[300];
	unsigned int color_2[300];
	unsigned int fade_2[300];    ///�����x

	bool isActive_3[300];
	float particleX_3[300];
	float particleY_3[300];
	float particleW_3[300];
	float particleH_3[300];
	unsigned int color_3[300];
	unsigned int fade_3[300];    ///�����x

	//�G�~�b�^�[
	int emitterX_;
	int emitterY_;
	int emitterY1_;
	int emitterY2_;
	int emitterW_;
	int emitterH_;

	//�{��
	float collisionX_;
	float collisionY_;
	float collisionY1_;
	float collisionY2_;
	float collisionR_;

	float speed_;

	float t_;
};