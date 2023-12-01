#include <stdio.h>
#include <device.h>

__attribute__((weak)) int putchar(int ch)
{
    return 0;
}
