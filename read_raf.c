#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_for_dup(char *,char *);
int main(int argc, char *argv[]){
	//read the file
	if(argc==3){
		char *arg0 = argv[0];
		char *arg1 = argv[1];
		char *arg2 = argv[2];
		printf("exe is %s,raffle_file is %s,looking to match%s\n", arg0,arg1,arg2);
		FILE *fp;
		char *line = NULL;
		size_t length = 0;
		ssize_t get_line_chars;

		fp = fopen(arg1, "r");
		if(fp==NULL){
			printf("EXITING-bad file open\n");
			exit(1);
		}
		//we need a counter in here to say which line in the file we are at
		unsigned int count = 0;
		//int found = 0;
		while((get_line_chars = getline(&line,&length,fp)) != -1){
			//printf("length %zu\n", get_line_chars);
			//printf("line as read:%s\n", line);
			
			//strip trailing \n or \r due to getline fcn
			while(get_line_chars>0 && (line[get_line_chars-1]=='\n'||line[get_line_chars]=='\r'))
				line[--get_line_chars] = 0;
			int found = check_for_dup(arg2,line);
			//printf("found value:%d\n",found);
			if(found){
				printf("duplicate found at line %d\n",count);
				//do not break, find multiple duplicates...
			}
			count++;//zero based indexing....blah blah blah
		}
		free(line);
		fclose(fp);
		//printf("char size %d bytes\n",sizeof(char));
		//max 2 to the 32 count lines 
		printf("total lines:%d\n",count);
		return 0;
	}else{
		printf("single argument problem\n");
		fprintf(stderr, "we have problems houston\n");
		exit(1);
	}
}
int check_for_dup(char *lookup, char *exist){
	//printf("lookup:%s,exist:%s\n",lookup,exist);
	//printf("lookup:%d,exist:%d\n",strlen(lookup),strlen(exist));
	if((strcmp(lookup,exist))==0){
		//printf("we got a match houston, bummer\n");		
		return 1;
	}else{return 0;}
}
