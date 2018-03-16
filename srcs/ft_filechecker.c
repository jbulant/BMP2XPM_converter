/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filechecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 00:13:50 by jbulant           #+#    #+#             */
/*   Updated: 2018/01/03 17:42:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp2xpm_converter.h"

void				print_header(t_bmp_header *header)
{
	// mon dieu... il serait temps que je fasse ft_printf O.o
	ft_putstr("     >>>  BMP_HEADER  <<<\n       >>> IDENTITY <<<\nid------------== ");
	write(1, (char*)&header->id.identity, 2);
	ft_putstr("\nfile_size-----== ");
	ft_putnbr(header->id.file_size);
	ft_putstr("\nimage_address-== ");
	ft_putnbr(header->id.image_address);
	ft_putstr("\n\n        >>> INFO <<<\nheader size------------== ");
	ft_putnbr(header->info.header_size);
	ft_putstr("\nwidth------------------== ");
	ft_putnbr(header->info.width);
	ft_putstr("\nheight-----------------== ");
	ft_putnbr(header->info.height);
	ft_putstr("\ncolor plane------------== ");
	ft_putnbr(header->info.color_plane);
	ft_putstr("\nbpp--------------------== ");
	ft_putnbr(header->info.bpp);
	ft_putstr("\ncompression------------== ");
	ft_putnbr(header->info.compression);
	ft_putstr("\nimage size-------------== ");
	ft_putnbr(header->info.image_size);
	ft_putstr("\npixel per meter-width--== ");
	ft_putnbr(header->info.width_ppm);
	ft_putstr("\npixel per meter-height-== ");
	ft_putnbr(header->info.height_ppm);
	ft_putstr("\ncolor palette length---== ");
	ft_putnbr(header->info.color_palette_length);
	ft_putstr("\nimportant color used---== ");
	ft_putnbr(header->info.important_color_used);
	ft_putstr("\n\n");
}

int				get_image_data(int fd, t_bmp_file *bmp)
{
	ssize_t	readed_bytes;
	char	test[54];

	if (!bmp->header.info.image_size)
		ft_error(FILE_CORRUPT, NULL);
	bmp->img_data = (unsigned int*)ft_memalloc(bmp->header.info.image_size);
	if (!(readed_bytes = read(fd, (char*)bmp->img_data, bmp->header.info.image_size)))
		ft_error("read", NULL);
	if (readed_bytes != bmp->header.info.image_size
		|| (readed_bytes = read(fd, test, 54)) > 0)
		ft_error(FILE_CORRUPT, NULL);
	return (0);
}

int					get_bmp_header(int fd, t_bmp_header *header)
{
	char				data[54];
	int					readed_bytes;
	t_bmp_id_header		id_h;
	t_bmp_info_header	inf_h;

	if (((readed_bytes = read(fd, data, 54)) == -1 && ft_error("read", NULL))
		|| ((readed_bytes < 54) && ft_error(FILE_CORRUPT, NULL)))
		return (1);
	id_h.identity = *(short*)(data);
	id_h.file_size = *(int*)(data + 2);
	id_h.reserved1 = *(short*)(data + 6);
	id_h.reserved2 = *(short*)(data + 8);
	id_h.image_address = *(int*)(data + 10);
	*(t_bmp_info_header*)&inf_h = *(t_bmp_info_header*)(data + 14);
	*header = (t_bmp_header){id_h, inf_h};
	return (0);
}

char				*get_name(char *filename)
{
	char *name;
	char *type;

	name = ft_strrchr(filename, '/');
	if (!name)
		name = filename;
	else
		name++;
	if (!(type = ft_strstr(name, ".bmp")) && type[4])
		ft_error(INCORRECT_TYPE, USAGE);
	return (ft_strdup(name));
}

t_bmp_file			open_bmp(char *filename)
{
	int				fd;
	t_bmp_file		bmp;

	fd = ft_open_file(&filename, O_RDONLY, 0, FALSE);
	bmp.name = get_name(filename);
	get_bmp_header(fd, &bmp.header);
	if (bmp.header.info.bpp != 32 || bmp.header.info.compression)
		ft_error(INCORRECT_FORMAT, NULL);
	get_image_data(fd, &bmp);
	print_header(&bmp.header);
	close(fd);
	return (bmp);
}
