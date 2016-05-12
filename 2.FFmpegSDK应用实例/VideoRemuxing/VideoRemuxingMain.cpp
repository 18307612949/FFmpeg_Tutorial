#include "common.h"

/*************************************************
	Function:		hello
	Description:	���������д���Ĳ���
	Calls:			��
	Called By:		main
	Input:			(in)argc : Ĭ�������в���
					(in)argv : Ĭ�������в���					
	Output:			(out)io_param : ���������еĽ��
	Return:			true : �����н�����ȷ
					false : �����н�������
*************************************************/
static bool hello(int argc, char **argv, IOFiles &io_param)
{
	printf("FFMpeg Remuxing Demo.\nCommand format: %s inputfile outputfile\n", argv[0]);
	if (argc != 3)
	{
		printf("Error: command line error, please re-check.\n");
		return false;
	}

	io_param.inputName = argv[1];
	io_param.outputName = argv[2];

	return true;
}


/*************************************************
Function:		main
Description:	��ڵ㺯��
*************************************************/
int main(int argc, char **argv)
{
	IOFiles io_param;
	if (!hello(argc, argv, io_param))
	{
		return -1;
	}

	AVOutputFormat *ofmt = NULL;
	AVFormatContext *ifmt_ctx = NULL, *ofmt_ctx = NULL;
	AVPacket pkt;
	int ret = 0;

	av_register_all();

	if ((ret = avformat_open_input(&ifmt_ctx, io_param.inputName, NULL, NULL)) < 0)
	{
		printf("Error: Open input file failed.\n");
		goto end;
	}
	if ((ret = avformat_find_stream_info(ifmt_ctx, NULL)) < 0)
	{
		printf("Error: Failed to retrieve input stream information.\n");
		goto end;
	}
	av_dump_format(ifmt_ctx, 0, io_param.inputName, 0);

	avformat_alloc_output_context2(&ofmt_ctx, NULL, NULL, io_param.outputName);
	if (!ofmt_ctx)
	{
		printf("Error: Could not create output context.\n");
		goto end;
	}
	ofmt = ofmt_ctx->oformat;

end:
	return 0;
}