
#include <stdio.h>
#include <stdlib.h>

int b[1005];
int j=0;

int compare(const void * a,  const void * b);
void mid_tre(int root,int N,int a[]);

int main(){
	int N;
	int i=0;
	scanf("%d",&N);
	int a[N];
	for(i=0;i<N;i++){
	   scanf("%d",&a[i]);
	}
	qsort(a,N,sizeof(int),compare);
	mid_tre(1,N,a);
	printf("%d",b[1]);
	for(i=2;i<=N;i++){
		printf(" %d",b[i]);
	}
}

 int compare(const void * a, const void * b)
 {
     return *(int *)a - *(int *)b;
 }
 
 void mid_tre(int root,int N,int a[]){
 	if(root<=N){
 		mid_tre(2*root,N,a);
 		b[root]=a[j++];
 		mid_tre(2*root+1,N,a);
	 }
 }
