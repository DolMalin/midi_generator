#include "main.h"

static char	**get_scale_pattern(t_scale scale)
{
	char	**output;

	switch(scale)
	{
		case MAJOR_PENTATONIC :
			output = ft_split("W-W-3H-W-3H", '-');
			break;
		case MINOR_PENTATONIC :
			output = ft_split("3H-W-W-3H-W", '-');
			break;
		case MAJOR_HARMONIC :
			output = ft_split("W-W-H-W-H-3H-H", '-');
			break;
		case MINOR_MELODIC_ASCENDING :
			output = ft_split("W-H-W-W-W-W-H", '-');
			break;
		case IONIAN :
			output = ft_split("W-W-H-W-W-W-H", '-');
			break;
		case DORIAN :
			output = ft_split("W-H-W-W-W-H-W", '-');
			break;
		case PHRYGIAN :
			output = ft_split("H-W-W-W-H-W-W", '-');
			break;
		case LYDIAN :
			output = ft_split("W-W-W-H-W-W-H", '-');
			break;
		case MIXOLYDIAN :
			output = ft_split("W-W-H-W-W-H-W", '-');
			break;
		case AEOLIAN :
			output = ft_split("W-H-W-W-H-W-W", '-');
			break;
		case LOCRIAN :
			output = ft_split("H-W-W-H-W-W-W", '-');
			break;
		case MINOR_HUNGARIAN :
			output = ft_split("W-H-3H-H-H-3H-H", '-');
			break;
	}
	if (!output)
		return (NULL);
	return (output);
}

static int	interval_to_int(char *interval)
{
	if (ft_isdigit((int)interval[0]))
	{
		if (interval[1] == 'H')
			return (ft_atoi(interval));
		return (ft_atoi(interval) * 2);
	}
	if (interval[0] == 'H')	
		return (1);
	return (2);
}

static size_t	get_scale_len(char **pattern)
{
	size_t	i;

	i = 0;
	while (pattern[i])
		i++;
	return (i);
}

static t_note	*get_scale(t_note start, char **pattern)
{
	t_note	*output;
	size_t	len;
	size_t	i;
	size_t	count;

	i = 0;
	len = get_scale_len(pattern);
	output = ft_calloc(len + 1, sizeof(t_note));
	count = start;
	while (i < len)
	{
		if (i == 0)
			output[i] = start;
		else
		{
			output[i] = count + interval_to_int(pattern[i - 1]);
			count += interval_to_int(pattern[i - 1]);
		}
		i++;
	}
	return (output);	
}

t_note	get_rand_note(t_note tone, t_scale scale)
{
	t_note	*scale_array;
	char	**pattern;
	size_t	n;
	t_note	note;

	pattern = get_scale_pattern(scale);
	scale_array = get_scale(tone, pattern);
	n = rand() % get_scale_len(pattern);
	note = scale_array[n];
	ft_free_tab((void **)pattern);
	free(scale_array);
	return (note);
}

size_t	get_rand_len(void)
{
	size_t	n;

	n = rand() % 100;
	if (n < 10)
		return (NOIRE / 4);
	else if (n < 30)
		return (NOIRE / 2);
	else if ( n < 80)
		return (NOIRE);
	else
		return (NOIRE * 2);
}