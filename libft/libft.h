/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:12:26 by edgribei          #+#    #+#             */
/*   Updated: 2025/06/16 14:51:05 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h> //SIZE_T

//istests
int				ft_isalpha(char c);
int				ft_isdigit(char c);
int				ft_isalnum(char c);
int				ft_isascii(char c);
int				ft_isprint(char c);

//to
int				ft_tolower(int c);
int				ft_toupper(int c);

//string
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *s);
unsigned int	ft_atoihex(const char *str);
int				safe_atoi(const char *str, int *ret);

//putfd
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *c, int fd);
void			ft_putendl_fd(const char *c, int fd);
void			ft_putnbr_fd(int n, int fd);

//mem
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memdup(const void *src, size_t n);

//memcheck
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memfnd(const void *mem, size_t bsize, void *c, size_t n);

//bsdstring
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
//stdlib
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
//iter
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
//newstring
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_itoa(int n);
//splitrim
char			*ft_strtrim(const char *s1, const char *set);
char			**ft_split(const char *str, char c);
size_t			ft_count_words(const char *s, char c);
//lists
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **l, t_list *new);
void			ft_lstadd_back(t_list **l, t_list *new);
int				ft_lstsize(const t_list *l);
t_list			*ft_lstlast(t_list *l);
void			ft_lstdelone(t_list *l, void (*del)(void*));
void			ft_lstclear(t_list **l, void (*del)(void*));
void			ft_lstiter(t_list *l, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));

char			*get_next_line(int fd);

#endif
