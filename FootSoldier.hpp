#pragma once
#include "Soldier.hpp"
#include "Board.hpp"

class FootSoldier:public Soldier{
	public:
	FootSoldier(int i) : Soldier(i,100,10,"footSoldier"){
	}
	~FootSoldier(){
	}
	void attack(vector<vector<Soldier*>> board,pair<int,int>location);
};
