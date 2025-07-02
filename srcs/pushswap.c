#include <instructions.h>
#include <libft.h>
#include <stack.h>
#include <unistd.h>
#include <parser.h>
#include <my_math.h>
#include <solve.h>

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
	c.type = (c.rrota > c.rota) << 1;
	do_inst(stacks, c);
}

void	pusha_loop(t_stacks *stacks)
{
	t_list	*tmp;
	t_cost	c;

	c.rrota = ft_lstsize(stacks->stack_a);
	ft_bzero(&c, sizeof(t_cost));
	while (ft_lstsize(stacks->stack_b))
	{
		c.rota = 0;
		tmp = stacks->stack_a;
		while(tmp->content != stacks->stack_b->content - 1)
		{
			tmp = tmp->next;
			c.rota++;
		}
		c.rrota -= c.rota;
		c.type = (c.rrota > c.rota) << 1;
		do_inst(stacks, c);
		write(1, "pa\n", 3);
		stack_push(&(stacks->stack_a), stack_pop(&(stacks->stack_b)));
		c.rrota += c.rota + 1;
	}
}

void	pushb_loop(t_stacks *stacks)
{
	t_cost	temp;

	while (ft_lstsize(stacks->stack_a) > 3)
	{
		temp = best_cost(stacks);
		do_inst(stacks, temp);
		stack_push(&(stacks->stack_b), stack_pop(&(stacks->stack_a)));
		write(1, "pb\n", 3);
	}
}

void	small_solve(t_list **lsta)
{
	if ((*lsta)->content > (*lsta)->next->content &&
		((*lsta)->content < (*lsta)->next->next->content ||
		(*lsta)->next->content > (*lsta)->next->next->content))
	{
		write(1, "sa\n", 3);
		stack_swap(lsta);
		return ;
	}
	if ((*lsta)->content < (*lsta)->next->next->content &&
		(*lsta)->next->content > (*lsta)->next->next->content)
	{
		write(1, "ra\nsa\n", 6);
		stack_rotate(lsta, 1);
		stack_swap(lsta);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	ft_bzero(&stacks, sizeof(t_stacks));
	stacks.stack_a = parse_inputs(argc - 1, argv + 1);
	if (!stacks.stack_a)
	{
		write(2, "Error!\n", 7);
		return (1);
	}
	pushb_loop(&stacks);
	small_solve(&(stacks.stack_a));
	pusha_loop(&stacks);
	rotate_to_top(&stacks);

	ft_lstclear(&(stacks.stack_a), NULL);
}
