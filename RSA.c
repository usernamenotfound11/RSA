#include "RSA.h"

void random_number_generator(uint8_t number1[1024],uint8_t number2[1024]){
	size_t r=getrandom(number1,1024,0);
	size_t g=getrandom(number2,1024,0);
}

uint8_t* multiplication(uint8_t number1[1024],uint8_t number2[1024], int *current_size) {
	uint8_t *result;
	result=calloc(*current_size,sizeof(uint8_t));
	uint8_t buffer=0;

	for(int i=0;i<1024;i++) {
	
		result[i]=number1[i]*number2[i];
		int j=i;

	while(result[j]>=10){

		if(j+1>=*current_size) {
	
		int new_size = *current_size + 1;
		uint8_t *tmp = realloc(result, new_size * sizeof(uint8_t));
	
	if (tmp == NULL) {
		fprintf(stderr, "failure\n");
		exit(1);
	
	}
		result = tmp;
		result[*current_size]=0;
		*current_size = new_size;

	}
	
		buffer=result[j]/10;
		result[j]%=10;
		result[j+1]+=buffer;

		j++;

	}

	}
	return result;
}


int main() {
	uint8_t number1[1024];
	uint8_t number2[1024];
	int size;
	size=1024;
	uint8_t *result;

	random_number_generator(number1,number2);

	result=multiplication(number1,number2,&size);
	for(int i=0;i<32;i++) {

	printf("%d",result[i]);
	
	}

printf("\n");
return 0;

}
