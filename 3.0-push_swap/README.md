# Push_Swap Project

## Overview

Push_Swap revolves around creating a program named `push_swap` that efficiently sorts a stack using a limited set of instructions while minimizing the number of operations.

## Skills Acquired

- **Algorithmic Exploration**: Explored various sorting strategies to optimize stack sorting and implemented a sorting algorithm under specific operations constraints.
- **Linked List Manipulation**: Gained proficiency in manipulating linked lists, a crucial skill for stack-based algorithms.

## Project Details

### The `push_swap` Program

The push_swap program takes a list of integers as an argument and stores it on a stack - `a`. 

1. While `a` has more than three value, each value of `a` is pushed to the other stack - `b` -  while sorting `b` in descending order. 
   - The latter is done first by assigning each `a` node a target node from `b`, namely the smallest closest value from `b`.
   - Then, the program evaluates the push cost of each node, which is the number of operations needed to bring the node and its target to the top of their stacks. The first cheapest node is then pushed to `b`.
2. The 3 remaining values in `a` are sorted by a specific function. 
3. While `b` still contains values, each node from `b` is assigned a target node from `a`, this time the biggest closest value from `a`. The first cheapest node is pushed to `a`.

The program returns the list of operations used to sort the list, or none if the stack is either empty or already sorted. In case of incorrect arguments, it prints "Error".


### The `checker` Program (bonus)

The checker program takes a list of integers as an argument, reads instructions from the standard input, and executes these instructions on the provided stack.  
If, after execution, the initial stack is sorted and the secondary stack is empty, the program displays "OK"; otherwise, it displays "KO". In case of an error, it prints "Error".

## Business Relevance

This project underscores my ability to explore and implement diverse sorting algorithms, demonstrating adaptability in problem-solving. By mastering the latter, I've acquired valuable skills in optimizing sorting processes and efficiently manipulating linked lists.
