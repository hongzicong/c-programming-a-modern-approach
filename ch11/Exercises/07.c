#include <stdio.h>
#include <stdbool.h>

void split_date(int day_of_year,int year,int *month,int *day);
bool isLeap(int year);

int main(void){
	
	int month,day;
	
	split_date(365,2017,&month,&day);
	printf("%d %d",month,day);
	
	return 0;
} 

void split_date(int day_of_year,int year,int *month,int *day){
	
	
	for(int i=0;i<=12;i++){
		switch(i){
			case 0:
				break;
			case 2:
				day_of_year-=(isLeap(year))?29:28;
				break;
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				day_of_year-=31;
				break;
			case 4: case 6: case 9: case 11:
				day_of_year-=30;
				break;
			}
		if(i+1==2&&(day_of_year<=((isLeap(year))?30:29))){
			*month=i+1;
			*day=day_of_year;
			break;
		}
		else if((i+1==1||i+1==3||i+1==5||i+1==7||i+1==8||i+1==10||i+1==12)&&(day_of_year<=31)){
			*month=i+1;
			*day=day_of_year;
			break;
		}
		else if((i+1==4||i+1==6||i+1==9||i+1==11)&&day_of_year<=30){
			*month=i+1;
			*day=day_of_year;
			break;
		}
	}
	
}

bool isLeap(int year){
	
	return year%400==0||(year%100!=0&&year%4==0);
	
}
