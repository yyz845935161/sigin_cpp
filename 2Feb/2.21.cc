// #include<iostream>
// using namespace std;
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


template<class T>
struct Less
{
    bool operator()(const T x,const T y)
    {
        return  x < y;
    }
    /* data */
};
template<class T>
struct Greater
{
    bool operator()(const T x,const T y)
    {
        return  x > y;
    }
    /* data */
};


typedef int HPDataType; 
typedef struct Heap
{
    /* data */
    HPDataType *a;
    int size;
    int capacity;

}HP;




void HeapInit(HP* hp){
    assert(hp);
    hp->a = NULL;
    hp ->size = hp ->capacity = 0;
}

void HeapDestroy(HP* hp){
    assert(hp);
    free(hp->a);
    hp ->size = hp ->capacity = 0;
}

template<class Compear = Less<HPDataType>>
void AdjustUp(HPDataType *a,int n, int child)
{
    Compear _com;
    assert(a); 
    int parent = (child - 1)/2;
    while (child > 0)
    {
        /* code */
        if(_com(a[child],a[(child-1)/2]) )
        {
            HPDataType temp = a[child];
            a[child] = a[(child-1)/2];
            a[(child-1)/2] = temp;

            child = parent;
            parent = (child - 1)/2; 
        }
        else{
            break;
        }
        
    }

}



void Heappush(HP* hp,HPDataType x ){
    assert(hp);
    //扩容
    if (hp->size == hp ->capacity)
    {
        size_t newCapacoty = hp ->capacity ==0 ? 4: hp ->capacity*2;
        HPDataType* temp = (HPDataType*)realloc(hp->a,sizeof(HPDataType)*newCapacoty);
        if(temp ==NULL)
        {
            printf("relloc fail\n");
            exit(-1);
        }
        hp->a = temp;
        hp->capacity = newCapacoty;
    }
    hp->a[hp->size] = x;
    hp->size++;
    AdjustUp<Greater<HPDataType>>(hp->a,hp->size,hp->size-1);
    
}





void HeapPop(HP* hp){}



void test01()
{
    int a[] = {70,56,30,25,15,10,75};
    HP hp;
    HeapInit(&hp);
    for(int i=0;i < sizeof(a)/sizeof(a[0]);i++)
    {
        Heappush(&hp,a[i]);
    }

    for(int i=0; i < hp.size;i++)
    {
        printf("%d  ",hp.a[i]);
    }
}





int main()
{
    test01();
    return 0;
 }