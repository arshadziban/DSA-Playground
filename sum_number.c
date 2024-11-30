//Complete the function sumOfTwoNumbers to compute the sum of two integers and return the result.

#include <stdio.h>
int solveMeFirst(int a, int b) {
    return a + b;  
}

int main() {
    int num1, num2, sum;

    scanf("%d %d", &num1, &num2);

    sum = solveMeFirst(num1, num2);

    printf("%d\n", sum);

    return 0;
}
