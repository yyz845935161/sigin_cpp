#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetMemory(char* p)
{
    p = (char*)malloc(100);
}

void Test()
{
    char *str = NULL;
    GetMemory(str);
    strcpy(str, "hello world");
    printf("%s", str);
}

void GetMemory2(char** p, int num)
{
    *p = (char*)malloc(num);
}

void Test2()
{
    char *str = NULL;
    GetMemory2(&str, 100);
    strcpy(str, "hello world");
    printf("%s", str);
}

char* GetMemory3()
{
    char p[] = "nihao";
    // char *p2 = "nihao";
    return p;
}

void Test3()
{
    char *str = NULL;
    str = GetMemory3();
    printf("---\n%s\n---\n", str);
}

int main()
{
    char *str = NULL;
    str = GetMemory3();

    const char * s1 = "nihao";
    printf("%p %p",s1 ,str);
    // Test3();
    return 0;
}