#include <stdio.h>

int gcd(int a,int b);

int main(void){
	
	int a,b;
	
	printf("Enter two integers: ");
	scanf("%d %d",&a,&b);
	printf("Greatest common divisor: %d",gcd(a,b));
	return 0;
	
}

int gcd(int a,int b){
	int temp,result;
	
	if(b>a){
		temp=a;
		a=b;
		b=temp;
	}
	
	while(b!=0){
		temp=a;
		a=b;
		b=temp%b;
	}
	
	return a;
	
}
