#include "ft_db.h"

void	tag_it(int res, FILE *f)
{
	char	tag[50];

	if (res > 0)
	{
		fprintf(f, "\t\"tags\":[");
		while (res > 0)
		{
			printf("\e[36mType one tag, then press enter\e[0m\n");
			scanf(" %[^},\n]", tag);
			clear_stdin();
			fprintf(f, "\"%s\"", tag);
			if (res > 1)
				fprintf(f, ",");
			res--;
		}
		fprintf(f, "]");
	}
	fprintf(f, "\n}");
}

void	create_tag(FILE *f)
{
	int	res;

	res = 0;
	printf("\e[36mHow many tags would you like to add for this entry?\e[0m\n");
	if (!scanf("%i", &res))
	{
		printf("\e[31mThat was not an integer...\e[0m\n");
		clear_stdin();
		fprintf(f, "\t\"tags\":[\"no tag\"]\n}");
		return ;
	}
	if (res == 0)
	{
		fprintf(f, "\t\"tags\":[\"no tag\"]\n}");
		return ;
	}
	tag_it(res, f);
}

int		end_id(void)
{
	int		r;
	char	*str;
	FILE 	*f;

	r = 0;
	f = fopen("db.txt", "r");
	str = (char *)malloc(5);
	if (fgets(str, 3, f) != NULL)
		r = atoi(str);
	fclose(f);
	return (r);
}

void	detail_entry(int detail_lines, FILE *f)
{
	char	detail_name[50];
	char	detail_val[50];
	int		count;

	count = 1;
	while (detail_lines > 0)
	{
		printf("\e[36m%i Enter detail field name:\e[0m\n", count);
		scanf(" %[^},\n]", detail_name);
		clear_stdin();
		printf("\e[36m%i Enter detail value:\e[0m\n", count);
		scanf(" %[^},\n]", detail_val);
		clear_stdin();
		fprintf(f, "\n\t\t \"%s\" = \"%s\"", detail_name, detail_val);
		if (detail_lines > 1)
			fprintf(f, ",");
		detail_lines--;
		count++;
	}
	fprintf(f, "\n");
}

int		create_label(FILE *f, int id)
{
	char		label[50];
	int			detail_lines;

	detail_lines = 0;
	printf("\e[36mEnter a label for the new node ('}'',' are not recognized)\e[0m\n");
	scanf(" %[^},\n]", label);
	clear_stdin();
	printf("\e[32mHow many details do you want to enter for this node (int)\e[0m\n");
	if (!(scanf("%i", &detail_lines)) || detail_lines <= 0)
	{
		printf("\e[31mError, invalid entry...Try again\e[0m\n");
		return (id);
	}
	fprintf(f, "    \n{\n\t\"ID\": \"%i\",\n", id++);
	fprintf(f, "\t\"label\": \"%s\",\n", label);
	if (detail_lines > 0)
		fprintf(f, "\t\"details\":");
	detail_entry(detail_lines, f);
	create_tag(f);
	return (id);
}
