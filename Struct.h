#pragma once

//�x�N�g��
typedef struct Vector2 {
	float X;
	float Y;
};

//�L�����N�^�[
typedef struct Chara {
	Vector2 pos;
	Vector2 speed;
	float radius;
	int HP;
	bool isAlive;
};

typedef struct Zako {
	Vector2 pos[9];
	Vector2 pos1[9]; //�����ʒu
	Vector2 pos2[9]; //�ŏI�I�Ȉʒu
	Vector2 speed[9];
	float radius[9];
	int HP[9];
	bool isAlive[9];
	unsigned int color[9];
	float t[9];
	float easedT[9];
	bool start[9];   //�s���J�n�t���O
};

//�e
typedef struct Bullet {
	Vector2 pos[15];
	Vector2 speed;
	float radius[15];
	int attack;
	bool isShot[15];
	int coolTime;
};

typedef struct EBullet {
	Vector2 pos[8];
	Vector2 speed[8];
	float radius[8];
	bool isShot[8];
	int coolTime[8];
};

typedef struct EBullets {
	Vector2 pos[9];
	Vector2 speed[9];
	float radius[9];
	bool isShot[9];
};