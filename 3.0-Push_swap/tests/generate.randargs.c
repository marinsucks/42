/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.randargs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:30:22 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/24 14:54:50 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
	int n = atoi(argv[2]); 

	if (argc != 3)
	{
		printf("\033[1;31mUsage: ./a.out filename n\n\033[0m");
		return 1;
	}
	
	FILE *file = fopen(argv[1], "w");
	
	if (file == NULL) 
	{
		printf("\033[1;31mError opening file.\n\033[0m");
		return 1;
	}
	
	srand(time(NULL));
	
	for (int i = 0; i < n; i++) 
	{
		////min -9223372036854775808, max 9223372036854775807
		//long int randomInt = rand();
		
		////min -2147483648, max 2147483647
		//int randomInt = rand();
		
		////min -32768, max 32767
		//short int randomInt = rand(); 

		////min -128, max 127
		//char randomInt = (char)rand(); 

		//min 0, max 255
		unsigned char randomInt = (char)rand();

		fprintf(file, "%d ", randomInt);
	}
	
	fclose(file);
	
	printf("\033[1;37m%d\033[0m random integers written to \033[1;37m%s\033[0m.\n", n, argv[1]);
	
	return 0;
}

