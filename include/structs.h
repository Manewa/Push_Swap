#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_list
{
	int				content;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
	int				addr;
	int				count_move;
	struct s_list	*next;
}					t_list;

#endif