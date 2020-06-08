#include "FootCommander.hpp"
#include <cmath> 
#include <bits/stdc++.h>


void FootCommander::attack(vector<vector<Soldier*>> board,pair<int,int>location){
	double minDistance=INT_MAX;
	Soldier* selSol;
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			if(board[i][j]){
				if(board[i][j]->player_number != this->player_number){	
					if(board[i][j]->current_HP >0){
						double distance = sqrt(pow((location.first-i),2) + pow((location.second-j),2));
						if(minDistance>distance){
							minDistance = distance;
							selSol = board[i][j];
						}
					}
				}
			}
		}
	}


	if(selSol){
		selSol->current_HP -= this->dpa;
	}

	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			if(board[i][j] && board[i][j]->player_number == this->player_number && board[i][j]->type == "footSoldier"){
					try{
						board[i][j]->attack(board,pair<int,int>(i,j));
					}
					catch(const std::exception& e){
					}
			}
		}
	}

}


