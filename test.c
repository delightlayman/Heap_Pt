#include "heap.h"
int main(){
    Heap hp;
    int arr[10]={27,18,19,15,28,34,65,49,25,37};

    HeapInit(&hp,arr,10);
    HeapPrint(&hp);
    return 0;
}