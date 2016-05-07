#include "common.h"
#include "FileIO.h"

static AVFormatContext *ifmt_ctx = NULL;
static AVFormatContext *ofmt_ctx = NULL;

/*************************************************
	Function:		Open_input_file
	Description:	�������ļ�
	Calls:			��
	Called By:		main
	Input:			(in) FileInOut &files : ���������ļ���									
	Output:			��
	Return:			true : ���ļ��ɹ�
					false : ���ļ�ʧ��
*************************************************/
bool Open_input_file(FileInOut &files)
{
	int ret = 0;
	
	//������ļ������������е�����Ϣ
	if ((ret = avformat_open_input(&ifmt_ctx, files.inputFileName, NULL, NULL)) < 0)
	{
		printf("Error: Open input file failed.\n");
		return false;
	}
	if ((ret = avformat_find_stream_info(ifmt_ctx, NULL)) < 0)
	{
		printf("Error: Cannot find stream info.\n");
		return false;
	}

	//��������Ƶ�ļ��еĸ��ֽ�����
	AVStream *stream = NULL;
	AVCodecContext *codecCtx = NULL;
	for (int streamIdx = 0; streamIdx < ifmt_ctx->nb_streams; streamIdx++)
	{
		stream = ifmt_ctx->streams[streamIdx];
		codecCtx = stream->codec;

		if (codecCtx->codec_type == AVMEDIA_TYPE_VIDEO || codecCtx->codec_type == AVMEDIA_TYPE_AUDIO)
		{
			if ((ret = avcodec_open2(codecCtx, avcodec_find_decoder(codecCtx->codec_id), NULL)) < 0)
			{
				printf("Error: Open decoder for stream %d failed.\n", streamIdx);
				return false;
			}
		}
	}

	return true;
}
