#pragma once
#include "Soldier.hpp"

class FootCommander:public Soldier{
	public:
	FootCommander(int i) : Soldier(i,150,20,"FootCommander"){
	}
	~FootCommander(){
	}
	void attack(vector<vector<Soldier*>> board,pair<int,int>location);

};
