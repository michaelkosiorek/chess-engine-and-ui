#ifndef MOVE_GENERATION_H
#define MOVE_GENERATION_H

#include <vector>

#include "piece.h"

struct Move
{
	int from;
	int to;
	Piece moving_piece;
	Piece captured_piece;
	Piece piece_promoted_to;
	bool is_castle;
	bool is_promotion;
};

std::vector<Move> generate_all_legal_moves(const Board& board);
std::vector<Move> generate_king_moves(const Board& board);
std::vector<Move> generate_queen_moves(const Board& board);
std::vector<Move> generate_rook_moves(const Board& board);
std::vector<Move> generate_bishop_moves(const Board& board);
std::vector<Move> generate_knight_moves(const Board& board);
std::vector<Move> generate_pawn_moves(const Board& board);

#endif