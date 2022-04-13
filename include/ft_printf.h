/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyeo <responsible@kakao.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:54:01 by seyeo             #+#    #+#             */
/*   Updated: 2022/04/13 21:46:55 by seyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "../libft/libft.h"

# define FLAGS "-+ 0#123456789"
# define HEX_L	"0123456789abcdef"
# define HEX_U	"0123456789ABCDEF"
# define DECIMAL "0123456789"

typedef struct s_format
{
	const char	*format;
	va_list		ap;
	size_t		i;
	size_t		len;
}	t_format;

typedef struct s_syntax
{
	int		leftjustify;
	int		width;
	int		precision;
	char	*prefix;
	char	*argument;
	char	pad;
	char	conversion;
	size_t	len;
}	t_syntax;

int			ft_printf(const char *format, ...);
t_format	*ft_init_format(const char *format, va_list ap);
t_syntax	*ft_init_syntax(void);
void		ft_syntax(t_format *fm);
void		*ft_parsing(t_format *fm, t_syntax *syntax);
void		ft_convert_parsing(t_format *fm, t_syntax *syntax);
void		ft_precision(t_format *fm, t_syntax *syntax);
void		ft_width(t_format *fm, t_syntax *syntax);
void		ft_flags(t_format *fm, t_syntax *syntax);
void		ft_convert_type(t_format *fm, t_syntax *syntax);
void		ft_left_padding(char **str, char pad, int width);
void		ft_right_padding(char **str, char pad, int width);
void		ft_prefix_h(t_syntax *syntax);
void		ft_prefix(t_syntax *syntax, int sign);
void		ft_conversion_c(t_format *fm, t_syntax *syntax);
void		ft_conversion_id(t_format *fm, t_syntax *syntax);
void		ft_conversion_p(t_format *fm, t_syntax *syntax);
void		ft_conversion_percent(t_syntax *syntax);
void		ft_conversion_s(t_format *fm, t_syntax *syntax);
void		ft_conversion_digit(t_format *fm, t_syntax *syntax, char *base);
char		*ft_make_num(t_syntax *syntax);
void		ft_id_width(t_syntax *syntax, int sign);
void		ft_syntax(t_format *fm);
#endif
