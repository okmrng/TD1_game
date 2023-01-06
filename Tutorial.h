#pragma once
#include "Admission.h"
#include "Player.h"
#include "Enemy.h"

class Tutorial
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, int scene);

	//描画処理
	void Draw(int frameSide, int Plate, bool WASDStile_, bool directionStile_, int tutorialText1, int tutorialText2,
		int tutorialText3Direction, int tutorialText3WASD, int tutorialText4, int tutorialText5, int textBox, int scene,
		int tutorialBg);

	//メンバ変数
	//ステージ入場演出
	Admission* admission_;

	//自機
	Player* player_;

	//敵
	Enemy* enemy_;

	//テキストフラグ
	int text_;
	bool textDisplay_;

	//テキスト位置
	float textX_;
	float textY_;

	//入力カウント
	int pushCount_;

	//シーン遷移
	bool next_;

	//自機移動フラグ
	bool onPlayerMove_;

	//自機弾発射フラグ
	bool onPlayerShot_;
};

