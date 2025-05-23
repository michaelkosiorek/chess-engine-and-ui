#include "board.h"

#include "piece.h"

Piece Board::get_piece_at(int square)
{
    uint64_t mask = 1ULL << square;

    for (const auto& [piece, bitboard] : piece_masks) {
        if (bitboard & mask) {
            return piece;
        }
    }
    return EMPTY;
}