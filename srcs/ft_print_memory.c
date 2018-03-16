/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:05:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/01/02 20:05:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_hex(t_byte c)
{
	const static char	charset[17] = "0123456789abcdef";

	ft_putchar(charset[c / 16]);
	ft_putchar(charset[c % 16]);
}

void	print_ascii(t_byte *mem, size_t max)
{
	int		i;

	i = -1;
	while (++i < 16 && (size_t)i < max)
		ft_putchar(ft_isprint(mem[i]) ? mem[i] : '.');
	ft_putchar('\n');
}

void	print_addr(size_t s)
{
	int		s_hex_count;
	int		empty_slots;

	s_hex_count = s / 255 + ((s % 255 == 0) ? 0 : 1);
	empty_slots = 4 - s_hex_count;
	while(empty_slots--)
		print_hex(0);
	while(s_hex_count--)
	{
		print_hex(s % 255);
		s /= 255;
	}
}

void	print_memory(void *data, size_t size)
{
	t_byte	*mem;
	size_t	i;
	int		j;

	mem = (t_byte*)data;
	if (!size)
		ft_error("Can't print memory from buffer\n", NULL);
	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			print_addr(i);
			ft_putstr(": ");
		}
		print_hex(mem[i]);
		if (i % 2 == 1)
		{
			ft_putstr(i % 16 == 15 ? "  " : " ");
			if (i % 16 == 15)
				print_ascii((mem + i - 15), size);
		}
		i++;
	}
	j = 16 - (size % 16);
	while (j)
		ft_putstr((j-- % 2 == 1) ? "   " : "  ");
	ft_putchar(' ');
//	printf("\n\ni == %zu\nsize == %zu\nsize %% 16 == %zu\n", i, size, size % 16);
	if (size % 16 > 0)
		print_ascii(mem + size - (size % 16), size);
	ft_putchar('\n');
}
