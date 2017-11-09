#include <stdio.h>

void Swap(int *a, int *b) {
	int temp;
	temp = *a; *a = *b; *b = temp;
}

//void BubbleSort(int a[], int N) {
//	int P, i;
//	int flag;
//	
//	for (P = N - 1; P > 0; P--) {
//		flag = -1;
//		for (i = 0; i < P; i++) {
//			if (a[i] > a[i+1]) {
//				Swap(&a[i], &a[i+1]);
//				flag = 1;
//			}
//		}
//		if (flag == -1) break;
//	}
//}

//void InsertionSort(int a[], int N) {
//	int P, i;
//	int Tmp;
//	
//	for (P = 1; P < N; P++) {
//		Tmp = a[P];
//		for (i = P; i > 0 && a[i - 1] > Tmp; i--) {
//			a[i] = a[i - 1];
//		}
//		a[i] = Tmp;
//	}
//} 

void PercDown(int a[], int p, int N) {
	int Parent, Child;
	int X;
	X = a[p];
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (a[Child] < a[Child+1])) {
			Child++;
		}
		if (X >= a[Child]) {
			break;
		} else {
			a[Parent] = a[Child];
		}
	}
	
	a[Parent] = X;
} 

void HeapSort(int a[], int N) {
	int i;
	
	for (i = N / 2 - 1; i >= 0; i--) {
		PercDown(a, i, N);
	}
	
	for (i = N - 1; i > 0; i--) {
		Swap(&a[0], &a[i]);
		PercDown(a, 0, i);
	}
}




int main() {
	int i, j, N;
	scanf("%d", &N);
	int a[N];
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	//BubbleSort(a, N);
	//InsertionSort(a, N);
	HeapSort(a, N); 
	printf("%d", a[0]);
	for (i = 1; i < N; i++) {
		printf(" %d", a[i]);
	}
	
	return 0;
}
