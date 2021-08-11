/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:24:12 by igearhea          #+#    #+#             */
/*   Updated: 2020/10/30 14:43:44 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			count;

	count = 0;
	ptr = dst;
	if (n != 0)
	{
		while (count < n)
		{
			*ptr = (unsigned char)c;
			ptr++;
			count++;
		}
	}
	return (dst);
}
