/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:06:57 by emakas            #+#    #+#             */
/*   Updated: 2022/02/14 19:23:36 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	ft_prepend_if_exists(char **prepend, char **buffer);
void	ft_inflate(char **buffer, char **append);
char	*ft_takexcess(char **buffer);
char	*ft_strpos(char *s, int c);
int		ft_strlen(char *s);

#endif