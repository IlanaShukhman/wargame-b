#include "Sniper.hpp"
#include "Soldier.hpp"
#include "Board.hpp"
#include <cmath> 
#include <bits/stdc++.h>


void Sniper::attack(vector<vector<Soldier*>> board,pair<int,int>location){
	int maxHP=INT_MIN;
	Soldier* selSol;
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			if(board[i][j] && board[i][j]->player_number != this->player_number){
				if(maxHP<board[i][j]->current_HP){
					maxHP = board[i][j]->current_HP;
					selSol = board[i][j];
				}
			}
		}
	}
	if(selSol){
		selSol->current_HP -= this->dpa;

	}

}

