/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

void red(){
  printf("\033[1;31m");
}

void green(){
  printf("\033[1;32m");
}

void blue(){
  printf("\033[1;34m");
}

void reset(){
  printf("\033[0m");
}

void	atoiTest()
{
    char atoi0[] = "-42";
    char atoi1[] = "0";
    char atoi2[] = "123456";
    char atoi3[] = "  67xy";
    char atoi4[] = "   +42";
    char atoi5[] = "  xyz9";
    
    blue();
    printf("Input\tatoi\tft_atoi\n");
    red();
    if (ft_atoi(atoi0) == atoi(atoi0)) green();
    printf("%s\t%d\t%d\n", atoi0, atoi(atoi0), ft_atoi(atoi0));
	red();
    if (ft_atoi(atoi1) == atoi(atoi1)) green();
    printf("%s\t%d\t%d\n", atoi1, atoi(atoi1), ft_atoi(atoi1));
	red();
    if (ft_atoi(atoi2) == atoi(atoi2)) green();
    printf("%s\t%d\t%d\n", atoi2, atoi(atoi2), ft_atoi(atoi2));
	red();
    if (ft_atoi(atoi3) == atoi(atoi3)) green();
    printf("%s\t%d\t%d\n", atoi3, atoi(atoi3), ft_atoi(atoi3));
	red();
    if (ft_atoi(atoi4) == atoi(atoi4)) green();
    printf("%s\t%d\t%d\n", atoi4, atoi(atoi4), ft_atoi(atoi4));
	red();
    if (ft_atoi(atoi5) == atoi(atoi5)) green();
    printf("%s\t%d\t%d\n", atoi5, atoi(atoi5), ft_atoi(atoi5));
	reset();
} 

void	bzeroTest()
{
	blue();
	printf("\n\n*** BZERO ***\nwrite n zeroed bytes to the string s \n\n");
	reset();

	printf("Enter a string (100 char max): ");
	char bzerostr[101];
	scanf("%s", bzerostr);
	char *bzerostr2 = malloc(ft_strlen(bzerostr) + 1);
	bzerostr2 = ft_strcpy(bzerostr2, bzerostr);
	printf("Enter the number of zeroed bytes to write to the string: ");
	int bzeron;
	scanf("%d", &bzeron);
	ft_bzero(bzerostr, bzeron);
	bzero(bzerostr2, bzeron);

	red();
	if (!ft_strcmp(bzerostr, bzerostr2))
		printf("\nComparison between ft and og succesful.\n");
	else
		printf("\nFailure : comparison unsuccesful between ft_bzero str and bzero str.\n");
	reset();
}

void	isTest()
{
	blue();
	printf("\n\n*** ISALNUM, ISALPHA, ISASCII, ISDIGIT, ISPRINT ***\n\n");
	reset();

	printf("Please enter a character, or '*' to test all char:");
	char isc;
	scanf("%s", &isc);

	red();
	if(isc == '*')
	{
		for (int i = 0; i <= 255; i++)
		{
			if (ft_isalnum(i))
				printf("%c is alnum.\n", i);
			if (ft_isalpha(i))
				printf("%c is alpha.\n", i);
			if (ft_isdigit(i))
				printf("%c is digit.\n", i);
			if (ft_isascii(i))
				printf("%c is ascii.\n", i);
			if (ft_isprint(i))
				printf("%c is print.\n", i);
		}
	}

	if (ft_isalnum(isc))
		printf("%c is alnum.\n", isc);
	if (ft_isalpha(isc))
		printf("%c is alpha.\n", isc);
	if (ft_isdigit(isc))
		printf("%c is digit.\n", isc);
	if (ft_isascii(isc))
		printf("%c is ascii.\n", isc);
	if (ft_isprint(isc))
		printf("%c is print.\n", isc);
	reset();
}

void	toTest()
{
	blue();
	printf("\n\n*** TOLOWER, TOUPPER ***\n\n");
	reset();

	printf("Please enter an alphabetical character :");
	char toc;
	scanf("%s", &toc);
	char toc2 = toc;
	
	red();
	if (ft_isalpha(toc))
	{
		printf("tolower = %c\n", ft_tolower(toc));
		printf("toupper = %c\n", ft_toupper(toc2));
	}
	else 
		printf("\nincorrect output.");
	reset();
}

int	main()
{
	red();
	printf("\nWELCOME TO LIBFT TEST PROGRAM.\n");
	reset();

	while (1)
	{
		char 	func_name[50];
		printf("\nPlease write the name of the function you want to test, or q to quit: ");
		scanf("%s", func_name);

		if (!ft_strcmp(func_name, "q"))
			break;

		if (!ft_strcmp(func_name, "atoi"))
			atoiTest();
		else if (!ft_strcmp(func_name, "bzero"))
			bzeroTest();
		else if (!ft_strncmp(func_name, "is", 2))
			isTest();
		else if (!ft_strncmp(func_name, "to", 2))
			toTest();
		
		else
			printf("Not a valid entry. Examples can be 'atoi', 'is...', 'strcmp', 'q'.\n");
	}
	red();
	printf("\nEND OF THE PROGRAM\n");
	return 0;
}*/














//ANCIEN MAIN

/* int	main(void) {

	//IS~
	// for (int i = -1; i < 129; i++)
	// {
	// 	if (ft_is~(i))
	// 		printf("%c / ", i);
	// }
	
	//STRCAT 
	char strcat_src[] = "World!"; //CHECKS Empty OK
	char strcat_dest[] = "Hello,"; //CHECKS Empty OK
	green();
	printf("STRCAT\n");
	reset();
	printf("src = %s\ndest = %s", strcat_src, strcat_dest);
	ft_strcat(strcat_dest, strcat_src);
	red();
	printf("\nmy output = %s\n\n", strcat_dest);
	reset();
	
	//STRNCAT
	char strncat_src[] = "_World!"; //CHECKS Empty OK
	char strncat_dest[] = "Hello,"; //CHECKS Empty OK
	int strncat_n = 3;
	green();
	printf("STRNCAT\n");
	reset();
	printf("src = %s\ndest = %s\nn = %i\n", strncat_src, strncat_dest, strncat_n);
	ft_strncat(strncat_dest, strncat_src, strncat_n);
	red();
	printf("\nmy output = %s\n\n", strncat_dest);
	reset();

	//STRCHR
	char *strchr_char;
	char strchr_str[] = "a b c d"; //CHECKS Empty OK
	green();
	printf("STRCHR\n");
	reset();
	printf("input = %s", strchr_str);

	strchr_char = ft_strchr(strchr_str, ' ');
	*strchr_char = '-';
	red();
	printf("\ntest result = %s\n\n", strchr_str);
	reset();

	//STRRCHR
	char *strrchr_char;
	char strrchr_str[] = "e f g h"; //CHECKS Empty OK
	green();
	printf("STRRCHR\n");
	reset();
	printf("input = %s", strrchr_str);
	strrchr_char = ft_strrchr(strrchr_str, '\0');
	*strrchr_char = '-';
	red();
	printf("\ntest result = %s\n\n", strrchr_str);
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

	//STRNCMP
	char strncmp_a[] = "aaaaa";
	char strncmp_b[] = "aaaba";
	char strncmp_c[] = "aaaab"; //CHECKS Empty OK
	int num = 4;
	green();
	printf("STRNCMP\n");
	reset();
	printf("input a = %s\ninput b = %s\ninput c = %s\nlimit = %i\n", strncmp_a, strncmp_b, strncmp_c, num);
	red();
	printf("a - b = %i\n", ft_strncmp(strncmp_a, strncmp_b, num));
	printf("a - c = %i\n\n", ft_strncmp(strncmp_a, strncmp_c, num));
	reset();

	//STRCPY
	char strcpy_src[] = "text replacing part of dst"; //CHECKS Empty OK
	char strcpy_dst[] = "xxxxxxxxxxxxxxxxxxxxxxxxxx //DONE";
	green();
	printf("STRCPY\n");
	reset();
	printf("src = %s\n", strcpy_src);
	red();
	printf("dst output = %s\n\n", ft_strcpy(strcpy_dst, strcpy_src));
	printf("OG output = %s\n\n", strcpy(strcpy_dst, strcpy_src));
	reset();

	//STRNCPY
	char strncpy_src[] = "copied text fom src to dstxxxxxxx"; //CHECKS Empty OK
	char strncpy_dst[] = "xxxxxxxxxxxxxxxxxxxxxxxxxx //DONE";
	int strncpy_len = 27;
	green();
	printf("STRNCPY\n");
	reset();
	printf("src = %s\nlen = %d\n", strncpy_src, strncpy_len);
	red();
	printf("dst output = %s\n\n", ft_strncpy(strncpy_dst, strncpy_src, strncpy_len));
	reset();

	//STRLEN
	char strlen[] = "yolo"; //CHECKS Empty OK
	green();
	printf("STRLEN\n");
	reset();
	printf("input = %s\n", strlen);
	red();
	printf("output = %zu\n\n", ft_strlen(strlen));
	reset();

	//STRSTR
	char *strstr_haystack = "foofoobarfoo"; //CHECKS Empty OK
	char *strstr_needle = "bar";
	green();
	printf("STRSTR\n");
	reset();
	printf("haystack = %s\nneedle = %s\n", strstr_haystack, strstr_needle);
	red();
	printf("output = %s\n\n", ft_strstr(strstr_haystack, strstr_needle));
	reset();

	//STRNSTR
	char *strnstr_haystack = "foofoobarfoo"; //CHECKS Empty OK
	char *strnstr_needle = "bar";
	int n1 = 9;
	int n2 = 7;
	green();
	printf("STRNSTR\n");
	reset();
	printf("haystack = %s\nneedle = %s\nn1 = %d\nn2 = %d\n", strnstr_haystack, strnstr_needle, n1, n2);
	red();
	printf("n1 output = %s\n", ft_strnstr(strnstr_haystack, strnstr_needle, n1));
	printf("n2 output = %s\n\n", ft_strnstr(strnstr_haystack, strnstr_needle, n2));
	reset();

	//STRDUP
	char strdup_src[] = "src text to dup"; //CHECKS Empty OK
	char *strdup_dst = ft_strdup(strdup_src);
	green();
	printf("STRDUP\n");
	reset();
	printf("src = %s\n", strdup_src);
	red();
	printf("dst output = %s\n\n", strdup_dst);
	reset();
	free(strdup_dst);

	//MEMSET
	char memset_b[10];
	char memset_c = 'A';
	green();
	printf("MEMSET\n");
	reset();
	printf("char c = %c\nsizeof buffer = %lu\n", memset_c, sizeof(memset_b));
	ft_memset(memset_b, memset_c, sizeof(memset_b));
	red();
	printf("result : %s\n(anything after %c is normal, memory tests are fucked lol)\n", memset_b, memset_c);
	reset();

	
	return (0);
}*/