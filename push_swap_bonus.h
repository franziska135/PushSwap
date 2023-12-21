/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <fmarggra@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:50:28 by fmarggra          #+#    #+#             */
/*   Updated: 2023/11/20 10:50:30 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# define A 0
# define B 1
# define UP 0
# define DOWN 1
# define RR 2
# define RRR 3
# define RRB 4
# define RB 5
# define RA 6
# define RRA 7
# define PB 8
# define PA 9
# define SA 10
# define FULL 1
# define LIMITED 0
# define EXIT 1
# define NEX 2

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl
{
	char			*str;
	char			*new_string;
	char			*storage;
	int				gelesen;
}		t_gnl;

typedef struct s_list
{
	int			*stack[2];
	int			size[2];
	int			direction[2];
	int			total;
}		t_list;

//checker
int		ft_operations(t_list *content, char *str);
void	ft_free(t_list *content);
void	ft_free_gnl(t_gnl *gnl, int status);
void	ft_init_gnl(t_gnl *gnl);
int		main(int argc, char *argv[]);

//setup
int		just_digits(int argc, char **argv);
int		no_doublicates(int argc, char **argv);
int		just_int(int argc, char **argv);
int		error_check(int argc, char **argv);
int		init_struct(int argc, char **argv, t_list *content);

//gnl
char	*get_next_line(int fd, t_gnl *gnl, t_list *content);
char	*ft_storage_to_output(char *storage, t_gnl *gnl, t_list *content);
char	*ft_extract_remnant(char *storage, t_gnl *gnl, t_list *content);

//gnl utils
int		ft_strlen(char *str, char c);
int		ft_strcpy(char *dest, char *src, char c, int start);
int		ft_newline(char *string);
char	*ft_strjoin(char *old, char *to_add, t_gnl *gnl, t_list *content);

//ops
void	ft_rotate(t_list *content, int stack, int direction);
void	ft_push(t_list *content, int from);
void	ft_swap(t_list *content, int stack);

//utils
int		in_order(t_list *content, int stack, int scope);
int		ft_strncmp(char *s1, const char *s2, size_t n);
int		is_number(char c);
int		ft_length(long int n);
char	*ft_write_str(char *converted, int length, long int number, int n);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_strlen_new(char *str);
void	return_exit(int status);

#endif