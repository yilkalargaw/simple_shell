#include "shell.h"

/* char *my_strtok(char *str, const char *delim) { */
/* 	char *last = NULL; */
/* 	static char *ret = NULL; */
/* 	const ssize_t len = strlen(delim); */

/* 	if (str != NULL) { */
/* 		last = str; */
/* 		ret = str; */
/* 	} else { */
/* 		last = ret; */
/* 	} */
/* 	if (last == NULL) { */
/* 		return NULL; */
/* 	} */

/* 	while (*last != '\0') { */
/* 		int i; */
/* 		for (i = 0; i < len; ++i) { */
/* 			if (*last == delim[i]) { */
/* 				*last = '\0'; */
/* 				ret = last + 1; */
/* 				return ret - 1; */
/* 			} */
/* 		} */
/* 		++last; */
/* 	} */
/* 	ret = NULL; */
/* 	return ret; */
/* } */

/* size_t _strcspn(const char *s1, const char *s2) { */
/*     size_t i = 0; */
/*     while (s1[i]) { */
/*         size_t j = 0; */
/*         while (s2[j]) { */
/*             if (s1[i] == s2[j]) { */
/*                 return i; */
/*             } */
/*             ++j; */
/*         } */
/*         ++i; */
/*     } */
/*     return i; */
/* } */

/* size_t _strspn(const char *s, const char *c) */
/* { */
/* 	const char *a = s; */
/* 	size_t byteset[32/sizeof(size_t)] = { 0 }; */

/* 	if (!c[0]) return 0; */
/* 	if (!c[1]) { */
/* 		for (; *s == *c; s++); */
/* 		return s-a; */
/* 	} */

/* 	for (; *c && BITOP(byteset, *(unsigned char *)c, |=); c++); */
/* 	for (; *s && BITOP(byteset, *(unsigned char *)s, &); s++); */
/* 	return s-a; */
/* } */

/* char *_strtok(char *restrict s, const char *restrict sep) */
/* { */
/* 	static char *p; */
/* 	if (!s && !(s = p)) return NULL; */
/* 	s += strspn(s, sep); */
/* 	if (!*s) return p = 0; */
/* 	p = s + strcspn(s, sep); */
/* 	if (*p) *p++ = 0; */
/* 	else p = 0; */
/* 	return s; */
/* } */

/**
 * _strchr - locate character in string
 * @s: string to search
 * @c: character to locate
 *
 * Return: pointer to the first occurrence of the character c in the string s,
 * or NULL if the character is not found
 */
char *_strchr(const char *s, int c) {
    while (*s != (char)c)
        if (!*s++)
            return NULL;
    return (char *)s;
}

/* char *_strtok(char *str, const char *delim) { */
/*     static char *last = NULL; */
/*     char *ret = last; */
/*     char *p; */

/*     if (str != NULL) last = str; */
/*     if (last == NULL) return NULL; */

/*     p = last; */
/*     while (*p != '\0') { */
/*         if (_strchr(delim, *p) != NULL) { */
/*             *p = '\0'; */
/*             last = p + 1; */
/*             return ret; */
/*         } */
/*         p++; */
/*     } */
/*     last = NULL; */
/*     return ret; */
/* } */

/* char *_strchr(const char *s, int c) { */
/*     while (*s != (char)c) */
/*         if (!*s++) */
/*             return NULL; */
/*     return (char *)s; */
/* } */

/* char *_strtok(char *str, const char *delim) { */
/*     static char *last = NULL; */
/*     char *ret = last; */
/*     char *p = last; */

/*     if (str != NULL) last = str; */
/*     if (last == NULL) return NULL; */

/*     while (*p != '\0') { */
/*         if (_strchr(delim, *p) != NULL) { */
/*             *p = '\0'; */
/*             last = p + 1; */
/*             return ret; */
/*         } */
/*         p++; */
/*     } */
/*     last = NULL; */
/*     return ret; */
/* } */

/**
 * _strtok - A function that breaks a string into a sequence of zero or more nonempty tokens.
 * @str: The string to be parsed.
 * @delim: The delimiter characters.
 *
 * Return: A pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim) {
    static char *last = NULL;
    char *token;

    if (str != NULL) {
        last = str;
    }

    if (last == NULL) {
        return NULL;
    }

    token = last;

    while (*last != '\0') {
        if (strchr(delim, *last) != NULL) {
            *last++ = '\0';

            if (*token != '\0') {
                return token;
            } else {
                token = last;
            }
        } else {
            last++;
        }
    }

    last = NULL;

    if (*token != '\0') {
        return token;
    } else {
        return NULL;
    }
}
