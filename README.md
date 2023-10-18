# Simple Shell - A Minimal Unix-like Shell

## Overview

This is a minimal Unix-like shell, similar to the standard Unix shell (`sh`). It allows users to run basic command-line operations and system calls. The project aims to provide a simplified shell environment for educational purposes, showcasing the use of various system calls and functions.

## List of Allowed Functions and System Calls

- `access` (man 2 access): Check real file accessibility.
- `chdir` (man 2 chdir): Change current working directory.
- `close` (man 2 close): Close a file descriptor.
- `closedir` (man 3 closedir): Close a directory stream.
- `execve` (man 2 execve): Execute a program.
- `exit` (man 3 exit): Terminate the calling process.
- `_exit` (man 2 _exit): Terminate the calling process.
- `fflush` (man 3 fflush): Flush a stream.
- `fork` (man 2 fork): Create a new process.
- `free` (man 3 free): Deallocate memory.
- `getcwd` (man 3 getcwd): Get the current working directory.
- `getline` (man 3 getline): Read a line from a stream.
- `getpid` (man 2 getpid): Get the process ID.
- `isatty` (man 3 isatty): Check if a file descriptor refers to a terminal.
- `kill` (man 2 kill): Send a signal to a process.
- `malloc` (man 3 malloc): Allocate memory.
- `open` (man 2 open): Open a file or device.
- `opendir` (man 3 opendir): Open a directory stream.
- `perror` (man 3 perror): Print an error message.
- `read` (man 2 read): Read from a file descriptor.
- `readdir` (man 3 readdir): Read the next directory entry.
- `signal` (man 2 signal): Install a signal handler.
- `stat` (__xstat) (man 2 stat): Get file status.
- `lstat` (__lxstat) (man 2 lstat): Get file status (link information).
- `fstat` (__fxstat) (man 2 fstat): Get file status from a file descriptor.
- `strtok` (man 3 strtok): Split a string into tokens.
- `wait` (man 2 wait): Wait for a child process to terminate.
- `waitpid` (man 2 waitpid): Wait for a specific child process to terminate.
- `wait3` (man 2 wait3): Wait for child processes with status.
- `wait4` (man 2 wait4): Wait for child processes with status.
- `write` (man 2 write): Write to a file descriptor.

## How to Use

1. Compile your simple shell program using a C/C++ compiler.
2. Run the compiled program from the command line.
3. You can enter commands and utilize the system calls and functions listed above.

## Disclaimer

This simple shell is a basic implementation for educational purposes. It may lack many features and optimizations found in standard Unix-like shells. Use it as a starting point for learning about shell programming and system calls. Do not use it for critical or production purposes.

## Contributors

- mohammed lahrache
- oyayna laudat
