#include <stdio.h>
#include <math.h>

void check_values(int numbers[], int size, int *multiples, int *sum_divisible_by_4, int *perfect_square) {
    for (int i = 0; i < size; i++) {
        int num = numbers[i];
        
        multiples[i] = (num % 3 == 0 || num % 5 == 0 || num % 8 == 0);
        
        int sum_of_digits = 0;
        int temp = num;
        while (temp > 0) {
            sum_of_digits += temp % 10;
            temp /= 10;
        }
        sum_divisible_by_4[i] = (sum_of_digits % 4 == 0);
        
        int sqrt_num = (int)sqrt(num);
        perfect_square[i] = (sqrt_num * sqrt_num == num);
    }
}

int main() {
    int numbers[] = {15, 27, 81, 100, 49, 153};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    int multiples[size];
    int sum_divisible_by_4[size];
    int perfect_square[size];
    
    check_values(numbers, size, multiples, sum_divisible_by_4, perfect_square);
    
    for (int i = 0; i < size; i++) {
        printf("Number: %d, Multiple of 3,5,8: %d, Sum of digits divisible by 4: %d, Perfect square: %d\n",
               numbers[i], multiples[i], sum_divisible_by_4[i], perfect_square[i]);
    }
    
    return 0;
}