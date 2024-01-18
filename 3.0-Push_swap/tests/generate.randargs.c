/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.randargs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:30:22 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/18 14:16:08 by mbecker          ###   ########.fr       */
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
		short int randomInt = rand();
		fprintf(file, "%d ", randomInt);
	}
	
	fclose(file);
	
	printf("\033[1;37m%d\033[0m random integers written to \033[1;37m%s\033[0m.\n", n, argv[1]);
	
	return 0;
}

