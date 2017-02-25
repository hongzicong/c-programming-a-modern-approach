#include <stdio.h>
#include <stdbool.h>

void read_word(int counts[]);
bool equal_array(int counts1[],int counts2[]);

int main(void){
	
	int c1[26]={0},c2[26]={0};//simply
	
	printf("Enter first word: ");
	read_word(c1);
	
	printf("Enter second word: ");
	read_word(c2);
	
	printf(equal_array(c1,c2)?"The words are anagrams.":"The words are not anagrams.");
	
	return 0;
}

void read_word(int counts[]){
	
	char c;
	
	c=getchar();
	while(c!='\n'){
		counts[c-'a']++;
		c=getchar();
	}
	
}

bool equal_array(int counts1[],int counts2[]){
	
	int i;
	bool isAnagram=true;
	
	for(i=0;i<26;i++){
		if(counts1[i]!=counts2[i]){
			isAnagram=false;
			break;//simply
		}
	}
	
	return isAnagram;
}
