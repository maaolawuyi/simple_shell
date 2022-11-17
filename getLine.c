#include "shell.h"

/**
*input buf - buffers chained commands
*@info: parameter struck
*@buf: address of buffer
*@len: address of len var
*
*Return: bytes read
*/
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info ->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
	#if USE_GETLINE
		r = getline(but, &len_p, stdin);
		r = getline(info, but, &len_p);
	#endif
		if (r > 0)
		{
			if ((*buf) [r - 1] == '\n')
			{
				(*buf) [r - 1] = '\0'; /* remove trailing newline */
				r -- ;
			}
		}
	}
}
