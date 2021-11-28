#include <stdio.h>
#define MAX_SIZE 100
int AND (int a, int b);
int OR (int a, int b);
int XOR (int a, int b);

 int (*fptr)(int ,int) = &AND;
 int (*afptr[])(int ,int) = {
     &AND,
     &OR,
     &XOR
 };

int main()
{
  int a = 5, b = 7;
  
  printf("%d\n", fptr(a,b) );
  printf("%d", afptr[1](a,b) );

}

int AND (int a, int b)
{
    return a & b;
}
int OR (int a, int b)
{
    return a | b;
}
int XOR (int a, int b)
{
    return a ^ b;
}