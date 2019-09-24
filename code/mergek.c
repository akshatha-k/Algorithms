#include <stdio.h>
#include <stdlib.h>
void merge(int l, int r, int* output)
{
	int l_in = l * n, r_in = ((l + r) / 2 + 1) * n;
	int l_c = ((l + r) / 2 - l + 1) * n;
	int r_c = (r - (l + r) / 2) * n;

	int l_arr[l_c], r_arr[r_c];

	for (int i = 0; i < l_c; i++)
		l_arr[i] = output[l_in + i];

	for (int i = 0; i < r_c; i++)
		r_arr[i] = output[r_in + i];

	int l_curr = 0, r_curr = 0;

	int in = l_in;

	while (l_curr + r_curr < l_c + r_c) {
		if (r_curr == r_c || (l_curr != l_c &&
			l_arr[l_curr] < r_arr[r_curr]))
			output[in] = l_arr[l_curr], l_curr++, in++;
		else
			output[in] = r_arr[r_curr], r_curr++, in++;
	}
}

void divide(int l, int r, int* output,
			int arr[][n])
{
	if (l == r) {

		for (int i = 0; i < n; i++)
			output[l * n + i] = arr[l][i];

		return;
	}

	divide(l, (l + r) / 2, output, arr);

	divide((l + r) / 2 + 1, r, output, arr);

	merge(l, r, output);
}

int main()
{

	int arr[][n] = { { 5, 7, 15, 18 },
					{ 1, 8, 9, 17 },
					{ 1, 4, 7, 7 } };

	int k = sizeof(arr) / sizeof(arr[0]);
  int* output=(int*)malloc(sizeof(int)*n*k);

	divide(0, k - 1, output, arr);

	for (int i = 0; i < n * k; i++)
		printf("%d ",output[i]);

	return 0;
}
