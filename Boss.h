#pragma once

class Boss
{
public:
	//�����o�֐�
	void Initialeze();

	void Update();

	void Draw(int bossImage, int bossCore);

	//�����o�ϐ�
	struct Vector2 {
		float X;
		float Y;
	};

	struct boss {
		Vector2 pos;  
		float radius; 
		int maxHP;          //�ő�HP
		int HP;             //���݂�HP
		bool isAlive; 
		int pattern;        //�U���p�^�[��
		unsigned int collor;
		unsigned int alpha; //�����x
		float theta;
		float amplitude;    //�U��
	};
	boss boss_;

	//�퓬�J�n�܂ł̃J�E���g
	bool onStartCount_;
	int startCount_;
	bool start_;
};