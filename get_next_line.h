
#ifndef GET_NEXT_LINE
# include <stdlib.h>
# include <unistd.h>
char    *get_next_line(int fd);
char    *ft_strpos(char *str, int c);
char    *ft_expand(const char *s1, const char *s2);
char    *ft_substr(char *s, int start, int end);
int     ft_strposi(char *s, int start, int search);
int     ft_strlen(const char *s);
void    clear_after(char **s, int after);
#endif