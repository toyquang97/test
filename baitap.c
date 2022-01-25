#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct nhanvien
{
    char id[10];
    char name[40];
    float salary;
    float allow;
    float total;
} Khaibao;

int n;
void nhapDanhSachSinhVien(Khaibao *p, int *n);
void xoaKyTuXuongDong(char *p);
int timDoDaiCuaChuoiDungFgets(char *p);
void nhapDS(Khaibao *p);
void showFull(Khaibao *p);
void timKiem(Khaibao *p, int n);
void hienThiLuong(Khaibao *p, int n);
bool checkID(Khaibao *p, int n);
void xoaKyTuXuongDong(char *p)
{
    size_t len = strlen(p);
    // toy quang\n\0
    if (*(p + len - 1) == '\n')
    {
        *(p + len - 1) = '\0';
    }
}

int timDoDaiCuaChuoiDungFgets(char *p)
{
    int count = 0;
    xoaKyTuXuongDong(p);
    while (*(p + count) != '\0')
    {
        count++;
    }

    return count;
}

void nhapDS(Khaibao *p)
{
    do
    {
        printf("nhap id: ");
        scanf("%s", p->id);
        getchar();

        printf("\n");
    } while (timDoDaiCuaChuoiDungFgets(p->id) > 5);
    
    do
    {
        fflush(stdin);
        printf("nhap name: ");
        fgets(p->name, sizeof(p->name), stdin);
        printf("\n");
    } while (timDoDaiCuaChuoiDungFgets(p->name) > 30);

    printf("nhap salary: ");
    scanf("%f", &p->salary);
    printf("\n");
    printf("nhap allow: ");
    scanf("%f", &p->allow);
    getchar();
}

bool checkID(Khaibao *p, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (strcmp(p->id, (p + i)->id) == 0)
        {
            printf("trung id\n");
            return true;
        }
    }
    return false;
}
void showFull(Khaibao *p)
{
    printf("Thong tin nhan vien:\n");
    printf("id: ");
    puts(p->id);
    printf("name: ");
    puts(p->name);
    printf("luong ");
    printf("%.2f\n", p->salary);
    printf("phu cap:");
    printf("%.2f\n", p->allow);
    printf("full:");
    printf("%.2f\n", p->allow + p->salary);
}
void hienThiLuong(Khaibao *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        (p + i)->total = (p + i)->salary + (p + i)->allow;
        if ((p + i)->total > 900)
        {
            showFull(p + i);
        }
    }
}

void timKiem(Khaibao *p, int n)
{
    char sid[10];
    do
    {
        printf("nhap id can tim: ");
        fgets(sid, sizeof(p->id), stdin);
        printf("\n");
    } while (timDoDaiCuaChuoiDungFgets(sid) > 5);

    for (int i = 0; i < n; i++)
    {
        if (strcmp((p + i)->id, sid) == 0)
        {
            showFull(p + i);
        }
    }
}

void nhapDanhSachSinhVien(Khaibao *p, int *n)
{
    do
    {
        printf("\nNhap vao n:");
        scanf("%d", n);
    } while (n <= 0);
    for (int i = 0; i < *n; i++)
    {
        printf("\nNhap vao nhan vien thu %d: \n", i + 1);
        nhapDS(p + i);
    }
}
void main()
{
    Khaibao ds[100];
    Khaibao *nv1 = (Khaibao *)malloc(3 * sizeof(Khaibao));

    nhapDanhSachSinhVien(nv1, &n);
    hienThiLuong(nv1, n);
    // timKiem(ds, n);
    //  nhapDS(&nv1);
    //  showFull(nv1);
    //  nhapDS(&nv2);
    //  nhapDS(&nv3);
}
