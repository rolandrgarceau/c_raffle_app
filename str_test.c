#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
	char line[11] = "1234567890";
	char num_str[33] = {'\0'};
	int num = 1234567890;
	int tester = atoi(line);
	if(tester == num){
		printf("match\n");
	}
}
