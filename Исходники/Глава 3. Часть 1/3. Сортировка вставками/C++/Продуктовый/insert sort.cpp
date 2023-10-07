template<typename T>
bool comp(T firstData, T secondData)
{
	return firstData < secondData;
}

template<typename T>
T InsertionSort(T *arr, int array_size, bool comp)
{
	int tmp;
	for (int numberIndex = 0; i < array_size; i++)
	{
		int currentIndex = numberIndex;
		
		while (not comp(currentIndex, 0))
		{
			if (comp(arr[currentIndex], arr[currentIndex - 1]))
			{
				tmp = arr[currentIndex - 1];
				arr[currentIndex - 1] = arr[currentIndex];
				arr[currentIndex] = tmp;
				currentIndex--;
			}
		}
	}
	
	return arr;
}