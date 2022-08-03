/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count-args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:46:12 by emakas            #+#    #+#             */
/*   Updated: 2022/08/03 17:19:53 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	count_words(char *c)
{
	unsigned int	count;
	unsigned int	i;
	static char		delimiter = ' ';

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == delimiter)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != delimiter)
				i++;
		}
	}
	return (count);
}

int	count_args(int ac, char **av)
{
	int	count;
	int	index;

	index = 1;
	count = 0;
	while (index < ac)
	{
		count += count_words(av[index]);
	}
	return (count);
}
