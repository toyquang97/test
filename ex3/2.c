#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

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

int ucar(int a[], int n)
{
  int uc = a[0];
  for (int i = 1; i < n; i++)
  {
    uc = ucln(uc, a[i]);
  }
  return uc;
}
int ramdom(int min, int max)
{
  return min + rand() % (max + 1 - min);
}
int main()
{
  int n, k;
  srand((int)time(0));
  
  // printf("Nhap m: ");
  scanf("%d %d", &n, &k);
  int arr[n];
  int newar[k];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", arr + i);
  }

  for (int i = 0; i < k; i++)
  {
    newar[i] = arr[ramdom(0,n)];
  }
  int uc = ucar(newar, k);
  printf("%d", uc);
}
