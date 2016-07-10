#include "minishell.h"

/* It does not seem like we will need the string vector because we are reading
 * from stdin and only after the program is fully set up and running.
 * To set it up and running will not require any kind of vector, even.
 */

void	set_funct_pointers(t_proutil *util)
{
	util->builtin.b_ptr[0] = &ft_cd;
	util->builtin.b_ptr[1] = &ft_exit;
	util->builtin.b_ptr[2] = &ft_unsetenv;
	util->builtin.b_ptr[3] = &ft_echo;
}

int		init_shell(t_proutil *util)
{
	int		i;
	char	*line;
	int		fd;
	mode_t	mode;

	i = -1;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fd = open ("utils/cmds.txt", O_RDONLY | O_CREAT, mode);
	if (!(util->builtin.cmd = (char **)malloc(sizeof(char *) * 4)))
		return (-42);
	while (++i < 6)
		if (!(util->builtin.cmd[i] = (char *)malloc(sizeof(char))))
			return (-42);
	i = -1;
	while (get_next_line(fd, &line) > 0 && ++i >= 0)
		ft_memcpy(util->builtin.cmd[i], line, ft_strlen(line));
	util->builtin.cmd[i] = 0;
	set_funct_pointers(util);
	close(fd);
	return (42);
}

int		main(void)
{
	t_proutil		tool_box;

	//printf("%s\n", *envp);
	init_shell(&tool_box);
	write(1, "\033[32me2r4p7>\033[0m ", 20);
	read_and_lex_data(&tool_box);
	parse_data(&tool_box);
	while (1)
	{
		write(1, "\033[32me2r4p7>\033[0m ", 20);
		read_and_lex_data(&tool_box);
		parse_data(&tool_box);
	}
	return (0);
}
