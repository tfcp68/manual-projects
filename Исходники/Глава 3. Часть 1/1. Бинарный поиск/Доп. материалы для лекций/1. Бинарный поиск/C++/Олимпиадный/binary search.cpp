int binary_search(int arr[], int length, int data)
{
	int l = 0;
	int r = length - 1;

	while (l <= r)
	{
		int m = floor((l + r) / 2);
		
		if ( arr[m] == data ) {return m;}
		
		else if (arr[m] < data) {l = m + 1;}
		
		else {r = m - 1;}
	}
	
	return -1;
}