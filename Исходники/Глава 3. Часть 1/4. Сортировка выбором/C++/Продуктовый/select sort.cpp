template<typename T>
bool comp(T firstData, T secondData)
{
	return firstData < secondData;
}

template <typename T arr>
T* selection_sort(T *arr, int size, bool comp)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (comp(arr[j], arr[min_index]))
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr[i], arr[min_index]);
        }
    }
}