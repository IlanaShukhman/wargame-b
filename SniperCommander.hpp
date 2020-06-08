#pragma once
#include "Soldier.hpp"

class SniperCommander:public Soldier{
	public:
	SniperCommander(int i) : Soldier(i,120,100,"SniperCommander"){
	}
	~SniperCommander(){
	}
	void attack(vector<vector<Soldier*>> board,pair<int,int>location);

};
