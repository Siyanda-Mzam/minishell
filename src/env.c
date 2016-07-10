#include "minishell.h"

char	*get_env(const char *key)
{
	register int			len;
	register int			i;
	register const char		*np;
	register char			**p;
	register char			*cp;

	if ((np = key) == NULL || environ == NULL)
		return (NULL);
	while (*np && *np != '=')
		++np;
	len = np - key;
	p = environ--;
	while((cp = *(++p)) != NULL)
	{
		np = key;
		i = len + 1;
		while (--i && *cp)
			if (*cp++ != *np++)
				i = 0;
		if (i == 0 && *cp++ == '=')
			return (cp);
	}
	return (NULL);
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
