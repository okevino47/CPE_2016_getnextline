/*
** my_usefull.h for my_usefull in /home/bibibrutal/bibi_linux/Rendu/Projets/CPE/CPE_2016_getnextline
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Mon Jan  2 12:29:31 2017 Kevin Bidet
** Last update Sun Jan 15 21:22:25 2017 Kevin Bidet
*/


#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#include <stdlib.h>
#include <unistd.h>

#define READ_SIZE	1024

int	my_strnlen(char *buf, char stop);
int	check_string(char *str);
char	*get_next_line(const int fd);
char	*my_stop_strdup(char *src, char stop, int end);
char	*my_strncat(char *string1, char *string2, char stop);

#endif /* !GET_NEXT_LINE_H_ */
