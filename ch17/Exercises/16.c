#include <stdio.h>

int sum(int (*f)(int), int start, int end);
int square(int i);
int cube(int i);

int main(void)
{
    /* Sum the square of all numbers from 1..10 inclusive */
    printf("sum: %d\n", sum(square, 1, 10));
    /* Sum the cube of all numbers from 7..11 inclusive */
    printf("sum: %d\n", sum(cube, 7, 11));
    return 0;
}

int sum(int (*f)(int), int start, int end)
{
    int sum = 0;
    while (start <= end) {
        sum += (*f)(start);
        start++;
        /*
         *可以写成sum+=(*f)(start++);
         *因为虽然start++产生的副作用会
         *导致start在内存中值加1，但是
         *start++返回的是一个右值，是start
         *的值来的
         */
    }
    return sum;
}

int square(int i)
{
    return i * i;
}

int cube(int i)
{
    return i * i * i;
}
