#include <stdio.h>

int max(int n,int a[n]);
int posNumber(int n,int a[n]);
int average(int n,int a[n]);

int main(void){
	
	int a[10]={1,2,3,5};
	
	printf("%d %d %d",max(10,a),posNumber(10,a),average(10,a));
	
	return 0;
}

int max(int n,int a[n]){
	
	int i,maxIndex=0;
	
	for(i=0;i<n;i++){
		if(a[i]>a[maxIndex]){
			maxIndex=i;
		}
	}
	
	return a[maxIndex];
}

int posNumber(int n,int a[n]){
	
	int i,posNum=0;
	
	for(i=0;i<n;i++){
		if(a[i]>0)
			posNum++;
	}
	
	return posNum;
}

int average(int n,int a[n]){
	
	int i,sum=0;
	
	for(i=0;i<n;i++){
		sum+=a[i];
	}
	
	return sum/n;
	
}
