/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:10:53 by mmaterna          #+#    #+#             */
/*   Updated: 2024/12/19 15:28:52 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*temp;
	unsigned int	i;

	if (!s)
		return (NULL);
	temp = ft_strdup(s);
	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	return (temp);
}
