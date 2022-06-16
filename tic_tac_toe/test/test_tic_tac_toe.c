#define TEST
#ifdef TEST

#include "unity.h"

#include "tic_tac_toe.h"

void setUp(void)
{
    tic_tac_toe_init(); 
}

void tearDown(void)
{

}

void test_tic_tac_toe_X_player_move_after_tic(void)
{
    bool tic_result = tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0, 0); 
    bool tac_result = tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0, 0); 


    TEST_ASSERT_EQUAL(false, tac_result);
}


void test_tic_tac_toe_O_player_move_after_tac(void)
{
    bool tac_result = tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0, 0); 
    bool tic_result = tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0, 0); 

    TEST_ASSERT_EQUAL(false, tic_result); 

}

void test_tic_tac_toe_X_player_two_moves_in_a_row(void)
{
    bool tac_result = false; 

    tac_result = tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0, 0); 
    tac_result = tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,1, 1); 

    TEST_ASSERT_EQUAL(false, tac_result); 
}

void test_tic_tac_toe_O_player_two_moves_in_a_row(void)
{
    bool tic_result = false; 

    tic_result = tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0, 0); 
    tic_result = tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,1, 1); 

    TEST_ASSERT_EQUAL(false, tic_result); 
}

void test_tic_tac_toe_O_player_wins_row_0(void)
{
    tic_tac_toe_result_t game_result = TIC_TAC_TOE_GAME_IDLE; 
    
    /* scenario when plane has looks like foolowing 
    *   
    *  0 0 0
    *  - X -
    *  - - X
    *
    */
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,1,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,1,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,2,2); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,0); 

    game_result = tic_tac_toe_get_game_result(); 

    TEST_ASSERT_EQUAL(TIC_TAC_TOE_GAME_PLAYER_O_WIN, game_result); 
}

void test_tic_tac_toe_O_player_wins_row_2(void)
{
    tic_tac_toe_result_t game_result = TIC_TAC_TOE_GAME_IDLE; 
    
    /* scenario when plane has looks like foolowing 
    *   
    *  - - X
    *  0 0 0
    *  - - X
    *
    */
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,2,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,1,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,2,2); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,1); 

    game_result = tic_tac_toe_get_game_result(); 

    TEST_ASSERT_EQUAL(TIC_TAC_TOE_GAME_PLAYER_O_WIN, game_result); 
}

void test_tic_tac_toe_O_player_wins_column_1(void)
{
    tic_tac_toe_result_t game_result = TIC_TAC_TOE_GAME_IDLE; 
    
    /* scenario when plane has looks like foolowing 
    *   
    *  0 - -
    *  0 X -
    *  0 - X
    *
    */
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,1,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,2,2); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,2); 

    game_result = tic_tac_toe_get_game_result(); 

    TEST_ASSERT_EQUAL(TIC_TAC_TOE_GAME_PLAYER_O_WIN, game_result); 
}

void test_tic_tac_toe_O_player_wins_column_2(void)
{
    tic_tac_toe_result_t game_result = TIC_TAC_TOE_GAME_IDLE; 
    
    /* scenario when plane has looks like foolowing 
    *   
    *  - - 0
    *  - X 0
    *  X - 0
    *
    */
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,1,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0,2); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,2); 

    game_result = tic_tac_toe_get_game_result(); 

    TEST_ASSERT_EQUAL(TIC_TAC_TOE_GAME_PLAYER_O_WIN, game_result); 
}

void test_tic_tac_toe_O_player_wins_diagonal(void)
{
    tic_tac_toe_result_t game_result = TIC_TAC_TOE_GAME_IDLE; 

    /* scenario when plane has looks like foolowing 
    *   
    *  0 - -
    *  X 0 -
    *  X - 0
    *
    */

    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,1,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0,2); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,2); 

    game_result = tic_tac_toe_get_game_result(); 
 

    TEST_ASSERT_EQUAL(TIC_TAC_TOE_GAME_PLAYER_O_WIN, game_result); 

}

void test_tic_tac_toe_O_player_wins_diagonal_second(void)
{
    tic_tac_toe_result_t game_result = TIC_TAC_TOE_GAME_IDLE; 

    /* scenario when plane has looks like foolowing 
    *   
    *  X - 0
    *  X 0 -
    *  0 - -
    *
    */

    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,1,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,2); 

    game_result = tic_tac_toe_get_game_result(); 

    TEST_ASSERT_EQUAL(TIC_TAC_TOE_GAME_PLAYER_O_WIN, game_result); 
}


void test_tic_tac_toe_0_player_all_corners_set_should_not_win(void)
{
    tic_tac_toe_result_t game_result = TIC_TAC_TOE_GAME_IDLE; 

    /* scenario when plane has looks like foolowing 
    *   
    *  0 - 0
    *  X X -
    *  0 X 0
    *
    */

    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,1,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,2); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,1,2); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,2); 


    game_result = tic_tac_toe_get_game_result(); 

    TEST_ASSERT_EQUAL(TIC_TAC_TOE_GAME_RUNNING, game_result); 
}

void test_tic_tac_toe_0_player_corners_test_0_should_not_win(void)
{
    tic_tac_toe_result_t game_result = TIC_TAC_TOE_GAME_IDLE; 

    printf("test player 0 should not win \r\n");
    /* scenario when plane has looks like foolowing 
    *   
    *  X 0 -
    *  X 0 -
    *  0 X 0
    *
    */

    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,1,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,1,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,2); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,1,2); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,2); 


    game_result = tic_tac_toe_get_game_result(); 


    TEST_ASSERT_EQUAL(TIC_TAC_TOE_GAME_RUNNING, game_result); 
}

void test_tic_tac_toe_0_player_corners_test_1_should_not_win(void)
{
    tic_tac_toe_result_t game_result = TIC_TAC_TOE_GAME_IDLE; 

    /* scenario when plane has looks like foolowing 
    *   
    *  - 0 -
    *  X 0 X
    *  0 X 0
    *
    */

    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,1,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0,1);

    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,1,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,2,1);

    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,2); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,1,2);

    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,2); 


    game_result = tic_tac_toe_get_game_result(); 

    TEST_ASSERT_EQUAL(TIC_TAC_TOE_GAME_RUNNING, game_result); 
}


void test_tic_tac_toe_X_player_wins_diag(void)
{
    tic_tac_toe_result_t game_result = TIC_TAC_TOE_GAME_IDLE; 

    /* scenario when plane has looks like foolowing 
    *   
    *  X - -
    *  0 X -
    *  0 - X
    *
    */

    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,1);

    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,1, 1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0, 2);

    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,2, 2); 


    game_result = tic_tac_toe_get_game_result(); 


    TEST_ASSERT_EQUAL(TIC_TAC_TOE_GAME_PLAYER_X_WIN, game_result); 
}

void test_tic_tac_toe_players_draw_scenario(void)
{
    tic_tac_toe_result_t game_result = TIC_TAC_TOE_GAME_IDLE; 

    /* scenario when one of the players doesnt won after 5th move 
    *   
    *  X 0 X
    *  0 X X
    *  0 X 0
    *
    */

    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,0,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,1,0);

    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,2,0); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,1,0);

    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,1,1); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,0,2);

    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,1,2); 
    tic_tac_toe_player_move_update(TIC_TAC_TOE_O_PLAYER_ID,2,2);

    tic_tac_toe_player_move_update(TIC_TAC_TOE_X_PLAYER_ID,2,1); 


    game_result = tic_tac_toe_get_game_result(); 


    TEST_ASSERT_EQUAL(TIC_TAC_TOE_GAME_DRAW, game_result); 
}

#endif // TEST
