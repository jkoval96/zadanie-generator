#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
int main(int argc, char* argv[]) {
	char* name = argv[1];
	int n = atoi(argv[2]);
	
	printf("%s %d", name, n);
    
    return 0;
}

