#include <stdio.h>
int main()
{
    char a, b, c, tmp;
    while (scanf_s("%c%c%c%*c", &a, &b, &c) != EOF)    //ÓÃ"%*c"(¿Õ×Ö·û£¬²»´æ´¢×Ö·ûµÄ×Ö·û)ÂËµô»Ø³µ
    {
        if (a > b) tmp = a, a = b, b = tmp;   //¶ººÅ±í´ïÊ½£¬¼ò½à
        if (a > c) tmp = a, a = c, c = tmp;
        if (b > c) tmp = b, b = c, c = tmp;
        printf("%c %c %c\n", a, b, c);
    }
    return 0;
}