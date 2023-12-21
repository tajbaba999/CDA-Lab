% {
#include <stdio.h>
      % }

        DIGIT[0 - 9] ID[a - zA - Z][a - zA - Z0 - 9] *

        % % char |
    void | int | while | do | float | break | continue
{
    printf("%s is a keyword\n", yytext);
}
{DIGIT} + { printf("%s is an integer\n", yytext); }
{ID} + { printf("%s is an identifier\n", yytext); }
{DIGIT} + "." {DIGIT} + { printf("%s is a floating point number\n", yytext); }
[<>] = ? |= = | != { printf("%s is a relational operator\n", yytext); }
[+\- * / ]
{ printf("%s is a special operator\n", yytext); }
    [{}() @ # & ] { printf("%s is a special character\n", yytext); }
[., ;]
{ printf("%s is a punctuation mark\n", yytext); }
    . { printf("Unknown token: %s\n", yytext); }
% %

    int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
