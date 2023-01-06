#pragma once
#include "Admission.h"

class Tutorial
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update(char* keys, char* preKeys);

	//描画処理
	void Draw(int frameSide, int Plate, bool WASDStile_, bool directionStile_, int tutorialText1, int tutorialText2,
		int tutorialText3Direction, int tutorialText3WASD, int tutorialText4);

	//メンバ変数
	//ステージ入場演出
	Admission* admission_;

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
};

