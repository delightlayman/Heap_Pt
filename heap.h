#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;
typedef struct heap{
    HPDataType * a;//数组
    int size;
    int capacity;
}Heap;

void swap(HPDataType* a,HPDataType* b);
void AdjustDown(Heap *php,int root,int size);
void AdjustUp(Heap *php,int child);
void HeapBuild(Heap* php);
void HeapSort(Heap* php);
void HeapInit(Heap* php,HPDataType* a,int arr_size);
void HeapDest(Heap* php);
void HeapPush(Heap* php,HPDataType val);
void HeapPop(Heap* php);//须默认删除位置
HPDataType HeapTop(Heap* php);
int HeapFind(Heap* php,int val);
void HeapModi(Heap* php,int pos,int val);
void HeapPrint(Heap* php);