#include <stdio.h>

struct time{
	int hours;
	int minutes;
	int seconds;
};

struct time split_time(long total_seconds);

int main(void){
	
	struct time t=split_time(60*60*12+64);
	
	printf("%d:%d:%d",t.hours,t.minutes,t.seconds);
	return 0;
}

struct time split_time(long total_seconds){
	return (struct time){total_seconds/60/60,total_seconds/60%60,total_seconds%60};
}
