#pragma once

#define ACCEPTABLE_MOVES ((s == 0 && pos == 1) || (s == 0 && pos == 3) || (s == 0 && pos == 4) || (s == 0 && pos == 2) || (s == 1 && pos == 4) || (s == 1 && pos == 2))

#define ACCEPTABLE_MOVES_1 (side == 0 && pos == 1)

#define ACCEPTABLE_MOVES_2 (side == 0 && pos == 2) 

#define ACCEPTABLE_MOVES_3 (side == 0 && pos == 3) 

#define ACCEPTABLE_MOVES_4 (side == 0 && pos == 4)

#define ACCEPTABLE_MOVES_5 (side == 1 && pos == 2)

#define ACCEPTABLE_MOVES_6 (side == 1 && pos == 4)

