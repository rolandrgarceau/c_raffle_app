#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
int select_winner(char *file,int count);
int main(int argc, char **argv){
	FILE *fp;
	//the raffle file
	if(argc==2){
		char *arg0 = argv[0];
		char *arg1 = argv[1];
		
		//printf("exe is %s,list is %s\n",arg0,arg1);
		//get the line count for the amount in the list
		FILE *t_list = fopen(arg1, "r");
		if(t_list==NULL){
			printf("list count did not generate\n");
			exit(1);
		}else{ 
			char c;
			int line_counter = 0;
			while(!feof(t_list)){
				c = fgetc(t_list);
				if(c == '\n')line_counter++;
			}
			//printf("list contains %d entries\n", line_counter);
			fclose(t_list);
			//the actual winner would be the trans id# info with the ticket number
			if(line_counter==0){//the file was there but empty
				printf("file was empty\n");//dont proceed because modulo division by zero is bad...umkay...			
			}
			int the_winner = select_winner(arg1,line_counter);
			//create_winner_file(the_winner);
			//send_email(winner_file);
		}
		return 0;
	}else{
		printf("passing argument problem\n");
		fprintf(stderr, "we have problems houston\n");
		exit(1);
	}
}
/*num is the number of lines found in the file to mod on
//num cannot be zero-in denominator is undefined
choose rand number, mod on the amount of lines and get that line out of the list*/
int select_winner(char *p,int num){
	srand(time(0));
	int ran_num = rand();
	int selected_line = ran_num % num;
	//printf("file: %s num: %d ran_num: %d selected_line: %d\n",p,num,ran_num,selected_line);
	char *line = NULL;
	size_t length = 0;
	ssize_t get_line_chars;
	int line_found = -1;
	
	//if it starts off empty eof will make comparison return -1
	FILE *fp = fopen(p, "r");
	if(fp==NULL){
		printf("EXITING-bad file select winner\n");
		exit(1);
	}else{ 
		//printf("select winner open was a success\n");
		
	}
	//we need a counter in here to say which line in the file we are at
	unsigned int count = 0;
	int line_convert;
	//39mod1=0;
	while((get_line_chars = getline(&line,&length,fp)) != -1){
		
		if(selected_line == count){
			line_convert = atoi(line);
			printf("winning ticket #%d returned from line %d\n",line_convert,count);
			free(line);
			fclose(fp);
			return line_convert;
		}
		count++;
		
	}
	free(line);
	fclose(fp);
	printf("select_winner did not return a proper value\n");
	printf("line_converted: %d count: %d\n",line_convert,count);
	return line_found;	
}
