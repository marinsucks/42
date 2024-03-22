# Pipex Project

Welcome to the Pipex project! This project is all about understanding and implementing Unix pipes in C. It's a fun and challenging way to dive deep into the Unix mechanisms you've been using in your programs.

## Project Overview

The Pipex program is designed to mimic the behavior of the shell command `< infile cmd1 | cmd2 > outfile`. It takes four arguments: two file names (`infile` and `outfile`) and two shell commands (`cmd1` and `cmd2`).

Here's how it works:

1. `infile` is the input file. The contents of this file are passed to `cmd1`.
2. `cmd1` is a shell command that processes the input and sends the result to `cmd2` via a pipe.
3. `cmd2` is another shell command that processes the output of `cmd1`.
4. `outfile` is the output file. The final result of `cmd2` is written to this file.

For example, if you run `./pipex infile "ls -l" "wc -l" outfile`, it will behave like the shell command `< infile ls -l | wc -l > outfile`.

## Code Walkthrough

The main function of the program starts by parsing the arguments and opening the input and output files. It then duplicates the file descriptor of the input file to the standard input (`STDIN_FILENO`) and closes the original file descriptor.

Next, it enters a loop where it creates a child process for each command. In each child process, it handles the input and output redirections and executes the command. 
> If the command is not the last one, it creates a pipe and duplicates the write end of the pipe to the standard output (`STDOUT_FILENO`). 
> If the command is the last one, it duplicates the file descriptor of `outfile` to the standard output.

Back in the parent process, it duplicates the read end of the pipe to the standard input for the next command and waits for the child process to finish.

Finally, it cleans up any remaining open file descriptors and exits.

## Concepts Learned

By working on this project, you'll gain a deep understanding of several key Unix concepts:

- File Descriptors and Redirection: You'll learn how to open files, duplicate file descriptors, and redirect standard input and output.
- Pipes: You'll learn how to create pipes and use them to connect the output of one process to the input of another.
- Process Creation: You'll learn how to create new processes using `fork` and execute commands in them using `execve`.
- Error Handling: You'll learn how to handle errors thoroughly and avoid common pitfalls like segmentation faults, double frees, and memory leaks.

So, are you ready to dive into the world of Unix pipes? Let's get started!

## Try me!!

First, install pipex, either by cloning the entire repository:
```
git clone git@github.com:marinsucks/42.git
```

or by cloning this subdirectory only:
```
mkdir 42-pipex && cd 42-pipex

# Initialize Git and add this remote repository.
git init && git remote add -f origin git@github.com:marinsucks/42.git

# Configure Git to only fetch pipex from the remote repository.
git config core.sparseCheckout true && echo "3.2-pipex" >> .git/info/sparse-checkout

git pull origin master
```

Create the program:
```
make all
```

Test it !
```
./pipex pipex.h "cat -e" "grep Hello" result
```