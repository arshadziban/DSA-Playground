//You are given an array of integers, and your task is to find the sum of its elements. The function simpleArraySum should compute and return this sum.
#include <stdio.h>

int simpleArraySum(int ar[], int n) {
    int total_sum = 0;
    
    for (int i = 0; i < n; i++) {
        total_sum += ar[i];
    }
    
    return total_sum;
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    int ar[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    
    int result = simpleArraySum(ar, n);
    printf("%d\n", result);  
    return 0;
}
