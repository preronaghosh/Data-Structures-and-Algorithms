#include <iostream>

#define HEAP_SIZE 1024 * 1024 

struct BlockHeader {
    bool isFree;
    size_t size;
    BlockHeader* next;
};

char heap[HEAP_SIZE];
BlockHeader* free_list = nullptr;

void* my_malloc(size_t size) {
    BlockHeader* curr = free_list;

    while (curr) {
        if (curr->isFree && curr->size >= size) {
            curr->isFree = false;
            return (void*)(curr+1); // since curr points to the block's metadata
        }
        curr = curr->next;
    }
    return nullptr;
}

void my_free(void* ptr) {
    if (!ptr) return;
    BlockHeader* block = (BlockHeader*)(ptr) - 1;
    block->isFree = true;
}

void initHeap() {
    free_list = (BlockHeader*)heap;
    free_list->isFree = true;
    free_list->size = HEAP_SIZE - sizeof(BlockHeader);
    free_list->next = nullptr;
}

int main() {

    initHeap();

    int* arr = (int*)my_malloc(100 * sizeof(int));
    if (arr) {
        arr[0] = 24;
        arr[1] = 25;
        arr[2] = 26;
        arr[3] = 27;
        std::cout << "arr[0]: " << arr[0] << std::endl;
        std::cout << "arr[1]: " << arr[1] << std::endl;
        std::cout << "arr[2]: " << arr[2] << std::endl;
        std::cout << "arr[3]: " << arr[3] << std::endl;
    }

    my_free(arr);
    return 0;
}