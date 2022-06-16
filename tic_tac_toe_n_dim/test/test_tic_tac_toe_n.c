#ifdef TEST

#include "unity.h"

#include "tic_tac_toe_n.h"

void setUp(void)
{
    tic_tac_toe_n_init(); 
}

void tearDown(void)
{
}

void test_tic_tac_toe_X_player_move_after_O_player(void)
{
    bool player_o_res = tic_tac_toe_n_player_move_update(TIC_TAC_TOE_PLAYER_O,0, 0); 
    bool player_x_res = tic_tac_toe_n_player_move_update(TIC_TAC_TOE_PLAYER_X,0, 0); 


    TEST_ASSERT_EQUAL(false, player_x_res);
}


void test_tic_tac_toe_O_player_move_after_X_player(void)
{
    bool player_x_res = tic_tac_toe_n_player_move_update(TIC_TAC_TOE_PLAYER_O,0, 0); 
    bool player_o_res = tic_tac_toe_n_player_move_update(TIC_TAC_TOE_PLAYER_X,0, 0); 

    TEST_ASSERT_EQUAL(false, player_o_res); 

}

void test_tic_tac_toe_X_player_two_moves_in_a_row(void)
{
    bool player_x_res = false; 

    player_x_res = tic_tac_toe_n_player_move_update(TIC_TAC_TOE_PLAYER_X,0, 0); 
    player_x_res = tic_tac_toe_n_player_move_update(TIC_TAC_TOE_PLAYER_X,1, 1); 

    TEST_ASSERT_EQUAL(false, player_x_res); 
}

void test_tic_tac_toe_O_player_two_moves_in_a_row(void)
{
    bool player_o_res = false; 

    player_o_res = tic_tac_toe_n_player_move_update(TIC_TAC_TOE_PLAYER_O,0, 0); 
    player_o_res = tic_tac_toe_n_player_move_update(TIC_TAC_TOE_PLAYER_O,1, 1); 

    TEST_ASSERT_EQUAL(false, player_o_res); 
}


#endif // TEST
