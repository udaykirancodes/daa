#include<stdio.h>
#include<limits.h>


int sum(int freq[],int i,int j){
    int s=0;
    for(int k=i;k<=j;k++){
        s=s+freq[k];
    }
    return s;
}

int optcost(int freq[],int i,int j){
    if(i>j){
        return 0;
    }
    if(i==j){
        return freq[i];
    }
    int fsum=sum(freq,i,j);
    int min=INT_MAX;
    for(int r=i;r<=j;++r){
        int cost=(optcost(freq,i,r-1)+optcost(freq,r+1,j));
        if(cost<min){
            min=cost;
        }
    }
    return min+fsum;
}	




int main(){
    int keys[]={10,20,30};
    int freq[]={9,2,6};
    int n=sizeof(keys)/sizeof(keys[0]);
    int s=optcost(freq,0,n-1);
    printf("The cost of optimal bst is:%d",s);
}

