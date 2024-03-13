#include "pipex.h"

void redirect_in_out(int in, int out)
{
	if (dup2(in, STDIN_FILENO) == -1)
		perror("Error redirecting standard input");
	if (dup2(out, STDOUT_FILENO) == -1)
		perror("Error redirecting standard output");
}

int	main(int argc, char const **argv, char **envp)
{
	t_args	args = {argc, argv, envp};
	char	*cmd[] = {"cat -e", NULL};


	//OPEN FILES
	int input_fd[2];
	input_fd[0] = open("infile", O_RDONLY);
	input_fd[1] = open("outfile", O_RDWR | O_CREAT | O_APPEND, 0644);
	if (input_fd[0] < 0 || input_fd[1] < 0)
		return (perror("open failed"), 1);

	//PIPE


	//FORK PROCESSES
	int		maxpid = 3;
	pid_t	pid[maxpid];
	int		pipe_fd[2];
	for (int i = 0; i < maxpid; i++)
	{
		if (pipe(pipe_fd) < 0)
			return (perror("pipe failed"), 1);
		pid[i] = fork();
		if (pid[i] < 0)
			return (perror("fork failed"), 1);
		else if (!pid[i])
		{
			if (i == 0)
				redirect_in_out(input_fd[0], pipe_fd[1]);
			else if (i >= 0 && i != maxpid - 1)
				redirect_in_out(pipe_fd[0], pipe_fd[1]);
			else
				redirect_in_out(pipe_fd[0], input_fd[1]);
			exec_cmd(*cmd, envp);
			exit(1);
		}
		else
			printf("pid[%d] = %d\n", i, pid[i]);
	}
	
	waitpid(pid[0], NULL, 0);
	


	close(input_fd[0]);
	close(input_fd[1]);
	return 0;
}
