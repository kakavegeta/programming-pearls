#include <stdio.h>
#define N 10000000
#define BITS 32
#define SHIFT 5
#define MASK 0x1f

#define index(i) i>>SHIFT // i / 32
#define v(i) i&MASK // i % 32

int arr[N/BITS + 1];

void clear(int i) { arr[index(i)] &= ~(1<<v(i));}
void set(int i) {arr[index(i)] |= 1<<v(i);}
int in(int i) {return arr[index(i)] & (1<<v(i));}

int main(void) {
    int i;
    for (i = 0; i < N; ++i) {
        clear(i);
    }
    while (scanf("%d", &i) != EOF) {
        set(i);
    }
    for (i = 0; i < N; ++i) {
        if (in(i)) printf("%d\n",i);
    }

    return 0;
}
