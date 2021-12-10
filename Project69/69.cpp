#include <stdio.h>
#include <string.h>

int main()
{          
    char num[12];
    int i, j;

    scanf("%s", num);

    if (num[0] == '-')
    {
        printf("-");
        for (i = strlen(num) - 1; i > 0; i--)
        {
            if (num[i] != '0')
            {
                break;
            }
        }

        for (; i > 0; i--)
        {
            printf("%c", num[i]);
        }

    }
    else
    {
        for (j = strlen(num) - 1; j >= 0; j--)
        {
            if (num[j] != '0')
            {
                break;
            }
        }


        for (; j >= 0; j--)
        {
            printf("%c", num[j]);
        }
    }

    return 0;
}