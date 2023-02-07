#pragma once
class StageSelect
{
public:
	//メンバ関数

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(char *keys, char* preKeys);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	//ゲッター関数
	bool GetterInStage1() { return inStage1_; }
	bool GetterInStage2() { return inStage2_; }
	bool GetterInStage3() { return inStage3_; }
	float GetterBlackT() { return black_.t; }

private:
	//メンバ変数
	int mapFrameX;
	int mapFrameY;

	int stage1;
	int stage2;
	int stage3;

	int stageSelect;

	//構造体
	struct Vector2 {
		float X;
		float Y;
	};
	struct object {
		Vector2 pos;
		Vector2 pos1; //初期位置
		Vector2 pos2; //最終的な位置
		float radius;
		float t;
		float easedT;
	};

	//フレーム
	object frameX_;
	object frameY_;

	//プレート
	object stage1_;
	object stage2_;
	object stage3_;

	//文字
	object stageSelect_;

	//カーソル
	object cursor_;

	object black_;
	int startEaseCount_;
	bool onEase_;

	//選択
	bool onSelect_;
	bool selectStage1_;
	bool selectStage2_;
	bool selectStage3_;
	int pushCount_;
	bool inStage1_;
	bool inStage2_;
	bool inStage3_;
};

