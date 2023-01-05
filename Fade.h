#pragma once
class Fade
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update();

	//描画処理
	void Draw();

	//ゲッター関数
	bool GetterNext() { return next_; }

	//セッター関数
	void SetOnFade(bool onFade);

private:
	//メンバ変数
	//色
	unsigned int color_;

	//フェード
	unsigned int fade_;

	//フェードイン開始フラグ
	bool onFade_;

	//シーン遷移するまでのカウント
	int nextCount_;

	//シーン遷移フラグ
	bool next_;
};

