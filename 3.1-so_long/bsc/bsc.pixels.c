#include "so_long.h"

/**
 * Encode RGB values into a single integer through bitshifting.
 * @returns an int which binary is 00000000 rrrrrrrr gggggggg bbbbbbbb
 */
int	encode_rgb(t_byte red, t_byte green, t_byte blue)
{
	return (red << 16 | green << 8 | blue);
}


int	handle_input(int keysym, t_mlx *data)
{
	if (keysym == XK_r)
		color_fill(data, 0xff0000, 0, 0);
	else if (keysym == XK_g)
		color_fill(data, 0x00ff00, 0, 0);
	else if (keysym == XK_b)
		color_fill(data, 0x0000ff, 0, 0);
	else if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->cnx, data->wdw);
		mlx_destroy_display(data->cnx);
		free(data->cnx);
		exit(0);
	}
	mlx_put_image_to_window(data->cnx, data->wdw, data->img.img_ptr, 0, 0);
	return (0);
}

int	main(void)
{
	t_mlx	data;

	data.cnx = mlx_init();
	data.wdw = mlx_new_window(data.cnx, WWIDTH, WHEIGHT, "mlx pixelput");
	if (!data.wdw)
	{
		mlx_destroy_display(data.cnx);
		free(data.cnx);
		return (1);
	}
	data.img.img_ptr = mlx_new_image(data.cnx, WWIDTH, WHEIGHT);
	data.img.img_pxls_ptr = mlx_get_data_addr(data.img.img_ptr,
			&data.img.bits_per_pxl, &data.img.line_len, &data.img.endian);
	mlx_key_hook(data.wdw, handle_input, &data);
	mlx_loop(data.cnx);
	mlx_destroy_window(data.cnx, data.wdw);
	mlx_destroy_display(data.cnx);
	free(data.cnx);
}
