void getMax(int a[], int n) // O(n)
{
	int i, minMax = 0, max = 0;
	for (i = 0; i < n; i++) {
		minMax += a[i];
		if (minMax < 0) {
			minMax = 0;
		} else if (minMax > max) {
			max = minMax;
		}
	}
	printf("%d\n", max);
}

void getMax(int a[], int n) // O(n^3)
{
	int i, j, k, minMax, max = 0;
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			minMax = 0;
			for (k = i; k < j; k++) {
				minMax += a[k];
			}
			if (minMax > max) {
				max = minMax;
			}
		}
	}
	
	printf("%d\n", max);	
}

void getMax(int a[], int n)  // O(n^2)
{
	int i, j, minMax, max = 0;
	for (i = 0; i < n; i++) {
		minMax = 0;
		for (j = i; j < n; j++) {
			minMax += a[j];
			if (minMax > max) {
				max = minMax;
			}
		}
	} 
	
	printf("%d\n", max);	
} 

// O(nlogn)
//int max(int a, int b, int c)
//{
//	return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
//}
//
//int DivideAndConquer(int a[], int left, int right)
//{
//	int sum, leftBorderMax, rightBorderMax, borderMax;
//	
//	if (left == right) {
//		return (a[left] > 0 ? a[left] : 0); 
//	}
//	
//	int mid = (left + right) / 2;
//	int leftMax = DivideAndConquer(a, left, mid);
//	int rightMax = DivideAndConquer(a, mid + 1, right);
//	int i;
//	
//	sum = leftBorderMax = 0;
//	for (i = mid; i >= left; i--) {
//		sum += a[i];
//		if (sum > leftBorderMax) {
//			leftBorderMax = sum;
//		}
//	}
//	sum = rightBorderMax = 0;
//	for (i = mid + 1; i <= right; i++) {
//		sum += a[i];
//		if (sum > rightBorderMax) {
//			rightBorderMax = sum;
//		}
//	}
//	borderMax = leftBorderMax + rightBorderMax;
//	
//	return max(leftMax, rightMax, borderMax);
//}
//
//void getMax(int a[], int n)
//{
//	printf("%d\n", DivideAndConquer(a, 0, n - 1));	
//} 


