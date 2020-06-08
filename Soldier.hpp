#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

class Soldier{
	public:
	int initial_HP;
	int current_HP;
	int dpa;
	int player_number;
	string type;
	Soldier(int i, int IHP, int dpa,string type){
		player_number = i;
		initial_HP = IHP;
		current_HP = IHP;
		this->dpa = dpa;
		this->type = type;
	}


	Soldier(int i){
		player_number = i;
	}

	virtual ~Soldier(void){
		
	}

	virtual void attack(vector<vector<Soldier*>> board, pair<int,int>location)=0;

};
