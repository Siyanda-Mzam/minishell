#include "minishell.h"
#include <stdio.h>

void	erro_msg(char *s, char *msg);

int		parse_data(t_proutil *utils)
{
	if (utils->tokens)
	{
		utils->cp_id = fork();
		if(utils->cp_id == 0)
		{
			if (execvp(utils->tokens[0], utils->tokens) == ERROR)
				erro_msg(utils->tokens[0], INVALID_COMMAND);
			exit(1);
		}
		else if (utils->cp_id < 0)
				erro_msg(utils->tokens[0], FAILED_FORK);
		else
		{
			do
			{
				utils->wp_id =
				waitpid(utils->cp_id, &utils->status, WUNTRACED);
			}
			while (!WIFEXITED(utils->status) && !WIFSIGNALED(utils->status));
		}
	}
	return (utils->status);
}
