/*
** get_next_line.c for getnextline in /home/bibibrutal/bibi_linux/Rendu/Projets/CPE/CPE_2016_getnextline
**
** Made by Kevin Bidet
** Login   <bibibrutal@epitech.net>
**
** Started on  Wed Jan  4 18:15:42 2017 Kevin Bidet
** Last update Mon Jan 16 14:07:45 2017 Kevin Bidet
*/

#include "get_next_line.h"

char		*get_next_line(const int fd)
{
  char		buf[READ_SIZE + 1];
  static char	*save = NULL;
  char		*line;
  int		ret;

  line = NULL;
  if (save && my_strnlen(save, '\n') != my_strnlen(save, '\0'))
    {
      line = my_stop_strdup(save, '\n', (my_strnlen(save, '\n') - 1));
      save = my_stop_strdup(&save[my_strnlen(save, '\n') + 1], '\0', READ_SIZE);
      return (line);
    }
  if ((ret = read(fd, buf, READ_SIZE)) <= 0)
    return (NULL);
  buf[ret] = '\0';
  while (my_strnlen(buf, '\n') == my_strnlen(buf, '\0'))
    {
      line = my_strncat(line, buf, buf[my_strnlen(buf, '\n')]);
      ret = read(fd, buf, READ_SIZE);
      buf[ret] = '\0';
    }
  line = my_strncat(save, line, '\0');
  line = my_strncat(line, buf, '\n');
  save = my_stop_strdup(&buf[my_strnlen(buf, '\n')] + 1, '\0', READ_SIZE);
  return (line);
}

  int	my_strnlen(char *buf, char stop)
  {
    int		nb_char;

    nb_char = 0;
    while (buf[nb_char] != stop && buf[nb_char] != '\0')
      nb_char += 1;
    return (nb_char);
  }

char	*my_stop_strdup(char *src, char stop, int end)
{
  int	i;
  char	*dest;

  i = 0;
  if (end <= 0)
    {
      dest = malloc(1);
      dest[0] = '\0';
      return (dest);
    }
  while (src[i] != stop && i <= end && src[i] != '\0')
    i += 1;
  dest = malloc(sizeof(*dest) * (i + 1));
  if (!dest)
    return (NULL);
  i = 0;
  while (src[i] != stop && src[i] != '\0' && i <= end)
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}

/*
**  retour du malloc non checker pour le dernier push.
*/

char	*my_strncat(char *string1, char *string2, char stop)
{
  char	*result;
  int	i;
  int	j;
  int	len;
  int	len2;

  i = j = 0;
  len = check_string(string1);
  len2 = check_string(string2);
  if ((result = (malloc(sizeof(*result) * (len + len2 + 1);))) = NULL)
    return (NULL);
  while (string1 && string1[i] != '\0')
    {
      result[j] = string1[i];
      i += 1;
      j += 1;
    }
  i = 0;
  while (string2 && string2[i] != '\0' && string2[i] != stop)
    {
      result[j] = string2[i];
      i += 1;
      j += 1;
    }
  result[j] = '\0';
  return (result);
}

int	check_string(char *str)
{
  int	result;

  if (!str)
    result = 0;
  else
    result = my_strnlen(str, '\0');
  return (result);
}
