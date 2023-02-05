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
	Vector2 pos[14];
	Vector2 pos1[14];     //初期位置
	Vector2 pos2[14];     //最終的な位置
	Vector2 speed[14];
	float radius[14];
	int HP[14];
	bool isAlive[14];
	unsigned int color[14];
	float t[14];
	float easedT[14];
	bool start[14];      //行動開始フラグ
	float theta[14];
	float amplitude[14]; //波
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
	Vector2 pos[15];
	Vector2 speed[15];
	float radius[15];
	bool isShot[15];
	int coolTime[15];
};

typedef struct EBullets {
	Vector2 pos[24];
	Vector2 speed[24];
	float radius[24];
	bool isShot[24];
};