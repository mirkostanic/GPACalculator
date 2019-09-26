#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <dir.h>

using namespace std;

int main(void)
{
    int i = 0;
    int sum = 0;
    float result = 0;
    char digit[0] = {};
    char number[500] = {0};
    int num5 = 0;
    int num4 = 0;
    int num3 = 0;
    int num2 = 0;
    
    char Cname[100];
    char Uname[100];

    DWORD length = 100;
    SYSTEMTIME fileTime;
    GetLocalTime(&fileTime);
    char fileTimeStamp[256]; 
    sprintf(fileTimeStamp, "%02d.%02d.%02d.%02d.%02d.%02d", fileTime.wDay, fileTime.wMonth, fileTime.wYear, fileTime.wHour, fileTime.wMinute, fileTime.wSecond);
    int Ho = fileTime.wHour;
    
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    SMALL_RECT srctWindow;
    HANDLE hstdout;
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    
    if(!GetConsoleScreenBufferInfo(hstdout,&csbiInfo))
    {
		cout << "Error: " << GetLastError() << endl;
    }
    
    for(i = 0; i < csbiInfo.dwSize.X; i++)
    {
         printf("-");
    }

    do
    {
         printf("Input: ");
         scanf("%s", &number);
         if(number[0] == 'c' || number[0] == 'C')
         {
               system("cls");
               for(i = 0; i < csbiInfo.dwSize.X; i++) printf("-");
               continue;
         }
         if(number[0] == 'e' || number[0] == 'E')
         {
               return EXIT_SUCCESS;
         }
         else if(isdigit(number[0]))
         {
              printf("\n      ");
              for(i=0; i<strlen(number); i++)
              {
                    digit[0] = number[i];
                    sum = sum + atoi(digit);
                    if(atoi(digit) == 5)
                    {
                         num5++;
                    }
                    else if(atoi(digit) == 4)
                    {
                         num4++;
                    }
                    else if(atoi(digit) == 3)
                    {
                         num3++;
                    }
                    else if(atoi(digit) == 2)
                    {
                         num2++;
                    }
                    printf(" %d", atoi(digit));
              }
              printf("   5(%d)  4(%d)  3(%d)  2(%d)", num5, num4, num3, num2);
              num5 = 0;
              num4 = 0;
              num3 = 0;
              num2 = 0;
              result = (float) sum / i;
              printf("\n\n >>>>  %d \\ %d = %.2f  <<<<\n\n", sum, i, result);
              for(i = 0; i < csbiInfo.dwSize.X; i++)
              {
                    printf("-");
              }
              i = 0;
              sum = 0;
              result = 0;
         }
    }
    while(5 > 1);
}
