#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
	
int main(int argc, char* argv[]) {
	char* filename = argv[1];
	int i, j;
	unsigned char length, n;
	int file_descriptor;

	srand(time(NULL));	
	n = atoi(argv[2]);
	if (argc < 3) {
        printf("ERROR INPUT, usage: %s <filename> <Nrows> \n", argv[0]);
        exit(1);
    }
    //For Linux users, remove `O_BINARY` in method `open`, add mode `0666`in method `open` 
	file_descriptor = open(filename, O_RDWR | O_CREAT | O_BINARY);
	
	for(j = 0; j < n; j++) {
		length = rand() % 11 + 10;
		float fields[length];
		
		for(i = 0; i < length; i++) {
			fields[i] = (float)(rand() /(float)(RAND_MAX)) + 10 + rand() % 10;
		}
		write(file_descriptor, &length, sizeof(unsigned char));
		write(file_descriptor, fields, length * sizeof(float));
	}
	
	close(file_descriptor);
    
	return 0;
}

