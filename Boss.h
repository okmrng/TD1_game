#pragma once

class Boss
{
public:
	//メンバ関数
	void Initialeze();

	void Update();

	void Draw(int bossImage, int bossCore);

	//メンバ変数
	struct Vector2 {
		float X;
		float Y;
	};

	struct boss {
		Vector2 pos;  
		float radius; 
		int maxHP;          //最大HP
		int HP;             //現在のHP
		bool isAlive; 
		int pattern;        //攻撃パターン
		unsigned int collor;
		unsigned int alpha; //透明度
		float theta;
		float amplitude;    //振幅
	};
	boss boss_;

	//戦闘開始までのカウント
	bool onStartCount_;
	int startCount_;
	bool start_;
};