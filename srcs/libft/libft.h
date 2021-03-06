/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salibert <salibert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:37:30 by salibert          #+#    #+#             */
/*   Updated: 2017/05/05 18:41:53 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 1024
# define END '\n'

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoi_base(char *s, int base);
int				ft_ismaj(char c);
int				ft_ismin(char c);
double			ft_atod(char **s);
void			ft_strlowcase(char *s);
double			ft_dtrim(double min, double max, double nb);
char			*ft_ditoa(double n, int preci);
int				ft_pow(int nb, int power);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, int base);
char			*ft_litoa(long n);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_putendl(char const *s);
void			ft_putnbr(int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstsort(t_list *lst, int (*cmp)(void *a, void *b));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_putstrtab(char **s);
void			ft_push_back(t_list **alst, t_list *new);
void			ft_push_front(t_list **alst, t_list *new);
char			*ft_strjoinf(char const *s1, char const *s2, char c);
int				ft_trim(int min, int max, int nb);
void			ft_freetab(char ***tab);
void			ft_putxy(int x, int y);
double			ft_dabs(double nb);
int				get_next_line(const int fb, char **line);
int				get_next_char(const int fb, char **line, char c);
t_list			*ptr_of(t_list *lst, void *data, int (*cmp)(void *a, void *b));
t_list			*elem_rm(t_list *head, void *value, int cmp(void*, void*));
void			swap(double *a, double *b);
void			ft_write_n_bytes(unsigned char *d, unsigned char *s, int i);
#endif
