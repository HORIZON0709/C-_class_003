//===================================================
//
//授業その3[main.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "main.h"
#include "enemy.h"
#include "enemyHuman.h"
#include "enemyBird.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//定数の定義
//********************************
namespace
{

}// namespaceはここまで

//********************************
//プロトタイプ宣言
//********************************
namespace
{
CEnemy::ENEMY_TYPE SelectType();
int SetNumEnemy();
}// namespaceはここまで

//===================================================
//メイン関数
//===================================================
void main(void)
{
	CEnemy* apEnemy[CEnemy::MAX_ENEMY] = {};	//敵情報のポインタ

	//敵の数を設定
	int nNumEnemy = SetNumEnemy();

	for (int i = 0; i < nNumEnemy; i++)
	{
		if (apEnemy[i] != nullptr)
		{//NULLチェック
			//メモリの解放
			delete apEnemy[i];
			apEnemy[i] = nullptr;
		}

		//何体目か表示
		printf("\n 《 %d体目 》", (i + 1));

		//敵の種類を選択
		CEnemy::ENEMY_TYPE type = SelectType();

		switch (type)
		{//敵の種類毎の処理
		case CEnemy::ENEMY_TYPE::HUMAN:		/* 人型 */

			//メモリの動的確保
			apEnemy[i] = new CEnemyHuman;
			break;

		case CEnemy::ENEMY_TYPE::BIRD:		/* 鳥型 */

			//メモリの動的確保
			apEnemy[i] = new CEnemyBird;
			break;

		case CEnemy::ENEMY_TYPE::NONE:		/* 選択範囲外 */
		case CEnemy::ENEMY_TYPE::MAX:
		default:
			assert(false);
			break;
		}

		if (apEnemy[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrでは無い場合 */
		apEnemy[i]->Init();		//初期化
		apEnemy[i]->Input();	//入力
		apEnemy[i]->Output();	//出力
		apEnemy[i]->Uninit();	//終了

		//Enter入力待ち
		PressEnter();

		//画面をクリア
		system("cls");
	}

	for (int i = 0; i < CEnemy::MAX_ENEMY; i++)
	{
		if (apEnemy[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrではない場合 */
		
		//メモリの解放
		delete apEnemy[i];
		apEnemy[i] = nullptr;
	}

	//終了メッセージ
	printf("\n プログラムを終了します。お疲れ様でした。");

	//Enter入力待ち
	PressEnter();
}

//===================================================
//Enter入力待ち
//===================================================
void PressEnter()
{
	//Enter入力待ち
	printf("\n\n Press Enter");
	rewind(stdin);
	getchar();
}

namespace
{
//---------------------------------------------------
//敵の種類を選択
//---------------------------------------------------
CEnemy::ENEMY_TYPE SelectType()
{
	CEnemy::ENEMY_TYPE selectType;	//敵の種類選択用

	while (1)
	{
		//メッセージ
		printf("\n 《 敵の種類を選択 》");
		printf("\n [%d] 人型",CEnemy::ENEMY_TYPE::HUMAN);
		printf("\n [%d] 鳥型", CEnemy::ENEMY_TYPE::BIRD);
		printf("\n 番号を入力 > ");
		scanf("%d", &selectType);

		if ((selectType > CEnemy::ENEMY_TYPE::NONE) && (selectType < CEnemy::ENEMY_TYPE::MAX))
		{//範囲内
			break;
		}

		/* 範囲外 */

		//メッセージ & Enter入力待ち
		printf("\n\n ※※※ 範囲外です ※※※");
		PressEnter();

		//画面をクリア
		system("cls");
	}

	return selectType;	//選択した敵の種類を返す
}

//---------------------------------------------------
//敵の数を設定
//---------------------------------------------------
int SetNumEnemy()
{
	int nNumEnemy = 0;	//敵の数設定用

	while (1)
	{
		//メッセージ
		printf("\n 敵の数を設定( %d体まで ) > ",CEnemy::MAX_ENEMY);
		scanf("%d", &nNumEnemy);

		if ((nNumEnemy >= CEnemy::MIN_ENEMY) && (nNumEnemy <= CEnemy::MAX_ENEMY))
		{//範囲内
			break;
		}

		/* 範囲外 */

		//メッセージ & Enter入力待ち
		printf("\n\n ※※※ 範囲外です ※※※");
		PressEnter();

		//画面をクリア
		system("cls");
	}

	//画面をクリア
	system("cls");

	return nNumEnemy;	//設定した敵の数を返す
}
}