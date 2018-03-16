/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 23:59:41 by jbulant           #+#    #+#             */
/*   Updated: 2018/02/06 00:31:01 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BMP_H
# define FT_BMP_H

# include <unistd.h>
# include <fcntl.h>

# define	INCORRECT_TYPE "Filename is not typed \"bmp\", please reffer to :"
# define	INCORRECT_FORMAT "BMP file must be uncompressed and 32bits/color"

typedef struct		s_bmp_id_header
{
	short			filler;
	short			identity;
	unsigned int	file_size;
	short			reserved1;
	short			reserved2;
	int				image_address;
}					t_bmp_id_header;

typedef struct		s_bmp_info_header
{
	unsigned int	header_size;
	unsigned int	width;
	unsigned int	height;
	short			color_plane;
	short			bpp;
	unsigned int	compression;
	unsigned int	image_size;
	int				width_ppm;
	int				height_ppm;
	unsigned int	color_palette_length;
	unsigned int	important_color_used;
}					t_bmp_info_header;

typedef struct		s_bmp_header
{
	t_bmp_id_header		id;
	t_bmp_info_header	info;
}					t_bmp_header;

typedef struct		s_bmp_file
{
	char			*name;
	t_bmp_header	header;
	unsigned int	*img_data;
}					t_bmp_file;

t_bmp_file			open_bmp(char *filename);

#endif
