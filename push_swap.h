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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
# define NONE 100
# define FULL 1
# define LIMITED 0
# define BIGGEST 0
# define SMALLEST 1
# define SAME	0
# define DIFFERENT 1

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s_list
{
	int			*stack[2];
	int			size[2];
	int			direction[2];
	int			total;
	int			moves;
	int			index_cheapest;
	int			target;
	int			cost;
}		t_list;

//init
int			main(int argc, char *argv[]);//h
int			init_struct(int argc, char *argv[], t_list *content);//
void		ft_free(t_list *content);//

//erorr checks
int			error_check(int argc, char **argv); //
int			just_digits(int argc, char **argv);//
int			no_doublicates(int argc, char **argv);//
int			just_int(int argc, char **argv);//
int			is_number(char c); //

//sort
void		sort(t_list *content);//
void		ft_sort_three(t_list *content, int stack); //
void		ft_sort_five(t_list *content);//
void		custom_sort(t_list *content);//

//utils
void		rotate_cor_dir(t_list *content, int stack, int index);//
int			in_order(t_list *content, int stack, int scope);//
int			in_order_confused(t_list *content, int stack); //
int			ft_min_ind(t_list *content, int stack);//
int			ft_max_ind(t_list *content, int stack); //
int			compare(int one, int two, int comparison); //

//target search
int			ft_target_index(t_list *content, int value);//
int			target_decending(t_list *content, int value); //

//cost calculations
void		find_cheapest(t_list *content);//
int			calculate_cost(t_list *content, int index_a); //
int			cost_a_smaller(t_list *content, int index_a, int down, int up); //
int			cost_b_smaller(t_list *content, int index_a, int down, int up); //

//direction
void		calculate_direction(t_list *content, int index_a, int target_index);
void		ft_find_direction(t_list *content); //
void		ft_store_direction(t_list *content, int stack_a, int stack_b); //
void		dir_a_smal(t_list *content, int ind_a, int ind_b); //
void		dir_b_smal(t_list *content, int ind_a, int ind_b);//

//operations
void		ft_swap(t_list *content, int stack);//
void		ft_push(t_list *content, int from);//
void		ft_rotate(t_list *content, int stack, int direction);//
void		ft_rotate_manager(t_list *content); //
void		ft_double_rotate(t_list *content, int direction); //
void		write_op(t_list *content, int operation, int stack); //

// libft functions
int			ft_atoi(const char *str);
int			ft_strncmp(char *s1, const char *s2, size_t n);
char		*ft_itoa(int n);
char		*ft_write_str(char *converted, int length, long int number, int n);
int			ft_length(long int n);
int			ft_strlen(char *str);
void		return_exit(int status);

#endif