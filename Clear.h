#pragma once
/// <summary>
/// クリア演出
/// </summary>
class Clear
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
	void Draw(int clearPlate);

private:
	//プレート
	float plateX_;  ///初期位置
	float plateX1_; ///初期位置
	float plateX2_; ///最後の位置
	float plateY_;
	float plateT_;

	//幕
	int iCTime_;      ///inCurtainがtrueになるまでの時間
	bool inCurtain_;  ///幕が下がるフラグ
	float curtainX_;
	float curtainY_;  ///初期位置
	float curtainY1_; ///初期位置
	float curtainY2_; ///最後の位置
	float curtainT_;
};