#include <stdio.h>
#include <stdarg.h>

void prtf(char *str, ...) {
    va_list args;
    va_start(args, str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i+1] == 'u') {
            unsigned int u = va_arg(args, unsigned int);
            printf("%u", u);
            i++;
        } else {
            putc(str[i], stdout);
        }
    } 
}

int main() {
    unsigned int x = 100;
    prtf("teste teste teste %u, teste %u %u.\n", x, 1000, 777);
}