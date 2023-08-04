// Write a program to generate a table of number

# include<stdio.h>

int main(){
	
	int num,i;
	
	printf("Enter the number : ");
	scanf("%d",&num);
	
	for(i=1;i<=10;i++){
		printf("\n%d * %d = %d\n",num,i,num*i);
	}
	
	return 0;
}
