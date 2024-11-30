//large value sum
#include <stdio.h>

long aVeryBigSum(int n, long ar[]) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar[i];
    }
    return sum;
}

int main() {
    int n;
    

    scanf("%d", &n);
    
    long ar[n];
    

    for (int i = 0; i < n; i++) {
        scanf("%ld", &ar[i]);
    }
    
    long result = aVeryBigSum(n, ar);
    printf("%ld\n", result);
    
    return 0;
}
