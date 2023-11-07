#include <stdio.h>
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
    blue();
	printf("\n\n*** ATOI ***\n\n");
	reset();

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
	{
		green();
		printf("\nComparison between ft and og succesful.\n");
	}
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

	green();
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
		green();
		printf("tolower = %c\n", ft_tolower(toc));
		printf("toupper = %c\n", ft_toupper(toc2));
	}
	else 
		printf("\nincorrect output.");
	reset();
}

void	memmoveTest() 
{
	blue();
	printf("\n\n*** MEMMOVE ***\n\n");
	reset();

    char str0[] = "samestring";
    char str1[20] = "Hello, World!";
    char str2[20] = "1234567890";
    char str3[20] = "1234567890"; 
    char str4[20] = "ABCDEFGHIJ"; 
    char empty[] = "";
   
    char str01[20] = "Hello, World!";
    char str02[20] = "1234567890";
    char str03[20] = "1234567890";
    char str04[20] = "ABCDEFGHIJ"; 

    blue();
	printf("Case 1 : src < dst\nimplementation: memmove(str1 + 3, str1, 12)\n");
    reset();
	printf("Input:\t\t%s\n", str1);
    memmove(str01 + 3, str01, 12);
    ft_memmove(str1 + 3, str1, 12);
    if(!ft_strcmp(str01, str1)) green();
    else red();
    printf("memmove :\t%s\nft_memmove :\t%s\n\n", str01, str1);
	reset();

    blue();
	printf("Case 2 : src > dst\nimplementation: memmove(str2, str2 + 3, 12)\n");
    reset();
	printf("Input:\t\t%s\n", str2);
    memmove(str02, str02 + 3, 12);
    ft_memmove(str2, str2 + 3, 12);
    if(!ft_strcmp(str02, str2)) green();
    else red();
    printf("memmove :\t%s\nft_memmove :\t%s\n\n", str02, str2);
	reset();

    blue();
	printf("Case 3 : src = dst\nimplementation: memmove(str0, str0, sizeof(str0))\n");
    reset();
	printf("Input:\t\t%s\n", str0);
    memmove(str0, str0, sizeof(str0));
    ft_memmove(str0, str0, sizeof(str0));
    if(!ft_strcmp(str0, str0)) green();
    else red();
    printf("memmove :\t%s\nft_memmove :\t%s\n\n", str0, str0);
	reset();

    blue();
	printf("Case 4 : empty string on empty string\nimplementation: memmove(empty, empty, sizeof(empty))\n");
    reset();
	printf("Input:\t\t%s\n", empty);
    memmove(empty, empty, sizeof(empty));
    ft_memmove(empty, empty, sizeof(empty));
    if(!ft_strcmp(empty, empty)) green();
    else red();
    printf("memmove :\t%s\nft_memmove :\t%s\n\n", empty, empty);
	reset();

    blue();
	printf("Case 5 : no specific behaviour\nimplementation: memmove(str3, str4, 12)\n");
    reset();
	printf("Input:\t\t%s and %s\n", str3, str4);
    memmove(str03, str04, 12);
    ft_memmove(str3, str4, 12);
    if(!ft_strcmp(str03, str3)) green();
    else red();
    printf("memmove :\t%s\nft_memmove :\t%s\n\n", str03, str3);
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
		else if (!ft_strcmp(func_name, "memmove"))
			memmoveTest();
		
		else
			printf("Not a valid entry. Examples can be 'atoi', 'is...', 'strcmp', 'q'.\n");
	}
	red();
	printf("\nEND OF THE PROGRAM\n");
	return 0;
}
