/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg-parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emakas <rasnesakam@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:41:25 by emakas            #+#    #+#             */
/*   Updated: 2022/08/03 20:12:39 by emakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGPARSER_H
# define ARGPARSER_H

int		count_words(char *c);
int		count_args(int ac, char **args);
char	**collect_args(int ac, char **args);

# endif