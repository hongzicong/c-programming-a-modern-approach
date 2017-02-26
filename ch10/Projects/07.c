
#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 10
#define MAX_SEGMENTS 7

const int segments[10][7]= {  {1,1,1,1,1,1},
		          {0,1,1},
			{1,1,0,1,1,0,1},
			{1,1,1,1,0,0,1},
			{0,1,1,0,0,1,1},
		          {1,0,1,1,0,1,1},
			{1,0,1,1,1,1,1},
			{1,1,1},
			{1,1,1,1,1,1,1},
			{1,1,1,1,0,1,1}};

/*row=digitIndex[digit][0]
  col=digitIndex[digit][1]*/
  
const int digitIndex[MAX_SEGMENTS][2]= {{0,1},
				{1,2},
			          {2,2},
			          {2,1},
				{2,0},
			          {1,0},
				{1,1}};

char digits[3][MAX_DIGITS*4];

void clear_digits_array(void);
void process_digit(int digit,int position);
void print_digits_array(void);

int main(void){
	
	int i;
	char ch;
	
	do{
		i=0;
		clear_digits_array();
		printf("Enter a number: ");
		while((ch=getchar())!='\n'&&i<MAX_DIGITS){
			if(ch>='0'&&ch<='9'){
				process_digit(ch-'0',i);
				print_digits_array();
				i++;
			}
		}
		print_digits_array();
		printf("\nAgain? (Y/N)");
		ch=getchar();
	}while(ch=='Y',getchar());
	
	return 0;
}

void clear_digits_array(void){
	
	for(int i=0;i<3;i++){
		for(int j=0;j<MAX_DIGITS*4;j++){
			digits[i][j]=' ';
		}
	}
	
}
	
void process_digit(int digit,int position){
	
	int segment,row,col;
	
	for(segment=0;segment<MAX_SEGMENTS;segment++){
		if(segments[digit][segment]){
			row=digitIndex[segment][0];
			col=digitIndex[segment][1]+position*4;
			digits[row][col]= segment%3 == 0? '_' : '|' ;
		}
	}
	
	/*for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			if(j==3||(j==0&&i==0)||(i==0&&j==2)){
				digits[i][j+position*4]=' ';
				continue;
			}
			else if(j==1){
				if(i==0&&segments[digit][0]==1){
					digits[i][j+position*4]='_';
				}
				if(i==1&&segments[digit][6]==1){
					digits[i][j+position*4]='_';
				}
				if(i==2&&segments[digit][3]==1){
					digits[i][j+position*4]='_';
				}
			}
			else{
				if(j==0&&i==1&&segments[digit][5]==1){
					digits[i][j+position*4]='|';
				}
				if(j==0&&i==2&&segments[digit][4]==1){
					digits[i][j+position*4]='|';
				}
				if(j==2&&i==1&&segments[digit][1]==1){
					digits[i][j+position*4]='|';
				}
				if(j==2&&i==2&&segments[digit][2]==1){
					digits[i][j+position*4]='|';
				}
			}
		}
	}*/
	
}

void print_digits_array(void){
	
	for(int i=0;i<3;i++){
		for(int j=0;j<MAX_DIGITS*4;j++){
			putchar(digits[i][j]);
		}
		putchar('\n');
	}
	
}
