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



bool HeapEmpty(HP* hp)
{
    assert(hp);
    return hp->size ==0;
}


int HeaSpize(HP* hp)
{
    return hp->size;
}

void Swap(HPDataType* px,HPDataType* py)
{
    HPDataType tem  = *px;
    *px = *py;
    *py = tem;
}


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

template<class Compear = Less<HPDataType>>
void AdjustDown(HPDataType *a,int n, int parent)
{
    Compear _com;
    assert(a);
    int child = parent*2+1;
    while (child < n )
    {

        //选出左右孩子中小的哪一个
        if(child+1 < n && _com(a[child+1],a[child]))
        {
                child++;
        }
        if(_com(a[child],a[parent]))
        {
            Swap(&a[child],&a[parent]);
            parent = child;
            child = parent*2 +1 ;
        }
        else
        {
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




//删除堆顶数据 ，和最后位置元素交换，向下调整
void HeapPop(HP* hp){
    assert(hp);
    assert(!HeapEmpty(hp));
    Swap(&hp->a[0], &hp->a[hp->size-1]);
    hp->size--;
    AdjustDown<Greater<HPDataType>>(hp->a,hp->size,0);

}

void HeapPrint(HP* hp)
{
    for(int i=0; i < hp->size;i++)
    {
        printf("%d  ",hp->a[i]);
    }

}



void test01()
{
    int a[] = {70,56,30,25,15,10,75};
    HP hp;
    HeapInit(&hp);
    for(int i=0;i < sizeof(a)/sizeof(a[0]);i++)
    {
        Heappush(&hp,a[i]);
    }

    HeapPop(&hp);
    HeapPrint(&hp);

    
    
}





int main()
{
    test01();
    return 0;
 }