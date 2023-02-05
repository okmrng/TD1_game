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
	Vector2 pos[12];
	Vector2 pos1[12];     //�����ʒu
	Vector2 pos2[12];     //�ŏI�I�Ȉʒu
	Vector2 speed[12];
	float radius[12];
	int HP[12];
	bool isAlive[12];
	unsigned int color[12];
	float t[12];
	float easedT[12];
	bool start[12];      //�s���J�n�t���O
	float theta[12];
	float amplitude[12]; //�g
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
	Vector2 pos[12];
	Vector2 speed[12];
	float radius[12];
	bool isShot[12];
	int coolTime[12];
};

typedef struct EBullets {
	Vector2 pos[9];
	Vector2 speed[9];
	float radius[9];
	bool isShot[9];
};