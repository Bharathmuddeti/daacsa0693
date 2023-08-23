#include <stdio.h>

#define CONTAINER_CAPACITY 100

int main() {
    int containers[CONTAINER_CAPACITY];
    int numItems, i, j;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the sizes of the items:\n");
    for (i = 0; i < numItems; i++) {
        scanf("%d", &containers[i]);
    }

    // Sorting items in descending order (largest first)
    for (i = 0; i < numItems - 1; i++) {
        for (j = 0; j < numItems - i - 1; j++) {
            if (containers[j] < containers[j + 1]) {
                int temp = containers[j];
                containers[j] = containers[j + 1];
                containers[j + 1] = temp;
            }
        }
    }

    int containerCount = 1;
    int remainingSpace = CONTAINER_CAPACITY;

    printf("\nLoading items into containers:\n");

    for (i = 0; i < numItems; i++) {
        if (containers[i] <= remainingSpace) {
            printf("Container %d: Item with size %d\n", containerCount, containers[i]);
            remainingSpace -= containers[i];
        } else {
            containerCount++;
            remainingSpace = CONTAINER_CAPACITY - containers[i];
            printf("Container %d: Item with size %d\n", containerCount, containers[i]);
        }
    }

    return 0;
}
