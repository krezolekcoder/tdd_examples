#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <stdint.h> 
#include <stdbool.h> 

typedef enum 
{
    TIC_TAC_TOE_GAME_IDLE = 0, 
    TIC_TAC_TOE_GAME_RUNNING = 1,
    TIC_TAC_TOE_GAME_PLAYER_O_WIN = 2, 
    TIC_TAC_TOE_GAME_PLAYER_X_WIN= 3, 
    TIC_TAC_TOE_GAME_DRAW= 4
    
}tic_tac_toe_result_t; 


typedef enum 
{
    TIC_TAC_TOE_O_PLAYER_ID = 0, 
    TIC_TAC_TOE_X_PLAYER_ID = 1,
    TIC_TAC_TOE_PLAYERS_CNT = 2
}tic_tac_toe_player_id_t; 


/**
 * @brief 
 * 
 */
void tic_tac_toe_init(void); 


bool tic_tac_toe_player_move_update(tic_tac_toe_player_id_t player_id, uint8_t x_coord, uint8_t y_coord); 

tic_tac_toe_result_t tic_tac_toe_get_game_result(void); 


#endif // TIC_TAC_TOE_H
