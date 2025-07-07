#include <stack.h>
#include <libft.h>

int	check_sorted_stack(t_stacks *stacks)
{
	t_list	*tmp;

	if (stacks->stack_b != NULL)
		return (-1);
	tmp = stacks->stack_a;
	while (tmp && tmp->next)
	{
		if ((unsigned long) tmp->content > (unsigned long) tmp->next->content)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
