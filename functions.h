#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_ENTRIES 257
extern int test_count;//used to check for duplicates
int limit_ticket_sale(char *order_amount);
int rand_numb(char *raffle_list,char *transactions,unsigned int t_amount);
int check_num(char *file,int number);
#endif
