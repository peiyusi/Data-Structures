#include <stdio.h>

double fn( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x,n));

    return 0;
}

double fn(double x, int n) {
	double result;
	if (n == 1) {
		result = x;
	} else {
		result = x - x * fn(x, n-1);
	}
	
	return result;
}
