/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:38:21 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/19 17:23:29 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

/**
 * mbecker@paul-f4Ar4s4:~/42/3.2-pipex$ valgrind --track-fds=yes ./pipexbonus here_doc stop "cat -e" "cat -e" out
==524581== Memcheck, a memory error detector
==524581== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==524581== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==524581== Command: ./pipexbonus here_doc stop cat\ -e cat\ -e out
==524581== 
hey
s
==524582== Invalid read of size 1
==524582==    at 0x402280: ft_strlen (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x401B5A: redirect_input (here_doc.c:22)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582==  Address 0x4aa00e0 is 0 bytes inside a block of size 5 free'd
==524582==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==524582==    by 0x401BA0: redirect_input (here_doc.c:26)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582==  Block was alloc'd at
==524582==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==524582==    by 0x402016: gnl_tempsplit (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x401E2C: get_next_line (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x401B35: redirect_input (here_doc.c:19)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582== 
==524582== Invalid read of size 1
==524582==    at 0x402280: ft_strlen (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x4024B5: ft_putstr_fd (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x401B97: redirect_input (here_doc.c:25)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582==  Address 0x4aa00e0 is 0 bytes inside a block of size 5 free'd
==524582==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==524582==    by 0x401BA0: redirect_input (here_doc.c:26)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582==  Block was alloc'd at
==524582==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==524582==    by 0x402016: gnl_tempsplit (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x401E2C: get_next_line (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x401B35: redirect_input (here_doc.c:19)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582== 
==524582== Syscall param write(buf) points to unaddressable byte(s)
==524582==    at 0x4988887: write (write.c:26)
==524582==    by 0x4024C4: ft_putstr_fd (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x401B97: redirect_input (here_doc.c:25)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582==  Address 0x4aa00e0 is 0 bytes inside a block of size 5 free'd
==524582==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==524582==    by 0x401BA0: redirect_input (here_doc.c:26)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582==  Block was alloc'd at
==524582==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==524582==    by 0x402016: gnl_tempsplit (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x401E2C: get_next_line (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x401B35: redirect_input (here_doc.c:19)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582== 
==524582== Invalid free() / delete / delete[] / realloc()
==524582==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==524582==    by 0x401BA0: redirect_input (here_doc.c:26)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582==  Address 0x4aa00e0 is 0 bytes inside a block of size 5 free'd
==524582==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==524582==    by 0x401BA0: redirect_input (here_doc.c:26)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582==  Block was alloc'd at
==524582==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==524582==    by 0x402016: gnl_tempsplit (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x401E2C: get_next_line (in /home/mbecker/42/3.2-pipex/pipexbonus)
==524582==    by 0x401B35: redirect_input (here_doc.c:19)
==524582==    by 0x401C12: here_doc (here_doc.c:42)
==524582==    by 0x401517: main (main.c:85)
==524582== 

*/
void	redirect_input(const char *limiter, int fd)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strlen(limiter) == ft_strlen(line) - 1 
			&& !ft_strcmp(line, limiter))
			exit(EXIT_SUCCESS);
		ft_putstr_fd(line, fd);
		free(line);
		get_next_line(STDIN_FILENO);
	}
}



void	here_doc(const char *limiter)
{
	pid_t	reader;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit_error("pipe");
	reader = fork();
	if (reader == 0)
	{
		close(pipe_fd[0]);
		redirect_input(limiter, pipe_fd[1]);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		wait(NULL);
	}
}
