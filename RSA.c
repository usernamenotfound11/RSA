#include "RSA.h"

void random_number_generator(uint8_t number1[1024],uint8_t number2[1024]){
	size_t r=getrandom(number1,1024,0);
	size_t g=getrandom(number2,1024,0);
}
uint8_t* multiplication(uint8_t number1[1024],uint8_t number2[1024], int *current_size) {
        uint8_t *result;
        result=calloc(*current_size * 2,sizeof(uint8_t));

        for(int i=0;i<*current_size;i++) {
        for(int j=0;j<*current_size;j++) {
			
                result[i+j]+=number1[i]*number2[j];
			
                }
        }

        for(int k=0; k < *current_size*2; k++) {
			
        if(result[k] >= 10) {
			
        result[k+1]+= result[k] / 10;
        result[k]%=10;
			
        }

        }


        return result;
}

uint8_t* substraction(uint8_t number1[1024],uint8_t number2[1024], int *current_size) {

        uint8_t *result;
        result=calloc(*current_size,sizeof(uint8_t));
        int borrow = 0;

        for(int i=0;i<*current_size;i++) {
			
        int number1_copy = number1[i] - borrow;
        int number2_copy = number2[i];
			
        if(number1_copy < number2_copy) {
        borrow = 1;
        number1_copy += 10;
			
        }else {
			
        borrow = 0;
			
			}
        result[i]= number1_copy - number2_copy;
        }

        return result;
}

uint8_t* euler_function(uint8_t number1[1024],uint8_t number2[1024], int *current_size) {
        uint8_t minus[1024] = {1};

        uint8_t *first_number = substraction(number1 , minus , current_size);
        uint8_t *second_number = substraction(number2 , minus , current_size);

        uint8_t *result = multiplication(first_number , second_number , current_size);
        free(first_number);
        free(second_number);

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
