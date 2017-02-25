#include <stdio.h>

float compute_GPA(char grades[],int n);

int main(void){
	
	printf("%g",compute_GPA((char []){'A','B','C','D'},4));
	return 0;
}

float compute_GPA(char grades[],int n){
	
	int i;
	float GPA=0.0f;
	
	for(i=0;i<n;i++){
		switch(grades[i]){
			case 'A':
				GPA+=4.0f;
				break;
			case 'B':
				GPA+=3.0f;
				break;
			case 'C':
				GPA+=2.0f;
				break;
			case 'D':
				GPA+=1.0f;
				break;
			case 'F':
				break;
		}
	}
	
	return GPA/n;
	
}
