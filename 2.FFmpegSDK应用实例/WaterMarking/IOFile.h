#ifndef _IOFILE_H_
#define _IOFILE_H_
#include <stdio.h>

/*************************************************
Struct:			IOParam
Description:	���������в���
*************************************************/
typedef struct 
{
	const char *src_filename;
	const char *dst_filename;

	FILE *video_dst_file;
	FILE *audio_dst_file;
	FILE *temp_file;
} IOFileName;

#endif