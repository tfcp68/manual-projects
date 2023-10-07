double ternary_search(double f(double), double l, double r, double e)
{
	while (r - l > e)
		double a = (l * 2 + r) / 3
        double b = (l + r * 2) / 3
        if f(a) < f(b)
            r = b
        else
            l = a
    return (l + r) / 2
}