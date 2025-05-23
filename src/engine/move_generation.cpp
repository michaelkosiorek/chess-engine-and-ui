#include "move_generation.h"

#include "board.h"

std::vector<Move> generate_all_legal_moves(const Board& board)
{
	std::vector<Move> legal_moves;
    auto append_moves = [&legal_moves](const std::vector<Move>& piece_moves) {
        legal_moves.insert(legal_moves.end(), piece_moves.begin(), piece_moves.end());
    };

    append_moves(generate_king_moves(board));
    append_moves(generate_queen_moves(board));
    append_moves(generate_rook_moves(board));
    append_moves(generate_bishop_moves(board));
    append_moves(generate_knight_moves(board));
    append_moves(generate_pawn_moves(board));

	return legal_moves;
}