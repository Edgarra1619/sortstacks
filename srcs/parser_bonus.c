/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:20:25 by edgribei          #+#    #+#             */
/*   Updated: 2025/07/09 14:22:06 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	bbl_srt(int *arr, const size_t size)
{
	size_t	i;
	size_t	j;

	if (!arr)
		return ;
	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (arr[j] < arr[j - 1])
			{
				arr[j] ^= arr[j - 1];
				arr[j - 1] ^= arr[j];
				arr[j] ^= arr[j - 1];
			}
			j--;
		}
		i++;
	}
}

//returns -1 on error
t_list	*arr_to_indx_lst(int *arr, const size_t size)
{
	int *const	tmp = ft_memdup(arr, size * sizeof(int));
	size_t		i;
	t_list		*lst;
	t_list		*new;

	bbl_srt(tmp, size);
	i = 0;
	lst = NULL;
	while (i < size && tmp)
	{
		new = ft_lstnew((void *)
				((int *)ft_memfnd(tmp, size, arr + i, sizeof(int)) - tmp));
		if (!new)
		{
			ft_lstclear(&lst, NULL);
			lst = NULL;
			break ;
		}
		ft_lstadd_back(&lst, new);
		i++;
	}
	free(tmp);
	free(arr);
	return (lst);
}

void	check_sorted(int *arr, int size)
{
	(void) arr;
	(void) size;
	return ;
}

t_list	*parse_inputs(const int c, char **strs)
{
	int *const	ret = ft_calloc(c, sizeof(int));
	int			i;

	if (!ret || !c)
	{
		free(ret);
		return (NULL);
	}
	i = 0;
	while (i < c)
	{
		if (safe_atoi(strs[i], ret + i) == -1)
		{
			free(ret);
			return (NULL);
		}
		if (ft_memfnd(ret, i, ret + i, sizeof(int)))
		{
			free(ret);
			return (NULL);
		}
		i++;
	}
	check_sorted(ret, c);
	return (arr_to_indx_lst(ret, c));
}
