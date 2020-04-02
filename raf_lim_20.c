#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int limit_ticket_sale(char *);
void rand_numb(unsigned int);
FILE *fp;

//global variable errno set if FILE pointer returned is NULL, indicating error
int main(int argc, char **argv){
	//the raffle and the amount of tickets
	if(argc==3){
		char *arg0 = argv[0];
		char *arg1 = argv[1];
		char *arg2 = argv[2];
		printf("exe is %s,raffle_file is %s,ticket_amount is %s\n", arg0,arg1,arg2);
		//printf("you entered:%s", file_name);
		
		//int f_name_len = strlen(file_name);
		//printf("length of file_name is %d\n", f_name_len-1);
		int act_tickets = limit_ticket_sale(arg2);
		fp = fopen(arg1, "a+");
		if(fp==NULL){
			printf("EXITING-bad file creation\n");
			exit(1);
		}else{ 
			printf("file was a success\n");
			//printf("Rudy's FOPEN_MAX is %d\n", FOPEN_MAX);
			//printf("Rudy's FILENAME_MAX is %d\n", FILENAME_MAX);
			//printf("Rudy's time(0) is %d\n", time(0) );
			//printf("Rudy's time(NULL) is %d\n", time(NULL) );
			rand_numb(act_tickets);
		}
		fclose(fp);
		//printf("closed file\n");
		return 0;
	}else{
		printf("passing argument problem\n");
		fprintf(stderr, "we have problems houston\n");
		exit(1);
	}
}
int limit_ticket_sale(char *amount){
	int ticket_amt = atoi(amount);//shrink it to limit 20 at a time		
	printf("you wanted %d tickets\n", ticket_amt);
	if (ticket_amt>20){
		printf("ticket maximum is 20\n");
		return 20;
	}else{return ticket_amt;} 
}
//try to change the seed based off time() fcn...

void rand_numb(unsigned int amt){
	//set the seed and put the start time in the file
	srand(time(0));
	fprintf(fp,"clocking time(0):%d\n", time(0));
	fprintf(fp,"amount to generate:%d\n",amt); 
	unsigned int the_num = 0;
	int i = 0;
	for(i;i<amt;i++){
		fprintf(fp,"%d\n", rand());
	}
}
