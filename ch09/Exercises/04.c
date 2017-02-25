#include <stdio.h>
#include <stdbool.h>

int day_of_year(int month,int day,int year);
bool isLeap(int year);

int main(void){
	
	printf("%d",day_of_year(4,10,2008));
	return 0;
}

int day_of_year(int month,int day,int year){
	
	int i;
	int sum=0;
	int day_of_Feb;
	
	if(isLeap(year)){
		day_of_Feb=30;
	}else{
		day_of_Feb=29;
	}
	
	sum+=day;
	
	for(i=1;i<month;i++){
		switch(i){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				sum+=31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				sum+=30;
				break;
			case 2:
				sum+=day_of_Feb;
				break;
		}
	}
	return sum;
}

bool isLeap(int year){
	return year%400==0||(year%100!=0&&year%4==0);
}
