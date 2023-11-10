
#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <string.h>
#include <unistd.h>

const int aa = 10;
int a2 = 100;
int* p = &a2;


int *const a2 =p; 

class A
{
public:
    static int a1;
    static int * a;
    static const int * b  = a2 ;
    static int*  const c; 

};


int A::a1 = 10;

const int* A::b = &aa;
int* const A::c = p;

int main()
{

}
