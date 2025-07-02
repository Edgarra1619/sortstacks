#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H
# include <stack.h>

//also works as flags for reverse, 10 for RRA mask and 01 for RRB mask
enum e_instructiontype
{
	RARB = 0,
	RARRB = 1,
	RRARB = 2,
	RRARRB = 3,
};

typedef struct	s_cost
{
	int						rota;
	int						rrota;
	int						rotb;
	int						rrotb;
	int						total;
	enum e_instructiontype	type;
} t_cost;


void	cost_to_topa(t_stacks *stacks, int num, t_cost *cost);
void	update_costb(t_cost *cost, int n, int size);
t_cost	best_cost(t_stacks *stacks);


#endif
