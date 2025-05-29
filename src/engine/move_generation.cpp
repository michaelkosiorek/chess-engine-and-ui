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
    std::vector<int> pawn_indices;

    Piece pawn_side_to_move = board.white_to_move ? W_PAWN : B_PAWN;
    pawn_indices = bitboard_to_indices(board.piece_masks.at(pawn_side_to_move));

    for (auto pawn_idx : pawn_indices)
    {   
        // Single push check
        if (pawn_push_is_legal(board, pawn_idx, 1))
        {
            legal_pawn_moves.push_back(generate_pawn_push_move(board, pawn_idx, false));
            // Double push check
            if (pawn_push_is_legal(board, pawn_idx, 2))
                legal_pawn_moves.push_back(generate_pawn_push_move(board, pawn_idx, true));
        }
        // Captures
        int left_offset = board.white_to_move ? 7 : -9;
        int right_offset = board.white_to_move ? 9 : -7;

        if (pawn_capture_is_legal(board, pawn_idx, left_offset))
            legal_pawn_moves.push_back({ pawn_idx, pawn_idx + left_offset, pawn_side_to_move });
        if (pawn_capture_is_legal(board, pawn_idx, right_offset))
            legal_pawn_moves.push_back({ pawn_idx, pawn_idx + right_offset, pawn_side_to_move });
            
    }

    return legal_pawn_moves;
}

bool pawn_push_is_legal(const Board& board, int pawn_idx, int push_distance)
{ 
    const int direction = board.white_to_move ? 8 : -8;

	// Make sure the pawn is on starting rank for double push
    if (push_distance == 2) {
        uint64_t starting_rank = board.white_to_move ? 0xFF00ULL : 0xFF000000000000ULL;
        if (!(1ULL << pawn_idx & starting_rank))
            return false;
    }

    // Check each square the pawn would move through
    for (int step = 1; step <= push_distance; ++step) {
        int target_idx = pawn_idx + direction * step;
        uint64_t target_bit = 1ULL << target_idx;
        if (target_bit & board.all_pieces)
            return false;
    }

    return true;
}

Move generate_pawn_push_move(const Board& board, int pawn_idx, bool is_double)
{
    int offset = board.white_to_move ? (is_double ? 16 : 8)
        : (is_double ? -16 : -8);
    Piece piece_type = board.white_to_move ? W_PAWN : B_PAWN;
    return { pawn_idx, pawn_idx + offset, piece_type };
}

bool pawn_capture_is_legal(const Board& board, int pawn_idx, int capture_offset)
{
    int target_idx = pawn_idx + capture_offset;

    // make sure target index in bounds
    if (target_idx < 0 || target_idx > 63)
        return false;

	// dont let pawns capture off board
    int file = pawn_idx % 8;
    if ((capture_offset == (board.white_to_move ? 7 : -9) && file == 0) ||
        (capture_offset == (board.white_to_move ? 9 : -7) && file == 7))
        return false;

    uint64_t target_bit = 1ULL << target_idx;
    const uint64_t opponent_pieces = board.white_to_move ? board.black_pieces : board.white_pieces;

    return (target_bit & opponent_pieces) != 0;
}
