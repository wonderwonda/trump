#pragma once
#include<iostream>
#include<random>
#include<string>
#include<map>
using namespace std;

struct Trump
{
	int deifinitionNum; //1~53の割り振り数字
	string CardName;	//スペードの1など。カード名
};

class Yamahuda
{
private:
	vector<Trump>m_Yamahuda;
	vector<int>Sutehuda;

	//Init
	void MakeYamahuda();

public:
	Yamahuda();
	virtual ~Yamahuda() = default;

	Trump Draw();
	void CardReset();
};

class Player
{
private:
	Trump myHand;
	string PlayerName;
public:
	void showHand();
};