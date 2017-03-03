#include <stdio.h>
#include <ctype.h>

void capitalize_a(char str[]);
void capitalize_b(char *str);
void print_str(char *str);

int main(void)
{
    char str[10] = "j9.d,c34p\0";
    printf("Original String: ");
    print_str(str);

    capitalize_b(str);
    printf("Capitalized String: ");
    print_str(str);

    return 0;
}

void capitalize_a(char str[])
{
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i++]);
    }
}

void capitalize_b(char *str)
{
    char *p;
    for (p = str; *p; p++) {
        *p = toupper(*p);
    }
}

void print_str(char *str)
{
    char *p;
    for (p = str; *p; p++)
        printf("%c", *p);
    printf("\n");
}

void capitalize(char *p){
	while(*p = toupper(*p))
		p++;
	/*
	    不能写成
		while(*p++ = toupper(*p))
			;
	    在这个编译器中，会是第一个数接受第二个数的大写
		因为有两个副作用，不知道谁先谁后，是++先，还是
		=先，但是这两个东西指的都不是同一个变量，++对
		应的是p指针变量，=对的是p地址指的变量，只知道
		当这个while控制语句结束时，这两个副作用都会发
		生而已，别的都不知道 
		
		我的错误想法：
		我猜应该是因为编译器从左到右读取了p将会++这个副
		作用，然后读取到toupper函数，在函数调用时的函数
		入口点有一个顺序点，然后这个副作用便完成他的使命
		但是如果这样的话，就应该是第二个数接受第一个数的
		大写了，所以是不对的
		
		我的第一种正确想法：
		有两种可能，第一种可能是先发生++副作用，后发生=副
		作用，p指的变量等于toupper(*(p+1)),第二种是先发生
		=副作用，后发生++副作用
		
		我的第二种正确想法：
		 。。。直接就不要发生这种情况就好了嘛，不要出现两
		 种副作用了嘛！！！ 
	*/
}
