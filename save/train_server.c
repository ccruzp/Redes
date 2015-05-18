/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "train.h"

int seats[MAX_ROW][MAX_COL];
int i, j;
int seatsAvailable = MAX_ROW * MAX_COL;

int *
is_wagon_full_1_svc(void *argp, struct svc_req *rqstp)
{
  static int  result;
  if (seatsAvailable > 0) { 
    result = 0;
    printf("Not full: %d %d\n", seatsAvailable, result);
  } else {
    result = 1;
    printf("Full: %d %d\n", seatsAvailable, result);
  }
  return &result;
}

available *
is_seat_taken_1_svc(seat *argp, struct svc_req *rqstp)
{
	static available result;
	seat list[seatsAvailable];
	int k = 0;
	seat s;
	for(i = 0; i < MAX_ROW; ++i) {
	  for(j = 0; j < MAX_COL; ++j) {
	    if(seats[i][j] == 0) {
	      /* s = {i, j}; */
	      result.list[k].row = i;
	      result.list[k].col = j;
	      ++k;
	    }
	  }
	}
	/* int list[seatsAvailable]; */
	/* int l = 0; */
	/* for(i = 0; i < MAX_ROW; ++i) { */
	/*   for(j = 0; j < MAX_COL; ++j) { */
	/*     if (seats[i][j] == 0) { */
	/*       list[l] = i; */
	/*       ++l; */
	/*     } */
	/*   } */
	/* } */
	/* result.list = list; */
	return &result;
}

int *
reserve_seat_1_svc(seat *argp, struct svc_req *rqstp)
{
  static int  result;
  seat s = *argp;
  seats[s.row][s.col] = 1;
  for (i = 0; i < MAX_ROW; ++i) {
    for(j = 0; j < MAX_COL; ++j) {
      printf("%d ", seats[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  result = 1;
  return &result;
}
