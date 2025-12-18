#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/random.h>

void random_number_generator(uint8_t number1[1024], uint8_t number2[1024]);

uint8_t* multiplication(uint8_t number1[1024],uint8_t number2[1024], int *current_size);

uint8_t* substraction(uint8_t number1[1024],uint8_t number2[1024], int *current_size);

uint8_t* euler_function(uint8_t number1[1024],uint8_t number2[1024], int *current_size);
