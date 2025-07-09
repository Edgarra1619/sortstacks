/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:46:10 by edgribei          #+#    #+#             */
/*   Updated: 2025/07/09 13:54:54 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <instructions.h>
#include <my_math.h>
#include <unistd.h>

void	printntimes(const char *str, int count)
{
	const size_t	size = ft_strlen(str);

	while (count--)
		write(1, str, size);
}

static void	do_inst_stacks(t_stacks *const stacks, t_cost inst)
{
	if (inst.type & 0b10)
		stack_rrotate(&(stacks->stack_a), inst.rrota);
	else
		stack_rotate(&(stacks->stack_a), inst.rota);
	if (inst.type & 0b01)
		stack_rrotate(&(stacks->stack_b), inst.rrotb);
	else
		stack_rotate(&(stacks->stack_b), inst.rotb);
}

void	do_inst(t_stacks *const stacks, t_cost instructions)
{
	int	tmp;

	do_inst_stacks(stacks, instructions);
	if (instructions.type == RARB)
	{
		tmp = min(instructions.rota, instructions.rotb);
		printntimes("rr\n", tmp);
		instructions.rota -= tmp;
		instructions.rotb -= tmp;
	}
	if (instructions.type == RRARRB)
	{
		tmp = min(instructions.rrota, instructions.rrotb);
		printntimes("rrr\n", tmp);
		instructions.rrota -= tmp;
		instructions.rrotb -= tmp;
	}
	printntimes("ra\n", instructions.rota * !(instructions.type & 0b10));
	printntimes("rb\n", instructions.rotb * !(instructions.type & 0b01));
	printntimes("rra\n", instructions.rrota * !!(instructions.type & 0b10));
	printntimes("rrb\n", instructions.rrotb * !!(instructions.type & 0b01));
}

void	pushb(t_stacks *const stacks, t_cost instructions)
{
	do_inst(stacks, instructions);
	write(1, "pb\n", 3);
}
