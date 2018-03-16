/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 21:23:07 by jbulant           #+#    #+#             */
/*   Updated: 2018/01/03 17:39:14 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"
# include "ft_error.h"

# define MAX_STACK 128 - 32
# define COLOR_MAX_ERROR "/!\\FATAL ERROR/!\\\nMax stack exceeded."
# define EMPTY_STACK "/!\\FATAL ERROR/!\\\nTrying to get from empty stack."

typedef struct		s_stack
{
	int		container[MAX_STACK];
	int		i;
}					t_stack;

int			init_stack(t_stack *stack);
int			get_stack(t_stack *stack);
t_bool		add_stack(t_stack *stack, int to_add);
t_bool		find_stack(t_stack *stack, int to_find);
void		print_stack(t_stack *stack);

#endif
