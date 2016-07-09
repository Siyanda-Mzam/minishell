#include "../includes/minishell.h"

int		*is_builtin(t_proutil *utils, int *i)
{
	int		j;

	if (utils->tokens[0] != 0)
	{	
		while (utils->builtin.cmd[*i] && (j = strcmp(utils->tokens[0], utils->builtin.cmd[*i])))
			(*i)++;
		if (j == 0)
			return (i);
	}
	*i = *i * -1;
	return (i);
}

int		parse_data(t_proutil *utils)
{
	int		i;

	i = 0;
	if (utils->tokens)
	{
		if ((!*is_builtin(utils, &i)) && i >= 0)
			 return (utils->builtin.b_ptr[i](utils->tokens[1]));
		utils->cp_id = fork();
		if (utils->cp_id < 0)
				erro_msg(utils->tokens[0], FAILED_FORK);
		else if(utils->cp_id == 0)
		{
			if (execve(ft_strjoin("/bin/", utils->tokens[0]), utils->tokens, environ) == ERROR)
				erro_msg(utils->tokens[0], INVALID_COMMAND);
			exit(1);
		}
		else
		{
			utils->wp_id =
				waitpid(utils->cp_id, &utils->status, WUNTRACED);
			while (!WIFEXITED(utils->status) && !WIFSIGNALED(utils->status));
			{
				utils->wp_id =
				waitpid(utils->cp_id, &utils->status, WUNTRACED);
			}
		}
	}
	return (utils->status);
}
