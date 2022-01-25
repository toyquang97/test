#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    float diemChuan;
    float mon1;
    float mon2;
    float mon3;
    char kv;
    int dt;
} diemthi;

void xoaKyTuXuongDong(char *p)
{
    size_t len = strlen(p);
    // toy quang\n\0
    if (*(p + len - 1) == '\n')
    {
        *(p + len - 1) = '\0';
    }
}
void nhap(diemthi *d1)
{

    printf("nhap diem chuan: ");
    scanf("%f", &d1->diemChuan);
    printf("\nnhap diem 3 mon: ");
    scanf("%f %f %f", &d1->mon1, &d1->mon2, &d1->mon3);
    getchar();
    do
    {
        printf("\nnhap khu vuc:");
        scanf("%c", &d1->kv);
        getchar();
    } while (d1->kv != 'A' && d1->kv != 'B' && d1->kv != 'C' && d1->kv != 'X');
    do
    {
        printf("\nnhap Doi tuong: ");
        scanf("%d", &d1->dt);
    } while (d1->dt < 0 || d1->dt > 3);
}

void check(diemthi *d1)
{
    float utkv = 0;
    if (d1->kv == 'A')
    {
        utkv = 2;
    }
    else if (d1->kv == 'B')
    {
        utkv = 1;
    }
    else if (d1->kv == 'C')
    {
        utkv = 0.5;
    }
    else if (d1->kv == 'X')
    {
        utkv = 0;
    }

    float utdt = 0;
    if (d1->dt == 1)
    {
        utdt = 2.5;
    }
    else if (d1->dt == 2)
    {
        utdt = 1.5;
    }
    else if (d1->dt == 3)
    {
        utdt = 1;
    }
    else if (d1->dt == 0)
    {
        utdt = 0;
    }

    float diemut = (float)(utdt + utkv);

    float tong = d1->mon1 + d1->mon2 + d1->mon3 + diemut;

    if (d1->diemChuan > tong)
    {
        printf("ROT [%.2f]", tong);
    }
    else
    {
        printf("dau [%.2f]", tong);
    }
}

void main()
{
    diemthi d1;

    nhap(&d1);
    check(&d1);
}