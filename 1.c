#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#define MAX_SIZE 100
int c[100];
struct date
{
	int day;
	int month;
	int year;
};
struct phanso
{
	int tuso;
	int mauso;
};
typedef int (*f)(int, int);
void xoaKyTuXuongDong(char *p);
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
int timMax(int *p, int n)
{
	int max = *p;
	for (int i = 0; i < n; i++)
	{
		if (*(p + i) > max)
		{
			max = *(p + i);
		}
	}
	return max;
}
void inMangConKhogGiam(int *p, int n)
{
	int *b = &c[0];
	for (int i = 0; i < n; i++)
	{
		*(b + i) = 1;
	}
	for (int i = n - 1; i > 0; i--)
	{
		if (*(p + i) >= *(p + i - 1))
		{
			*(b + i - 1) = *(b + i) + 1;
		}
	}
	printf("mang b:");
	xuatMang(b, n);

	int SL = timMax(b, n);
	for (int i = 0; i < n; i++)
	{
		if (*(b + i) == SL)
		{
			printf("\nmang k giam dai nhat:");
			for (int j = i; j < SL + i; j++)
			{
				printf("%d ", *(p + j));
			}
		}
	}
}
void nhapChuoi(char *p)
{
	printf("nhap chuoi vao:");
	fgets(p, MAX_SIZE, stdin);
	xoaKyTuXuongDong(p);
}
void xuatChuoi(char *p)
{
	printf("chuoi la: ");
	// printf("\nchuoi la: %s", p);
	puts(p);
}
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
void noiChuoi(char *p1, char *p2)
{
	size_t l1 = timDoDaiCuaChuoiDungFgets(p1);
	size_t l2 = timDoDaiCuaChuoiDungFgets(p2);

	for (int i = l1; i < l1 + l2; i++)
	{
		*(p1 + i) = *(p2 + i - l1);
	}
	*(p1 + l1 + l2) = '\0';
}
void copyChuoi(char *p1, char *p2)
{
	size_t l1 = timDoDaiCuaChuoiDungFgets(p1);
	size_t l2 = timDoDaiCuaChuoiDungFgets(p2);

	for (int i = 0; i < l1; i++)
	{
		*(p2 + i) = *(p1 + i);
	}
	*(p2 + l1) = '\0';
}
int soSanhChuoi(char *p1, char *p2)
{
	int kq = 0;
	size_t l1 = timDoDaiCuaChuoiDungFgets(p1);
	size_t l2 = timDoDaiCuaChuoiDungFgets(p2);
	size_t min = l1 < l2 ? l1 : l2;
	for (int i = 0; i < min; i++)
	{
		kq = *(p1 + i) - *(p2 + i);
		if (kq > 0)
			kq = 1;
		else if (kq < 0)
			kq = -1;
		else
			break;
	}
	return kq;
}
void vietHoaToanCHuoi(char *p)
{
	size_t l1 = timDoDaiCuaChuoiDungFgets(p);

	for (int i = 0; i < l1; i++)
	{
		if (*(p + i) >= 97 && *(p + i) <= 122)
		{
			*(p + i) -= 'a' - 'A';
		}
	}
}
void vietThuongToanCHuoi(char *p)
{
	size_t l1 = timDoDaiCuaChuoiDungFgets(p);

	for (int i = 0; i < l1; i++)
	{
		if (*(p + i) >= 65 && *(p + i) <= 90)
		{
			*(p + i) -= 'A' - 'a';
		}
	}
}
void vietHoaChuCaiDau(char *p)
{
	size_t l1 = timDoDaiCuaChuoiDungFgets(p);
	vietThuongToanCHuoi(p);
	if (*p >= 97 && *p <= 122)
	{
		*p -= 32; // chu cai dau tien viet hoa
	}
	for (int i = 1; i < l1; i++)
	{
		if (*(p + i) == ' ') // viet hoa sau dau
		{
			if (*(p + i + 1) >= 97 && *(p + i + 1) <= 122)
			{
				*(p + i + 1) -= 32;
			}
		}
	}
}
void daoNguocChuoi(char *p)
{
	size_t l1 = timDoDaiCuaChuoiDungFgets(p);
	char temp;
	for (int i = 0; i < l1 / 2; i++)
	{
		temp = *(p + i);
		*(p + i) = *(p + l1 - i - 1);
		*(p + l1 - i - 1) = temp;
	}
	*(p + l1) = '\0';
}
char *timKyTu(char *p, char c)
{
	for (int i = 0; i < timDoDaiCuaChuoiDungFgets(p); i++)
	{
		if (*(p + i) == c)
		{
			return p + i;
		}
	}
}
bool kiemTraChuoiDoiXung(char *p)
{
	printf("%d\n", timDoDaiCuaChuoiDungFgets(p) / 2);
	for (int i = 0; i < timDoDaiCuaChuoiDungFgets(p) / 2; i++)
	{
		if (*(p + i) != *(p + timDoDaiCuaChuoiDungFgets(p) - i - 1))
		{
			return false;
		}
	}
	return true;
}
char *timChuoiCon(char *string, char *substring)
{
	register char *a, *b;

	/* First scan quickly through the two strings looking for a
	 * single-character match.  When it's found, then compare the
	 * rest of the substring.
	 */

	b = substring;
	if (*b == 0)
	{
		return string;
	}
	for (; *string != 0; string += 1)
	{
		if (*string != *b)
		{
			continue;
		}
		a = string;
		while (1)
		{
			if (*b == 0)
			{
				return string;
			}
			if (*a++ != *b++)
			{
				break;
			}
		}
		b = substring;
	}
	return NULL;
}
void nhapDate(struct date *p)
{
	printf("nhap ngay\n");
	scanf("%d", &p->day);
	printf("nhap thang\n");
	scanf("%d", &p->month);
	printf("nhap nam\n");
	scanf("%d", &p->year);
}
void printDate(struct date *p)
{
	printf("%d %d %d", p->day, p->month, p->year);
}
void nhapPhanSo(struct phanso *p)
{
	printf("nhap vao tu so");
	scanf("%d", &p->tuso);
	do
	{
		printf("nhap vao mau so");
		scanf("%d", &p->mauso);
	} while (p->mauso == 0);
}
int ucln(int a, int b)
{
	if (a == b)
	{
		return a;
	}
	else if (a > b)
		return ucln(a - b, b);
	else
		return ucln(a, b - a);
}
void rutGonPS(struct phanso *p)
{
	int uc = ucln(abs(p->tuso), abs(p->mauso));
	p->tuso /= uc;
	p->mauso /= uc;
}
void xuatPhanSO(struct phanso *p)
{
	if (p->mauso < 0)
	{
		p->tuso = -(p->tuso);

		p->mauso = -(p->mauso);
	}
	rutGonPS(p);
	printf("%d/%d", p->tuso, p->mauso);
}
int stringToInt(char *str)
{
	int t = 0;
	size_t len = timDoDaiCuaChuoiDungFgets(str);
	for (int i = 0; i < len; i++)
	{
		if (*(str + i) > 47 && *(str + i) < 58)
		{
			t += pow(10, (len - i - 1)) * (*(str + i) - 48);
		}
	}
	return t;
}
FILE writefile()
{
	FILE *f;
	f = fopen("xxx.txt", "w");
	if (f == NULL)
	{
		printf("out");
		exit(1);
	}

	int n;
	printf("nhap n: ");
	scanf("%d", &n);
	fprintf(f, "%d", n);
	fclose(f);
}

FILE readfile()
{
	FILE *f;
	f = fopen("xxx.txt", "r");
	if (f == NULL)
	{
		printf("out");
		exit(1);
	}
	int *n;
	fscanf(f, "%d", n);
	printf("%d", *n);
	fclose(f);
}

FILE writebinfile(struct date *p)
{
	FILE *f;
	f = fopen("bin.bin", "wb");
	if (f == NULL)
	{
		printf("out");
		exit(1);
	}

	fwrite(p, sizeof(struct date), 1, f);
	fclose(f);
}

FILE readbinfile(struct date *p)
{
	FILE *f;
	f = fopen("bin.bin", "rb");
	if (f == NULL)
	{
		printf("out");
		exit(1);
	}

	fread(p, 12, 1, f);
	printf("%d %d %d", p->day, p->month, p->year);
	fclose(f);
}

void xuatFile(int *p, int *n, char *name)
{
	FILE *f;
	f = fopen(name, "w");
	if (f == NULL)
	{
		printf("out");
		return;
	}

	printf("nhap n: ");
	scanf("%d", n);
	for (int i = 0; i < *n; i++)
	{
		printf("nhap x[%d] = ", i);
		scanf("%d", p + i);
		fprintf(f, "%d\n", *(p + i));
	}
	fclose(f);
}

void docFIle(int *p, int *n, char *name)
{
	FILE *f;
	f = fopen(name, "r");
	if (f == NULL)
	{
		printf("out");
		exit(1);
	}

	int i = 0;
	while (!feof(f))
	{
		// printf("%d", feof(f));
		fscanf(f, "%d", p + i);
		i++;
	}
	*n = i;
	printf("so luong phan tu :%d\n", *n);
	fclose(f);
}

int cong(int a, int b) { return a + b; }
int tru(int a, int b) { return a - b; }

int tinhtoan(int a, int b, f tinh)
{
	return tinh(a, b);
}
int Endian_Swap1(int x)
{
	return (
		((x >> 24) & 0x000000FF) |
		((x >> 8) & 0x0000FF00) |
		((x << 8) & 0x00FF0000) |
		((x << 24) & 0xFF000000));
}
int *Endian(int *x)
{
	*x = (*x >> 24) & 0xff |
		 ((*x << 8) & 0x00FF0000) |
		 ((*x >> 8) & 0x0000FF00) |
		 (*x << 24) & 0xff000000;
	return x;
}

int main()
{

	struct date d1;
	struct date d2;
	// char *name = "xxx.txt";
	// int *p = (int *)malloc(10);
	// int x = 0xA0B0C0D0;
	// int *p = Endian(&x);
	// printf("%X", *p);

   
	// openbinfile(&d1);
	//  char *p2 = (char *)malloc(30 * sizeof(char));

	// char *p1 = malloc(sizeof(100));
	// openfile();
	// xuatFile(p, &n, name);

	// docFIle(p, &n, name);

	// xuatMang(p, n);
	printf("\n");
}