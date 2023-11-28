
void	print_list(t_list content)
{
	int	i;

	i = 0;
	while (i < content.size[A] || i < content.size[B])
	{
		if (i < content.size[A])
			printf("%d\t", content.stack[A][i]);
		else
			printf("0\t");
		if (i < content.size[B])
			printf("%d\n", content.stack[B][i]);
		else
			printf("0\n");
		i++;
	}
}


int	main(int argc, char *argv[])
{
	t_list		content;

	if (argc < 2)
		return (0);
	if (error_check(argc, argv) < 0)
		return (write(2, "ERROR\n", 6), -1);
	if (init_struct(argc, argv, &content) == -1)
		return (write(2, "ERROR\n", 6), -1);
	print_list(&content);
	printf("-\t-\n%d\t%d\n\n", content->size[A], content->size[B]);
	sort(&content);
	print_list(&content);
	printf("-\t-\n%d\t%d\n", content->size[A], content->size[B]);
	(free(content.stack[0]), free(content.stack[1]));
	return (0);
}

printf("cheapest\t index: %d\tvalue: %d\n", content->index_cheapest, content->stack[A][content->index_cheapest]);
			printf("target\t index: %d\tvalue: %d\n", content->target, content->stack[B][content->target]);
			printf("dir_A\t%d\n", content->direction[A]);
			printf("dir_B\t%d\n\n", content->direction[B]);