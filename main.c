#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static void	nothing(int sig)
{
	(void)sig;
}

static void	exec_cmd(char *path, char *args[], char *env[])
{
	pid_t	pid;
	int		status;

	pid = 0;
	status = 0;
	pid = fork();
	
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (execve(path, args, env) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	char	*path;
	char	*args1[] = {"xrandr", "-o", "normal", NULL};
	char	*args2[] = {"xrandr", "-o", "right", NULL};
	char	*args3[] = {"xrandr", "-o", "inverted", NULL};
	char	*args4[] = {"xrandr", "-o", "left", NULL};
	char	*display;
	char	env_display[256];
	char	*env[] = {env_display, NULL};
	int		i;

	// signal(SIGINT, nothing);
	i = 1;
	path = "/usr/bin/xrandr";
	display = getenv("DISPLAY");
	if (display == NULL)
	{
		fprintf(stderr, "DISPLAY environment variable not set\n");
		return (1);
	}
	snprintf(env_display, sizeof(env_display), "DISPLAY=%s", display);
	while (1)
	{
		exec_cmd(path, args2, env);
		sleep(3);
		exec_cmd(path, args3, env);
		sleep(3);
		exec_cmd(path, args4, env);
		sleep(3);
		exec_cmd(path, args1, env);
		sleep(3);
		// break;
	}
	return (0);
}
