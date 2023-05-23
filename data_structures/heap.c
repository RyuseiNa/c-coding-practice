#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} Heap;

void initialize(Heap* heap) {
    heap->size = 0;
}

void insert(Heap* heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    int i = heap->size;
    heap->data[i] = value;
    heap->size++;

    while (i > 0 && heap->data[i] > heap->data[(i - 1) / 2]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

int extractMax(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty. Cannot extract max.\n");
        return -1;
    }

    int maxValue = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    int i = 0;
    while (1) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        if (leftChild < heap->size && heap->data[leftChild] > heap->data[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap->size && heap->data[rightChild] > heap->data[largest]) {
            largest = rightChild;
        }

        if (largest != i) {
            int temp = heap->data[i];
            heap->data[i] = heap->data[largest];
            heap->data[largest] = temp;

            i = largest;
        } else {
            break;
        }
    }

    return maxValue;
}

void printHeap(Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    Heap heap;
    initialize(&heap);

    insert(&heap, 10);
    insert(&heap, 5);
    insert(&heap, 7);
    insert(&heap, 12);
    insert(&heap, 3);

    printf("Max Value: %d\n", extractMax(&heap));

    printHeap(&heap);

    return 0;
}
