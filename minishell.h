#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft/libft.h"
#include <fcntl.h>

#define SUCCESS 0
#define ERROR -1
#define INVALID_COMMAND ": command not found"
#define IOERROR ": No such file or directory"
#define FAILED_FORK "Failed to fork the child process"

extern char				**environ;
typedef int				(*builtin_pointers)(const char *);

typedef struct			s_builtin_function_pointers
{
	builtin_pointers	b_ptr[6];
	char				**cmd;				
}						t_builtins;

typedef struct			s_shell_processing_utility
{
	pid_t				cp_id;
	pid_t				wp_id;
	int					status;
	char				*line;
	char				**tokens;
	t_builtins			builtin;
}						t_proutil;

char					*g_line(void);
void					erro_msg(char *s, char *msg);
void					read_and_lex_data(t_proutil *util);
int						parse_data(t_proutil *utils);
int						ft_cd(const char *dir);
int						ft_exit(const char *dir);
int						ft_unsetenv(const char *var);
int						ft_setenv(const char *key, const char *val,
									int overwrite);
