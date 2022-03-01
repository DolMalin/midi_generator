
#include "main.h"

int	main(void)
{
	FILE	*f;
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->tone = C2;
	data->scale = IONIAN;
	srand(time(NULL));
	f = fopen("assets/file.mid", "wb");
	write_midi_header(f, 1, 1, 128);
	write_track(f, data);
	fclose(f);
	return (0);
}
