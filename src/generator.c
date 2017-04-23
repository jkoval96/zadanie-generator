#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
	
int main(int argc, char* argv[]) {
	char* filename = argv[1];
	int i,j;
	unsigned char n = atoi(argv[2]);
	float fields[n];
	int file_descriptor;

	srand(time(NULL));	
	file_descriptor = open(filename, O_WRONLY | O_CREAT);
	
	for(j =0; j < n; j++) {
		for(i = 0; i < n; i++) {
			fields[i] = (float)(rand() /(float)(RAND_MAX)) + 10 + rand() % 10;
			printf("%lf ", fields[i]);
		}
		printf("\n");
		write(file_descriptor, &n, sizeof(unsigned char));
		write(file_descriptor, fields, n * sizeof(float));
	}
	
	printf("%s %d", filename, n); 
    close(file_descriptor);
    
    return 0;
}

