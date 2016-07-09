#include "minishell.h"

int		ft_cd(const char *dir)
{
	if (!dir)
		erro_msg("zsh: cd: ", "No argument specified");
	if (chdir(dir) != 0)
		erro_msg(ft_strjoin(ft_strjoin("zsh: cd: ", dir), IOERROR), NULL);
	return (1);
}

int		ft_exit(const char *dir)
{
	if (!dir || dir)
		return (0);
	return (-1);
}

int		ft_unsetenv(const char *var)
{
	char	**ep;
	char	**sp;
	int		len;

	if (var == NULL || var[0] == '\0' || ft_strchr(var, '=') != NULL)
	{
		erro_msg("Invalid argument(s)", NULL);
		return (-1);
	}
	len = ft_strlen(var);
	ep = environ;
	while (ep != NULL)
	{
		if (ft_strncmp((const char *)ep, var, len) == 0 && (*ep)[len] == '=')
		{
			sp = ep;
			while (*sp != NULL)
			{
				*sp = *(sp + 1);
				sp++;
			}
		}
		else
			ep++;	
	}
	return (0);
}

int		ft_setenv(const char *key, const char *val, int overwrite)
{
	char	*es;

	if (key == NULL || key[0] == '\0' || ft_strchr(key, '=') != NULL)
	{
		erro_msg("Invalid argument(s)", NULL);
		return (-1);
	}
	if (getenv(key) != NULL && overwrite == 0)
		return (0);
	ft_unsetenv(key);
	if (!(es = (char *)malloc(ft_strlen(key) + ft_strlen(val) + 2)))
		return (-1);
	ft_strjoin(ft_strjoin(ft_strcpy(es, key), "="), val);
	if (!putenv(es))
		return (-1);
	return (1);
}
