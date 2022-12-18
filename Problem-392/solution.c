#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequence(char * s, char * t);
int main (void)
{
    char s[] = "ace";
    char t[] = "abcd";
    bool answer = false;

    answer = isSubsequence(s,t);

    printf("Is Subsequence = %d", answer);

    return 0;
}

bool isSubsequence(char * s, char * t)
{
    for (int i = 0; i < strlen(s); i++)
    {
        /* '\0' = 0 in int */
        if (!strchr(t, (int) (*(s + i))))
        {
            return false;
        }
    }
    
    return true;
}