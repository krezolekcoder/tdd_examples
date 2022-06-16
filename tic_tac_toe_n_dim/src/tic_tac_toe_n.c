#include "tic_tac_toe_n.h"


typedef struct 
{
    uint32_t row_score; 
    uint32_t col_score; 
    uint32_t diags_score; 
    bool can_move; 

}player_t;

static tic_tac_toe_id_t prv_game_grid[GAME_DIMENSION][GAME_DIMENSION]; 

/**
 * @brief Make 2 players privately because tic tac toe cannot have more than 2 players 
 * 
 */
static player_t prv_players[TIC_TAC_TOE_PLAYERS_CNT]; 

static tic_tac_toe_n_result_t prv_game_result = TIC_TAC_TOE_N_GAME_RUNNING; 

void tic_tac_toe_n_init(void)
{
    for(int i = 0; i < GAME_DIMENSION; i++)
    {
        for(int j = 0; j < GAME_DIMENSION; j++)
        {
            prv_game_grid[i][j] = TIC_TAC_TOE_NONE; 
        }
    }

    for(int i = 0; i < TIC_TAC_TOE_PLAYERS_CNT; i++)
    {
        prv_players[i].can_move = true; 
        prv_players[i].row_score = 0U; 
        prv_players[i].col_score = 0U; 
        prv_players[i].diags_score = 0U; 
    }

}

bool tic_tac_toe_n_player_move_update(tic_tac_toe_id_t player_id, uint8_t x_coord, uint8_t y_coord)
{
    if(x_coord > GAME_DIMENSION - 1|| y_coord > GAME_DIMENSION - 1)
    {
        return false; 
    }

    // player cannot make two moves in a row 
    if(!prv_players[player_id].can_move)
    {
        return false; 
    }

    // check if this cell is free 
    if(prv_game_grid[x_coord][y_coord] != TIC_TAC_TOE_NONE)
    {
        return false; 
    }

    prv_game_grid[x_coord][y_coord] = player_id; 

    prv_players[player_id].can_move = false; 


    return true; 
}


tic_tac_toe_n_result_t tic_tac_toe_n_get_game_result(void)
{
    return prv_game_result; 
}