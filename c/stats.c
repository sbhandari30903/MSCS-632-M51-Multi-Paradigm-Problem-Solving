#include <stdio.h>
#include <stdlib.h>

// Function to calculate mean
double calculate_mean(int* numbers, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

// Function to calculate median
double calculate_median(int* numbers, int size) {
    // Sort the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    if (size % 2 == 0) {
        return (numbers[size/2 - 1] + numbers[size/2]) / 2.0;
    } else {
        return numbers[size/2];
    }
}

// Function to calculate mode
void calculate_mode(int* numbers, int size, int* mode, int* mode_count) {
    int max_count = 0;
    int current_count = 1;
    int current_number = numbers[0];
    int mode_size = 0;

    // Count occurrences of each number
    for (int i = 1; i < size; i++) {
        if (numbers[i] == current_number) {
            current_count++;
        } else {
            if (current_count > max_count) {
                max_count = current_count;
                mode_size = 1;
                mode[0] = current_number;
            } else if (current_count == max_count) {
                mode[mode_size++] = current_number;
            }
            current_count = 1;
            current_number = numbers[i];
        }
    }

    // Check last number
    if (current_count > max_count) {
        max_count = current_count;
        mode_size = 1;
        mode[0] = current_number;
    } else if (current_count == max_count) {
        mode[mode_size++] = current_number;
    }

    *mode_count = mode_size;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int mode[10]; // Assuming max 10 modes
    int mode_count;

    printf("Numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Mean: %.2f\n", calculate_mean(numbers, size));
    printf("Median: %.2f\n", calculate_median(numbers, size));
    
    calculate_mode(numbers, size, mode, &mode_count);
    printf("Mode: ");
    for (int i = 0; i < mode_count; i++) {
        printf("%d ", mode[i]);
    }
    printf("\n");

    return 0;
} 