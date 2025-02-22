#include "heap.h"
int main(){
    Heap hp;
    int arr[10]={27,18,19,15,28,34,65,49,25,37};

    HeapInit(&hp,arr,10);
    HeapPrint(&hp); 
    HeapSort(&hp);
    HeapPrint(&hp);
    HeapBuild(&hp);
    HeapPrint(&hp);
    HeapPush(&hp,13);
    HeapPrint(&hp);
    int num1=HeapFind(&hp,13);
    printf("%d\n",num1);
    int num2=HeapTop(&hp);
    printf("%d\n",num2);
    HeapPop(&hp);
    HeapPrint(&hp);
    HeapModi(&hp,3,16);
    HeapPrint(&hp);

    return 0;
}