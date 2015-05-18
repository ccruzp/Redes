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
    fflush(stdout);
  } else {
    result = 1;
    printf("Full: %d %d\n", seatsAvailable, result);
    fflush(stdout);
  }
  return &result;
}

available *
is_seat_taken_1_svc(seat *argp, struct svc_req *rqstp)
{
	static available result;
	result.available_val = malloc(sizeof(seat)*40);
	for(i = 0; i < 40; ++i) {
	  result.available_val[i].row = i;
	  result.available_val[i].col = i;
	  /* printf("ASIENTO: (%d, %d)\n", result.available_val[i].row, result.available_val[i].col); */
	}
	/* seat list[seatsAvailable]; */
	int k = 0;
	/* printf("OLA BALE"); */
	/* fflush(stdout); */
	/* seat s; */
	for(i = 0; i < MAX_ROW; ++i) {
	  for(j = 0; j < MAX_COL; ++j) {
	    if(seats[i][j] == 0) {
	      /* s = {i, j}; */
	      /* printf("%d ", seats[i][j]); */
	      /* fflush(stdout); */
	      result.available_val[k].row = i;
	      result.available_val[k].col = j;
	      /* printf("HOLA: %d %d\n", result.available_val[k].row, result.available_val[k].col); */
	      ++k;
	    }
	  }
	  /* printf("\n"); */
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
      fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
  }
  printf("\n");
  fflush(stdout);
  result = 1;
  return &result;
}
