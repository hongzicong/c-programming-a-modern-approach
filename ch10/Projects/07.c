#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

#define DIGIT_HEIGHT 3
#define DIGIT_WIDTH 3
#define DIGIT_SPACING 1

#define MAX_DIGITS_SPACE (MAX_DIGITS * (DIGIT_WIDTH + DIGIT_SPACING)) - DIGIT_SPACING
#define MAX_SEGMENTS 7

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

/* Contains digit segments for all digits 0 through 9.
 * Segments are 'off' if 0, and 'on' if 1.
 * All digits can be represented using a maximum of 7 segments.
 *
 *     0
 *    ___ 
 * 5 |   | 1
 *   |_6_|
 * 4 |   | 2
 *   |___|
 *     3
 */
const int digit_segments[10][7] = {
/*Segment: 0  1  2  3  4  5  6  | Digit | */
          {1, 1, 1, 1, 1, 1, 0}, /* 0 */
          {0, 1, 1, 0, 0, 0, 0}, /* 1 */
          {1, 1, 0, 1, 1, 0, 1}, /* 2 */
          {1, 1, 1, 1, 0, 0, 1}, /* 3 */
          {0, 1, 1, 0, 0, 1, 1}, /* 4 */
          {1, 0, 1, 1, 0, 1, 1}, /* 5 */
          {1, 0, 1, 1, 1, 1, 1}, /* 6 */
          {1, 1, 1, 0, 0, 0, 0}, /* 7 */
          {1, 1, 1, 1, 1, 1, 1}, /* 8 */
          {1, 1, 1, 1, 0, 1, 1}  /* 9 */
};

/* Row, col positions of the 7 segments in a 3 by 3 grid 
 * positions 0,0 and 0,2 do not contain a segment 
 *
 *    012 
 *  0  _
 *  1 |_|
 *  2 |_| 
 */
const int segment_grid_pos[MAX_SEGMENTS][2] = {
/*  row  col | Segment | */
    {0,   1},  /* 0 */
    {1,   2},  /* 1 */
    {2,   2},  /* 2 */
    {2,   1},  /* 3 */
    {2,   0},  /* 4 */
    {1,   0},  /* 5 */
    {1,   1}   /* 6 */
};

char digits[DIGIT_HEIGHT][MAX_DIGITS_SPACE];

int main(void)
{
    char ch;
    int position = 0;

    clear_digits_array();
    printf("Enter a number (up to 10 digits): ");
    while ((ch = getchar()) != '\n' && position < MAX_DIGITS_SPACE) {

        if (isdigit(ch)) {
            process_digit(ch - '0', position);
            position += DIGIT_WIDTH + DIGIT_SPACING;
        }
    }
    print_digits_array();

}

/* Fill the digits array with empty spaces */
void clear_digits_array(void)
{
    int row, col;
    for (row = 0; row < DIGIT_HEIGHT; row++) {
        for (col = 0; col < MAX_DIGITS_SPACE; col++) 
            digits[row][col] = ' ';
    }
}

/* Construct a digit in the digits array at the starting col */
void process_digit(int digit, int starting_col)
{
    int segment, segment_row_pos, segment_col_pos;

    for (segment = 0; segment < MAX_SEGMENTS; segment++) {

        if (digit_segments[digit][segment]) {
            segment_row_pos = segment_grid_pos[segment][0];
            segment_col_pos = segment_grid_pos[segment][1] + starting_col;
            digits[segment_row_pos][segment_col_pos] = segment % 3 == 0 ? '_' : '|';
        }
    }
}

/* Print the digits array */
void print_digits_array(void)
{
    int row, col;
    for (row = 0; row < DIGIT_HEIGHT; row++) {
        for (col = 0; col < MAX_DIGITS_SPACE; col++) 
            printf("%c", digits[row][col]);

        printf("\n");
    }
}


#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 10

const int segments[10][7]= {{1,1,1,1,1,1},
							{0,1,1},
							{1,1,0,1,1,0,1},
							{1,1,1,1,0,0,1},
							{0,1,1,0,0,1,1},
							{1,0,1,1,0,1,1},
							{1,0,1,1,1,1,1},
							{1,1,1},
							{1,1,1,1,1,1,1},
							{1,1,1,1,0,1,1}};

char digits[3][MAX_DIGITS*4];

void clear_digits_array(void);
void process_digit(int digit,int position);
void print_digits_array(void);

int main(void){
	
	int i=0;
	char ch;
	
	do{
		clear_digits_array();
		printf("\nEnter a number: ");
		while((ch=getchar())!='\n'&&i<MAX_DIGITS){
			if(ch>='0'&&ch<='9'){
				process_digit(ch-'0',i);
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
	
	int m=0;
	int digitPosition[7];
	
	for(int i=0;i<7;i++){
			digitPosition[i]=segments[digit][i];
	}
	
	for(int i=0;i<3;i++){
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
	}
	
}

void print_digits_array(void){
	
	for(int i=0;i<3;i++){
		for(int j=0;j<MAX_DIGITS*4;j++){
			putchar(digits[i][j]);
		}
		putchar('\n');
	}
	
}
