/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

#include <cassert>

namespace WarGame {

		DemoGame::DemoGame(): board (numRows, numCols) {
		   board[{0,0}] = new FootSoldier(1);
		    board[{0,1}] = new FootSoldier(2);
		    board[{0,3}] = new SniperCommander(2);
		    board[{0,4}] = new FootCommander(2);
		    board[{2,0}] = new Paramedic(2);
		    board[{2,1}] = new Paramedic(1);
		    board[{2,2}] = new FootCommander(1);
		    board[{2,3}] = new SniperCommander(1);
		    board[{4,0}] = new Sniper(1);
		    board[{4,1}] = new Sniper(2);
		    board[{4,3}] = new ParamedicCommander(1);
		   board[{4,4}] = new ParamedicCommander(2);

		}

		uint DemoGame::play() {
    board.move(1,{2,2},WarGame::Board::Up);

    board.move(1,{2,3},WarGame::Board::Down);

    board.move(1,{4,3},WarGame::Board::Down);

    board.move(2,{0,4},WarGame::Board::Up);

    board.move(2,{0,3},WarGame::Board::Left);

    board.move(2,{4,4},WarGame::Board::Down);
			return 0;
		}

		void DemoGame::print(){
			for (int iRow=0; iRow<numRows; ++iRow) {
				for (int iCol=0; iCol<numCols; ++iCol) {
					Soldier* soldier = board[{iRow,iCol}];
					if (soldier){
						cout<<soldier->player_number;
					}
					else
						cout<<"0";
				}
				cout<<endl;
			}
		}

		DemoGame::~DemoGame() {
			for (int iRow=0; iRow<numRows; ++iRow) {
				for (int iCol=0; iCol<numCols; ++iCol) {
					Soldier* soldier = board[{iRow,iCol}];
					if (soldier){
						//cout<<iRow<<","<<iCol<<endl;
						delete soldier;
					}
				}
			}
		}

}
