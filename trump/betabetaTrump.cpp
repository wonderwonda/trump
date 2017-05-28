#include"stdafx.h"
#include<iostream>
#include<random>
#include<string>
using namespace std;


int RandomKaesu()
{
	random_device seed_gen;
	default_random_engine engine(seed_gen());
	uniform_int_distribution<> dist(1, 53);

	return dist(engine);
}


string CardName(int CardNum)
{
	if (1 <= CardNum&&CardNum < 13)
		return  "スペードの" + to_string(CardNum%13);
	
	else if (14 <= CardNum&&CardNum < 26)
		return "クラブの" + to_string(CardNum%13);

	else if (27 <= CardNum&&CardNum < 39)
		return "ハートの" + to_string(CardNum%13);

	else if (40 <= CardNum&&CardNum < 52)
		return "ダイヤの" + to_string(CardNum%13);

	if (CardNum == 13)
		return "スペードの13";

	if (CardNum == 26)
		return "クラブの13";

	if (CardNum == 39)
		return "ハートの13";

	if (CardNum == 52)
		return "ダイヤの13";

	else if (CardNum == 53)
		return "ジョーカー";
}



void battle(int PlayerANum,int PlayerBNum)
{
	int returnNum;
	//ジョーカーの処理
	if (PlayerANum == 53 ||PlayerBNum==53)
	{
		PlayerANum == 53 ? cout << "プレイヤーAの勝ち!" << endl : cout << "プレイヤーBの勝ち!" << endl;
		return;
	}

	//13の剰余を取れば、1~13,14~26,27~39,40~52の数値が対等条件で揃う
	int battleNumA = PlayerANum % 13;
	int	battleNumB = PlayerBNum % 13;

	//同数になった場合の絵柄勝負 スペード,クラブ,ハート,ダイヤの順に数値が大きくなるので勝敗はその逆
	if (battleNumA == battleNumB)
	{
		PlayerANum < PlayerBNum ? cout << "プレイヤーAの勝ち!" << endl : cout << "プレイヤーBの勝ち!" << endl;
		return;
	}

	//以下、同数にならなかった場合

	//13を引けば勝ち
	if (battleNumA==0||battleNumB==0)
	{
		battleNumA==0 ?cout << "プレイヤーAの勝ち!"<<endl : cout << "プレイヤーBの勝ち!" << endl;
		return;
	}

	//13以外なら剰余の値が大きい方の勝ち
	else
		battleNumA>battleNumB ? cout << "プレイヤーAの勝ち!" << endl : cout << "プレイヤーBの勝ち!" << endl;

	return;
		
}

void oneGame(int& a,int& b)
{
	int PlayerANum = RandomKaesu();
	int PlayerBNum = RandomKaesu();

	while (PlayerANum == PlayerBNum)
		PlayerBNum = RandomKaesu();
	
	cout << "プレイヤーA:" << CardName(PlayerANum) << endl;
	cout << "プレイヤーB:" << CardName(PlayerBNum) << endl;

	battle(PlayerANum, PlayerBNum);
	a = PlayerANum;
	b = PlayerBNum;
}



int betabetaMain() 
{
	int Acard[5];
	int Bcard[5];
	int Awin = 0, Bwin = 0;

	for (int i = 0; i < 5; i++)
		oneGame(Acard[i],Bcard[i]);
	
	cout << "" << endl;
	cout << "プレイヤーAのカード:" << endl;
	for (int m = 0; m < 5; m++)
		cout << CardName(Acard[m]) << endl;

	cout << "プレイヤーBのカード:" << endl;
	for (int n = 0; n < 5; n++)
		cout << CardName(Bcard[n]) << endl;
	
	for (int a = 0; a < 5; a++)
	{
		Acard[a] > Bcard[a] ? Awin++ : Bwin++;
	}

	Awin > Bwin ? 
		cout << Awin << "勝" << Bwin << "敗でプレイヤーAのマッチ勝ち!" << endl : 
		cout << Bwin << "勝" << Awin << "敗でプレイヤーBのマッチ勝ち!" << endl;

	return 0;
}