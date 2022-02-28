#ifndef MAIN_H
# define MAIN_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <time.h>

# include "../megalib/libft.h"

# define NOIRE 128
# define ON  0x90
# define OFF 0x80

typedef enum e_note
{
	C0 = 24,
	C0s, D0, D0s, E0, F0, F0s, G0, G0s, A0, A0s, B0,
	C1, C1s, D1, D1s, E1, F1, F1s, G1, G1s, A1, A1s, B1,
	C2, C2s, D2, D2s, E2, F2, F2s, G2, G2s, A2, A2s, B2,
	C3, C3s, D3, D3s, E3, F3, F3s, G3, G3s, A3, A3s, B3,
	C4, C4s, D4, D4s, E4, F4, F4s, G4, G4s, A4, A4s, B4,
	C5, C5s, D5, D5s, E5, F5, F5s, G5, G5s, A5, A5s, B5,
	C6, C6s, D6, D6s, E6, F6, F6s, G6, G6s, A6, A6s, B6,
	C7, C7s, D7, D7s, E7, F7, F7s, G7, G7s, A7, A7s, B7,
	C8, C8s, D8, D8s, E8, F8, F8s, G8, G8s, A8, A8s, B8
}			t_note;

typedef enum e_scale
{
	MAJOR_PENTATONIC,
	MINOR_PENTATONIC,
	MAJOR_HARMONIC,
	MINOR_MELODIC_ASCENDING,
	IONIAN,
	DORIAN,
	PHRYGIAN,
	LYDIAN,
	MIXOLYDIAN,
	AEOLIAN,
	LOCRIAN,
	MINOR_HUNGARIAN
}			t_scale;

typedef	struct	s_data
{
	t_note	tone;
	t_scale	scale;
}				t_data;	


void	write_midi_header(FILE* f, unsigned char smf, unsigned short tracks_nb, unsigned short nbdiv);
void	write_track(FILE *f, t_data *data);

t_note	get_rand_note(t_note tone, t_scale scale);
size_t	get_rand_len(void);
#endif