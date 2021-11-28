#include <stdio.h>
#define MAX_SIZE 100
 
int main()
{
    int m, n;
        printf("Nhap m: ");
        scanf("%d", &m);
        printf("Nhap n: ");
        scanf("%d", &n);
 
    // Nhập mảng
    for (int i = 1; i <= m; i++)
    {
       for (int j = 1; j <n; j++)
        { 
            printf("*  ", j);
        }
            printf("*\n");
    }
}