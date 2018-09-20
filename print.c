/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 08:52:45 by sbxaba            #+#    #+#             */
/*   Updated: 2018/08/31 10:03:53 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_l(t_dir *list)
{
	t_dir		*tmp;
	struct stat	fstat;
	char		*bytes;
	int			len;
	int			i;

	tmp = list;
	while (tmp != NULL)
	{
		lstat(tmp->path, &fstat);
		ft_perm(tmp, fstat);
		ft_putnbr(fstat.st_nlink);
		ft_putstr(ft_strjoin(" ", ft_user(fstat)));
		i = 5;
		bytes = ft_itoa(fstat.st_size);
		ft_putstr("  ");
		len = ft_strlen(bytes);
		while (i-- > len)
			ft_putchar(' ');
		ft_putstr(ft_strjoin(bytes, " "));
		ft_time(fstat, tmp);
		tmp = tmp->next;
		if (tmp != NULL)
			ft_putchar('\n');
	}
}

void	rev_list(t_dir **head_ref)
{
	t_dir	*prev;
	t_dir	*current;
	t_dir	*next;

	current = *head_ref;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void	ft_perm(t_dir *temp, struct stat fstat)
{
	if (temp->is_dir)
		ft_putchar('d');
	else
		ft_putchar((S_ISLNK(fstat.st_mode)) ? 'l' : '-');
	ft_putchar((fstat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
}
