#pragma once
#include "Soldier.hpp"

class ParamedicCommander:public Soldier{
	public:
	ParamedicCommander(int i) : Soldier(i,200,0,"ParamedicCommander"){
	}
	~ParamedicCommander(){
	}
	void attack(vector<vector<Soldier*>> board,pair<int,int>location);

};
