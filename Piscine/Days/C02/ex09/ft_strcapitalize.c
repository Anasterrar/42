/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 20:48:58 by ------            #+#    #+#             */
/*   Updated: 2026/06/05 22:34:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha_num(char c)
{
	if (!(c >= 'A' && c <= 'Z')
		&& !(c >= 'a' && c <= 'z')
		&& !(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (i > 0 && ft_str_is_alpha_num(str[i - 1]) == 1)
				str[i] = str[i] + 32;
		}
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i == 0 || (i > 0 && ft_str_is_alpha_num(str[i - 1]) == 0))
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
