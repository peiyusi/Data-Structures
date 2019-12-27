double dist( double h, double p )  //non-recursive
{
	double d = h;
	
	while (h * p  >= TOL) {  // notice the condition
		d += 2 * h * p;
		h *= p;
	}
	
	return d;	
}

double dist( double h, double p )  //recursive
{
	if (h * p < TOL) {
		return h;                  //notice the export of recursion
	}	
	
	return h + h * p + dist(h * p, p);
}
