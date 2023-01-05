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
	bool GetterDirectionStaile() { return directionStile_; }
	bool GetterNext() { return next_; }

private:
	//メンバ変数
	//WASD操作
	bool WASDStile_;

	//方向キー操作
	bool directionStile_;

	//カウンター
	int choiceCount_;
	bool choice_;

	//色
	unsigned int white_;
	unsigned int whiteBg_;

	//フェード
	unsigned int fade_;
	unsigned int fade2_;

	//Enterフラグ
	bool OnReturn_;
	bool OffReturn_;

	//操作フラグ
	bool OnOperation_;

	//表示フラグ
	bool OnDisplay_;

	//シーン遷移フラグ
	bool next_;
};

