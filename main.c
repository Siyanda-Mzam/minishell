#include "minishell.h"
#include <stdio.h>
int		len(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	erro_msg(char *s, char *msg)
{
	write(2, s, len(s));
	write(2, msg, len(msg));
	exit(0);  
}

char	**lex_line(char **line)
{
	char	**lexed_line;

	lexed_line = ft_strsplit(*line, ' ');
	if (!lexed_line)
		return (0);
	return (lexed_line);
}

void	parse_data(t_proutil *utils)
{
	if (utils->line && *utils->line)
	{
		utils->cp_id = fork();
		if(utils->cp_id == SUCCESS)
		{
			if (execve(utils->tokens[0], (utils->tokens + 1), utils->environ) == ERROR)
				erro_msg(utils->tokens[0], INVALID_COMMAND);
			else if (utils->cp_id < 0)
				erro_msg(utils->tokens[0], FAILED_FORK);
			else
			{
				while (!(WIFEXITED(utils->status) && WIFSIGNALED(utils->status)))
				{
					utils->wp_id = waitpid(utils->cp_id, &utils->status, WUNTRACED | WNOHANG);
				}
			}
		}
	}
	else
		return ;
}

void	read_and_lex_data(t_proutil *util)
{
	read(0, &util->line, 7);
	util->tokens = lex_line(&util->line);
	parse_data(util);
}


/* It does not seem like we will need the string vector because we are reading
 * from stdin and only after the program is fully set up and running.
 * To set it up and running will not require any kind of vector, even.
 */

int		main(void)
{
	t_proutil		tool_box;

	tool_box.status = 1;
	//init_shell();
	while (tool_box.status)
	{
		read_and_lex_data(&tool_box);
		parse_data(&tool_box);
	}
	return (0);
}
