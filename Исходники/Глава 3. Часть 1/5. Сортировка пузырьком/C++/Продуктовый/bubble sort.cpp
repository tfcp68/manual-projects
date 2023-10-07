template<typename T>
bool comp(T firstData, T secondData)
{
	return firstData > secondData;
}

template <typename T arr>
T* bubble_sort(T *arr, int size, bool comp)
{
    int i = 0;
	bool repeat = true;
    while (repeat)
    {
	    repeat = false;
        for (j = 0; j < n - i - 2; j++)
        {
	        if (comp(a[j], a[j + 1]))
	        {
		        std::swap(a[j], a[j + 1]);
		        repeat = true;
	        }
        }
	    i++; 
    }
}