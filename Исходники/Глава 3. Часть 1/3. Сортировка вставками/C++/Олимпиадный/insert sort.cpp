int* InsertionSort(int *arr, int length)
{
	int tmp;
	for (int i = 0; i < dataLength; i++)
	{
		int j = i;
		
		while (j > 0 and arr[j] < arr[j - 1])
		{
			tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
			j--;
		}
	}
	
	return arr;
}