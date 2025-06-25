#include <libft.h>
#include <stdio.h>
#include <unistd.h>
#include <parser.h>

int	main(int argc, char **argv)
{
	int *const	inp = parse_inputs(argc - 1, argv + 1);
	int			i;

	if (!inp)
	{
		write(2, "Error!\n", 7);
		return (1);
	}

	i = 0;
	while (i < argc - 1)
	{
		printf("%d : %d\n", i, inp[i]);
		i++;
	}
}
