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
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw(int mapFrameX, int mapFrameY);

private:
	//メンバ変数

	//フレーム
	float frameXX_;  
	float frameXY_;  
	float frameXY1_; ///初期位置
	float frameXY2_; ///最後の位置
	float frameXT_;

	float frameYX_;
	float frameYX1_; ///初期位置
	float frameYX2_; ///最後の位置
	float frameYY_;
	float frameYT_;
};

