/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "train.h"


void
train_1(char *host, char *row, char *col)
{
	CLIENT *clnt;
	int  *result_1;
	char *is_wagon_full_1_arg;
	available  *result_2;
	seat  is_seat_taken_1_arg;
	int  *result_3;
	seat  reserve_seat_1_arg;
	reserve_seat_1_arg.row = atoi(row) -1;
	reserve_seat_1_arg.col = atoi(col) -1;

#ifndef	DEBUG
	clnt = clnt_create (host, TRAIN, TRAIN_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = is_wagon_full_1((void*)&is_wagon_full_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = is_seat_taken_1(&reserve_seat_1_arg, clnt);
	if (result_2 == (available *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	/* result_3 = reserve_seat_1(&reserve_seat_1_arg, clnt); */
	/* if (result_3 == (int *) NULL) { */
	/* 	clnt_perror (clnt, "call failed"); */
	/* } */
	/* printf("El vagón está lleno? %d\n", *result_1); */
	int i;
	/* available r = *result_2; */
	/* seat *s = (seat)r.list; */
	printf("OLA BALE");
	fflush(stdout);
	/* for(i = 0; i < 40; ++i) { */
	  printf("VACIO: (%d, %d)\n", result_2->available_val[0].row, result_2->available_val[0].col);
	/* } */
	/* printf("RESERVA: %d\n", *result_3); */
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	train_1 (host, argv[2], argv[3]);
exit (0);
}
