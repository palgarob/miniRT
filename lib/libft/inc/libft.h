/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:22:25 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/28 18:56:46 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// for malloc and free:
# include <stdlib.h>
// for write, read:
# include <unistd.h>
// for va_start, va_arg, va_end and va_list:
# include <stdarg.h>
// for true, false and bool
# include <stdbool.h>
// for sqrt and pow
# include <math.h>

/* PREPROCESSOR PARAMETERS                                                    */
# define HEXADECIMAL_LO "0123456789abcdef"
# define HEXADECIMAL_UP "0123456789ABCDEF"
# define DECIMAL "0123456789"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define EPSILON 0.00001

/* ERROR MESSAGES                                                             */
# define INVALID_MATRIX_SIZE "Error \nDon't compare matrices other than \
2x2, 3x3, 4x4\n"

/* LINKED LISTS                                                               */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lst2ndlast(t_list *lst);
t_list			*ft_lstcpy(t_list *lst, void (*del)(void *));

/* TUPLES                                                                     */
struct s_tpl
{
	double	x;
	double	y;
	double	z;
	double	w;
};

bool			tpl_equal(struct s_tpl a, struct s_tpl b);
struct s_tpl	tpl_negate(struct s_tpl tpl);
struct s_tpl	tpl_add(struct s_tpl a, struct s_tpl b);
struct s_tpl	tpl_sub(struct s_tpl a, struct s_tpl b);
struct s_tpl	tpl_multiply(struct s_tpl tuple, double scalar);
struct s_tpl	tpl_divide(struct s_tpl tuple, double scalar);
struct s_tpl	tpl(double x, double y, double z, double w);
struct s_tpl	tpl_multiply_matrix(double mat[4][4], struct s_tpl tpl);
void			print_tpl(struct s_tpl t);

/* IS_SOMETHING                                                               */
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
bool			is_coord(struct s_tpl *dst, char *src);
bool				is_normalized_vec(t_vec v);
bool			is_number(char *str);
bool			is_double(const char *str);

/* MEMORY                                                                     */
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *s, int c, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/* STRING                                                                     */
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strins(char **str_ptr, int snip_l, int snip_r,
					char *str_insert);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_gnl(char *s1, char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);

/* ALFA2NUMERIC                                                               */
int				a2double(double *dst, char *src);
int				ft_atoi(const char *str);
int				a2i(char *str, int *n);
int				a2uc(char *str, unsigned char *n);
char			*ft_itoa(int n);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strcmp(const char *s1, const char *s2);
double			to_double(const char *str);

/* PRINTFD                                                                   */
int				printfd(int fd, char const *format, ...);
int				ft_print_hex(int fd, unsigned int n, int lcase);
int				ft_print_char(int fd, int c);
int				ft_print_str(int fd, char *str);
int				ft_print_ptr(int fd, void *ptr);
int				ft_print_dec(int fd, int n);
int				ft_print_uns(int fd, unsigned int n);

/* SPLIT                                                                      */
char			**splitstr(char const *s, char c);
size_t			splitlen(char **array);
void			splitcpy(char **src, char **dst);
void			splitfree(char **split);
char			**splitlast(char **split);
int				splitadd(char *new_string, char ***split_ptr);
char			**splitdup(char **src);

/* POINTS AND VECTORS                                                         */
typedef struct s_tpl t_pnt,	t_vec;
t_pnt			pnt(double x, double y, double z);
t_pnt			pnt_add(t_pnt point, t_vec vector);
t_pnt			pnt_sub(t_pnt point, t_vec vector);
t_vec			vec(double x, double y, double z);
t_vec			vec_add(t_vec a, t_vec b);
t_vec			vec_sub(t_vec a, t_vec b);
t_vec			vec_from_to(t_pnt from, t_pnt to);
double			vec_len(t_vec vector);
t_vec			vec_normalize(t_vec vector);
double			vec_dot(t_vec a, t_vec b);
t_vec			vec_cross(t_vec a, t_vec b);

/* MATRIX                                                                     */
bool			matrix_is_equal(double a[4][4], double b[4][4], size_t size);
void			matrix_multiply(double a[4][4], double b[4][4],
					double result[4][4]);
void			matrix4_transpose(double mat[4][4]);
void			matrix_cpy(double src[4][4], double cpy[4][4]);
double			matrix2_det(double mat2[2][2]);
void			submatrix4(double mat4[4][4], double mat3[3][3],
					int row, int column);
void			submatrix3(double mat3[3][3], double mat2[2][2],
					int row, int column);
double			matrix3_minor(double mat3[3][3], int row, int column);
double			matrix4_minor(double mat4[4][4], int row, int column);
double			matrix3_cofactor(double mat3[3][3], int row, int column);
double			matrix4_cofactor(double mat4[4][4], int row, int column);
double			matrix3_det(double mat3[3][3]);
double			matrix4_det(double mat4[4][4]);
bool			matrix_inverse(double mat4[4][4], double inv[4][4]);
void			matrix4_print(double mat4[4][4]);
void			matrix_get_identity(double mat[4][4]);

/* TRANSFORMATIONS                                                            */
void			translation(double mat[4][4], t_vec *v);
void			scaling(double mat[4][4], t_vec *values);
void			rotation_x(double mat[4][4], double degrees);
void			rotation_y(double mat[4][4], double degrees);
void			rotation_z(double mat[4][4], double degrees);
t_pnt			transform(double mat[4][4], t_pnt point);
t_pnt			transform_inv(double mat[4][4], t_pnt point);
void			rotation(double mat[4][4], t_vec *v);

/* UTILS                                                                      */
typedef enum e_comp_result
{
	EQUAL,
	A_LESST_B,
	A_GREAT_B
}	t_comp;

double			deg2rad(double deg);
char			*get_next_line(int fd);

#endif
