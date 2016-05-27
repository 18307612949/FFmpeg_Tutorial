#ifndef _COMMON_H_
#define _COMMON_H_

#include "VideoFilterHeader.h"
#include "VideoFilter.h"
#include "ClassFrame.h"
#include "Encoder.h"

//��������ļ��ṹ
typedef struct _IOFiles
{
	const char *inputName;
	const char *outputName;
	const char *logoName;

	FILE *outputFile;
} IOFiles;

#endif