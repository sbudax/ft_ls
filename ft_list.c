/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:18:48 by sbxaba            #+#    #+#             */
/*   Updated: 2018/08/31 08:45:45 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_ls(t_dir *list, t_env *e, char *path)
{
	t_dir	*tmp;

	if (e->t == 1)
		sort_list(&list, compare_time, 0);
	if (e->r == 1)
		rev_list(&list);
	if (e->rr == 1)
		ft_putstr(ft_strjoin(path, ":\n"));
	if (e->l == 1)
		print_l(list);
	else
	{
		tmp = list;
		while (tmp != NULL)
		{
			ft_putstr(tmp->dir);
			tmp = tmp->next;
			if (tmp != NULL)
				ft_putchar('\n');
		}
	}
	ft_putchar('\n');
	if (e->rr == 1)
		cap_r(list, e);
}

void		do_ls(char *dir, t_env *e)
{
	t_dir	*list;
	t_dir	*tmp;

	list = NULL;
	if ((e->dirp = opendir(dir)) != NULL)
	{
		while ((e->dp = readdir(e->dirp)) != NULL)
		{
			if (e->dp->d_name[0] != '.' || e->a == 1)
			{
				tmp = (t_dir *)malloc(sizeof(t_dir));
				tmp->dir = e->dp->d_name;
				tmp->path = ft_strjoin(ft_strjoin(dir, "/"),
						e->dp->d_name);
				lstat(tmp->path, &e->sb);
				tmp->time = e->sb.st_mtime;
				if (S_ISDIR(e->sb.st_mode) == 1)
					tmp->is_dir = 1;
				tmp->next = list;
				list = tmp;
			}
		}
		sort_list(&list, compare_strings, 0);
		ft_print_ls(list, e, dir);
	}
}
