#include <stdio.h>

int computeX(int x);

int main(void){
	
	int x;
	
	printf("Enter the x: ");
	scanf("%d",&x);
	printf("The result is %d.",computeX(x));
	
	return 0;
} 

int computeX(int x){
	return x*x*x*x*x*3+2*x*x*x*x-5*x*x*x-x*x+7*x-6;
}
