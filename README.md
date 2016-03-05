#rshell
Created by: Aakash Kadakia and Raymond Farias
- rshell is a basic command shell using the syscalls fork, execvp, and wait.
- rshell is similar to bash and reads and executes commands provided by the user
Our command shell prints a command prompt ($) and reads in a command on one line. Command will have the form:

 - cmd = executable [ argumentList ] [ connector cmd ] 
 - connector = || or && or ;
 
 - where executable is an executable program in the PATH and argumentList is a list of zero or more arguments separated by spaces. Connector is optional way to run multiple commands at once.  If a command is followed by ;, then the next command is always executed;if a command is followed by &&, then the next command is executed only if the first one succeeds; if a command is followed by ||, then the next command is executed only if the first one fails.

 - this program can also perform the test command using the command test or [] operators
 - precedence can be made possible using parenthesis around commands with higher precedence

##Installation
 -	git clone https://github.com/dabearrr/rshell.git
 -	cd bin
 -	run ./rshell

##Bugs/Limitations/Issues
 - Rshell does not support command redirection operators such as echo "text text" >> file.txt
 - Rshell can be called recursively within itself to produce multiple Rshells and will require that same number of exit calls to completely exit the rshell. - Rshell does not support the cd commands
 - Ctrl-Z will put rshell into the background and pressing fg will return to rshell but without outputting the $ command prompt.  
