/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 23:47:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/01/03 02:31:57 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

int			ft_error(char *arg1, char *arg2)
{
	if (arg1)
	{
		if (ft_strequ(arg1, "open") || ft_strequ(arg1, "read")
			|| ft_strequ(arg1, "malloc"))
			perror(arg1);
		else
			ft_putendl_fd(arg1, 2);
	}
	if (arg2)
		ft_putendl_fd(arg2, 2);
	exit(1);
	return (1);
}
