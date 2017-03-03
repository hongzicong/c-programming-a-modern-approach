#include <stdio.h>
#include <ctype.h>

void censor(char *str);

int main(void)
{
    char str[10] = "food fool\0";
    printf("Original string: %s\n", str);
    censor(str);
    printf("Censored string: %s\n", str);
    return 0;
}

void censor(char *str)
{
    char *p;
    for (p = str; *p; p++)
        if (*p == 'f' && *(p+1) == 'o' && *(p+2) == 'o')
            *p = *(p+1) = *(p+2) = 'x';
}

//my_editor

void censor(char *p){
	
	while(p[0]!='\0'&&p[1]!='\0'&&p[2]!='\0'){
		if(p[0]=='f'&&p[1]=='o'&&p[2]=='o'){
			p[0]=p[1]=p[2]='x';
		}
		p++;
	}
}
