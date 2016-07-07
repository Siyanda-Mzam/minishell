#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft/libft.h"
#define SUCCESS 0
#define ERROR -1
#define INVALID_COMMAND ": command not found\n"
#define FAILED_FORK "Failed to fork the child process"

typedef struct		s_shell_processing_utility
{
	pid_t			cp_id;
	pid_t			wp_id;
	int				status;
	char			*line;
	char			**tokens;
	char			**environ;
}					t_proutil;

char				*g_line(void);
void				read_and_lex_data(t_proutil *util);
void				parse_data(t_proutil *utils);
