#include "so_long.h"

#define MALLOC_ERROR	1
#define	SIDE_LEN		800

int	encode_rgb(t_byte red, t_byte green, t_byte blue)
{
    return (red << 16 | green << 8 | blue);
}

/*
 * This function really sucks 👎🏻
 * 	~No buffer, i can literally see the pixels being drawn
*/
void	slow_fill(t_mlx *data, int color)
{
	for (int y = 0; y < WHEIGHT - 20; ++y)	
	{
		for (int x = 0; x < WWIDTH; ++x)
		{
			mlx_pixel_put(data->cnx, data->wdw, x, y, color);
		}
	}
}

/*
 * KeySym values in X11/keysym.h
 * ~https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h
*/
int	handle_input(int keysym, t_mlx *data)
{
	if (keysym == XK_r)
		slow_fill(data, encode_rgb(255, 0, 0));	
	else if (keysym == XK_g)
		slow_fill(data, encode_rgb(0, 0xff, 0));	
	else if (keysym == XK_b)
		slow_fill(data, encode_rgb(0, 0, 0b11111111));	
	return 0;
}

int	main()
{
	t_mlx	data;

	data.cnx = mlx_init();
	data.wdw = mlx_new_window(data.cnx, WWIDTH, WHEIGHT, "Heyy :)");
	if (!data.wdw)
	{
		mlx_destroy_display(data.cnx);
		free(data.cnx);
		return (1);
	}
	mlx_key_hook(data.wdw, handle_input, &data);
	mlx_loop(data.cnx);
}

