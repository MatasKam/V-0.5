#pragma once
#include "biblioteka.h"

struct duomenys {
	string vardas = "";
	string pavarde = "";
	int egzp;
	vector<int>ndp;

	string var;
	string pav;
	vector<string> kiek;
	string q;
	int ilgis;
	vector < duomenys> gaidz;
	vector < duomenys> mldc;
	float galbal;
	float med;
};
void rasom(vector<duomenys>);
void rasomp(vector<duomenys>);