#include "../includes/minishell.h"

int		ft_cd(const char *dir)
{
	if (!dir)
	{
		erro_msg("zsh: cd: ", "No argument specified");
		return (-1);
	}
	if (chdir(dir) != 0)
	{
		erro_msg(ft_strjoin(ft_strjoin("zsh: cd: ", dir), IOERROR), NULL);
		return (-1);
	}
	return (1);
}

int		ft_exit(const char *dir)
{
	if (!dir || dir)
		return (0);
	return (-1);
}

int		ft_echo(const char *str)
{
	if (!str)
		return (-1);
	return (write(1, str, ft_strlen(str)));
}
