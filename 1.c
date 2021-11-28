#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define MAX_SIZE 100

int trungbinhcong(int *p, int n)
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a += (*(p + i));
    }

    return a / n;
}
int timminvitri2(int *p, int n)
{
    int min = INT_MAX;
    int min_2 = INT_MAX;
    printf("%d\n", min);
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) < min)
        {
            min = *(p + i);
        }
    }

    printf("%d", min);
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) == min)
        {
            continue;
        }
        else
        {
            if (*(p + i) < min_2)
            {
                min_2 = *(p + i);
            }
        }
    }
    return min_2;
}
void xoaMangTaiViTri(int *ptarr, int *n, int vitri)
{
    for (int i = vitri; i < (*n) - 1; i++)
    {
        *(ptarr + i) = *(ptarr + i + 1);
    }
    (*n)--;
}
void xoaMangTheoGiaTri(int *ptarr, int *n)
{
    int gt = 0;
    printf("Nhap giatri can xoa: ");
    scanf("%d", &gt);

    for (int i = 0; i < (*n); i++)
    {
        if (*(ptarr + i) == gt)
        {
            xoaMangTaiViTri(ptarr, n, i);
        }
    }
}
void xuatMang(int *ptarr, int n)
{
    printf("mang\n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, *(ptarr + i));
    }
}
void themVaoCuoiMang(int *ptarr, int *n, int m)
{
    int size = sizeof(ptarr) / sizeof(*ptarr);
    if (*n == size)
    {
        printf("k the them");
    }

    *(ptarr + *n) = m;
    (*n)++;
}
void themVaoDauMang(int *ptarr, int *n, int m)
{
    int size = sizeof(ptarr) / sizeof(*ptarr);
    if (*n == size)
    {
        printf("k the them");
    }

    (*n)++;
    for (int i = (*n) - 1; i > 0; i--)
    {
        *(ptarr + i) = *(ptarr + i - 1);
    }
    *ptarr = m;
}
void themMangViTriK(int *ptarr, int *n, int m, int k)
{
    int size = sizeof(ptarr) / sizeof(*ptarr);
    if (*n == size)
    {
        printf("k the them");
    }

    (*n)++;
    for (int i = (*n) - 1; i > k; i--)
    {
        *(ptarr + i) = *(ptarr + i - 1);
    }
    *(ptarr + k) = m;
}

void sapXepTangDan(int *ptarr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((*(ptarr + i)) > (*(ptarr + j)))
            {
                temp = *(ptarr + i);
                (*(ptarr + i)) = (*(ptarr + j));
                (*(ptarr + j)) = temp;
            }
        }
    }
}

void tronMang(int *p1, int n1, int *p2, int n2, int *p3, int *n3)
{
    *n3 = n1 + n2;
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    while (i3 < *n3)
    {
        if (i1 >= n1)
        {
            *(p3 + i3) = *(p2 + i2);
            i2++;
        }
        else if (i2 >= n2)
        {
            *(p3 + i3) = *(p1 + i1);
            i1++;
        }
        else if (*(p1 + i1) < *(p2 + i2))
        {
            *(p3 + i3) = *(p1 + i1);
            i1++;
        }
        else
        {
            *(p3 + i3) = *(p2 + i2);
            i2++;
        }
        i3++;
    }
}

void nhapMang(int *p, int *n)
{
    // Nhập mảng
    do
    {
        printf("Nhap so luong phan tu: ");
        scanf("%d", n);
    } while ((*n) < 1);
    for (int i = 0; i < (*n); i++)
    {
        printf("Nhap a[%d] = ", i);
        scanf("%d", (p + i));
    }
}

void tachMang(int *p1, int n1, int *p2, int *n2, int *p3, int *n3)
{
    int i2 = 0;
    *n2 = 0;
    int i3 = 0;
    *n3 = 0;
    for (int i1 = 0; i1 < n1; i1++)
    {
        if (*(p1 + i1) % 2 == 0)
        {
            *(p2 + i2) = *(p1 + i1);
            i2++;
            (*n2)++;
        }
        else
        {
            *(p3 + i3) = *(p1 + i1);
            i3++;
            (*n3)++;
        }
    }
}

bool kiemTraMangCon(int *p1, int n1, int *p2, int n2)
{
    int kq = false;
    if (n2 < n1)
    {
        for (int i = 0; i < n1; i++)
        {
            if (*(p1 + i) == *p2)
            {
                int j = 0;
                for (; j < n2; j++)
                {
                    if (*(p1 + i + j) != *(p2 + j))
                    {
                        break;
                    }
                }
                if (j == n2)
                {
                    kq = true;
                }
            }
        }
    }
    return kq;
}

void soDuongChanNhoNhat(int *p, int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) < min)
        {
            min = *(p + i);
        }
    }
    if (min > 0 && min % 2 == 0)
        {

            printf("so duong %d\n", min);
        }
}
int main()
{
    int n1, n2, n3;
    int a1[MAX_SIZE], a2[MAX_SIZE], a3[MAX_SIZE];
    int *p1 = &a1[0];
    int *p2 = &a2[0];
    int *p3 = &a3[0];

    nhapMang(p1, &n1);

    xuatMang(p1, n1);

    printf("\n");

    soDuongChanNhoNhat(p1, n1);

    // printf("%d", min2(p, n));
}