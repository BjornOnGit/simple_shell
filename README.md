# 0x16. C - Simple Shell

<img src="https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg" width="300px" height="300px" align="center">

###### A shell, also known as a command interpreter, is a program that provides a command-line interface for users to interact with the operating system. It acts as an intermediary between the user and the operating system, interpreting and executing commands entered by the user.

#### An alx team project where each team are required to create a command line interpreter that takes a text command and execute other program in response to thet command

<hr>

## Contributors

|Name|Email|
| --- | --- |
| Lerato Mgwangqa | <ivyratermgwangqa@gmail.com> |
| Francis Eze | <fhrancorey99@gmail.com> |

<hr>

## Output

* The shell have exact same output as the `sh` (`/bin/sh`)
* The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

###### Example of an error in `sh`

```shell
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

###### Example of an error on the program `hsh`

```shell
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

<hr>

## Compilation

###### The program should be compiled with
>
> gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

<hr>

## Testing

###### Your code should work like this in interactive mode

```shell
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

###### But also in non-interactive mode

```shell
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
# CODING YOUR OWN SHELL
## Contents

1. [PID & PPID](#pid--ppid)
2. [Creating a Simple Shell](#creating-a-simple-shell)
3. [Executing Programs with execve](#executing-programs-with-execve)
4. [Creating Processes with fork](#creating-processes-with-fork)
5. [Synchronizing Processes with wait](#synchronizing-processes-with-wait)
6. [Working with Environment Variables](#working-with-environment-variables)

## PID & PPID

- Understanding process IDs (PID) and parent process IDs (PPID)
- Retrieving process IDs using system calls

## Creating a Simple Shell

- Implementing a simple shell interpreter based on bash and sh
- Parsing user commands and executing them

## Executing Programs with execve

- Using the execve system call to execute another program
- Replacing the current process with a new program

## Creating Processes with fork

- Understanding the fork system call
- Creating child processes from a parent process

## Synchronizing Processes with wait

- Using the wait system call to suspend the execution of the parent process
- Waiting for child processes to terminate before continuing

## Working with Environment Variables

- Accessing and manipulating environment variables in shell programs
- Retrieving the environment using the `environ` variable
- Modifying environment variables using custom functions
