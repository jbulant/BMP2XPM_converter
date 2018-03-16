/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp2xpm_converter.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 23:42:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/01/03 14:40:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP2XPM_CONVERTER_H
# define BMP2XPM_CONVERTER_H

# include "libft.h"
# include "ft_error.h"
#include "ft_io.h"
# include "ft_bmp.h"
#include "ft_stack.h"

# define XPM_EXT ('.' | ('x' << 8) | ('p' << 16) | ('m' << 24))

# define XPM_HEADER1 "/*XPM_CONVERTER - jbulant@student.42.fr*/\nstatic char\t*"
# define XPM_HEADER2 "_xpm[] = {\n\""
# define XPM_INTER "\",\n\""
# define XPM_TAIL "\"};\n"

typedef struct		s_xpm_file
{
	char		*name;
	int			width;
	int			height;
	int			color_max;
	int			max_letters;
	t_stack		color_stack;
}					t_xpm_file;

void				create_xpm_from(t_bmp_file *bmp);

#endif
