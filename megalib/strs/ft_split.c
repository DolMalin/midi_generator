/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:56:42 by ljourand          #+#    #+#             */
/*   Updated: 2022/02/16 11:09:52 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_nb_words(char const *str, char c)
{
	int		count;

	while (str[0] && str[0] == c)
		str++;
	if (!str[0])
		return (0);
	str = ft_strchr(str, c);
	while (str && str[0] == c && str[0])
		str++;
	count = 1;
	while (str && str[0])
	{
		str = ft_strchr(str, c);
		while (str && str[0] == c)
			str++;
		count++;
	}
	return (count);
}

static int	free_tab(char **tab, char const *str, char c)
{
	int	i;
	int	size;

	size = ft_get_nb_words(str, c);
	i = 0;
	while (i < size)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static char	*ft_get_word(char const *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	word = ft_malloc(i + 1);
	if (!word)
		return (0);
	word[i] = 0;
	ft_memcpy(word, str, i);
	return (word);
}

char	**ft_split(const char *str, char c)
{
	int		word_count;
	char	**output;
	int		i;

	if (!str || !str[0])
		return (ft_calloc(1, sizeof (char *)));
	word_count = ft_get_nb_words(str, c);
	output = ft_calloc(word_count + 1, sizeof (char *));
	if (!output)
		return (0);
	i = -1;
	while (++i < word_count)
	{
		output[i] = ft_get_word(str, c);
		if (!output[i])
		{
			free_tab(output, str, c);
			return (0);
		}
		while (str[0] && str[0] == c)
			str++;
		str += ft_strlen(output[i]);
	}
	return (output);
}
