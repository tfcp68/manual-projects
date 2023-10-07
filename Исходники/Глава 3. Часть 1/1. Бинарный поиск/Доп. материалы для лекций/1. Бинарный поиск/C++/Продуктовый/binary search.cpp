template<typename T>
bool comp(T firstElement, T secondElement)
{
	return firstElement < secondElement;
}

template<typename T>
T binary_search(T arr[], int length, T data, bool comp)
{
	int left = 0;
	int right = length - 1;

	while (left <= right)
	{
		int mid = floor((left + right) / 2);
		
		if ( arr[mid] == data ) {return mid;}
		
		else if (comp(arr[mid], data)) {left = mid + 1;}
		
		else {right = mid - 1;}
	}
	
	return -1;
}