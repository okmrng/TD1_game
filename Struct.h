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

//�e
typedef struct Bullet {
	Vector2 pos[15];
	Vector2 speed;
	float radius;
	int attack;
	int isShot[15];
	int coolTime;
};