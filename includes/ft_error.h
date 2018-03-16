/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 23:45:04 by jbulant           #+#    #+#             */
/*   Updated: 2018/01/02 01:59:27 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define USAGE "usage"
# define FILE_CORRUPT "Fatal error:\nFile seems to be corrupted. Please be sure to entered a valid filename which is in standard bmp format."

void		print_memory(void *data, size_t size);
int			ft_error(char *arg1, char *arg2);

#endif
