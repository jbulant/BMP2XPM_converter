/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 01:21:30 by jbulant           #+#    #+#             */
/*   Updated: 2018/01/03 03:08:09 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char		*get_new_filename(char **filename)
{
	char *answer;

	ft_putendl(ASK_NEW_NAME);
	if (get_next_line(0, &answer) == -1)
		ft_error("read", NULL);
	ft_strdel(filename);
	if (!(*filename = ft_strdup(answer)))
		ft_error("malloc", NULL);
	return (*filename);
}

t_bool		get_answer_yn(char *msg)
{
	char *answer;

	while (1)
	{
		if (get_next_line(0, &answer) == -1)
			ft_error("read", NULL);
		if (ft_strequ(answer, "yes") || ft_strequ(answer, "y"))
		{
			ft_strdel(&answer);
			return (TRUE);
		}
		if	(ft_strequ(answer, "no") || ft_strequ(answer, "n"))
		{
			ft_strdel(&answer);
			return (FALSE);
		}
		ft_putendl("Please answer by \"yes\" or \"no\"");
		if (msg)
			ft_putendl(msg);
		ft_strdel(&answer);
	}
	return (FALSE);
}

t_bool		get_auth_write(char **filename, t_bool *auth)
{
	char *msg;
	
	msg = ft_strjoin(*filename, AUTH_USR_WR);
	ft_putendl(msg);
	if (get_answer_yn(msg))
	{
		ft_strdel(&msg);
		return ((*auth = TRUE));
	}
	ft_putendl(ASK_EXIT);
	if (get_answer_yn(ASK_EXIT))
	{
		ft_strdel(&msg);
		return (FALSE);
	}
	get_new_filename(filename);
	return (TRUE);
}

int		ft_open_file(char **filename, int type, int attr, t_bool check_ifexist)
{
	int		fd;
	t_bool	auth;

	auth = FALSE;
	while (type & O_CREAT && check_ifexist
	&& (fd = open(*filename, O_RDONLY)) != -1)
	{
		close(fd);
		if (!get_auth_write(filename, &auth))
			ft_error(USR_CHOICE_ERR_NAME, USAGE);
		if (auth)
			break ;
	}
	fd = attr ? open(*filename, type, attr)
		: open(*filename, type);
	if (fd == -1)
		ft_error("open", NULL);
	return (fd);
}
