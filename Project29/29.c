#include <stdio.h>
int main()
{
    char a, b, c, tmp;
    while (scanf_s("%c%c%c%*c", &a, &b, &c) != EOF)    //��"%*c"(���ַ������洢�ַ����ַ�)�˵��س�
    {
        if (a > b) tmp = a, a = b, b = tmp;   //���ű��ʽ�����
        if (a > c) tmp = a, a = c, c = tmp;
        if (b > c) tmp = b, b = c, c = tmp;
        printf("%c %c %c\n", a, b, c);
    }
    return 0;
}