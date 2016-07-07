#include "minishell.h"
#include <stdio.h>

/* It does not seem like we will need the string vector because we are reading
 * from stdin and only after the program is fully set up and running.
 * To set it up and running will not require any kind of vector, even.
 */

int		main(void)
{
	t_proutil		tool_box;

	tool_box.status = -1;
	//init_shell();
	while (tool_box.status)
	{
		write(1, ">", 2);
		read_and_lex_data(&tool_box);
	}
	return (0);
}
