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
	Vector2 pos[3];
	Vector2 speed[3];
	float radius[3];
	int HP[3];
	bool isAlive[3];
	unsigned int color[3];
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
	Vector2 pos;
	Vector2 speed;
	float radius;
	bool isShot;
};

typedef struct EBullets {
	Vector2 pos[10];
	Vector2 speed;
	float radius[10];
	bool isShot[10];
};