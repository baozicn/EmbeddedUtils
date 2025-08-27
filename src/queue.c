#include "queue.h"

void queue_init(queue_t *q, uint8_t *buf, uint16_t size) {
    q->buffer = buf;
    q->size = size;
    q->head = 0;
    q->tail = 0;
}

bool queue_enqueue(queue_t *q, uint8_t data) {
    uint16_t next = (q->head + 1) % q->size;
    if (next == q->tail) {
        return false; // full
    }
    q->buffer[q->head] = data;
    q->head = next;
    return true;
}

bool queue_dequeue(queue_t *q, uint8_t *data) {
    if (q->head == q->tail) {
        return false; // empty
    }
    *data = q->buffer[q->tail];
    q->tail = (q->tail + 1) % q->size;
    return true;
}

bool queue_is_empty(const queue_t *q) {
    return (q->head == q->tail);
}

bool queue_is_full(const queue_t *q) {
    uint16_t next = (q->head + 1) % q->size;
    return (next == q->tail);
}

uint16_t queue_count(const queue_t *q) {
    if (q->head >= q->tail) {
        return q->head - q->tail;
    } else {
        return q->size - (q->tail - q->head);
    }
}
