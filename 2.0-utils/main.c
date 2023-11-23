#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int main() {
    char c = 'A';
    char *s = "Hello, world!";
    int d = 12345;
    unsigned int u = 54321;
    int negative = -6789;
    unsigned int hex = 0xABCD;
    void *ptr = &d;

	ft_printf("%X\n", 0);


	 printf("\n   printf %%c: %c\n", c);
	ft_printf("ft_printf %%c: %c\n", c);
	 printf("\n   printf %%s: %s\n", s);
	ft_printf("ft_printf %%s: %s\n", s);
	 printf("\n   printf %%p: %p\n", ptr);
	ft_printf("ft_printf %%p: %p\n", ptr);
	 printf("\n   printf %%d: %d\n", d);
	ft_printf("ft_printf %%d: %d\n", d);
	 printf("\n   printf %%i: %i\n", d);
	ft_printf("ft_printf %%i: %i\n", d);
	 printf("\n   printf %%u: %u\n", u);
	ft_printf("ft_printf %%u: %u\n", u);
	 printf("\n   printf %%x: %x\n", hex);
	ft_printf("ft_printf %%x: %x\n", hex);
	 printf("\n   printf %%X: %X\n", hex);
	ft_printf("ft_printf %%X: %X\n", hex);
	 printf("\n   printf %%d with negative: %d\n", negative);
	ft_printf("ft_printf %%d with negative: %d\n", negative);
	 printf("\n   printf %%i with negative: %i\n", negative);
	ft_printf("ft_printf %%i with negative: %i\n", negative);
	 printf("\n   printf %%p with NULL pointer: %p\n", NULL);
	ft_printf("ft_printf %%p with NULL pointer: %p\n", NULL);
	 printf("\n   printf %%x with zero: %x\n", 0);
	ft_printf("ft_printf %%x with zero: %x\n", 0);
	 printf("\n   printf %%X with zero: %X\n", 0);
	ft_printf("ft_printf %%X with zero: %X\n", 0);
	 printf("\n   printf %%%%: %%\n");
	ft_printf("ft_printf %%%%: %%\n");
    return 0;
}

