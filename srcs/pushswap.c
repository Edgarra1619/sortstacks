/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:55:04 by edgribei          #+#    #+#             */
/*   Updated: 2025/07/09 13:59:02 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <instructions.h>
#include <parser.h>
#include <solve.h>
#include <stack.h>

void	rotate_to_top(t_stacks *stacks)
{
	t_cost	c;
	t_list	*temp;

	ft_bzero(&c, sizeof(t_cost));
	temp = stacks->stack_a;
	while (temp->content)
	{
		c.rota++;
		temp = temp->next;
	}
	c.rrota = ft_lstsize(stacks->stack_a) - c.rota;
	c.type = (c.rrota < c.rota) << 1;
	do_inst(stacks, c);
}

void	pusha_loop(t_stacks *stacks)
{
	t_cost			c;
	const t_list	*helper = stacks->stack_a;

	ft_bzero(&c, sizeof(t_cost));
	c.rrota = ft_lstsize(stacks->stack_a);
	while (helper)
	{
		if ((long)helper->content > stacks->maxa)
			stacks->maxa = (long) helper->content;
		if ((long)helper->content < stacks->mina)
			stacks->mina = (long) helper->content;
		helper = helper->next;
	}
	while (ft_lstsize(stacks->stack_b))
	{
		cost_to_topa(stacks, (long) stacks->stack_b->content, &c);
		c.type = (c.rrota < c.rota) << 1;
		do_inst(stacks, c);
		write(1, "pa\n", 3);
		stack_push(&(stacks->stack_a), stack_pop(&(stacks->stack_b)));
		if ((long)stacks->stack_a->content > stacks->maxa)
			stacks->maxa = (long) stacks->stack_a->content;
		if ((long)stacks->stack_a->content < stacks->mina)
			stacks->mina = (long) stacks->stack_a->content;
	}
}

void	pushb_loop(t_stacks *stacks)
{
	t_cost	temp;

	stacks->minb = ft_lstsize(stacks->stack_a);
	stacks->maxb = 0;
	stack_push(&(stacks->stack_b), stack_pop(&(stacks->stack_a)));
	if ((long) stacks->stack_b->content < stacks->minb)
		stacks->minb = (long) stacks->stack_b->content;
	if ((long) stacks->stack_b->content > stacks->maxb)
		stacks->maxb = (long) stacks->stack_b->content;
	write(1, "pb\n", 3);
	while (ft_lstsize(stacks->stack_a) > 3)
	{
		temp = best_cost(stacks);
		do_inst(stacks, temp);
		stack_push(&(stacks->stack_b), stack_pop(&(stacks->stack_a)));
		if ((long) stacks->stack_b->content < stacks->minb)
			stacks->minb = (long) stacks->stack_b->content;
		if ((long) stacks->stack_b->content > stacks->maxb)
			stacks->maxb = (long) stacks->stack_b->content;
		write(1, "pb\n", 3);
	}
}

void	small_solve(t_list **lsta)
{
	if ((*lsta)->content > (*lsta)->next->content
		&& ((*lsta)->content < (*lsta)->next->next->content
			|| (*lsta)->next->content > (*lsta)->next->next->content))
	{
		write(1, "sa\n", 3);
		stack_swap(lsta);
		return ;
	}
	if ((*lsta)->content < (*lsta)->next->next->content
		&& (*lsta)->next->content > (*lsta)->next->next->content)
	{
		write(1, "sa\n", 3);
		stack_swap(lsta);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc <= 2)
		return (0);
	ft_bzero(&stacks, sizeof(t_stacks));
	stacks.stack_a = parse_inputs(argc - 1, argv + 1);
	if (!stacks.stack_a)
	{
		write(2, "Error!\n", 7);
		return (1);
	}
	stacks.mina = ft_lstsize(stacks.stack_a);
	if (stacks.mina == 2)
	{
		write(1, "sa\n", 3);
		return (0);
	}
	if (ft_lstsize(stacks.stack_a) != 3)
		pushb_loop(&stacks);
	small_solve(&(stacks.stack_a));
	pusha_loop(&stacks);
	rotate_to_top(&stacks);
	ft_lstclear(&(stacks.stack_a), NULL);
}
