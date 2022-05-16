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
//スタティック変数
//********************************
namespace
{
CEnemy* s_apEnemy[CEnemy::MAX_ENEMY];	//敵情報のポインタ
}// namespaceはここまで

//********************************
//プロトタイプ宣言
//********************************
namespace
{
int SetNumEnemy();
CEnemy::ENEMY_TYPE SelectType();

void Init();
int Input();
void Output(int nNumEnemy);
void Uninit();
}// namespaceはここまで

//===================================================
//メイン関数
//===================================================
void main(void)
{
	//初期化
	Init();

	//敵の数を設定
	int nNumEnemy = Input();

	//出力
	Output(nNumEnemy);
	
	//終了
	Uninit();

	//終了メッセージ & Enter入力待ち
	printf("\n プログラムを終了します。お疲れ様でした。");
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
//敵の数を設定
//---------------------------------------------------
int SetNumEnemy()
{
	int nNumEnemy = 0;	//敵の数設定用

	while (1)
	{
		//メッセージ
		printf("\n 敵の数を設定( %d〜%d体まで ) > ", CEnemy::MIN_ENEMY,CEnemy::MAX_ENEMY);
		scanf("%d", &nNumEnemy);

		if ((nNumEnemy >= CEnemy::MIN_ENEMY) && (nNumEnemy <= CEnemy::MAX_ENEMY))
		{//範囲内
			break;
		}

		/* 範囲外 */

		//メッセージ & Enter入力待ち
		printf("\n ※※※ 範囲外です ※※※");
		PressEnter();

		//画面をクリア
		system("cls");
	}

	//画面をクリア
	system("cls");

	return nNumEnemy;	//設定した敵の数を返す
}

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
		printf("\n ※※※ 範囲外です ※※※");
		PressEnter();

		//画面をクリア
		system("cls");
	}

	return selectType;	//選択した敵の種類を返す
}

//---------------------------------------------------
//初期化
//---------------------------------------------------
void Init()
{
	for (int i = 0; i < CEnemy::MAX_ENEMY; i++)
	{//nullptrで初期化する
		if (s_apEnemy[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrではない場合 */

		//終了
		s_apEnemy[i]->Uninit();

		//メモリの解放
		delete s_apEnemy[i];
		s_apEnemy[i] = nullptr;
	}
}

//---------------------------------------------------
//入力
//---------------------------------------------------
int Input()
{
	//敵の数を設定
	int nNumEnemy = SetNumEnemy();

	for (int i = 0; i < nNumEnemy; i++)
	{
		if (s_apEnemy[i] != nullptr)
		{//NULLチェック
			//メモリの解放
			delete s_apEnemy[i];
			s_apEnemy[i] = nullptr;
		}

		//何体目か表示
		printf("\n 《 %d体目 》", (i + 1));

		//敵の種類を選択
		CEnemy::ENEMY_TYPE type = SelectType();

		switch (type)
		{//敵の種類毎の処理
		case CEnemy::ENEMY_TYPE::HUMAN:		/* 人型 */

			//メモリの動的確保
			s_apEnemy[i] = new CEnemyHuman;
			break;

		case CEnemy::ENEMY_TYPE::BIRD:		/* 鳥型 */

			//メモリの動的確保
			s_apEnemy[i] = new CEnemyBird;
			break;

		case CEnemy::ENEMY_TYPE::NONE:		/* 選択範囲外 */
		case CEnemy::ENEMY_TYPE::MAX:
		default:
			assert(false);
			break;
		}

		//初期化
		s_apEnemy[i]->Init();

		if (s_apEnemy[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrでは無い場合 */

		//入力
		s_apEnemy[i]->Input();

		//画面をクリア
		system("cls");
	}

	return nNumEnemy;	//設定した敵の数を返す
}

//---------------------------------------------------
//出力
//---------------------------------------------------
void Output(int nNumEnemy)
{
	for (int i = 0; i < nNumEnemy; i++)
	{
		if (s_apEnemy[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrでは無い場合 */

		//出力
		s_apEnemy[i]->Output();
	}
}

//---------------------------------------------------
//終了
//---------------------------------------------------
void Uninit()
{
	for (int i = 0; i < CEnemy::MAX_ENEMY; i++)
	{
		if (s_apEnemy[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrではない場合 */

		//終了
		s_apEnemy[i]->Uninit();

		//メモリの解放
		delete s_apEnemy[i];
		s_apEnemy[i] = nullptr;
	}
}
}