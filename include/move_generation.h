#ifndef MOVE_GENERATION_H
#define MOVE_GENERATION_H

#include <vector>

#include "piece.h"

struct Move
{
	int from;
	int to;
	Piece moving_piece;
	Piece captured_piece = EMPTY;
	Piece piece_promoted_to = EMPTY;
	bool is_castle = false;
	bool is_promotion = false;
};

std::vector<Move> generate_all_legal_moves(const Board& board);
std::vector<Move> generate_king_moves(const Board& board);
std::vector<Move> generate_queen_moves(const Board& board);
std::vector<Move> generate_rook_moves(const Board& board);
std::vector<Move> generate_bishop_moves(const Board& board);
std::vector<Move> generate_knight_moves(const Board& board);
std::vector<Move> generate_pawn_moves(const Board& board);

bool double_move_is_legal(const Board& board, const int& pawn_idx);	
Move generate_double_push_move(const Board& board, const int& pawn_idx);


#endif