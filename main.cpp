#include <iostream>
using namespace std;


long long int Fibonacci(long int arr[], long int n, long int Q)
{
	long long int max = 1;
	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i < n; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % Q;
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}


void countSort(long int arr[], long int arr_copy[],  long int shift, long int n)
{
	long int* countArr;
	countArr = new long int[1024];

	for (int i = 0; i < 1024; i++) {
		countArr[i] = 0;
	}
		
	for (int i = 0; i < n; i++)
	{
		countArr[(arr[i] >> shift) % 1024]++;
		arr_copy[i] = arr[i];
	}

	for (int i = 1; i < 1024; i++) {
		countArr[i] += countArr[i - 1];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		arr[countArr[(arr_copy[i] >> shift) % 1024] - 1] = arr_copy[i];
		--countArr[(arr_copy[i] >> shift) % 1024];
	}
}


int main()
{	
	long int n, Q;
	long int* arr, * arr_copy;

	long long int res;
	long int max;
	
	arr = new long int[5000000];
	arr_copy = new long int[5000000];
	
	
	int T;
	cin >> T;

	for (int q = 0; q < T; q++)
	{
		cin >> n >> Q;
		res = 0;

		max = Fibonacci(arr, n, Q);

		for (long long int i = 0; (max >> i) > 0; i += 10) {
			countSort(arr, arr_copy, i, n);

		}

		for (long long int j = 0; j < n; j++)
		{
			res = res + (j + 1) * arr[j];
			res = res%Q;
		}

		cout << res << endl;
	}

	return 0;
}
