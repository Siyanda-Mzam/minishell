#include "../includes/minishell.h"

void	erro_msg(char *s, char *msg)
{
	if (s)
		write(2, s, ft_strlen(s));
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1); 
}

int		stop(char *s)
{
	return (!(ft_strcmp(s, "quit")) ||
			!(ft_strcmp(s, "exit")) ||
			!(ft_strcmp(s, "q")));
}
