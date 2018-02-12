#include "ft_db.h"

int		validate_query(char *q, char *q_cmds[], int *index)
{
	int		i;

	i = 0;
	while (q_cmds[i])
	{
		if (strncmp(q, q_cmds[i], strlen(q_cmds[i])))
		{
			*index = i;
			return (1);
		}
		i++;
	}
	return (0);
}
