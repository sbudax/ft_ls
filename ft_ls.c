/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 08:17:00 by sbxaba            #+#    #+#             */
/*   Updated: 2018/08/31 09:43:16 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_time(struct stat fstat, t_dir *tmp)
{
	char	t_fmt[13];
	char	*s;
	char	buf[64];
	size_t	len;

	(void)fstat;
	s = ctime(&tmp->time);
	ft_memcpy(t_fmt, &s[4], 12);
	t_fmt[12] = '\0';
	ft_putstr(t_fmt);
	ft_putchar(' ');
	ft_putstr(tmp->dir);
	if (S_ISLNK(fstat.st_mode))
	{
		ft_putstr(" -> ");
		len = readlink(tmp->path, buf, 64);
		buf[len] = '\0';
		ft_putstr(buf);
	}
}

void	cap_r(t_dir *list, t_env *e)
{
	t_dir *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->is_dir == 1 && tmp->dir[0] != '.')
			do_ls(tmp->path, e);
		tmp = tmp->next;
	}
}

char	*ft_user(struct stat fstat)
{
	char			*s;
	struct passwd	*pass;
	struct group	*grp;

	pass = getpwuid(fstat.st_uid);
	grp = getgrgid(fstat.st_gid);
	s = ft_strjoin(ft_strjoin(pass->pw_name, "  "), grp->gr_name);
	return (ft_strjoin(s, ""));
}

void	do_list(t_env *e)
{
	e->list = (t_dir *)malloc(sizeof(t_dir));
	e->list->dir = ".";
	e->list->next = NULL;
}

void	ft_ls(t_env *e)
{
	t_dir	*tmp;

	tmp = e->list;
	while (tmp != NULL)
	{
		do_ls(tmp->dir, e);
		tmp = tmp->next;
	}
}
