#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int main() {
    char c = 'A';
    char *s = NULL;
    int d = 12345;
    unsigned int u = 54321;
    int negative = -6789;
    unsigned int hex = 0xABCD;
    void *ptr = &d;

	int ogRes;
	int ftRes;

	ogRes =  printf("og %%c: %c\n", c);
	ftRes = ft_printf("ft %%c: %c\n", c);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%s: %s\n", s);
	ftRes = ft_printf("ft %%s: %s\n", s);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%p: %p\n", ptr);
	ftRes = ft_printf("ft %%p: %p\n", ptr);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%d: %d\n", d);
	ftRes = ft_printf("ft %%d: %d\n", d);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%i: %i\n", d);
	ftRes = ft_printf("ft %%i: %i\n", d);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%u: %u\n", u);
	ftRes = ft_printf("ft %%u: %u\n", u);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%x: %x\n", hex);
	ftRes = ft_printf("ft %%x: %x\n", hex);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%X: %X\n", hex);
	ftRes = ft_printf("ft %%X: %X\n", hex);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%d with negative: %d\n", negative);
	ftRes = ft_printf("ft %%d with negative: %d\n", negative);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%i with negative: %i\n", negative);
	ftRes = ft_printf("ft %%i with negative: %i\n", negative);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%p with NULL pointer: %p\n", NULL);
	ftRes = ft_printf("ft %%p with NULL pointer: %p\n", NULL);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%x with zero: %x\n", 0);
	ftRes = ft_printf("ft %%x with zero: %x\n", 0);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%X with zero: %X\n", 0);
	ftRes = ft_printf("ft %%X with zero: %X\n", 0);
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	ogRes =  printf("og %%%%: %%\n");
	ftRes = ft_printf("ft %%%%: %%\n");
    red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
	
	return 0;
}


/*#include <stdio.h>

int	main()
{
	int ogRes;
	int ftRes;

	ogRes =  printf("og %%c: %c\n", 'c');
	ftRes = ft_printf("ft %%c: %c\n", 'c');
	red();
	printf("og = %d\nft = %d\n\n", ogRes, ftRes);
	reset();
}*/