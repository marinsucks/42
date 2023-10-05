#include <string.h>
#include <stdio.h>
#include "libft.h"

void red(){
  printf("\033[1;31m");
}

void green(){
  printf("\033[1;32m");
}

void reset(){
  printf("\033[0m");
}

int	main(void) {
	
	//STRCAT
	char strcat_src[] = " World!";
	char strcat_dest[] = "Hello,";
	green();
	printf("STRCAT\n");
	reset();
	printf("src = %s\ndest = %s", strcat_src, strcat_dest);
	ft_strcat(strcat_dest, strcat_src);
	red();
	printf("\noutput = %s\n\n", strcat_dest);
	reset();


	//STRCHR
	char *strchr_char;
	char strchr_str[] = "Remplace l'espace-par-un-tiret.";
	green();
	printf("STRCHR\n");
	reset();
	printf("input = %s", strchr_str);
	strchr_char = strchr(strchr_str, ' ');
	*strchr_char = '-';
	red();
	printf("\ntest result = %s\n\n", strchr_str);
	reset();

	//STRCMP
	char strcmp_a[] = "aaa";
	char strcmp_b[] = "aab";
	char strcmp_0[] = "";
	green();
	printf("STRCMP\n");
	reset();
	printf("input a = %s\ninput b = %s\ninput 0 = %s\n", strcmp_a, strcmp_b, strcmp_0);
	red();
	printf("a - b = %i\n", ft_strcmp(strcmp_a, strcmp_b));
	printf("a - \\0 = %i\n\n", ft_strcmp(strcmp_a, strcmp_0));
	reset();

	//STRLEN
	char strlen[] = "yolo";
	green();
	printf("STRLEN\n");
	reset();
	printf("input = %s\n", strlen);
	red();
	printf("output = %i\n\n", ft_strlen(strlen));
	reset();
	


	return (0);
}