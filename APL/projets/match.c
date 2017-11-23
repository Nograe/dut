#include <stdio.h>

int match(char *s1, char *s2, int opt) {

    int var = 0;
    if(opt)
        var = 1;

    if (*s1 == '\0' && *s2 == '\0')
        return 1;
    if (*s1 == '\0' && *s2 == '*')
        return match (s1, s2 + 1, var);
    if (*s1 == *s2)
        return match (s1 + 1, s2 + 1, var);
    if (*s2 == '*') {
        if(opt)
            return match(s1, s2 + 1, var) + match(s1 + 1, s2, var);
        if(!match(s1, s2 + 1, var))
            return match(s1 + 1, s2, var);
        return match(s1, s2 + 1, var);
    }
    return 0;
}

int main (int argc, char *argv[]) {

    if(argc == 4)
        printf("%d\n", match(argv[1], argv[2], 1));
    else
        printf("%d\n", match(argv[1], argv[2], 0));
    return 0;
}
