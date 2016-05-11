#include "common.h"

/*************************************************
	Function:		hello
	Description:	���������д���Ĳ���
	Calls:			��
	Called By:		main
	Input:			(in)argc : Ĭ�������в���
					(in)argv : Ĭ�������в���					
	Output:			(out)files : ��������ļ�����
	Return:			true : �����н�����ȷ
					false : �����н�������
*************************************************/
static bool  hello(int argc, char **argv, FileInOut &files)
{
	printf("FFMpeg Trans Coding Demo:\nCommand line format: %s inputFileName outputFileName.\n", argv[0]);
	if (argc != 3)
	{
		printf("Command line parameters error. Please re-check.\n");
		return false; 
	}

	files.inputFileName = argv[1];
	files.outputFileName = argv[2];

	return true;
}


/*************************************************
Function:		main
Description:	��ڵ㺯��
*************************************************/
int main(int argc, char **argv)
{
	FileInOut files = { NULL };
	unsigned int stream_index = 0;
	enum AVMediaType mediaType = AVMEDIA_TYPE_UNKNOWN;

	if (!hello(argc, argv, files))
	{
		printf("Error: Command line parameters error.\n");
		return -1;
	}

	TranscodingContext transCtx = {NULL};
	Init_transcoder(transCtx);

	if (!Open_input_file(files, transCtx))
	{
		printf("Error: Open input file failed.\n");
		return -1;
	}

	if (!Open_output_file(files, transCtx))
	{
		printf("Error: Open output file failed.\n");
		return -1;
	}

	/* read all packets */
	while (1) 
	{
		if (!Read_packets_from_input_file(transCtx))
		{
			break;
		}

		stream_index = transCtx.packet.stream_index;
		mediaType = transCtx.ifmt_ctx->streams[stream_index]->codec->codec_type;
	}

	return 0;
}