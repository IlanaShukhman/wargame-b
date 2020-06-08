#include "ParamedicCommander.hpp"
#include "Soldier.hpp"
#include "Board.hpp"


void ParamedicCommander::attack(vector<vector<Soldier*>> board,pair<int,int>location){

	for(int i=location.first-1;i<=location.first+1;i++){
		if(location.first-1 >=0 && location.first+1<board.size()){
			for(int j=location.second-1;j<=location.second+1;j++){
				if(location.second-1 >=0 && location.second+1<board.size()){
					if(board[i][j]){
						if(board[i][j]->player_number == this->player_number){
							board[i][j]->current_HP = board[i][j]->initial_HP;
							if(board[i][j]->type == "Paramedic"){
								board[i][j]->attack(board,pair<int,int>(i,j));
							
							}
						}
					}
				}
			}
		}
	}
cout<<endl;

}

