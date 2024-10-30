// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
    /* TODO: Implement strcpy(). */
    char *ptr = destination;
    while (*source != '\0')
    {
        *ptr = *source;
        source++;
        ptr++;
    }
    *ptr = '\0';
    return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
    /* TODO: Implement strncpy(). */
    char *current = destination;
    size_t i = 0;

    while (i < len && *source != '\0')
    {
        *current = *source;
        current++;
        source++;
        i++;
    }

    while (i < len)
    {
        *current = '\0';
        current++;
        i++;
    }

    return destination;
}

char *strcat(char *destination, const char *source)
{
    /* TODO: Implement strcat(). */
    char *current = destination;

    while (*current != '\0')
    {
        current++;
    }
    while (*source != '\0')
    {
        *current = *source;
        current++;
        source++;
    }

    *current = '\0';

    return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
    char *current = destination;

    while (*current != '\0')
    {
        current++;
    }

    size_t i = 0;

    while (i < len && *source != '\0')
    {
        *current = *source;
        current++;
        source++;
        i++;
    }

    *current = '\0';
    return destination;
}

int strcmp(const char *str1, const char *str2)
{
    /* TODO: Implement strcmp(). */
    while (*str1 != '\0' || *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
    /* TODO: Implement strncmp(). */
    size_t i = 0;
    while (i < len)
    {
        if (*str1 != *str2)
        {
            return *str1 - *str2;
        }
        str1++;
        str2++;
        i++;
    }
    return 0;
}

size_t strlen(const char *str)
{
    size_t i = 0;

    for (; *str != '\0'; str++, i++)
        ;

    return i;
}

char *strchr(const char *str, int c)
{
    /* TODO: Implement strchr(). */

    while (*str != '\0')
    {
        if (*str == c)
            return (char *)str;
        str++;
    }

    return NULL;
}

char *strrchr(const char *str, int c)
{
    /* TODO: Implement strrchr(). */
    char *ptr = (char *)str;
    while (*ptr != '\0')
    {
        ptr++;
    }
    while (ptr != str)
    {
        if (*ptr == c)
            return ptr;
        ptr--;
    }

    return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
    /* TODO: Implement strstr(). */
    char *p;
    for (p = (char *)haystack; *p != '\0'; p++)
    {
        if (*p == *needle)
        {
            int ok = 1;
            char *haystackcopy = p;
            for (char *j = (char *)needle; *j != '\0'; j++)
            {
                if (*j != *haystackcopy)
                {
                    ok = 0;
                    break;
                }
                haystackcopy++;
            }
            if (ok == 1)
                return p;
        }
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
    /* TODO: Implement strrstr(). */

    char *p;
    char *last_occureance = NULL;
    for (p = (char *)haystack; *p != '\0'; p++)
    {
        if (*p == *needle)
        {
            int ok = 1;
            char *haystackcopy = p;
            for (char *j = (char *)needle; *j != '\0'; j++)
            {
                if (*j != *haystackcopy)
                {
                    ok = 0;
                    break;
                }
                haystackcopy++;
            }
            if (ok == 1)
                last_occureance = p;
        }
    }

    return last_occureance;
}

void *memcpy(void *destination, const void *source, size_t num)
{
    /* TODO: Implement memcpy(). */
    char *dest = (char *)destination;
    char *sours = (char *)source;

    size_t i = 0;
    while (i < num)
    {
        *dest = *sours;
        dest++;
        sours++;
        i++;
    }
    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
    /* TODO: Implement memmove(). */
    unsigned char *dest = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;

    if (dest < src)
    {
        // for (int i = 0; i < num; i++) {
        //     dest[i] = src[i];
        // }
        size_t i = 0;
        while (i < num)
        {
            *dest = *src;
            src++;
            dest++;
            i++;
        }
    }else{
        for (int i = num; i > 0; i--)
        {
            dest[i - 1] = src[i - 1];
        }

        return destination;
    }
    return destination; // eliminare warning
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    /* TODO: Implement memcmp(). */
    char *pointer1 = (char *)ptr1;
    char *pointer2 = (char *)ptr2;

    size_t i = 0;
    while (i < num)
    {
        if (*pointer1 != *pointer2)
            return *pointer1 - *pointer2;
        i++;
        pointer1++;
        pointer2++;
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
    /* TODO: Implement memset(). */
    unsigned char *pointer = (unsigned char *)source;

    size_t i = 0;
    while (i < num)
    {
        *pointer = value;
        i++;
        pointer++;
    }
    return source;
}
