#pragma once
class Option
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update(char* keys, char* preKeys);

	//描画処理
	void Draw(int wasd,int wasdYellow,int direction,int directionYellow);

	//ゲッター関数
	bool GetterWASDStaile() { return WASDStile_; }
	bool GetterdirectionStaile() { return directionStile_; }

private:
	//メンバ変数
	//WASD操作
	bool WASDStile_;

	//方向キー操作
	bool directionStile_;

	//カウンター
	int choiceCount_;
	bool choice_;
};

