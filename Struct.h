#pragma once

//ベクトル
typedef struct Vector2 {
	float X;
	float Y;
};

//キャラクター
typedef struct Chara {
	Vector2 pos;
	Vector2 speed;
	float radius;
	int HP;
	bool isAlive;
};

typedef struct Zako {
	Vector2 pos;
	Vector2 speed;
	float radius;
	int HP;
	bool isAlive;
};

//弾
typedef struct Bullet {
	Vector2 pos[15];
	Vector2 speed;
	float radius;
	int attack;
	bool isShot[15];
	int coolTime;
};