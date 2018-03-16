/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 21:04:54 by jbulant           #+#    #+#             */
/*   Updated: 2018/01/03 17:35:57 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_print_hex(t_byte c)
{
	const static char	charset[17] = "0123456789abcdef";

	ft_putchar(charset[c / 16]);
	ft_putchar(charset[c % 16]);
}

void		print_stack(t_stack *stack)
{
	int i;

	i = 0;
	ft_putendl("Printing stack:");
	while (i <= stack->i)
	{
		ft_putstr(i < 10 ? "Stack[0" : "Stack[");
		ft_putnbr(i);
		ft_putstr("] == 0x");
		ft_print_hex((stack->container[i] >> 24) & 0xff);
		ft_print_hex((stack->container[i] >> 16) & 0xff);
		ft_print_hex((stack->container[i] >> 8) & 0xff);
		ft_print_hex(stack->container[i] & 0xff);
		ft_putchar('\n');
		i++;
	}
	ft_putendl("Stack printed.");
}

t_bool		find_stack(t_stack *stack, int to_find)
{
	int		i;

	i = 0;
	while (i <= stack->i)
	{
		ft_putnbr(i);
		ft_putstr(" <= ");
		ft_putnbr(stack->i);
		ft_putchar('\n');
		if (stack->container[i++] == to_find)
			return(TRUE);
	}
	return (FALSE);
}

t_bool		add_stack(t_stack *stack, int to_add)
{
	if (stack->i + 1 >= MAX_STACK)
		return (FALSE);
	stack->container[++stack->i] = to_add;
	return (TRUE);
}

int			get_stack(t_stack *stack)
{
	if (stack->i < 0)
		ft_error(EMPTY_STACK, NULL);
	return (stack->container[stack->i--]);
}

int			init_stack(t_stack *stack)
{
	ft_bzero(stack, sizeof(t_stack));
	stack->i = -1;
	return (0);
}
