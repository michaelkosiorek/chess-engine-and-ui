#include "chess_engine.h"
#include "math_utils.h"


// a1 -> 0x80/128, b2 -> 0x4000/16384
int64_t square_to_bitboard(const std::string& square)
{
    if (square.size() != 2) exit(EXIT_FAILURE);

    char file = square[0];
    char rank = square[1];
    assert(file >= 'a' && file <= 'h');
    assert(rank >= '1' && rank <= '8');

    int index = (rank - '1') * 8 + (file - 'h') * -1;
    return 1ULL << index;
}
