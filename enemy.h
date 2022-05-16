//===================================================
//
//授業その3[enemy.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

//********************************
//敵のクラス定義
//********************************
class CEnemy
{/* 基本クラス */
public:		/* 列挙型の定義 */
	enum class ENEMY_TYPE
	{
		NONE = 0,
		HUMAN,	//人型
		BIRD,	//鳥型
		MAX,
	};

public:		/* 定数の定義 */
	static const int MAX_ENEMY = 5;		//最大数
	static const int MIN_ENEMY = 1;		//最少数

public:		/* 静的メンバ関数宣言 */
	static int GetNumAll();	//総数を取得

public:		/* コンストラクタ・デストラクタ */
	CEnemy();
	virtual ~CEnemy();

public:		/* メンバ関数宣言 */
	virtual void Init();	//初期化
	virtual void Uninit();	//終了
	virtual void Input();	//入力
	virtual void Output();	//出力

private:	/* 静的メンバ変数宣言 */
	static int m_nNumAll;	//総数

private:	/* メンバ変数宣言 */
	int m_nLife;	//体力
	int m_nAttack;	//攻撃力
};

#endif