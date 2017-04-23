#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
	
int main(int argc, char* argv[]) {
	char* filename = argv[1];
	int n = atoi(argv[2]);
	
	printf("%s %d", filename, n);
    
    int file_descriptor = open(filename, O_WRONLY | O_CREAT);
    
    write(file_descriptor, "test", 4);
    
    close(file_descriptor);
    
    return 0;
}

