/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:19:33 by tbolsako          #+#    #+#             */
/*   Updated: 2024/09/30 18:55:24 by rshatra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// structure

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

// operations

void				pa(t_stack *a, t_stack *b, int checker);
void				pb(t_stack *a, t_stack *b, int checker);
void				sa(t_stack *stack, int check);
void				sb(t_stack *stack, int check);
void				ss(t_stack *a, t_stack *b);
void				ra(t_stack *a, int checker);
void				rb(t_stack *b, int checker);
void				rr(t_stack *a, t_stack *b, int checker);
void				rra(t_stack *a, int checker);
void				rrb(t_stack *b, int checker);
void				rrr(t_stack *a, t_stack *b, int checker);

// input validity

int					validate_input(char **splited_str, int num_args);

// initialize the stack A

void				create_stack(t_stack *stack, char **args, int num_args);
t_stack				*init_stack(void);
void				free_stack(t_stack *stack);
void				add_node_to_stack(t_stack *stack, t_node *new_node);

// stack helper

int					check_if_sorted(t_stack *stack);
int					stack_size(t_stack *stack);

// chunk helper

int					within_chunk_range(t_stack *a, int min, int max);

// stack sorting

void				sort_stack(t_stack *a, t_stack *b);

// from 3 to 5 elements

int					find_smallest(t_stack *stack);
int					pos_of_smallest(t_stack *stack);
void				sort_3(t_stack *a);
void				sort_4_or_5(t_stack *a, t_stack *b);

// from 6 elements

int					find_smallest_elem(t_stack *stack);
int					find_insert_position(t_stack *a, int value);
void				rotate_stack_a_to_position(t_stack *a, int target_pos);
int					get_last_elem(t_stack *stack);
int					find_mid_point(t_stack *stack);
int					find_next_largest_elem(t_stack *b, int max_value);
int					find_elem_index(t_stack *stack, int value);
int					find_chunk_min(t_stack *a, int chunk_size);
int					find_chunk_max(t_stack *a, int chunk_size);
int					find_nearest_elem_in_range(t_stack *a, int min, int max);
int					find_largest_elem(t_stack *b);
void				push_chunks_to_b(t_stack *a, t_stack *b);
void				push_back_sorted(t_stack *a, t_stack *b);
void				rotate_stack_a_to_top(t_stack *a, int target_index);
void				rotate_stack_b_to_top(t_stack *b, int max_value);
void				sort_6_plus(t_stack *a, t_stack *b);

// utils

t_node				*ft_nodenew(int value);
int					ft_strcmp(char *s1, char *s2);
void				ft_putstr_fd(char *str, int fd);
void				ft_swap(int *a, int *b);
char				**ft_split(char const *str, char c, t_stack *a, t_stack *b);
size_t				ft_strlcpy(char *dest, const char *source, size_t size);
int					ft_atoi(const char *ptr);
int					isdigit(int c);

#endif
