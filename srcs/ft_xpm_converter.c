/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 22:01:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/02/01 17:02:36 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp2xpm_converter.h"

void				print_xpm_info(t_xpm_file *xpm)
{
	ft_putstr("     >>>  XPM_FILE  <<<\n\nname------------== ");
	ft_putendl(xpm->name);
	ft_putstr("width--------== ");
	ft_putnbr(xpm->width);
	ft_putstr("\nheight-----== ");
	ft_putnbr(xpm->height);
	ft_putstr("\ncolor max--== ");
	ft_putnbr(xpm->color_max);
	ft_putstr("\nmax_letters--== ");
	ft_putnbr(xpm->max_letters);
	ft_putstr("\n\n");
}

int					get_color_max(t_bmp_file *bmp, t_stack *stack)
{
	unsigned int	max_px;
	unsigned int	i;

	max_px = bmp->header.info.width * bmp->header.info.height;
	i = 0;
	while (i < max_px)
	{
		if (!find_stack(stack, bmp->img_data[i])
			&& !add_stack(stack, bmp->img_data[i]))
			ft_error(COLOR_MAX_ERROR, ft_static_itoa(stack->i));
		i++;
	}
	return (stack->i + 1);
}

char				*static_itohex(int n)
{
	static char		charset[17] = "0123456789ABCDEF";
	static char		hex[8];
	t_byte			byte;
	int				i;

	ft_bzero(hex, 8);
	i = 0;
	while (i < 4)
	{
		byte = (n >> (8 * (3 - i)) & 0xff);
		hex[(i * 2)] = charset[byte / 16];
		hex[1 + (i * 2)] = charset[byte % 16];
		i++;
	}
	return (hex);
}

t_bool				is_unallowed_char(char c)
{
	return ((c == '\"' || c == '\\') ? TRUE : FALSE);
}

void				print_xpm_colors(t_xpm_file *xpm, int fd)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	while (i <= xpm->color_stack.i)
	{
		while (is_unallowed_char(c + i))
			c++;
		ft_putchar_fd(c + i, fd);
		ft_putstr_fd(" c #", fd);
		ft_putstr_fd(static_itohex(xpm->color_stack.container[i]), fd);
		ft_putstr_fd(XPM_INTER, fd);
		i++;
	}
}

void				print_xpm_info_fd(t_xpm_file *xpm, int fd)
{
	ft_putnbr_fd(xpm->width, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(xpm->height, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(xpm->color_max, fd);
	ft_putstr_fd(" 1", fd);
	ft_putstr_fd(XPM_INTER, fd);
}

char				get_xpm_color_char(t_xpm_file *xpm, int color)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	while (i <= xpm->color_stack.i)
	{
		if (is_unallowed_char(c + i))
			c++;
		if (color == xpm->color_stack.container[i])
			break ;
		i++;
	}
	return (c + i);
}

void				print_xpm_data(t_xpm_file *xpm, t_bmp_file *bmp, int fd)
{
	int		y;
	int		x;

	y = xpm->height;
	while (y-- > 0)
	{
		x = 0;
		while (x < xpm->width)
		{
			ft_putchar_fd(
				get_xpm_color_char(xpm
									, bmp->img_data[x + (y *xpm->width)])
									, fd);
			x++;
		}
		if (y - 1 >= 0)
			ft_putstr_fd(XPM_INTER, fd);
	}
	ft_putstr_fd(XPM_TAIL, fd);
}

void				convert_bmp2xpm(t_bmp_file *bmp, t_xpm_file *xpm)
{
	int fd;

	fd = ft_open_file(&xpm->name, O_RDWR | O_CREAT | O_TRUNC, 0666, TRUE);
	ft_putstr_fd(XPM_HEADER1, fd);
	write(fd, xpm->name, ft_strlen(xpm->name) - 4);
	ft_putstr_fd(XPM_HEADER2, fd);
	print_xpm_info_fd(xpm, fd);
	print_xpm_colors(xpm, fd);
	print_xpm_data(xpm, bmp, fd);
	close(fd);
}

void				create_xpm_from(t_bmp_file *bmp)
{
	t_xpm_file		xpm;

	init_stack(&xpm.color_stack);
	xpm.name = bmp->name;
	*(int*)ft_strstr(xpm.name, ".bmp") = XPM_EXT;
	xpm.width = bmp->header.info.width;
	xpm.height = bmp->header.info.height;
	xpm.color_max = get_color_max(bmp, &xpm.color_stack);
	xpm.max_letters = 1;
	print_xpm_info(&xpm);
	convert_bmp2xpm(bmp, &xpm);
}
