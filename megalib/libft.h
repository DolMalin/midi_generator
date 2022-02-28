/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:08:21 by ljourand          #+#    #+#             */
/*   Updated: 2022/02/17 16:51:51 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_free_tab(void **tab);

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);

char	*get_next_line(int fd);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

void	ft_lstadd_back(t_list **alst, t_list *new_lst);
void	ft_lstadd_front(t_list **alst, t_list *new_lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_strisalnum(char *str);
int		ft_isalpha(int c);
int		ft_strisalpha(char *str);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_strisnbr(char *str);
int		ft_isprint(int c);
int		ft_strisprint(char *str);
char	*ft_itoa(long long n);
char	**ft_split(const char *str, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src, int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_multi(size_t nb, ...);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
char	*ft_strtolower(char *str);
int		ft_toupper(int c);
char	*ft_strtoupper(char *str);

void	*ft_malloc(size_t size);
int		ft_access(char *path, int perm);
int		ft_dup(int fd);
void	ft_dup2(int fd1, int fd2);
void	ft_close(int fd);
int		ft_fork(void);
void	ft_waitpid(pid_t pid, int *status, int options);
void	ft_execve(char *path, char **args, char **env);
void	ft_pipe(int pip[2]);
int		ft_open(const char *path, int oflag, int perm);

#endif
