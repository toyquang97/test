int vidu(int a[], int n, int v)
{
	for (int i = 0; i < n; ++i)
	{
		if (&a[i] == v)
		{
			return i;
		}
	}
	int sum(int a, int b);
	typedef int (*fptr)(int, int);
	fptr vidu()
	{
		return sum;
	}
	void main()
	{
		fptr fptr1;
		fptr1 = vidu();
		printf("%d", fptr1(a, b));
	}
	//////////////////////////////// arrray of function pointer////////////////
	int (*afptr[])(int, int);
	//////////////////// cap pha bo nho dong //
	// malloc: n so luong phan tu can cap
	ptr = (castType *)malloc(size);
	ptr = (float *)malloc(n * sizeof(float));
	int *ptr = (int *)malloc(n * sizeof(int));
	// calloc: gan gia tri ban dau bang 0
	ptr = (castType *)calloc(n, size);
	ptr = (float *)calloc(25, sizeof(float));

	//// thay doi kich thuoc bo nho cap phat dong
	ptr = realloc(ptr, x);
	//// giai phong bo nho
	free(ptr);