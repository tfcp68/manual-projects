template<typename T>
T ternary_search(T f(T), T left, T right, T e)
{
	while (right - left > e)
	{
		T left_bound = (left * 2 + right) / 3;
        	T right_bound = (left + right * 2) / 3;
        	if f(left_bound) < f(right_bound)
        	{
	        	right = right_bound;
        	}
        	else
        	{
	        	left = left_bound;
        	}
	}
    return (left + right) / 2;
}