#include <smart/mm.h>

void mem_copy(char *source, char *dest, int num){

	for(int i = 0; i < num; i++){
		*(dest + i) = *(source + i);
	}
}