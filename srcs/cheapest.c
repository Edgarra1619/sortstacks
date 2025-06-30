#include "libft.h"
#include <stack.h>
#include <my_math.h>
#include <instructions.h>

void	update_costb(t_cost *cost, int n, int size)
{
	int	temp;

	cost->rotb = n;
	cost->rrotb = size - n;
	cost->type = RARB;
	cost->total = max(cost->rota, cost->rotb);
	temp = cost->rota + cost->rrotb;
	if (cost->total > temp)
	{
		cost->total = temp;
		cost->type = RARRB;
	}
	temp = cost->rrota + cost->rotb;
	if (cost->total > temp)
	{
		cost->total = temp;
		cost->type = RRARB;
	}
	temp = max(cost->rrota, cost->rrotb);
	if (cost->total > temp)
	{
		cost->total = temp;
		cost->type = RRARRB;
	}
}

void	cost_to_top(t_stacks *stacks, int num, t_cost *cost)
{
	const t_list	*stck = stacks->stack_b;
	const int		size = ft_lstsize(stck);
	int				max;
	int				i;

	if (num > stacks->maxb || num < stacks->minb)
		max = stacks->maxb;
	else
		max = stacks->minb;
	i = 0;
	while (stck)
	{
		if ((long) stck->content == num - 1 || (long) stck->content == max)
		{
			update_costb(cost, i, size);
			return ;
		}
		if ((long) stck->content > max && (long) stck->content < num)
		{
			update_costb(cost, i, size);
			max = (long) stck->content;
		}
		stck = stck->next;
		i++;
	}
}

t_cost	best_cost(t_stacks *stacks)
{
	t_cost			cheapest;
	t_cost			new;
	const t_list	*stacka = stacks->stack_a;

	new.rota = 0;
	new.rrota = ft_lstsize(stacka);
	cost_to_top(stacks, (long) stacka->content, &cheapest);
	stacka = stacka->next;
	while (stacka)
	{
		cost_to_top(stacks, (long) stacka->content, &new);
		if (new.total < cheapest.total)
			cheapest = new;
		if (cheapest.total <= 2)
			return (cheapest);
		new.rota++;
		new.rrota--;
		stacka = stacka->next;
	}
	return (cheapest);
}
