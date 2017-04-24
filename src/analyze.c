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
	float g_total, count_average, total, average;
	
	g_total = 0;
	g_average = 0;
	
	file_descriptor = open(filename, O_RDONLY | O_BINARY);
	while(1) {
		bytes_read = read(file_descriptor, &number, sizeof(unsigned char));
		if (bytes_read <= 0) {
			break;
		} else {
			float buffer[number];
			float* buffer_pointer = buffer;
			ssize_t count = sizeof(float) * number;
			total = 0; 
			
			while (count > 0) {
				bytes_read = read(file_descriptor, buffer_pointer, count);
				if (bytes_read <= 0) {
					break;
				} else {
					buffer_pointer += bytes_read;
					count -= bytes_read;
				}
			}
			printf("Count = %d  ", number);
			for (i = 0; i < number; i++) {
				printf("%f ", buffer[i]);
				total += buffer[i];
			}
			average = total / number;
			count_average += average;
			g_total ++;
			
			printf(" Average = %f\n", average);
		}
	}
	
	printf("Total average value = %f\n", (g_average / g_total));
	close(file_descriptor);
	
	return 0;
}
