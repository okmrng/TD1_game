#pragma once
class BossBullet
{
public:
	//メンバ関数
	void Initialize();

	void Update();

	void Draw();

	//メンバ変数
	int bossBullet0;

	struct Vector2 {
		float X;
		float Y;
	};

	struct bullet {
		Vector2 pos[13];
		Vector2 pos1[13];    //初期位置
		Vector2 pos2[13];    //最終的な位置
		Vector2 speed[13];
		float radius[13];
		bool isShot[13];
		float theta[13];
		float theta2[13];
		float amplitude[13]; //振幅
	};
	bullet pattern0_;
	bullet pattern1_;
	bullet pattern2_;
};

