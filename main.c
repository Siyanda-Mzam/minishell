#include "minishell.h"
#include <stdio.h>

/* It does not seem like we will need the string vector because we are reading
 * from stdin and only after the program is fully set up and running.
 * To set it up and running will not require any kind of vector, even.
 */

int		main(void)
{
	t_proutil		tool_box;

	//init_shell();
	write(1, "\033[32me2r4p7>\033[0m", 20);
	read_and_lex_data(&tool_box);
	parse_data(&tool_box);
	while (1)
	{
		write(1, "\033[32me2r4p7>\033[0m", 20);
		read_and_lex_data(&tool_box);
		parse_data(&tool_box);
	}
	return (0);
}
