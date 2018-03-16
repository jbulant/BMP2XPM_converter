/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 23:42:28 by jbulant           #+#    #+#             */
/*   Updated: 2018/01/02 22:21:35 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp2xpm_converter.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 1 || ac > 2)
		ft_error(USAGE, NULL);
	t_bmp_file h = open_bmp(av[1]);
	create_xpm_from(&h);
	return (0);
}
