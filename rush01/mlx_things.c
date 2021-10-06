#include "mlx.h"
#include <stdlib.h>

int		exit_x()
{
	exit(1);
	return (0);
}

void	mlx_initialize(void	**mlx_ptr, void **win_ptr, void **img2, char **img1, int *window_width, int *window_height)
{
	int bps;
	int size;
	int end;
	char rush[7] = "rush01";
	*mlx_ptr = mlx_init();

	*window_width = 820;
	*window_height = 600;

	*win_ptr = mlx_new_window(*mlx_ptr, *window_width, *window_height, rush);

	*img2 = mlx_new_image(*mlx_ptr, 800, 600);
	*img1 = mlx_get_data_addr(*img2, &bps, &size, &end);
	mlx_hook(*win_ptr, 17, 1L << 17, exit_x, 0);
}

void	mlx_refresh(void	*mlx_ptr)
{
	mlx_loop(mlx_ptr);
}

void mlx_string_to_win(void	*mlx_ptr, void *win_ptr, int x, int y, const char *string_mlx)
{
	mlx_string_put(mlx_ptr, win_ptr, y, x, 0xFFFFFF, (char*)string_mlx);
}

void mlx_string_to_win_red(void	*mlx_ptr, void *win_ptr, int x, int y, const char *string_mlx)
{
	mlx_string_put(mlx_ptr, win_ptr, y, x, 0xFF0000, (char*)string_mlx);
}

void mlx_string_to_win_green(void	*mlx_ptr, void *win_ptr, int x, int y, const char *string_mlx)
{
	mlx_string_put(mlx_ptr, win_ptr, y, x, 0x00FF00, (char*)string_mlx);
}

void mlx_string_to_win_yellow(void	*mlx_ptr, void *win_ptr, int x, int y, const char *string_mlx)
{
	mlx_string_put(mlx_ptr, win_ptr, y, x, 0xFFFF00, (char*)string_mlx);
}
