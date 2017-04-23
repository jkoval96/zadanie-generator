#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	char* filename = argv[1];
	int file_descriptor;
	int res, i;
	
	file_descriptor = open(filename, O_RDONLY);
	while(1) {
		unsigned char number;
		
		res = read(file_descriptor, &number, sizeof(unsigned char));
		printf("%d", res);
		printf("\n");
		if(res <= 0) {
			return 0;
		} else {
			float fields[number];
			int tmp = read(file_descriptor, fields, sizeof(float) * number);
			
			for(i = 0; i < number; i++) {
				printf("%lf ", fields[i]);
			}
			printf("\n");	
			printf("%d", tmp);	
			printf("\n");
		}
	}
	close(file_descriptor);
	
	return 0;
}
