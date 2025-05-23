#ifndef CHESS_ENGINE_H
#define CHESS_ENGINE_H

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>

#include "piece.h"


// contains bitboards for all pieces & colors
class Board
{
public:
    std::unordered_map<Piece, uint64_t> piece_masks;
    uint64_t white_pieces;
    uint64_t black_pieces;
	bool white_to_move = true;

    struct CastlingRights {
        bool white_kingside = true;
        bool white_queenside = true;
        bool black_kingside = true;
        bool black_queenside = true;
    };

    Board() {
        piece_masks.reserve(12);
        set_default_position();
    }

    Piece get_piece_at(int square);

private:
    void set_default_position() {
        piece_masks[W_PAWN] = 0xFF00;
        piece_masks[W_ROOK] = 0x81;
        piece_masks[W_KNIGHT] = 0x42;
        piece_masks[W_BISHOP] = 0x24;
        piece_masks[W_QUEEN] = 0x10;
        piece_masks[W_KING] = 0x8;
        white_pieces = 0xFFFF;

        piece_masks[B_PAWN] = 0xFF000000000000;
        piece_masks[B_ROOK] = 0x8100000000000000;
        piece_masks[B_KNIGHT] = 0x4200000000000000;
        piece_masks[B_BISHOP] = 0x2400000000000000;
        piece_masks[B_QUEEN] = 0x1000000000000000;
        piece_masks[B_KING] = 0x0800000000000000;
        black_pieces = 0xFFFF000000000000;
    }
};

#endif