#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"

using namespace std;
namespace WarGame {

	// operator for putting soldiers on the game-board during initialization.
	Soldier*& Board::operator[](pair<int,int> location){
		return board[location.first][location.second];
	}
	// operator for reading which soldiers are on the game-board.
	Soldier* Board::operator[](pair<int,int> location) const{

		return board[location.first][location.second];
	}

	void Board::move(uint player_number, pair<int,int> source, MoveDIR direction){
		if(source.first >=board.size() || source.second >=board.size()){
			throw runtime_error("Out of bounds!");	
		}
		if(board[source.first][source.second]==NULL){
			throw runtime_error("Empty!");
		}
		Soldier* soldier = board[source.first][source.second];
		if(soldier->player_number != player_number){	
			throw runtime_error("Not the right player!");
		}
		

		pair<int,int>dest;

		if(direction == MoveDIR::Up){
			if(source.first+1 == board.size())	
				throw runtime_error("Out of bounds!");	
			else if(board[source.first+1][source.second]){
				throw runtime_error("There is another soldier there!");
			}
			board[source.first+1][source.second] =board[source.first][source.second];
			board[source.first][source.second] = nullptr;
			dest = pair<int,int>(source.first+1,source.second);
			
		}
		else if(direction == MoveDIR::Down){
			if(source.first == 0)	
				throw runtime_error("Out of bounds!");
			else if(board[source.first-1][source.second]){
				throw runtime_error("There is another soldier there!");
			}
			board[source.first-1][source.second] =board[source.first][source.second];
			board[source.first][source.second] = nullptr;
			dest = pair<int,int>(source.first-1,source.second);
		}
		else if(direction == MoveDIR::Right){
			if(source.second+1 == board[0].size())	
				throw runtime_error("Out of bounds!");
			else if(board[source.first][source.second+1]){
				throw runtime_error("There is another soldier there!");
			}
			board[source.first][source.second+1] =board[source.first][source.second];
			board[source.first][source.second] = nullptr;
			dest = pair<int,int>(source.first,source.second+1);
		}
		else{
			if(source.second == 0)	
				throw runtime_error("Out of bounds!");
			else if(board[source.first][source.second-1]){
				throw runtime_error("There is another soldier there!");
			}
			board[source.first][source.second-1] =board[source.first][source.second];
			board[source.first][source.second] = nullptr;
			dest = pair<int,int>(source.first,source.second-1);
		}
		soldier->attack(board, dest);
		for(int i=0;i<board.size();i++){
			for(int j=0;j<board[i].size();j++){
				if(board[i][j] && board[i][j]->current_HP <=0){
					delete board[i][j];
					board[i][j] = nullptr;
				}
			}
		}
		
	}

	// returns true iff the board contains one or more soldiers of the given player.
	bool Board::has_soldiers(uint player_number) const{

		for (int i = 0; i < board.size(); i++) { 
    		    	for (int j = 0; j < board[i].size(); j++){
    			    	Soldier* soldier = board[i][j];
				if (soldier && soldier->player_number == player_number){
					return true;
				}
			}
    		} 
		return false;
	}
		    







}
