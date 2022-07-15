#include <stdio.h>

struct flag {
    /* mod i = 0 condition flag.
     * 0 - Default. 
     * 1 - Div by 3. 
     * 2 - Div by 5. 
     * 3 - Div by 3 and 5. 
     */
    int condition : 3; 
} bizzfuzz;

int main() {
    int i;
    for (i = 0; i < 30; i++) {
        if (i % 3 != 0 && i % 5 != 0) {
            bizzfuzz.condition = 0;
        }
        else if (i % 3 == 0 && i % 5 != 0) {
            bizzfuzz.condition = 1;
        }
        else if (i % 3 != 0 && i % 5 == 0) {
            bizzfuzz.condition = 2;
        }
        else if (i % 3 == 0 && i % 5 == 0) {
            bizzfuzz.condition = 3;
        }

        switch (bizzfuzz.condition) {
            case 0:
                printf("%d\n", i);
                break;
            case 1:
                printf("fizz\n");
                break;
            case 2:
                printf("buzz\n");
                break;
            case 3:
                printf("fizzbuzz\n");
                break;
        }
        bizzfuzz.condition = 0;
    }
}
