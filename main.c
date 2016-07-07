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
		if(utils->cp_id == -1)
		{
			if (execvp(utils->tokens[0], (utils->tokens)) == -1)
				erro_msg(utils->tokens[0], INVALID_COMMAND);
			else if (utils->cp_id < 0)
				erro_msg(utils->tokens[0], FAILED_FORK);
			else
			{
				while (!WIFEXITED(utils->status) || !WIFSIGNALED(utils->status))
				{
					utils->wp_id = waitpid(utils->cp_id, &utils->status, WUNTRACED);
				}
			}
		}
	}
	else
		return ;
}

void	buff_line(char *line, int length)
{
	char	*buff_mem;

	buff_mem = ft_strnew(length);
	buff_mem = ft_strcpy(buff_mem, line);
	ft_memdel((void **)&line);
	line = ft_strcpy(ft_strnew(length), buff_mem);
}

char	*get_line(void)
{
	char	*buf;
	char	r;
	int		b_size;
	int		i;

	i = 0;
	b_size = 80;
	buf = (char *)malloc(sizeof(char) * b_size);
	while (42)
	{
		if (read(0, &r, 1) && r != 10)
		{
			if (r != '>')
				*(buf + i) = r;
		}
		else
		{
			*(buf + i) = '\0';
			return (buf);
		}
		i++;
		if (i >= b_size)
		{
			b_size += b_size;
			buff_line(buf, b_size);
		}
	}
	return (NULL);
}

void	read_and_lex_data(t_proutil *util)
{
	util->line = get_line();
	if (!ft_strcmp(util->line, "quit"))
		exit(0);
	printf("%s\n", util->line);
}


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
		//parse_data(util);
	}
	return (0);
}
