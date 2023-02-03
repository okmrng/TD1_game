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
	Vector2 pos[4];
	Vector2 pos1[4]; //初期位置
	Vector2 pos2[4]; //最終的な位置
	Vector2 speed[4];
	float radius[4];
	int HP[4];
	bool isAlive[4];
	unsigned int color[4];
	float t[4];
	float easedT[4];
	bool start[4];   //行動開始フラグ
};

//弾
typedef struct Bullet {
	Vector2 pos[15];
	Vector2 speed;
	float radius[15];
	int attack;
	bool isShot[15];
	int coolTime;
};

typedef struct EBullet {
	Vector2 pos[4];
	Vector2 speed[4];
	float radius[4];
	bool isShot[4];
	int coolTime[4];
};

typedef struct EBullets {
	Vector2 pos[3];
	Vector2 speed[3];
	float radius[3];
	bool isShot[3];
};