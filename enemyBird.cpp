//===================================================
//
//授業その3[enemyBird.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "enemyBird.h"

#include <stdio.h>
#include <stdlib.h>

//===================================================
//コンストラクタ
//===================================================
CEnemyBird::CEnemyBird()
{
	//メンバ変数をクリア
	m_nSpeedFly = 0;
}

//===================================================
//デストラクタ
//===================================================
CEnemyBird::~CEnemyBird()
{
	/* 処理無し */
}

//===================================================
//初期化
//===================================================
void CEnemyBird::Init()
{
	//親クラスの初期化
	CEnemy::Init();

	//メンバ変数を初期化
	m_nSpeedFly = 0;
}

//===================================================
//終了
//===================================================
void CEnemyBird::Uninit()
{
	//親クラスの終了
	CEnemy::Uninit();
}

//===================================================
//入力
//===================================================
void CEnemyBird::Input()
{
	//親クラスの入力
	CEnemy::Input();

	//入力
	printf(" 飛行スピード > ");
	scanf("%d", &m_nSpeedFly);
}

//===================================================
//出力
//===================================================
void CEnemyBird::Output()
{
	//親クラスの出力
	CEnemy::Output();

	//出力
	printf(" 飛行スピード : %d ]\n", m_nSpeedFly);	//飛行スピード
}