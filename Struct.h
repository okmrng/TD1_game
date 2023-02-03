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
	Vector2 pos[8];
	Vector2 pos1[8]; //�����ʒu
	Vector2 pos2[8]; //�ŏI�I�Ȉʒu
	Vector2 speed[8];
	float radius[8];
	int HP[8];
	bool isAlive[8];
	unsigned int color[8];
	float t[8];
	float easedT[8];
	bool start[8];   //�s���J�n�t���O
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