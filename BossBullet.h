#pragma once
class BossBullet
{
public:
	//�����o�֐�
	void Initialize();

	void Update();

	void Draw();

	//�����o�ϐ�
	int bossBullet0;

	struct Vector2 {
		float X;
		float Y;
	};

	struct bullet {
		Vector2 pos[13];
		Vector2 pos1[13];    //�����ʒu
		Vector2 pos2[13];    //�ŏI�I�Ȉʒu
		Vector2 speed[13];
		float radius[13];
		bool isShot[13];
		float theta[13];
		float theta2[13];
		float amplitude[13]; //�U��
	};
	bullet pattern0_;
	bullet pattern1_;
	bullet pattern2_;
};

