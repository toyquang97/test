#include <stdio.h>
#define MAX_SIZE 100
 
int main()
{
    int m, n;
        printf("Nhap m: ");
        scanf("%d", &m);
      
 
    // Nhập mảng
    for (int i = 0; i < m; i++)
    {
       for (int j = 0; j < i; j++)
        { 
            printf("* ");
        }
            printf("*\n");
    }
}