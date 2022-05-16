//===================================================
//
//授業その3[enemy.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "enemy.h"

#include <stdio.h>
#include <stdlib.h>

//********************************
//静的メンバ変数
//********************************
int CEnemy::m_nNumAll = 0;	//総数

//===================================================
//総数を取得
//===================================================
int CEnemy::GetNumAll()
{
	return m_nNumAll;
}

//===================================================
//コンストラクタ
//===================================================
CEnemy::CEnemy()
{
	//メンバ変数をクリア
	m_nLife = 0;
	m_nAttack = 0;

	//総数をカウントアップ
	m_nNumAll++;
}

//===================================================
//デストラクタ
//===================================================
CEnemy::~CEnemy()
{
	/* 処理無し */
}

//===================================================
//初期化
//===================================================
void CEnemy::Init()
{
	//メンバ変数を初期化
	m_nLife = 0;
	m_nAttack = 0;
}

//===================================================
//終了
//===================================================
void CEnemy::Uninit()
{

}

//===================================================
//入力
//===================================================
void CEnemy::Input()
{
	printf("\n 《 敵のステータスを設定 》");	//メッセージ

	//体力
	printf("\n 体力 > ");
	scanf("%d", &m_nLife);

	//攻撃力
	printf(" 攻撃力 > ");
	scanf("%d", &m_nAttack);
}

//===================================================
//出力
//===================================================
void CEnemy::Output()
{
	printf("\n 《 設定したステータスはこちら 》");	//メッセージ
	printf("\n [ 体力 : %d /", m_nLife);			//体力
	printf(" 攻撃力 : %d /", m_nAttack);			//攻撃力
}