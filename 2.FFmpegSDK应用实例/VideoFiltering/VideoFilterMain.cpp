#include "common.h"


/*************************************************
	Function:		hello
	Description:	���������д���Ĳ���
	Calls:			��
	Called By:		main
	Input:			(in)argc : Ĭ�������в���
					(in)argv : Ĭ�������в���					
	Output:			(out)files : ���������еĽ��
	Return:			true : �����н�����ȷ
					false : �����н�������
*************************************************/
static bool hello(int argc, char **argv, IOFiles &files)
{
	printf("FFMpeg Filtering Demo.\nCommand format: %s inputfile outputfile logofile\n", argv[0]);
	if (argc != 4)
	{
		printf("Error: command line error, please re-check.\n");
		return false;
	}

	files.inputName = argv[1];
	files.outputName = argv[2];
	files.logoName = argv[3];
	return true;
}

/*************************************************
Function:		main
Description:	��ڵ㺯��
*************************************************/
const char *filter_descr = "movie=logo.png[wm];[in][wm]overlay=5:5[out]";

int main(int argc, char **argv)
{
	IOFiles files = { NULL };
	if (!hello(argc, argv, files))
	{
		return -1;
	}

	av_register_all();
	if (init_filters(filter_descr) < 0)
	{
		return -1;
	}

	return 0;
}