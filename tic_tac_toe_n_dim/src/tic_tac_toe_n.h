#ifndef TIC_TAC_TOE_N_H
#define TIC_TAC_TOE_N_H

// N DIMENSIONS TIC TAC TOE 
#include <stdint.h> 
#include <stdbool.h> 

#define GAME_DIMENSION   (3U)

typedef enum 
{
    TIC_TAC_TOE_N_IDLE = 0, 
    TIC_TAC_TOE_N_GAME_RUNNING, 
    TIC_TAC_TOE_N_PLAYER_O_WINS, 
    TIC_TAC_TOE_N_PLAYER_X_WINS, 
    TIC_TAC_TOE_N_DRAW
}tic_tac_toe_n_result_t;

typedef enum 
{
    TIC_TAC_TOE_NONE = -1, 
    TIC_TAC_TOE_PLAYER_O, 
    TIC_TAC_TOE_PLAYER_X,
    TIC_TAC_TOE_PLAYERS_CNT 
}tic_tac_toe_id_t; 

void tic_tac_toe_n_init(void); 

bool tic_tac_toe_n_player_move_update(tic_tac_toe_id_t player_id, uint8_t x_coord, uint8_t y_coord); 

tic_tac_toe_n_result_t tic_tac_toe_n_get_game_result(void); 


#endif // TIC_TAC_TOE_N_H
