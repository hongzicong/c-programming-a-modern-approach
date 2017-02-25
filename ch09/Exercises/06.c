#include <stdio.h>

int digit(int n,int k);

int main(void){
	printf("%d",num_digits(100));
	return 0;
}

int digit(int n,int k){
	int i,result;
	
	for(i=0;i<k;i++){
		result=n%10;
		n/=10;
	}
	
	return result;
}
