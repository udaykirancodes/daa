#include<stdio.h>
#include<string.h>
int main(){
	char mai[60],sub[20];
	int flag=-1;
	printf("enter the main string:");
	gets(mai);
	printf("enter the sub string to search:");
	gets(sub);
//	scanf("%[^\n]")
	int l1,l2,i,j;
	l1=strlen(mai);
	l2=strlen(sub);
	for(i=0;i<l1-l2;i++){
		for(j=i;j<i+l2;j++){
			if(mai[j]!=sub[j-i]){
				break;
			}
		}
		if(j==i+l2){
			flag=i;
		}
	}
	if(flag!=-1){
		printf("String \'%s\' found in \'%s\' at index %d\n",sub,mai,flag);
	}else{
		printf("String \'%s\' not  found in \'%s\' \n",sub,mai);
	}
}
