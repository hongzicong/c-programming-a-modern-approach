#include <stdio.h>
#include <stdbool.h>

int main(void){
	
	int i,n;
	char c,c1[26]={0},c2[26]={0};//simply
	bool isAnagram=true;
	
	printf("Enter first word: ");
	c=getchar();
	while(c!='\n'){
		c1[c-'a']++;
		c=getchar();
	}
	
	printf("Enter second word: ");
	c=getchar();
	while(c!='\n'){
		c2[c-'a']++;
		c=getchar();
	}
	
	for(i=0;i<26;i++){
		if(c1[i]!=c2[i]){
			isAnagram=false;
			break;//simply
		}
	}
	
	printf(isAnagram?"The words are anagrams.":"The words are not anagrams.");
	
	return 0;
}
