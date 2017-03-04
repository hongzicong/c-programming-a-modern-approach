#include <stdio.h>

/* Macro to stringize the values of the macro __LINE__ */
#define STRINGIZE(x) #x

/* We need to expand the __LINE__ macro to its integer value first before stringizing it,
   otherwise STRINGIZE would only convert the macro name __LINE__ to string */
#define EXPAND_TO_STRING(x) STRINGIZE(x)

/* We can now call EXPAND_TO_STRING on __LINE__ (we do not need to do this with __FILE__
 * because the __FILE__ macro expands to a string). We could however invoke
 * EXPAND_TO_STRING on the __FILE__ macro if we wanted quotes around the filename.
 * */
#define LINE_FILE "Line " EXPAND_TO_STRING(__LINE__) " of file " __FILE__

int main(void)
{
    const char *str = LINE_FILE;
    printf("%s\n", str);
}

/* 中间多了一个步骤，就能使__LINE__变成integer，是为什么呢？
 * 因为如果#x出现在替换列表中，其中x是一个宏参数，那么它对应
 * 的实际参数不会被扩展，所以要在中间加多一步才行，在扩展EXP
 * AND_TO_STRING的时候，会顺便把__LINE__也扩展了
 * */
