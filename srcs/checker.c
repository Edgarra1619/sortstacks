/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:15:28 by edgribei          #+#    #+#             */
/*   Updated: 2025/07/09 14:17:46 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <instructions.h>
#include <libft.h>
#include <stdlib.h>
#include <stack.h>
#include <unistd.h>
#include <parser.h>
#include <my_math.h>
#include <solve.h>

int	check_sorted_stack(t_stacks *stacks);

void	error_out(t_stacks *const stacks)
{
	char	c;

	c = 0;
	while (c != '\n' && read(1, &c, 1) == 1)
		;
	ft_lstclear(&(stacks->stack_a), NULL);
	ft_lstclear(&(stacks->stack_b), NULL);
	write(2, "Error!\n", 7);
	exit(0);
}

void	parse_push(t_stacks *const stacks)
{
	char	c[2];

	if (read(0, c, 2) <= 1)
		error_out(stacks);
	if (c[1] != '\n')
		error_out(stacks);
	if (c[0] == 'a')
		stack_push(&stacks->stack_a, stack_pop(&stacks->stack_b));
	if (c[0] == 'b')
		stack_push(&stacks->stack_b, stack_pop(&stacks->stack_a));
}

void	parse_rotation(t_stacks *const stacks)
{
	void	(*rotfunc)(t_list**, unsigned int);
	char	c[2];

	rotfunc = &stack_rotate;
	if (read(0, c, 2) <= 1)
		error_out(stacks);
	if (c[0] == 'r' && c[1] != '\n')
	{
		rotfunc = &stack_rrotate;
		c[0] = c[1];
		if (read(0, c + 1, 1) <= 0)
			error_out(stacks);
	}
	if (c[1] != '\n')
		error_out(stacks);
	if (c[0] == 'a' || c[0] == 'r')
		rotfunc(&stacks->stack_a, 1);
	if (c[0] == 'b' || c[0] == 'r')
		rotfunc(&stacks->stack_b, 1);
}

void	parse_swap(t_stacks *const stacks)
{
	char	c[2];

	if (read(0, c, 2) <= 1)
		error_out(stacks);
	if (c[1] != '\n')
		error_out(stacks);
	if (c[0] == 'a' || c[0] == 's')
		stack_swap(&stacks->stack_a);
	if (c[0] == 'b' || c[0] == 's')
		stack_swap(&stacks->stack_b);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		c;

	ft_bzero(&stacks, sizeof(t_stacks));
	stacks.stack_a = parse_inputs(argc - 1, argv + 1);
	if (!stacks.stack_a)
		error_out(&stacks);
	while (read(0, &c, 1) > 0)
	{
		if (c == 'r')
			parse_rotation(&stacks);
		else if (c == 's')
			parse_swap(&stacks);
		else if (c == 'p')
			parse_push(&stacks);
		else
			error_out(&stacks);
	}
	if (check_sorted_stack(&stacks))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_lstclear(&(stacks.stack_a), NULL);
	ft_lstclear(&(stacks.stack_b), NULL);
}
