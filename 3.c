#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int n;
    do
    {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
    } while (n < 1);
    //int* ptr = (int*) malloc (n*sizeof(int));
    int* ptr = (int*) calloc (n, sizeof(int));

    // Nhập mảng
    for (int i = 0; i < n; i++)
    {
        printf("Nhap a[%d] = ", i);
        scanf("%d", (ptr + i));
    }
     for (int i = 0; i < n; i++)
    {
        printf("xuat a[%d] = %d\n", i,*(ptr +i));
    }
    int x; 
    printf("thay doi kich htuoc");
    scanf("%d",&x);
    realloc(ptr,x);
    for (int i = x - n ; i < x; i++)
    {
        printf("Nhap a[%d] = ", i);
        scanf("%d", (ptr + i));
    }
     for (int i = 0; i < x; i++)
    {
        printf("xuat a[%d] = %d\n", i,*(ptr +i));
    }
    free(ptr);
}