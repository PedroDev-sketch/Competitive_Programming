#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1048576

static char input_buffer[BUFFER_SIZE];
static char *read_ptr = input_buffer;
static int bytes_read = 0;

static inline char read_char() {
    if (read_ptr == input_buffer + bytes_read) {
        bytes_read = fread(input_buffer, 1, BUFFER_SIZE, stdin);
        if (bytes_read == 0) return EOF;
        read_ptr = input_buffer;
    }
    return *read_ptr++;
}

static inline int read_int() {
    int num = 0;
    char c = read_char();
    int is_negative = 0;

    while ((c < '0' || c > '9') && c != '-' && c != EOF) {
        c = read_char();
    }

    if (c == EOF) return EOF;

    if (c == '-') {
        is_negative = 1;
        c = read_char();
        if (c == EOF) return EOF;
    }

    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = read_char();
    }

    return is_negative ? -num : num;
}

static char output_buffer[BUFFER_SIZE];
static int output_idx = 0;

static inline void flush_output() {
    if (output_idx > 0) {
        fwrite(output_buffer, 1, output_idx, stdout);
        output_idx = 0;
    }
}

static inline void write_char(char c) {
    if (output_idx == BUFFER_SIZE) {
        flush_output();
    }
    output_buffer[output_idx++] = c;
}

static inline void write_int(int num) {
    if (num == 0) {
        write_char('0');
        return;
    }
    if (num < 0) {
        write_char('-');
        num = -num;
    }
    char temp[12];
    int i = 0;
    while (num > 0) {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }
    while (i > 0) {
        write_char(temp[--i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int *array, int index) {
    int parent_index = (index - 1) / 2;
    while (index > 0 && array[parent_index] > array[index]) {
        swap(&array[parent_index], &array[index]);
        index = parent_index;
        parent_index = (index - 1) / 2;
    }
}

void heapifyDown(int *array, int size, int index) {
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    int smallest_index = index;

    if (left_child_index < size && array[left_child_index] < array[smallest_index]) {
        smallest_index = left_child_index;
    }
    if (right_child_index < size && array[right_child_index] < array[smallest_index]) {
        smallest_index = right_child_index;
    }

    if (smallest_index != index) {
        swap(&array[index], &array[smallest_index]);
        heapifyDown(array, size, smallest_index);
    }
}

void insertHeap(int **heap_array_ptr, int *heap_size_ptr, int *heap_capacity_ptr, int value) {
    if (*heap_size_ptr == *heap_capacity_ptr) {
        int new_capacity = (*heap_capacity_ptr == 0) ? 1 : *heap_capacity_ptr * 2;
        int *temp = (int *)realloc(*heap_array_ptr, sizeof(int) * new_capacity);
        if (temp == NULL) {
            exit(EXIT_FAILURE);
        }
        *heap_array_ptr = temp;
        *heap_capacity_ptr = new_capacity;
    }

    (*heap_array_ptr)[*heap_size_ptr] = value;
    (*heap_size_ptr)++;
    heapifyUp(*heap_array_ptr, *heap_size_ptr - 1);
}

int extractMinHeap(int **heap_array_ptr, int *heap_size_ptr) {
    if (*heap_size_ptr <= 0) {
        return -1;
    }

    int min_value = (*heap_array_ptr)[0];

    (*heap_size_ptr)--;
    (*heap_array_ptr)[0] = (*heap_array_ptr)[*heap_size_ptr];

    if (*heap_size_ptr > 0) {
        heapifyDown(*heap_array_ptr, *heap_size_ptr, 0);
    }

    return min_value;
}

int compareInts(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void menorPlacas() {
    int operation;
    int value;

    int *plates_heap = NULL;
    int plates_heap_size = 0;
    int plates_heap_capacity = 0;

    while ((operation = read_int()) != EOF) {
        value = read_int();

        if (operation == 1) {
            insertHeap(&plates_heap, &plates_heap_size, &plates_heap_capacity, value);
        } else {
            int ti_count = value;

            int temp_results[100];
            int extracted_count = 0;

            for (int i = 0; i < ti_count && plates_heap_size > 0; i++) {
                temp_results[extracted_count++] = extractMinHeap(&plates_heap, &plates_heap_size);
            }

            qsort(temp_results, extracted_count, sizeof(int), compareInts);

            for (int i = 0; i < extracted_count; i++) {
                write_int(temp_results[i]);
                if (i == extracted_count - 1) {
                    write_char('\n');
                } else {
                    write_char(' ');
                }
            }
            if (extracted_count == 0) {
                write_char('\n');
            }

            for (int i = 0; i < extracted_count; i++) {
                insertHeap(&plates_heap, &plates_heap_size, &plates_heap_capacity, temp_results[i]);
            }
        }
    }

    free(plates_heap);
    flush_output();
}

int main() {
    menorPlacas();
    return 0;
}