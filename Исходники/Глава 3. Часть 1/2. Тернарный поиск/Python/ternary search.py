def ternarySearch(f, left: float, right: float, eps: float):
	while right - left > eps:
		a = (left * 2 + right) / 3
        b = (left + right * 2) / 3
        if f(a) < f(b)
            right = b
        else
            left = a
    return (left + right) / 2