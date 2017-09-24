#include<stdio.h>
#include<ctype.h>

struct Node{
    int root;
    int left;
    int right;
};

int main(){
    //create the tree
    int n;
    struct Node nodes[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        nodes[i].root = 1;
        nodes[i].left = -1;
        nodes[i].right = -1;
    }
    for(int i=0;i<n;i++){
        char ch1,ch2;
        scanf("\n%c %c",&ch1,&ch2);
        if(isdigit(ch1)){
            nodes[i].left = ch1 - '0';
            nodes[ch1-'0'].root = 0;
        }
        if(isdigit(ch2)){
            nodes[i].right = ch2 - '0';
            nodes[ch2-'0'].root = 0;
        }
    }
    int root;
    for(int i=0;i<n;i++)
    {
        if(nodes[i].root == 1){
            root = i;
            break;
        }
    }
    int leaves = 0;
    int queue[10];
    int head=0,rear=0;

    queue[rear++] = root;
    while(rear-head){
        int node = queue[head++];
        if(nodes[node].left == -1 && nodes[node].right == -1){
            if(leaves)
                printf(" ");
            printf("%d",node);
            ++leaves;
        }
        if(nodes[node].left != -1){
            queue[rear++] = nodes[node].left;
        }
        if(nodes[node].right != -1){
            queue[rear++] = nodes[node].right;
        }
    }

    return 0;
}
