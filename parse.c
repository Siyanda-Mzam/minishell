#include "minishell.h"

void	erro_msg(char *s, char *msg);

void	parse_data(t_proutil *utils)
{
	if (utils->line)
	{
		utils->cp_id = fork();
		if(utils->cp_id == SUCCESS)
		{
			if (execvp(utils->tokens[0], utils->tokens) == ERROR)
				erro_msg(utils->tokens[0], INVALID_COMMAND);
			else if (utils->cp_id < 0)
				erro_msg(utils->tokens[0], FAILED_FORK);
			else
			{
				while (!WIFEXITED(utils->status) && !WIFSIGNALED(utils->status))
					utils->wp_id =
					waitpid(utils->cp_id, &utils->status, WUNTRACED);
			}
		}
	}
	else
		return ;
}
