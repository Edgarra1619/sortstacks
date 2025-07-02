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

void	do_inst(t_stacks *const stacks, t_cost instructions)
{
	if (instructions.type & 0b10)
		stack_rrotate(&(stacks->stack_a), instructions.rrota);
	else
		stack_rotate(&(stacks->stack_a), instructions.rota);
	if (instructions.type & 0b01)
		stack_rrotate(&(stacks->stack_b), instructions.rrotb);
	else
		stack_rotate(&(stacks->stack_b), instructions.rotb);
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

