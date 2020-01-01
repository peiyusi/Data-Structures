#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  
  int myints[10];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
  	myints[i] = i + 1;
  }

  do {
    for (int i = 0; i < n; i++) {
    	std::cout << myints[i];
	}
	std::cout << '\n';
  } while ( std::next_permutation(myints,myints+n) );

  

  return 0;
}



//DFS solution... 

//#include <stdio.h>
//
//void swap(int a[], int x, int y)
//{
//	int temp = a[x];
//	a[x] = a[y];
//	a[y] = temp;
//}
//
//void print(int a[], int n)
//{
//	int i;
//	for (i = 0; i < n; i++) {
//		printf("%d", a[i]);
//	}
//	printf("\n");
//}
//
//void permutation(int a[], int n, int depth)
//{
//	if (depth == n - 1) {
//		print(a, n);
//	} else {
//		int i;
//		for (i = depth; i < n; i++) {
//			swap(a, i, depth);
//			permutation(a, n, depth + 1);
//			swap(a, i, depth);
//		}		
//	}
//}
//
//int main()
//{
//	int a[10], n, i;
//	scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//  		a[i] = i + 1;
//    }
//	permutation(a, n, 0);
//	
//	return 0;
//}



//#include <stdio.h>
//
//static int visit[10] = {0};
//static int element[10] = {0};
//
//void print(int n)
//{
//	int i;
//	for (i = 0; i < n; i++) {
//		printf("%d", element[i]);
//	}
//	printf("\n");
//}
//
//void dfs(int depth, int n)
//{
//	if (depth == n) {
//		print(n);
//	} else {
//		int i;
//		for (i = 0; i < n; i++) {
//			if (!visit[i]) {
//				visit[i] = 1;
//				element[depth] = i + 1;
//				dfs(depth + 1, n);
//				visit[i] = 0;	
//			} 
//		}
//	} 
//}
//
//int main()
//{
//	int a[10], n, i;
//	scanf("%d", &n);
//    
//	dfs(0, n);
//	
//	return 0;
//}



