/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 08:38:43 by sbxaba            #+#    #+#             */
/*   Updated: 2018/08/24 12:44:16 by sbxaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	char	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	c = 0;
	s = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[c] != '\0')
	{
		s[i] = s2[c];
		i++;
		c++;
	}
	s[i] = '\0';
	return (s);
}
