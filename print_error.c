#include "main_header.h"
/**
 * print_error - print a shell error message
 * @exec_file: the executable
 * @command: the invalid command
 */
void print_error(char *exec_file, char *command, int prompet_num)
{
char *err_num = int_to_str(prompet_num);
char *err_msg = concat_all(4, exec_file, ": ", err_num, ": ");
char *err_msg2 = concat_all(3, err_msg, command, ": not found\n");
write(STDERR_FILENO, err_msg2, my_strlen(err_msg2));
free(err_num);
free(err_msg);
free(err_msg2);
}
