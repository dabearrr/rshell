#rshell
Created by: Aakash Kadakia and Raymond Farias
- rshell is a basic command shell using the syscalls fork, execvp, and wait.
- rshell is similar to bash and reads and executes commands provided by the user
Our command shell prints a command prompt ($) and reads in a command on one line. Command will have the form:

 - cmd = executable [ argumentList ] [ connector cmd ] 
 - connector = || or && or ;
 
 - where executable is an executable program in the PATH and argumentList is a list of zero or more arguments separated by spaces. Connector is optional way to run multiple commands at once.  If a command is followed by ;, then the next command is always executed;if a command is followed by &&, then the next command is executed only if the first one succeeds; if a command is followed by ||, then the next command is executed only if the first one fails.

 ##Installation
 -	git clone https://github.com/dabearrr/rshell.git
 -	cd rshell
 -	run ./a.out
  ##Bugs/Limitations/Issues
 - Currently no known bugs 
