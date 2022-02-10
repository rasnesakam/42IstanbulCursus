/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <emakas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:06:57 by emakas            #+#    #+#             */
/*   Updated: 2022/02/10 22:16:13 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strpos(char *str, int c);
char	*ft_expand(const char *s1, const char *s2);
char	*ft_substr(char *s, int start, int end);
int		ft_strposi(char *s, int start, int search);
int		ft_strlen(const char *s);
#endif