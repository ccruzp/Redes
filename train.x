const MAX_ROW = 10;
const MAX_COL = 4;

struct seat {
       int row;
       int col;
};

typedef seat available[40];

program TRAIN {
	version TRAIN_VERS {
		int is_wagon_full() = 1;
		available is_seat_taken(seat) = 2;
		int reserve_seat(seat) = 3;
	} = 1;
} = 0x31111111;