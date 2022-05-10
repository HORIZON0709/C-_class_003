//===================================================
//
//授業その3[enemyHuman.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _ENEMYHUMAN_H_
#define _ENEMYHUMAN_H_

#include "enemy.h"

//********************************
//人型の敵のクラス定義
//********************************
class CEnemyHuman : public CEnemy
{/* CEnemyの派生クラス */
public:		/* コンストラクタ・デストラクタ */
	CEnemyHuman();
	~CEnemyHuman();

public:		/* メンバー関数宣言 */
	void Init();	//初期化
	void Uninit();	//終了
	void Input();	//入力
	void Output();	//出力

private:	/* メンバー変数宣言 */
	int m_nSpeedWalk;	//歩くスピード
};

#endif