#pragma once
#include "Soldier.hpp"
#include "Board.hpp"

class Paramedic:public Soldier{
	public:
	Paramedic(int i) : Soldier(i,100,0,"Paramedic"){
	}
	~Paramedic(){
	}
	void attack(vector<vector<Soldier*>> board,pair<int,int>location);

};
