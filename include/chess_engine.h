#ifndef CHESS_ENGINE_H
#define CHESS_ENGINE_H

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>

// handles a1 -> a8, through h1 -> h8 (only lowercase)
// a1 -> 0x80/128, b2 -> 0x4000/16384
uint64_t square_to_bitboard(const std::string& square);
// for one square only
std::string bitboard_to_square(const uint64_t& bitboard);

// contains bitboards for all pieces & colors
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

#endif