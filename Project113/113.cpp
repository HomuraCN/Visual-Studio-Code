#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	char str1[100], str2[100], str3[100], str4[100], str5[100], str6[100];
    int word[6] = { 0 };

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%s", str3);
	scanf("%s", str4);
	scanf("%s", str5);
	scanf("%s", str6);

    if (str1 == "one" || str1 == "a" || str1 == "first" || str1 == "another") { word[0] = 1; }
    if (str2 == "two" || str1 == "both" || str1 == "second") { word[0] = 4;}
    if (str1 == "three" || str1 == "third") { word[0] = 9;}
    if (str1 == "four") { word[0] = 16;}
    if (str1 == "five") { word[0] = 25;}
    if (str1 == "six") { word[0] = 36;}
    if (str1 == "seven") { word[0] = 49;}
    if (str1 == "eight") { word[0] = 64;}
    if (str1 == "nine") { word[0] = 81;}
    if (str1 == "eleven") { word[0] = 21;}
    if (str1 == "twelve") { word[0] = 44;}
    if (str1 == "thirteen") { word[0] = 69;}
    if (str1 == "fourteen") { word[0] = 96;}
    if (str1 == "fifteen") { word[0] = 25;}
    if (str1 == "sixteen") { word[0] = 56;}
    if (str1 == "seventeen") { word[0] = 89;}
    if (str1 == "eightteen") { word[0] = 24;}
    if (str1 == "nineteen") { word[0] = 61;}

    if (str2 == "one" || str2 == "a" || str2 == "first" || str2 == "another") { word[1] = 1; }
    if (str2 == "two" || str2 == "both" || str2 == "second") { word[1] = 4; }
    if (str2 == "three" || str2 == "third") { word[1] = 9; }
    if (str2 == "four") { word[1] = 16; }
    if (str2 == "five") { word[1] = 25; }
    if (str2 == "six") { word[1] = 36; }
    if (str2 == "seven") { word[1] = 49; }
    if (str2 == "eight") { word[1] = 64; }
    if (str2 == "nine") { word[1] = 81; }
    if (str2 == "eleven") { word[1] = 21; }
    if (str2 == "twelve") { word[1] = 44; }
    if (str2 == "thirteen") { word[1] = 69; }
    if (str2 == "fourteen") { word[1] = 96; }
    if (str2 == "fifteen") { word[1] = 25; }
    if (str2 == "sixteen") { word[1] = 56; }
    if (str2 == "seventeen") { word[1] = 89; }
    if (str2 == "eightteen") { word[1] = 24; }
    if (str2 == "nineteen") { word[1] = 61; }

    if (str3 == "one" || str3 == "a" || str3 == "first" || str3 == "another") { word[2] = 1; }
    if (str3 == "two" || str3 == "both" || str3 == "second") { word[2] = 4; }
    if (str3 == "three" || str3 == "third") { word[2] = 9; }
    if (str3 == "four") { word[2] = 16; }
    if (str3 == "five") { word[2] = 25; }
    if (str3 == "six") { word[2] = 36; }
    if (str3 == "seven") { word[2] = 49; }
    if (str3 == "eight") { word[2] = 64; }
    if (str3 == "nine") { word[2] = 81; }
    if (str3 == "eleven") { word[2] = 21; }
    if (str3 == "twelve") { word[2] = 44; }
    if (str3 == "thirteen") { word[2] = 69; }
    if (str3 == "fourteen") { word[2] = 96; }
    if (str3 == "fifteen") { word[2] = 25; }
    if (str3 == "sixteen") { word[2] = 56; }
    if (str3 == "seventeen") { word[2] = 89; }
    if (str3 == "eightteen") { word[2] = 24; }
    if (str3 == "nineteen") { word[2] = 61; }

    if (str4 == "one" || str4 == "a" || str4== "first" || str4 == "another") { word[3] = 1; }
    if (str4 == "two" || str4 == "both" || str4 == "second") 
    {
        word[3] = 4; 
    }
    if (str4 == "three" || str4 == "third") { word[3] = 9; }
    if (str4 == "four") { word[3] = 16; }
    if (str4 == "five") { word[3] = 25; }
    if (str4 == "six") { word[3] = 36; }
    if (str4 == "seven") { word[3] = 49; }
    if (str4 == "eight") { word[3] = 64; }
    if (str4 == "nine") { word[3] = 81; }
    if (str4 == "eleven") { word[3] = 21; }
    if (str4 == "twelve") { word[3] = 44; }
    if (str4 == "thirteen") { word[3] = 69; }
    if (str4 == "fourteen") { word[3] = 96; }
    if (str4 == "fifteen") { word[3] = 25; }
    if (str4 == "sixteen") { word[3] = 56; }
    if (str4 == "seventeen") { word[3] = 89; }
    if (str4 == "eightteen") { word[3] = 24; }
    if (str4 == "nineteen") { word[3] = 61; }

    if (str5 == "one" || str5 == "a" || str5 == "first" || str5 == "another") { word[4] = 1; }
    if (str5 == "two" || str5 == "both" || str5 == "second") { word[4] = 4; }
    if (str5 == "three" || str5 == "third") { word[4] = 9; }
    if (str5 == "four") { word[4] = 16; }
    if (str5 == "five") { word[4] = 25; }
    if (str5 == "six") { word[4] = 36; }
    if (str5 == "seven") { word[4] = 49; }
    if (str5 == "eight") { word[4] = 64; }
    if (str5 == "nine") { word[4] = 81; }
    if (str5 == "eleven") { word[4] = 21; }
    if (str5 == "twelve") { word[4] = 44; }
    if (str5 == "thirteen") { word[4] = 69; }
    if (str5 == "fourteen") { word[4] = 96; }
    if (str5 == "fifteen") { word[4] = 25; }
    if (str5 == "sixteen") { word[4] = 56; }
    if (str5 == "seventeen") { word[4] = 89; }
    if (str5 == "eightteen") { word[4] = 24; }
    if (str5 == "nineteen") { word[4] = 61; }

    if (str6 == "one" || str6 == "a" || str6 == "first" || str6 == "another") { word[5] = 1; }
    if (str6 == "two" || str6 == "both" || str6 == "second") { word[5] = 4; }
    if (str6 == "three" || str6 == "third") { word[5] = 9; }
    if (str6 == "four") { word[5] = 16; }
    if (str6 == "five") { word[5] = 25; }
    if (str6 == "six") { word[5] = 36; }
    if (str6 == "seven") { word[5] = 49; }
    if (str6 == "eight") { word[5] = 64; }
    if (str6 == "nine") { word[5] = 81; }
    if (str6 == "eleven") { word[5] = 21; }
    if (str6 == "twelve") { word[5] = 44; }
    if (str6 == "thirteen") { word[5] = 69; }
    if (str6 == "fourteen") { word[5] = 96; }
    if (str6 == "fifteen") { word[5] = 25; }
    if (str6 == "sixteen") { word[5] = 56; }
    if (str6 == "seventeen") { word[5] = 89; }
    if (str6 == "eightteen") { word[5] = 24; }
    if (str6 == "nineteen") { word[5] = 61; }

    printf("%d", word[3]);

    sort(word + 0, word + 6);

    /*for(int i = 0; i < 6; i++)
    {
        if (word[i] != 0)
        {
            printf("%d", word[i]);
        }
    }*/

	return 0;
}