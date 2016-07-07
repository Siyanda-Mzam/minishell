#include "minishell.h"

void	b_line(char *line, int length)
{
	char	*buff_mem;

	buff_mem = ft_strnew(length);
	buff_mem = ft_strcpy(buff_mem, line);
	ft_memdel((void **)&line);
	line = ft_strcpy(ft_strnew(length), buff_mem);
}

char	*g_line(void)
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
			b_line(buf, b_size);
		}
	}
	return (NULL);
}

