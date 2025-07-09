/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:14:47 by edgribei          #+#    #+#             */
/*   Updated: 2025/07/09 14:15:10 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

void	stack_rotate(t_list **stack, unsigned int rotn)
{
	unsigned int		i;
	t_list				*tmp;

	if (!*stack)
		return ;
	if (rotn == 0)
		return ;
	ft_lstlast(*stack)->next = *stack;
	i = 0;
	while (i++ < rotn)
	{
		tmp = *stack;
		*stack = (*stack)->next;
	}
	tmp->next = NULL;
}

void	stack_rrotate(t_list **stack, unsigned int rotn)
{
	stack_rotate(stack, ft_lstsize(*stack) - rotn);
}

t_list	*stack_pop(t_list **stack)
{
	t_list *const	tmp = *stack;

	if (!*stack)
		return (NULL);
	*stack = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

void	stack_push(t_list **stack, t_list *node)
{
	ft_lstadd_front(stack, node);
}

void	stack_swap(t_list **stack)
{
	t_list	*tmp;

	if (!*stack)
		return ;
	tmp = (*stack)->next;
	if (!(*stack)->next)
		return ;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}
