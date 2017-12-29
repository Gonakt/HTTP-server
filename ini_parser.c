#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *ini;
    char str[50] = {0}, key[50] = {0}, value[50] = {0};

    ini = fopen(argv[1], "r");
    if (ini == NULL) {
        printf("Error\n");
        return 1;
    }
    else
        printf("Successfully done\n");

    int i = 0, j = 0;

    while (fgets(str, 50, ini) != NULL)
    {
        while (str[i] != '=')
        {
            key[i] = str[i];
            i++;
        }
        i = i + 2;
        while (str[i])
        {
            value[j] = str[i];
            i++;
            j++;
        }
        i = 0;
        j = 0;
        printf("%s", key);
        printf("= ");
        printf("%s", value);
        memset(key, 0, 50);
        memset(value, 0, 50);
        memset(str, 0, 50);
    }
    return 0;
}