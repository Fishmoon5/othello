#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    int minimax(Board *board, int depth, Side side, bool isEnd);
    int naiveScore(Board *board, Side side);
    int betterScore(Board *board, Side side);
	int dynamicScore(Board *board, Side side);

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
    Board *currBoard;

private:
	int searchDepth;
    Side us;
    Side oppo;
    Move *bestMove;
    
    int scoreMatrix[64] = {
	 99,  -8,  8,  6,  6,  8,  -8,  99,
	 -8, -24, -4, -3, -3, -4, -24,  -8,
	  8,  -4,  7,  4,  4,  7,  -4,   8,
	  6,  -3,  4,  0,  0,  4,  -3,   6,
	  6,  -3,  4,  0,  0,  4,  -3,   6,
	  8,  -4,  7,  4,  4,  7,  -4,   8,
	 -8, -24, -4, -3, -3, -4, -24,  -8,
	 99,  -8,  8,  6,  6,  8,  -8,  99
    };
    
	int scoreMatrix2[64] = {
	 20, -3, 11,  8,  8, 11, -3, 20,
	 -3, -7, -4,  1,  1, -4, -7, -3,
	 11, -4,  2,  2,  2,  2, -4, 11,
	  8,  1,  2, -3, -3,  2,  1,  8,
	  8,  1,  2, -3, -3,  2,  1,  8,
	 11, -4,  2,  2,  2,  2, -4, 11,
	 -3, -7, -4,  1,  1, -4, -7, -3,
	 20, -3, 11,  8,  8, 11, -3, 20
    };
};

#endif
