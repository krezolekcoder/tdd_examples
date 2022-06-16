#include "tic_tac_toe.h"

// helper macros 

#define ABS(x) (x < 0 ? -x : x)
#define BIT_SET(var, nbit) (var |= (1U << nbit))
#define BIT_CLR(var, nbit) (var &= ~(1U << nbit))
#define BIT_CHECK(var, nbit) (var & (1U << nbit))
#define BIT_TOGGLE(var, nbit) (var ^= (1U << nbit)) 

#define GRID_DIMENSON           (3U)
#define GRID_CENTER_IDX         (4U)
#define PLAYER_LOCK_IDX         (15U)
#define PLAYER_WIN_BIT_IDX   (14U) // if bit is set player has won 
#define NONE_BIT_SET            (0xFFU) 
#define MAX_MOVES_CNT           (5U)

#define TIC_TAC_PLANE_LOCK_NEXT_MOVE(plane) (BIT_SET(plane, PLAYER_LOCK_IDX))
#define TIC_TAC_PLANE_UNLOCK_NEXT_MOVE(plane) (BIT_CLR(plane, PLAYER_LOCK_IDX))

static tic_tac_toe_result_t prv_game_result = TIC_TAC_TOE_GAME_IDLE; 

static uint16_t prv_player_O_plane_state = 0x0000; 
static uint16_t prv_player_X_plane_state = 0x0000;  

static uint16_t prv_tic_tac_toe_players[TIC_TAC_TOE_PLAYERS_CNT] = {0x0000, 0x0000}; 

/**
 * @brief 
 * 
 * @param player_grid 
 * @param current_result 
 */
static void prv_update_game_state(uint16_t *player_grid); 

static bool prv_check_columns_state(uint16_t *player_grid); 
static bool prv_check_rows_state(uint16_t *player_grid); 
static bool prv_check_diag_state(uint16_t *player_grid); 
static bool prv_check_draw(uint16_t *player_grid); 

//////////////////////////// INTERFACE IMPLEMENTATION /////////////////////////////////////
void tic_tac_toe_init(void)
{
    prv_game_result = TIC_TAC_TOE_GAME_RUNNING; 
    prv_player_O_plane_state = 0x0000; 
    prv_player_X_plane_state = 0x0000; 

    prv_tic_tac_toe_players[0] = 0x0000; 
    prv_tic_tac_toe_players[1] = 0x0000; 

}

bool tic_tac_toe_player_move_update(tic_tac_toe_player_id_t player_id, uint8_t x_coord, uint8_t y_coord)
{
    
    if(x_coord > (GRID_DIMENSON - 1U) && y_coord > (GRID_DIMENSON - 1U))
    {   
        return false; 
    }

    // make first guess of oponnent id 
    tic_tac_toe_player_id_t opponent_id = TIC_TAC_TOE_O_PLAYER_ID; 

    // if it is wrong then change id to second - we only have 2 players
    if(opponent_id == player_id)
    {
        opponent_id = TIC_TAC_TOE_X_PLAYER_ID; 
    }

    // check if player can make a move 
    if(BIT_CHECK(prv_tic_tac_toe_players[player_id], PLAYER_LOCK_IDX))
    {   
        return false; 
    }

    // check if oponnent has this coord set 
    if(BIT_CHECK(prv_tic_tac_toe_players[opponent_id], x_coord + y_coord * GRID_DIMENSON))
    {   
        return false; 
    }

    // SET given bit on player grid and check game state 

    BIT_SET(prv_tic_tac_toe_players[player_id], x_coord + y_coord * GRID_DIMENSON); 

    prv_update_game_state(&prv_tic_tac_toe_players[player_id]); 


    // Check win conditions 
    if(BIT_CHECK(prv_tic_tac_toe_players[player_id], PLAYER_WIN_BIT_IDX))
    {   
        if(player_id == TIC_TAC_TOE_O_PLAYER_ID)
        {   
            prv_game_result = TIC_TAC_TOE_GAME_PLAYER_O_WIN; 
        }   
        else
        {
            prv_game_result = TIC_TAC_TOE_GAME_PLAYER_X_WIN; 
        }
    }

    /* make sure that tic player would not make two moves in a row */ 
    TIC_TAC_PLANE_LOCK_NEXT_MOVE(prv_tic_tac_toe_players[player_id]); 

    /* allow tac player to make next move */ 
    TIC_TAC_PLANE_UNLOCK_NEXT_MOVE(prv_tic_tac_toe_players[opponent_id]); 

    return true; 
}

tic_tac_toe_result_t tic_tac_toe_get_game_result(void)
{
    return prv_game_result; 
}

////////////////////// PRIVATE FUNCTIONS IMPLEMENTATION ////////////////////////////////


static void prv_update_game_state(uint16_t* player_grid)
{   
    // Check if player has 3 x or o in column 
    if(prv_check_columns_state(player_grid))
    {
        BIT_SET(*player_grid, PLAYER_WIN_BIT_IDX); 
        return; 
    }     
    // Check if player has 3 X or O in a row

    if(prv_check_rows_state(player_grid))
    {
        BIT_SET(*player_grid, PLAYER_WIN_BIT_IDX); 
        return; 
    }

    // Check if player has 3 X or O in diagonal 
    if(prv_check_diag_state(player_grid))
    {   
        BIT_SET(*player_grid, PLAYER_WIN_BIT_IDX); 
        return; 
    }

    // If none of upper conditions where met - check if we have draw 

    if(prv_check_draw(player_grid))
    {
        prv_game_result = TIC_TAC_TOE_GAME_DRAW; 
    }
}



static bool prv_check_columns_state(uint16_t *player_grid)
{
    for (int y = 0; y < GRID_DIMENSON ; y++)
    {   
        uint8_t col_result = 0U; 

        for(int x = 0 ; x < GRID_DIMENSON; x++)
        {
            if(BIT_CHECK(*player_grid, x + y * GRID_DIMENSON))
            {
                col_result++; 
            }
        }

        if(col_result == GRID_DIMENSON)
        {   
            return true;  
        }
        
    }

    return false; 
}

static bool prv_check_rows_state(uint16_t *player_grid)
{
    for( int x = 0; x < GRID_DIMENSON ; x++)
    {
        uint8_t row_result = 0U; 

        for(int y = 0; y < GRID_DIMENSON ; y++)
        {
            if(BIT_CHECK(*player_grid, x + y * GRID_DIMENSON))
            {
                row_result++; 
            }
        }

        if(row_result == GRID_DIMENSON)
        {
            return true; 
        }
    }
    return false; 
}

static bool prv_check_diag_state(uint16_t *player_grid)
{
    uint8_t first_diag_result = 0U; 
    uint8_t second_diag_result = 0U; 

    // RUN check diag algorithm only if center diag is set 

    if(BIT_CHECK(*player_grid, GRID_CENTER_IDX))
    {
        // helper var 
        uint8_t plane_idx = 0U;

        for(int x = 0; x < GRID_DIMENSON; x++)
        {
            for(int y = 0; y < GRID_DIMENSON ; y++)
            {   
                // For ease of use 
                plane_idx = x + y * GRID_DIMENSON; 

                // ONLY CHECK CORNERS 
                if(plane_idx != GRID_CENTER_IDX){
                    
                    if(plane_idx % GRID_CENTER_IDX == 0U)
                    {
                        // CHECK FIRST DIAGONAL 
                        if(BIT_CHECK(*player_grid, plane_idx))
                        {
                            first_diag_result++; 
                        }

                    } // if this condition is met second diagonal will be checked 
                    else if((plane_idx % 2U == 0U) && (plane_idx % GRID_CENTER_IDX != 0U))
                    {
                        // CHECK SECOND DIAGONAL 
                        if(BIT_CHECK(*player_grid, plane_idx))
                        {
                            second_diag_result++; 
                        }
                    }
                    else
                    {
                        ;
                    }
                }
            }
        }

    }    

    if(first_diag_result == GRID_DIMENSON - 1 || second_diag_result == GRID_DIMENSON - 1)
    {   
        return true; 
    }

    return false; 
}

static bool prv_check_draw(uint16_t *player_grid)
{   
    // if one of the player has 5 moves and doesnt won yet then it must be draw

    // calculate no of moves 
    uint8_t moves_no = 0U; 

    for( int i = 0; i < GRID_DIMENSON * GRID_DIMENSON ; i++)
    {
        if(BIT_CHECK(*player_grid, i))
        {
            moves_no++; 
        }
    }

    return moves_no == MAX_MOVES_CNT; 
}