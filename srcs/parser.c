#include <libft.h>
#include <stdlib.h>

void	bbl_srt(int *arr, const size_t size)
{
	size_t	i;
	size_t	j;

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
	int		*tmp = ft_memdup(arr, size * sizeof(int));
	size_t	i;
	t_list	*lst;
	t_list	*new;

	if (!tmp)
		return (NULL);
	bbl_srt(tmp, size);
	i = 0;
	lst = NULL;
	while (i < size)
	{
		new = ft_lstnew((void *)
				((int *)ft_memfnd(tmp, size, arr + i, sizeof(int)) - tmp));
		if (!new)
		{
			ft_lstclear(&lst, NULL);
			lst = NULL;
			break;
		}
		i++;
	}
	free(tmp);
	free(arr);
	return (lst);
}

t_list	*parse_inputs(const int c, char **strs)
{
	int	*const ret = ft_calloc(c, sizeof(int));
	int	i;

	if (!ret)
		return (NULL);
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
			return(NULL);
		}
		i++;
	}
	return (arr_to_indx_lst(ret, c));
}
