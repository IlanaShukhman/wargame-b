#pragma once
#include "Soldier.hpp"
#include "Board.hpp"

class Sniper:public Soldier{
	public:
	Sniper(int i) : Soldier(i,100,50,"sniper"){
	}
	~Sniper(){
	}
	void attack(vector<vector<Soldier*>> board,pair<int,int>location);

};
