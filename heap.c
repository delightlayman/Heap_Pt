#include "heap.h"
//堆运用向下调整法要求：小堆：两子树必须都是小堆 大堆：两子树必须都是大堆
void swap(HPDataType* a,HPDataType* b){
    HPDataType temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
//向下调整算法--小堆
void AdjustDown(Heap *php,int root,int size){//size用于控制向下调整量
     int parent=root;
     int kid=2*parent+1;
     while (kid<size)
     {
        //子节点的较小者
        if(kid+1<size && php->a[kid+1]<php->a[kid])
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
//向上调整算法--小堆
void AdjustUp(Heap *php,int child){
    int parent=(child-1)/2;
    while(child>0){
        if(php->a[parent]>php->a[child]){
            swap(&php->a[parent],&php->a[child]);
            child=parent;
            parent=(child-1)/2;
        }
        else    
            break;
    }
}
//建小堆
void HeapBuild(Heap* php){
    for(int i=(php->size-1-1)/2;i>=0;--i)
        AdjustDown(php,i,php->size);
}

//堆排序---自底向上依次处理
//排升序：建大堆      排降序：建小堆
//降序
void HeapSort(Heap* php){
    for(int i=php->size-1;i>0;i--){
        swap(&php->a[0],&php->a[i]);//一次交换：最小值换到最后
        AdjustDown(php,0,i);//一次向下调整：除根节点，两子树都是小堆，根节点一次调整后整体又是小堆
    }       
}

//初始化---小堆
void HeapInit(Heap* php,HPDataType* a,int arr_size){

    php->a=(HPDataType*)malloc(sizeof(HPDataType)*arr_size);
    memcpy(php->a,a,sizeof(HPDataType)*arr_size);
    php->size=arr_size;
    php->capacity=arr_size;
    //从最后的叶子节点的父节点依次回推
    HeapBuild(php);
}
void HeapDest(Heap* php){
    free(php->a);
    php->a=NULL;
    php->size=0;
    php->capacity=0;
}
void HeapPush(Heap* php,HPDataType val){
    assert(php);
    if(php->size==php->capacity){
        php->capacity*=2;
        HPDataType* temp=(HPDataType*)realloc(php->a,sizeof(HPDataType)*php->capacity);
        php->a=temp;
    }
    php->a[php->size++]=val;
    AdjustUp(php,php->size-1);    
}
void HeapPop(Heap* php){//须默认删除位置---堆顶
    assert(php);
    assert(php->size); 
    swap(&php->a[0],&php->a[php->size-1]);
    AdjustDown(php,0,php->size-1);
    php->size--;
}
HPDataType HeapTop(Heap* php){
    assert(php);
    return php->a[0];
}


int HeapFind(Heap* php,int val){
    if(val<php->a[0])
        return -1;
    for(int i=0;i<php->size;i++){
        if(val==php->a[i])
            return i;
    }     
}
void HeapModi(Heap* php,int pos,int val){
    php->a[pos]=val;
    HeapBuild(php);
}

void HeapPrint(Heap* php) {
    printf("size=%d capacity=%d\n",php->size,php->capacity);
    for (int i = 0; i < php->size; ++i) {
        printf("%d ", php->a[i]);
    }
    printf("\n");
}