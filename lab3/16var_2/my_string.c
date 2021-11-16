#include "my_string.h"
#include <stdio.h>
#include <stdbool.h>

char* my_strcpy(char* destination, const char* source) {
    if (destination == NULL) {
        return NULL;
    }
    char *ptr = destination; //указатель на начало строки, в которую нужно скопировать
    while (*source != '\0') {   //копируем посимвольно source в необходимую строку
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';    //в новую строку добавляем конец строки

    return ptr; //функция возвращает указатель на строку, в которую скопированы данные.
}

int len(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}

void removeChar(char * str, char charToRemove){
    int i, j;
    int length = len(str);
    for(i = 0; i < length; i++) {
        if(str[i] == charToRemove) {
            for(j = i; j < length; j++) {
                str[j] = str[j+1];
            }
            length--;
            i--;
        }
    }
}

char* my_strcat(char* destination, const char* source) {
    char* ptr = destination + len(destination); //указатель на конец первой строки
    while (*source != '\0') {   //конкатенируем)
        *ptr++ = *source++;
    }
    *ptr = '\0'; //не забываем добавить окончание строки

    return destination; //функция возвращает указатель на новую строку
}

bool is_delim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return true;
        delim++;
    }
    return false;
}

char *my_strtok(char *s, char *delim)
{
    static char *p; // start of the next search
    if(!s)
    {
        s = p;
    }
    if(!s)
    {
        // user is bad user
        return NULL;
    }

    // handle beginning of the string containing delims
    while(1)
    {
        if(is_delim(*s, delim))
        {
            s++;
            continue;
        }
        if(*s == '\0')
        {
            return NULL; // we've reached the end of the string
        }
        // now, we've hit a regular character. Let's exit the
        // loop, and we'd need to give the caller a string
        // that starts here.
        break;
    }

    char *ret = s;
    while(1)
    {
        if(*s == '\0')
        {
            p = s; // next exec will return NULL
            return ret;
        }
        if(is_delim(*s, delim))
        {
            *s = '\0';
            p = s + 1;
            return ret;
        }
        s++;
    }
}
