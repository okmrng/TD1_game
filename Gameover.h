#pragma once

class Gameover
{
public:
	//ƒƒ“ƒoŠÖ”
	void Initialize();

	void Update(char* keys);

	void Draw();

	//ƒƒ“ƒo•Ï”
	int gameover_;
	
	bool onEase_;

	float posX_;
	float posY_;
	float posY1_;
	float posY2_;
	float t_;
	float easedT_;
};

