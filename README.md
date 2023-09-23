<h1>This is the ALX simple shell project</h1>
<h2>All files are compiled by the following command</h2>
<code>gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh</code>
<h3>The simple shell provides the following</h3>
<ul>
<li>execute commands that are in the path environment variable such as <code>"ls" , "echo", etc</code>
<li>execute commands by their full path such as <code>/bin/ls</code>.
<li>The ability to use arguments such as <code>ls -la</code>
<li>Handle command line comments and EOF situations.
<li>The ability to exit with the status of the last command or even exit with specific status <code>exit 2</code>
<li>Handle Errors of the not found commands or not proper arguments
<li>free all the memory allocated after each command
</ul>
<h1>To run this shell</h1>
<h3>type the following commands your terminal</h3>
<ol>
<li><code>git clone https://github.com/EgyAbdo10/simple_shell.git</code> to clone the project into your machine
<li>inside the cloned repo type <code>gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh</code> to compile files
<li>then execute them by using the following command <code>./hsh</code>
<li>you are now inside the shell. Type any command you want to execute.
<li>to exit you can press <code>ctrl + d</code> or <code>exit</code>
</ol>
