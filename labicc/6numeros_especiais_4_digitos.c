#include <stdio.h>

int main(void) {
    for (int i = 32; i*i <= 9999; i++) {
        if ((i*i%100) + (i*i/100) == i) printf("%d\n", i*i);
        // printf("%d, %d, %d\n", i*i, (i*i%100), (i*i/100));
    }
}