#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t *buffer;
    uint16_t head;
    uint16_t tail;
    uint16_t size;
} queue_t;

void queue_init(queue_t *q, uint8_t *buf, uint16_t size);
bool queue_enqueue(queue_t *q, uint8_t data);
bool queue_dequeue(queue_t *q, uint8_t *data);
bool queue_is_empty(const queue_t *q);
bool queue_is_full(const queue_t *q);
uint16_t queue_count(const queue_t *q);

#endif // QUEUE_H
