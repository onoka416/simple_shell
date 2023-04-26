<<<<<<< HEAD
C - Simple Shell This project is a simple UNIX command interpreter written in C. The goal of this project is to create a functional shell program that mimics the basic functionality of the Bash shell.

Group Project This project is a group project and must be done in teams of two people. The project starts on April 12, 2023, at 6:00 AM and must end by April 27, 2023, at 6:00 AM. A checker will be released on April 26, 2023, at 1:12 AM, and an auto-review will be launched at the deadline.

Concepts For this project, you are expected to be familiar with the following concepts:

Everything you need to know to start coding your own shell Approaching a Project Background Context This project is inspired by the "The Gates of Shell" talk by Spencer Cheng, featuring Julien Barbier. The goal is to write a simple UNIX command interpreter that can execute commands just like the Bash shell.

Resources The following resources will be helpful in completing this project:

Unix shell Thompson shell Ken Thompson Everything you need to know to start coding your own shell concept page man or help: sh (Run sh as well) Learning Objectives At the end of this project, you should be able to explain the following without the help of Google:

Who designed and implemented the original Unix operating system Who wrote the first version of the UNIX shell Who invented the B programming language (the direct predecessor to the C programming language) Who is Ken Thompson How a shell works What is a pid and a ppid How to manipulate the environment of the current process What is the difference between a function and a system call How to create processes What are the three prototypes of main How the shell uses the PATH to find the programs How to execute another program with the execve system call How to suspend the execution of a process until one of its children terminates What is EOF / “end-of-file”? Requirements Allowed editors: vi, vim, emacs All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89 All your files should end with a new line A README.md file, at the root of the folder of the project is mandatory Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl Your shell should not have any memory leaks No more than 5 functions per file All your header files should be include guarded Use system calls only when you need to (why?) Write a README with the description of your project You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker GitHub There should be one project repository per group. If you and your partner have a repository with the same name in both your accounts, you risk a 0% score. Add your partner as a collaborator.

Output Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0].

List of Allowed Functions and System Calls The following system calls and functions are allowed in this project:

access (man 2 access) chdir (man 2 chdir)
=======

C - Simple Shell
This project is a simple UNIX command interpreter written in C. The goal of this project is to create a functional shell program that mimics the basic functionality of the Bash shell.

Group Project
This project is a group project and must be done in teams of two people. The project starts on April 12, 2023, at 6:00 AM and must end by April 27, 2023, at 6:00 AM. A checker will be released on April 26, 2023, at 1:12 AM, and an auto-review will be launched at the deadline.

Concepts
For this project, you are expected to be familiar with the following concepts:

Everything you need to know to start coding your own shell
Approaching a Project
Background Context
This project is inspired by the "The Gates of Shell" talk by Spencer Cheng, featuring Julien Barbier. The goal is to write a simple UNIX command interpreter that can execute commands just like the Bash shell.

Resources
The following resources will be helpful in completing this project:

Unix shell
Thompson shell
Ken Thompson
Everything you need to know to start coding your own shell concept page
man or help: sh (Run sh as well)
Learning Objectives
At the end of this project, you should be able to explain the following without the help of Google:

Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell
Who invented the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How a shell works
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How the shell uses the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?
Requirements
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)
Write a README with the description of your project
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker
GitHub
There should be one project repository per group. If you and your partner have a repository with the same name in both your accounts, you risk a 0% score. Add your partner as a collaborator.

Output
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0].

List of Allowed Functions and System Calls
The following system calls and functions are allowed in this project:

access (man 2 access)
chdir (man 2 chdir)
>>>>>>> 21c2d073dc8109ab954869e5a38d371ee4b3b3cd
