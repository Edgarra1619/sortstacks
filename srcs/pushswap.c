#include <instructions.h>
#include <libft.h>
#include <stack.h>
#include <unistd.h>
#include <parser.h>
#include <my_math.h>

// TODO: push to b loop
// TODO: push back to A

void	printntimes(const char *str, int count)
{
	const size_t	size = ft_strlen(str);

	while (count--)
		write(1, str, size);
}

void	pushb(t_stacks *const stacks, t_cost instructions)
{
	if (instructions.type & 0b10)
		stack_rrotate(&(stacks->stack_a), instructions.rrota);
	else
		stack_rotate(&(stacks->stack_a), instructions.rota);
	if (instructions.type & 0b01)
		stack_rrotate(&(stacks->stack_b), instructions.rrotb);
	else
		stack_rotate(&(stacks->stack_b), instructions.rotb);
	stack_push(&(stacks->stack_b), stack_pop(&(stacks->stack_a)));
	if (instructions.type == RARB)
	{
		printntimes("rr\n", min(instructions.rota, instructions.rotb));
		instructions.rota -= min(instructions.rota, instructions.rotb);
		instructions.rotb -= min(instructions.rota, instructions.rotb);
	}
	if (instructions.type == RRARRB)
	{
		printntimes("rrr\n", min(instructions.rrota, instructions.rrotb));
		instructions.rrota -= min(instructions.rrota, instructions.rrotb);
		instructions.rrotb -= min(instructions.rrota, instructions.rrotb);
	}
	printntimes("ra\n", instructions.rota * !(instructions.type & 0b10));
	printntimes("rb\n", instructions.rotb * !(instructions.type & 0b01));
	printntimes("rra\n", instructions.rrota * !!(instructions.type & 0b10));
	printntimes("rrb\n", instructions.rrotb * !!(instructions.type & 0b01));
	write(1, "pb\n", 3);
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




	
	ft_lstclear(&(stacks.stack_a), NULL);
}
