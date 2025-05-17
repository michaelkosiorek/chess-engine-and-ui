#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include "engine_helpers.h"

uint64_t square_to_bitboard(std::string square)
{   
    if (square.size() != 2) exit(EXIT_FAILURE);
    char file = square[0];
    char rank = square[1];
    assert(file >= 'a' && file <= 'h');
    assert(rank >= '1' && rank <= '8');

    // a = 128 (10000000), h = 1
    uint64_t bitboard = fastPower(2, ('h' - file));
    bitboard = bitboard << ((rank - '0') - 1) * 8;
    return bitboard;
}

class Board
{   
    public:
    std::unordered_map<std::string, uint64_t> pieces;
    uint64_t white_pieces;
    uint64_t black_pieces;

    Board()
    {   
        pieces.reserve(12);
        // default positions
        pieces["w_pawns"] = 0xFF00;
        pieces["w_rooks"] = 0x81;
        pieces["w_knights"] = 0x42;
        pieces["w_bishops"] = 0x24;
        pieces["w_queens"] = 0x10;
        pieces["w_king"] = 0x8;
        white_pieces = 0xFFFF;

        pieces["b_pawns"] = 0xFF000000000000;
        pieces["b_rooks"] = 0x8100000000000000;
        pieces["b_knights"] = 0x4200000000000000;
        pieces["b_bishops"] = 0x2400000000000000;
        pieces["b_queens"] = 0x1000000000000000;
        pieces["b_king"] = 0x0800000000000000;
        black_pieces = 0xFFFF000000000000;
    }


};