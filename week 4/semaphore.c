#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int mutex = 1;
int full = 0;
int empty = BUFFER_SIZE;

void wait(int *S) {
    while (*S <= 0);
    (*S)--;
}

void signal(int *S) {
    (*S)++;
}

void producer() {
    if (empty > 0) {
        wait(&empty);
        wait(&mutex);

        buffer[in] = in + 1;
        printf("Producer has produced: Item %d\n", buffer[in]);
        in = (in + 1) % BUFFER_SIZE;

        signal(&mutex);
        signal(&full);
    } else {
        printf("Buffer is full!\n");
    }
}

void consumer() {
    if (full > 0) {
        wait(&full);
        wait(&mutex);

        int item = buffer[out];
        printf("Consumer has consumed: Item %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        signal(&mutex);
        signal(&empty);
    } else {
        printf("Buffer is empty!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nEnter 1.Producer 2.Consumer 3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
