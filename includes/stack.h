/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:23:17 by edgribei          #+#    #+#             */
/*   Updated: 2025/07/09 14:23:40 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <libft.h>

typedef struct s_stackpair
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		maxb;
	int		minb;
	int		mina;
	int		maxa;
}	t_stacks;

void	stack_rotate(t_list **stack, unsigned int rotn);
void	stack_rrotate(t_list **stack, unsigned int rotn);
t_list	*stack_pop(t_list **stack);
void	stack_push(t_list **stack, t_list *node);
void	stack_swap(t_list **stack);

#endif
