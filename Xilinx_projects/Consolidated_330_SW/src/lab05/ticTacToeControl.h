/*
 * ticTacToeControl.h
 *
 *  Created on: Jun 2, 2015
 *      Author: Taylor Cowley
 */

#ifndef TICTACTOECONTROL_H_
#define TICTACTOECONTROL_H_

#include "ticTacToeDisplay.h"
#include "minimax.h"
#include <stdint.h>
#include <stdio.h>


//How many ticks we need to wait for the touch screen AD converter to cool down
#define TICTACTOECONTROL_TOUCH_COOLDOWN 1
#define TICTACTOECONTROL_PLAYER_TIMEOUT 15
#define TICTACTOECONTROL_STATUS_TEXT_SIZE 4
#define TICTACTOECONTROL_STATUS_TEXT_X 20
#define TICTACTOECONTROL_STATUS_TEXT_Y 100
#define TICTACTOECONTROL_CENTER 1

enum ticTacToeControl_state_t {
	init_state,							//boots up the game
	init_choose_players,				//displays the choose players dialog
	choose_players,						//waiting to choose players
	choose_players_chosen,				//Wait for them to lift their finger
	CPU_turn,							//X's turn
	player_turn,						//O's turn
	player_touch_wait_state,			//waiting for O's touch to cool off
	game_over,							//display who wins
	end_game							//wait for new game
};


//Ticks the current state of ticTacToe and returns the next state
void ticTacToeControl_tick();

//Starts the game
void ticTacToeControl_init();

//Displays a string to the screen- user notification and endgame results
void ticTacToeControl_print_status(const char str[]);



#endif /* TICTACTOECONTROL_H_ */
