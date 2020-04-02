#include "functions.h"

// stop the generator from creating a file bigger than the hard drive!!!!!!
//we also need to stop negative numbers...ARGH!
int limit_ticket_sale(char *amount){
	int ticket_amt = atoi(amount);//shrink it to limit 20 at a time		
	printf("you wanted %d tickets\n", ticket_amt);
	if (ticket_amt>20){
		printf("ticket maximum is 20\n");
		return 20;
	}else{return ticket_amt;} 
}
//try to change the seed based off time() fcn...
//takes the arg1 file name and passes it to check_num to open and lookup
int rand_numb(char *fptr, char *trans_id,unsigned int amt){
	//set the seed and put the start time in the file
	srand(time(0));
	FILE *trans = fopen(trans_id, "a+");
	if(trans==NULL){
		printf("transaction history file did not generate\n");
		//exit(1);
	}else{ 
		printf("printing transaction history\n");
		printf("clocking time(0):%d\n", time(0));
		fprintf(trans,"clocking time(0):%d\n", time(0));
		fprintf(trans,"amount of tickets to generate:%d\n",amt); 
		fclose(trans);
	}
	
	unsigned int the_num = 0;
	int replica_found = 0;
	int i = 0;

	for(i;i<amt;i++){
		//WE NEED TO EXCLUDE ZERO from the number list if atoi returns 0 for bad input
		//global test_count for testing
		
		int ran_num;
	    if(test_count==0){
		ran_num = 1796700401;
		test_count++;
	    }else{
	    		
		ran_num = rand();//hard coded number locks up prog if i--; when we match
	    }	
		int there = check_num(fptr,ran_num);
		if(there >= 0){
			//printf("%d is there already on line %d\n",ran_num,there);
			//we have to reroll the dice for one that is not there
			//i--;//should issue a new one and not affect the overall order amt
			replica_found++;
		}
		if(there < 0){
				FILE *fp = fopen(fptr, "a+");
				if(fp==NULL){
					printf("EXITING-bad file append or insert\n");
					exit(1);//might not wanna die just yet
				}else{ 
					//printf("file open for appending new number was a success\n");
					fprintf(fp,"%d\n", ran_num);
					fclose(fp);
				}	 			
		}
	}
	if(replica_found != 0){
		printf("must re-issue %d tickets due to replicas_found\n",replica_found);
		//while(no_more_replicas){
			//keep issuing unique ones....maybe this can take over the upper loop.
		}
		/*
		for(int j = 0;j<replica_found;j++){
			ran_num = rand();
			int there = check_num(fptr,ran_num);
			if(there >= 0){
				//printf("%d is there already on line %d\n",ran_num,there);
				//we have to reroll the dice for one that is not there
				//i--;//should issue a new one and not affect the overall order amt
				replica_found++;
			}
			if(there < 0){
				FILE *fp = fopen(fptr, "a+");
				if(fp==NULL){
					printf("EXITING-bad file append or insert\n");
					exit(1);//might not wanna die just yet
				}else{ 
					//printf("file open for appending new number was a success\n");
					fprintf(fp,"%d\n", ran_num);
					fclose(fp);
				}	 			
			}		
		}*/
	}	
	//now if there were duplicates found do these ove so the total order amount is correct
	return -1;//dont return until all instances are done
}
//return positive and the line referring to a find in the list, negative is no find
//zero CANNOT be part of the winning #???????????????????????????????
int check_num(char *p,int num){
	char *line = NULL;
	size_t length = 0;
	ssize_t get_line_chars;
	int line_found = -1;//for return
	//if it starts off empty eof will make comparison return -1
	FILE *fp = fopen(p, "a+");
	if(fp==NULL){
		printf("EXITING-bad file check_num\n");
		exit(1);
	}else{ 
		//printf("check_num file open was a success\n");
		
	}
	//we need a counter in here to say which line in the file we are at
	unsigned int count = 0;
	int line_convert;
	while((get_line_chars = getline(&line,&length,fp)) != -1){
		//printf("length %zu\n", get_line_chars);
		//printf("line as read:%s\n", line);
		
		/*strip trailing \n or \r due to getline fcn to compare strings
		while(get_line_chars>0 && (line[get_line_chars-1]=='\n'||line[get_line_chars]=='\r'))
			line[--get_line_chars] = 0;
		*/
		line_convert = atoi(line);
		if(num == line_convert){
			printf("%d duplicate found at line %d\n",line_convert,count);
			free(line);
			fclose(fp);
			return count;
		}
		count++;//zero based indexing....blah blah blah
	}
	free(line);
	fclose(fp);
	//printf("closed file\n");
	return line_found;	
}
