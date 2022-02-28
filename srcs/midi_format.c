#include "main.h"

static void	write_delta_time(FILE *f, unsigned long i)
{
	bool			check;
    unsigned long	filo = i & 0x7F ;

	if (i > 0x0FFFFFFF)
	{
		printf("Error delay > 0x0FFFFFFF ! \n") ;
		exit(EXIT_FAILURE) ;
	}
    i = i >> 7 ;
	while (i != 0)
	{
    	filo = (filo << 8)  + ((i & 0x7F) | 0x80) ;
		i = i >> 7 ;
	}
	do 
	{
		fwrite(&filo, 1, 1, f);
		check = filo & 0x80;
        if (check)
			filo = filo >> 8;
    }	while (check);    
}

static void	write_tempo(FILE *f, unsigned long n)
{
	unsigned char bytes[6] = {0xFF, 0x51, 0x03};

	write_delta_time(f, 0);
	bytes[3] = n >> 16;
	bytes[4] = n >> 8;
	bytes[5] = n;
	fwrite(&bytes, 6, 1, f);
}

void	write_midi_header(FILE* f, unsigned char smf, unsigned short tracks_nb, unsigned short nbdiv)
{
	unsigned char bytes[14] = {0x4d, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06};

	if (smf == 0 && tracks_nb > 1)
	{
		fprintf(stderr, "smf 0 format cannot handle more than one track\n");
		exit(EXIT_FAILURE);
	}
	bytes[8] = 0;
	bytes[9] = smf;
	bytes[10] = tracks_nb >> 8;
	bytes[11] = tracks_nb;
	bytes[12] = nbdiv >> 8;
	bytes[13] = nbdiv;
	fwrite(&bytes, 14, 1, f);
}

static unsigned long	write_track_header(FILE *f)
{
	unsigned char bytes[8] = {0x4d, 0x54, 0x72, 0x6b, 0x00, 0x00, 0x00, 0x00};

	fwrite(&bytes, 8, 1, f);
	return (ftell(f));
}

static void	write_track_end(FILE *f)
{
	unsigned char bytes[3] = {0xFF, 0x2F, 0x00};
	write_delta_time(f, 0);
	fwrite(&bytes, 3, 1, f);
}

static void	write_track_size(FILE *f, unsigned long pos) {
	unsigned char bytes[4];
	unsigned long len = ftell(f) - pos;

	fseek(f, pos-4, SEEK_SET);
	bytes[0] = len >> 24;
	bytes[1] = len >> 16;
	bytes[2] = len >> 8;
	bytes[3] = len;
	fwrite(&bytes, 4, 1, f);
	fseek(f, 0, SEEK_END);
}

static void	build_note(unsigned char state, FILE *f, unsigned char note, unsigned char velo)
{
	unsigned char bytes[3];

	bytes[0] = state + 0 % 16;
	bytes[1] = note % 128;
	bytes[2] = velo % 128;
	fwrite(&bytes, 3, 1, f);
}

static void write_note(FILE *f, unsigned char note, unsigned char velo, unsigned long len)
{
	write_delta_time(f, 0);
	build_note(ON, f, note, velo);
	write_delta_time(f, len);
	build_note(OFF, f, note, 0);
}

static void write_blank_note(FILE *f, unsigned long len)
{
	write_delta_time(f, 0);
	build_note(OFF, f, C2, 0);
	write_delta_time(f, len);
	build_note(OFF, f, C2, 0);
}

void	write_track(FILE *f, t_data *data)
{
	unsigned long	mark = write_track_header(f);

	write_tempo(f, 500000);
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_note(f, get_rand_note(data->tone, data->scale), 64, get_rand_len());
	write_blank_note(f, NOIRE);
	write_track_end(f);
	write_track_size(f, mark);
}
