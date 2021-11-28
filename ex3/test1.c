#include <stdio.h>

int main()
{
    int m;
    // printf("Nhap m: ");
    scanf("%d", &m);
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = 1; j <= arr[i]; j++)
        {
            if ((arr[i] % j) == 0)
            {
                count++;
            }
        }
        if (count == 3)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
        count = 0;
    }
}
