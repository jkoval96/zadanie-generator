#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	char* filename = argv[1];
	int file_descriptor, i;
	unsigned char number;
	ssize_t bytes_read;
	float g_total, g_average, total, average;
	
	g_total = 0;
	g_average = 0;
	// For Linux users, remove `O_BINARY` in method `open`
	file_descriptor = open(filename, O_RDONLY | O_BINARY);
	while(1) {
		bytes_read = read(file_descriptor, &number, sizeof(unsigned char));
		if (bytes_read <= 0) {
			break;
		} else {
			float *buffer;
			buffer = malloc(sizeof(float) * number);
			ssize_t count = sizeof(float) * number;
			total = 0; 
			
			bytes_read = read(file_descriptor, buffer, count);
			if (bytes_read <= 0) {
				break;
			} 
			printf("Count = %d  ", number);
			for (i = 0; i < number; i++) {
				printf("%f ", buffer[i]);
				total += buffer[i];
			}
			average = total / number;
			g_average += average;
			g_total ++;
			
			printf(" Average = %f\n", average);
			free(buffer);
		}
	}
	
	printf("Total average value = %f\n", (g_average / g_total));
	close(file_descriptor);
	
	return 0;
}
