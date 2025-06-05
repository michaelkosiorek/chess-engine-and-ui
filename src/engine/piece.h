#ifndef PIECE_H
#define PIECE_H

enum Direction : int8_t {
    UP = 8,
    DOWN = -8,
    LEFT = 1,
    RIGHT = -1,

	UP_LEFT = 9,
	UP_RIGHT = 7,
	DOWN_LEFT = -7,
    DOWN_RIGHT = -9
};

/* It is ordered this way because this is how our uint64_t
bitboards are ordered. Looking at other chess engines, it seems
this isn't the typical order but I don't really need any kind
of cross-compatability so I prefer it the way that seems
logical to me */
enum Square : int8_t {
    H1 = 0, G1, F1, E1, D1, C1, B1, A1,
    H2, G2, F2, E2, D2, C2, B2, A2,
    H3, G3, F3, E3, D3, C3, B3, A3,
    H4, G4, F4, E4, D4, C4, B4, A4,
    H5, G5, F5, E5, D5, C5, B5, A5,
    H6, G6, F6, E6, D6, C6, B6, A6,
    H7, G7, F7, E7, D7, C7, B7, A7,
    H8, G8, F8, E8, D8, C8, B8, A8 = 63
};

/* See enum Square above for order explanation */
enum File : int8_t {
    FILE_H = 0,
    FILE_G = 1,
    FILE_F = 2,
    FILE_E = 3,
    FILE_D = 4,
    FILE_C = 5,
    FILE_B = 6,
    FILE_A = 7,
	N_FILES = 8
};

enum Rank : int8_t {
    RANK_1 = 0,
    RANK_2 = 1,
    RANK_3 = 2,
    RANK_4 = 3,
    RANK_5 = 4,
    RANK_6 = 5,
    RANK_7 = 6,
    RANK_8 = 7
};

enum Piece : int8_t {
    EMPTY = 0,
    W_PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
    B_PAWN, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING
};

#endif