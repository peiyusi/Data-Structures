double fn( double x, int n )
{
	if (n == 1) {
		return x;
	} else {
		return x + (-1 * x* fn(x, n));	
	}
}

//Recursion
// x - x * x = x - x^2;
// x - x * (x - x^2) = x - x^2 + x^3
// ...
