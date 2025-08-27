#include <stdio.h>
#include "queue.h"

int main(void) {
    uint8_t buffer[8];
    queue_t q;

    queue_init(&q, buffer, sizeof(buffer));

    // Enqueue some values
    for (uint8_t i = 0; i < 5; i++) {
        queue_enqueue(&q, i);
        printf("Enqueued: %d\n", i);
    }

    // Dequeue and print
    uint8_t value;
    while (!queue_is_empty(&q)) {
        queue_dequeue(&q, &value);
        printf("Dequeued: %d\n", value);
    }

    return 0;
}
