#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
	
int main(int argc, char* argv[]) {
	char* filename = argv[1];
	int i, j;
	unsigned char length, n = atoi(argv[2]);
	int file_descriptor;

	srand(time(NULL));	
	file_descriptor = open(filename, O_RDWR | O_CREAT);
	
	for(j = 0; j < n; j++) {
		length = rand() % 11 + 10;
		float fields[length];
		for(i = 0; i < length; i++) {
			fields[i] = (float)(rand() /(float)(RAND_MAX)) + 10 + rand() % 10;
			printf("%lf ", fields[i]);
		}
		printf("\n");
		write(file_descriptor, &length, sizeof(unsigned char));
		write(file_descriptor, fields, length * sizeof(float));
	}
	
	printf("%s %d", filename, n); 
    close(file_descriptor);
    
    return 0;
}

