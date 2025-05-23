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
    void set_default_position();
	// updates white_pieces and black_pieces bitboards
    void update_side_masks();
};

#endif