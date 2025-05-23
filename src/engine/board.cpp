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

void Board::set_default_position() {
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

void Board::update_side_masks()
{
    white_pieces = piece_masks[W_PAWN] | piece_masks[W_ROOK] | piece_masks[W_KNIGHT] |
        piece_masks[W_BISHOP] | piece_masks[W_QUEEN] | piece_masks[W_KING];
	black_pieces = piece_masks[B_PAWN] | piece_masks[B_ROOK] | piece_masks[B_KNIGHT] |
        piece_masks[B_BISHOP] | piece_masks[B_QUEEN] | piece_masks[B_KING]; 
}