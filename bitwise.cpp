// Given a array with every number repeated twice except one . print that excepted number using bitwise XOR operator in C language.
#include<stdio.h>

int main(){
	
	int a[]={1,1,2,2,3,3,4,5,5};
	int res=0;
	
	for(int i=0;i<9;i++){
		res = res ^ a[i];
	}
	
	printf("%d",res);
	
	return 0;
}
