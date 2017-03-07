#include <stdbool.h>
#include <stdio.h>

#define EARLIER -1
#define SAME 0
#define LATER 1

struct date{
	int month;
	int day;
	int year;
};


bool isLeap(int year);
int all_day(struct date d);
int compare_dates(struct date d1,struct date d2);

int num_month[]={31,28,31,30,31,30,31,31,30,31,30,31};
int leap_num_month[]={31,29,31,30,31,30,31,31,30,31,30,31};

int main(void){
	struct date d={12,31,2015};
	printf("%d",all_day(d));
	return 0;
}

int all_day(struct date d){
	
	int sum=0;
	
	if(isLeap(d.year)){
		for(int i=0;i<d.month-1;i++){
			sum+=leap_num_month[i];
		}
		sum+=d.day;
	}
	else{
		for(int i=0;i<d.month-1;i++){
			sum+=num_month[i];
		}
		sum+=d.day;	
	}
	return sum;
}

bool isLeap(int year){
	return (year%400==0)||(year%100!=0&&year%4==0);
}

int compare_dates(struct date d1,struct date d2){
    
    int comparison;
    
	if(d1.year!=d2.year){
		comparison=(d1.year<d2.year)?EARLIER:LATER;
	}else{
		if(d1.month!=d2.month){
			comparison=(d1.month<d2.month)?EARLIER:LATER;
		}
		else{
			if(d1.day!=d2.day){
				comparison=(d1.day<d2.day)?EARLIER:LATER;
			}
			comparison=SAME;
		}
	}   
    
    return comparison;
}
