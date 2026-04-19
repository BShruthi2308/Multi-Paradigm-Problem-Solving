/*
 * statistics.c
 * Procedural implementation of mean, median, and mode
 */
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

double calculate_mean(const int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return (double)sum / size;
}

double calculate_median(int *arr, int size) {
    qsort(arr, size, sizeof(int), compare);
    if (size % 2 == 0)
        return (arr[size/2 - 1] + arr[size/2]) / 2.0;
    return arr[size/2];
}

void calculate_mode(const int *arr, int size) {
    int max_count = 0;
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) count++;
        }
        if (count > max_count) max_count = count;
    }

    printf("Mode(s): ");
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) count++;
        }
        if (count == max_count) printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {1,2,2,3,4,5,2};
    int size = sizeof(data)/sizeof(data[0]);

    printf("Mean: %.2f\n", calculate_mean(data, size));
    printf("Median: %.2f\n", calculate_median(data, size));
    calculate_mode(data, size);
    return 0;
}
