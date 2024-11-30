//You are given an array of integers representing the colors of socks. Your task is to determine how many pairs of socks can be made where both socks in the pair have the same color.
#include <stdio.h>

int sockMerchant(int n, int ar[]) {
    int color_count[101] = {0}; // Array to store the count of each color (1 to 100)
    int pairs = 0;
    
    // Count the occurrences of each color
    for (int i = 0; i < n; i++) {
        color_count[ar[i]]++;
    }
    
    // Calculate the number of pairs
    for (int i = 1; i <= 100; i++) {
        pairs += color_count[i] / 2; // Each pair is formed by 2 socks
    }
    
    return pairs;
}

int main() {
    int n;
    
    // Get the number of socks in the pile
    scanf("%d", &n);
    
    int ar[n];
    
    // Get the colors of the socks
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    
    // Call the function and display the result
    int result = sockMerchant(n, ar);
    printf("%d\n", result);  // Output the number of pairs
    
    return 0;
}
