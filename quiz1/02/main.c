#include <stdint.h>
#include <stdio.h>

#define TEST_ALIGN_UP(addr, align)                      \
    do {                                                \
        printf("align_up(%d, %d) = %ld\n", addr, align, \
               align_up(addr, align));                  \
    } while (0)

static inline uintptr_t align_up(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;
    if ((alignment & mask) == 0) { /* power of two? */
        return (sz + mask) & ~(mask);
    }
    return (((sz + mask) / alignment) * alignment);
}

int main(void)
{
    TEST_ALIGN_UP(120, 4);
    TEST_ALIGN_UP(121, 4);
    TEST_ALIGN_UP(122, 4);
    TEST_ALIGN_UP(123, 4);

    TEST_ALIGN_UP(124, 4);
    TEST_ALIGN_UP(125, 4);
    TEST_ALIGN_UP(126, 4);
    TEST_ALIGN_UP(127, 4);
    TEST_ALIGN_UP(128, 4);

    TEST_ALIGN_UP(120, 3);
    TEST_ALIGN_UP(121, 3);
    TEST_ALIGN_UP(122, 3);
    TEST_ALIGN_UP(123, 3);

    return 0;
}
