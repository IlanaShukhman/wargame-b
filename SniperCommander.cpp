#include "SniperCommander.hpp"
#include <cmath> 
#include <bits/stdc++.h>


void SniperCommander::attack(vector<vector<Soldier*>> board,pair<int,int>location){
	int maxHP=INT_MIN;
	Soldier* selSol;
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			if(board[i][j]){
				if(board[i][j]->player_number != this->player_number){
					if(maxHP<board[i][j]->current_HP){
						maxHP = board[i][j]->current_HP;
						selSol = board[i][j];
					}
				}
				else if(board[i][j]->type == "sniper"){
					board[i][j]->attack(board,pair<int,int>(i,j));
				
				}
			}
		}
	}
	if(selSol){
		selSol->current_HP -= this->dpa;

	}

}

