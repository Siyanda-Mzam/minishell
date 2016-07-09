#include "../includes/minishell.h"

int				stop(char *s);

char			**lex_line(char **line)
{
	char	**lexed_line;

	lexed_line = ft_strsplit(*line, ' ');
	if (!lexed_line)
		return (0);
	return (lexed_line);
}

void			read_and_lex_data(t_proutil *util)
{
	util->line = g_line();
	util->tokens = lex_line(&util->line);
	if (stop(util->line))
		exit(0);
}
