#pragma once

class Gameover
{
public:
	//メンバ関数
	void Initialize();

	void Update(char* keys);

	void Draw();

	//メンバ変数
	int gameover_;
	
	bool onEase_;

	float posX_;
	float posY_;
	float posY1_;
	float posY2_;
	float t_;
	float easedT_;
};

