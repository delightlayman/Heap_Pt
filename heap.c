#include "heap.h"
//堆运用向下调整法要求：小堆：两子树必须都是小堆 大堆：两子树必须都是大堆
void swap(HPDataType* a,HPDataType* b){
    HPDataType temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
//向下调整算法--小堆
void AdjustDown(Heap *php,int root){
     int parent=root;
     int kid=2*parent+1;
     while (kid<php->size)
     {
        //子节点的较小者
        if(kid+1<php->size && php->a[kid+1]<php->a[kid])
            kid++;
        //与父节点比较
        if(php->a[parent]>php->a[kid]){
            //交换值
            swap(&php->a[parent],&php->a[kid]);
            //更新父子节点位置
            parent=kid;
            kid=2*parent+1;
        }
        else 
            break;    
     }   
}
//自底向上依次处理
void HeapSort(Heap* php){
    for(int i=(php->size-1-1)/2;i>=0;--i)
        AdjustDown(php,i);
    
}
void HeapInit(Heap* php,HPDataType* a,int arr_size){

    php->a=(HPDataType*)malloc(sizeof(HPDataType)*arr_size);
    memcpy(php->a,a,sizeof(HPDataType)*arr_size);
    php->size=arr_size;
    php->capacity=arr_size;
    //从最后的叶子节点的父节点依次回推
    HeapSort(php);
}
void HeapDest(Heap* php);
void HeapPush(Heap* php,int val);
void HeapPop(Heap* php);//须默认删除位置
int HeapFind(Heap* php,int val);
void HeapModi(Heap* php,int pos,int val);

void HeapPrint(Heap* php) {
    for (int i = 0; i < php->size; ++i) {
        printf("%d ", php->a[i]);
    }
}