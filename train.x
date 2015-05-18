const MAX_ROW = 10;
const MAX_COL = 4;

struct seat {
       int row;
       int col;
};

program TRAIN {
	version TRAIN_VERS {
		int reserve_seat(seat) = 1;
	} = 1;
} = 0x31111111;