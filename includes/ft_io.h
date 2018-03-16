/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 01:25:30 by jbulant           #+#    #+#             */
/*   Updated: 2018/01/03 02:32:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <fcntl.h>
# include <unistd.h>
# include "ft_error.h"
# include "libft.h"
# include "get_next_line.h"

# define AUTH_USR_WR " already exist, do you want to owerwrite it ? [yes : no]"
# define USR_CHOICE_ERR_NAME "/!\\ Can't create a new file /!\\"
# define ASK_EXIT "Do you want to exit ? [yes : no]"
# define ASK_NEW_NAME "Please enter another file name:"

int		ft_open_file(char **filename, int type, int attr, t_bool check_ifexist);

#endif
