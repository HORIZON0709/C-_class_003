//===================================================
//
//授業その3[enemyBird.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _ENEMYBIRD_H_
#define _ENEMYBIRD_H_

#include "enemy.h"

//********************************
//鳥型の敵のクラス定義
//********************************
class CEnemyBird : public CEnemy
{/* CEnemyの派生クラス */
public:		/* コンストラクタ・デストラクタ */
	CEnemyBird();
	~CEnemyBird();

public:		/* メンバー関数宣言 */
	void Init();	//初期化
	void Uninit();	//終了
	void Input();	//入力
	void Output();	//出力

private:	/* メンバー変数宣言 */
	int m_nSpeedFly;	//飛行スピード
};

#endif