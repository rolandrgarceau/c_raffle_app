#include "functions.h"
int test_count = 0;
//global variable errno set if FILE pointer returned is NULL, indicating error
int main(int argc, char **argv){
	FILE *fp;
	//the raffle and the amount of tickets
	if(argc==4){
		char *arg0 = argv[0];
		char *arg1 = argv[1];
		char *arg2 = argv[2];
		char *arg3 = argv[3];
		printf("exe is %s,list is %s,ticket order amount is %s,transatcions is %s \n", arg0,arg1,arg2,arg3);
		//printf("you entered:%s", file_name);
		
		//int f_name_len = strlen(file_name);
		//printf("length of file_name is %d\n", f_name_len-1);
		//int *cur_ticket = NULL;
		int act_tickets = limit_ticket_sale(arg2);
		
		int done = rand_numb(arg1,arg3,act_tickets);
		//get the line count for the amount in the list
		FILE *t_list = fopen(arg1, "r");
		if(t_list==NULL){
			printf("list count did not generate\n");
			//exit(1);
		}else{ 
			char c;
			int line_counter = 0;
			while(!feof(t_list)){
				c = fgetc(t_list);
				if(c == '\n')line_counter++;
			}
			printf("lis now contains %d entries\n", line_counter);
			fclose(t_list);
		}
		return 0;
	}else{
		printf("passing argument problem\n");
		fprintf(stderr, "we have problems houston\n");
		exit(1);
	}
}
