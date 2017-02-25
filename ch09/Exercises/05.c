#include <stdio.h>

int num_digits(int n);

int main(void){
	printf("%d",num_digits(100));
	return 0;
}

int num_digits(int n){
	int i=0;
	
	do{
		n/=10;
		i++;
	}while(n!=0);
	
	return i;
}
