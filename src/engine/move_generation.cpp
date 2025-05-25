#include "move_generation.h"

#include <unordered_map>

#include "piece.h"
#include "board.h"
#include "masking_helpers.h"

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

std::vector<Move> generate_king_moves(const Board& board)
{
    std::vector<Move> moves;
    if (board.white_to_move)
    {

    }

	return moves;
}

std::vector<Move> generate_queen_moves(const Board& board)
{
    std::vector<Move> legal_queen_moves;
    std::vector<Move> eligible_queens;
    std::vector<int> queen_indices;

	Piece queen_side_to_move = board.white_to_move ? W_QUEEN : B_QUEEN;
    queen_indices = bitboard_to_indices(board.piece_masks.at(queen_side_to_move));



	return legal_queen_moves;
}

std::vector<Move> generate_rook_moves(const Board& board)
{
    std::vector<Move> moves;

	return moves;
}

std::vector<Move> generate_bishop_moves(const Board& board)
{
    std::vector<Move> moves;

    return moves;
}

std::vector<Move> generate_knight_moves(const Board& board)
{
    std::vector<Move> moves;

	return moves;
}

std::vector<Move> generate_pawn_moves(const Board& board)
{
    std::vector<Move> legal_pawn_moves;
    std::vector<Move> eligible_pawns;
    std::vector<int> pawn_indices;

    Piece pawn_side_to_move = board.white_to_move ? W_PAWN : B_PAWN;
    pawn_indices = bitboard_to_indices(board.piece_masks.at(pawn_side_to_move));

	uint64_t default_pawn_positions = board.white_to_move ? 0xFF00 : 0xFF000000000000;
    for (auto pawn_idx : pawn_indices)
    {
        if (double_move_is_legal(board, pawn_idx))
        {
			legal_pawn_moves.push_back(generate_double_push_move(board, pawn_idx));
        }
            
    }


    return legal_pawn_moves;
}

bool double_move_is_legal(const Board& board, const int& pawn_idx)
{
	const int direction_offset = board.white_to_move ? 8 : -8;
	uint64_t in_between_square = 1ULL << (pawn_idx + direction_offset);
    uint64_t destination_square = 1ULL << (pawn_idx + direction_offset * 2);
    if (in_between_square & destination_square & board.all_pieces)
        return false;
    else
        return true;
}

Move generate_double_push_move(const Board& board, const int& pawn_idx)
{
    const int double_push_offset = board.white_to_move ? 16 : -16;
    Move move;
    move.from = pawn_idx;
    move.to = pawn_idx + double_push_offset;
	move.moving_piece = board.white_to_move ? W_PAWN : B_PAWN;
    return move;
}
