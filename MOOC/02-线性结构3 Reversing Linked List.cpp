#include<iostream>
#include<algorithm>
using namespace std;
int list[100010];
int node[100010][2];
int main()
{
    int st,num,r;
    cin>>st>>num>>r;
    int address,data,next,i;
    for(i=0;i<num;i++)
    {
        cin>>address>>data>>next;
        node[address][0]=data;
        node[address][1]=next;
    }
    int m=0,n=st;
    while(n!=-1)
    {
        list[m++]=n;
        n=node[n][1];
    }
    i=0;
    while(i+r<=m)
    {
        reverse(list+i,list+i+r);
        i=i+r;
    }
    for (i = 0; i < m-1; i++)
    {
        printf("%05d %d %05d\n", list[i], node[list[i]][0], list[i+1]);
    }
    printf("%05d %d -1\n", list[i], node[list[i]][0]);
}
/*LinkList Reverse (LinkList head, int k)
{
	int cnt = 1;
	LinkList new, old, tmp;
	new = head->Next;
	old = new->Next;
	while (cnt < k) {
		tmp = old->Next;
		old->Next = new;
        new = old; old = tmp;
        cnt++;		
	}
	head->Next->Next = old;
	return new;
}*/