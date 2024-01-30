#include "so_long.h"



/*
 * Faster version of mlx_pixel_put.
 * Credits to https://github.com/suspectedoceano/mlx
*/
void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));	

	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}



void	color_screen(t_mlx *data, int color)
{
	for (int y = 0; y < WHEIGHT; ++y)	
	{
		for (int x = 0; x < WWIDTH; ++x)
		{
			my_pixel_put(&data->img,
						x, 
						y, 
						color);
		}
	}
}

/*
 * This time i plug color in hexadecimal directly
 * easy vanilla
*/
int	f(int keysym, t_mlx *data)
{

	if (keysym == XK_r)
		color_screen(data, 0xff0000);
	else if (keysym == XK_g)
		color_screen(data, 0xff00);
	else if (keysym == XK_b)
		color_screen(data, 0xff);
	else if (keysym == XK_Escape)
		exit(1);

	// push the READY image to window
	// the last parameters are the offset image-window
	mlx_put_image_to_window(data->cnx,
							data->wdw, 
							data->img.img_ptr, 
							0, 0);

	return 0;
}

int	main()
{
	t_mlx	data;

	data.cnx = mlx_init();
	data.wdw = mlx_new_window(data.cnx, WWIDTH, WHEIGHT, "fast pixel put");
	

	// Code to create an image and get the related DATA
	data.img.img_ptr = mlx_new_image(data.cnx, WWIDTH, WHEIGHT);
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr, 
												&data.img.bits_per_pixel, 
												&data.img.line_len, 
												&data.img.endian);


	printf("Line_len %d <-> WWIDTH %d\n"
			"bpp %d\n"
			"endian %d\n", data.img.line_len, WWIDTH, data.img.bits_per_pixel, data.img.endian);

	mlx_key_hook(data.wdw, 
				f,
				&data);
	mlx_loop(data.cnx);
}

