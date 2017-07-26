#include <stdio.h>
#define TOL 1E-2

double dist( double h, double p );

int main()
{
    double h, p, d;
    scanf("%lf %lf", &h, &p);
    d = dist(h, p);
    printf("%.6f\n", d);
    return 0;
}

double dist( double h, double p ) {
	double sum = h;
	h *= p;
    while (h > TOL) {
    	sum += 2 * h;
    	h *= p;
	}
	
	return sum;
}

