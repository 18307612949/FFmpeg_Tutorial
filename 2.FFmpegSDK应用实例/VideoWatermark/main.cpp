#include "common.h"
#include "IOFile.h"
#include "DemuxerDecoder.h"
#include "VideoFilter.h"
#include "MuxerEncoder.h"

const int c_maxDecodedFrames = 2000;
const int c_outputTempYUV = 0;

/*************************************************
Function:		hello
Description:	�����ʾ��Ϣ�������и�ʽ
Calls:			��
Called By:		main
Input:			��
Output:			��
Return:			��
*************************************************/
static int hello(IOFileName &files, int argc, char **argv)
{
	if (argc != 3) 
	{
		fprintf(stderr, "usage: %s input_file video_output_file\n", argv[0]);
		return -1;
	}

	files.src_filename = argv[1];
	files.dst_filename = argv[2];

	printf("Watermarking %s to %s.\n", files.src_filename, files.dst_filename);
	return 0;
}


/*************************************************
Function:		main
Description:	��ڵ㺯��
*************************************************/
int main(int argc, char **argv)
{
	int frameCnt = 0;
	IOFileName files = {NULL};

	//�����ʾ��Ϣ
	if(hello(files, argc, argv) < 0)
	{
		printf("Error: Command line format error.\n");
		return -1;
	}

	InputLogInit();
	OutputLogInit();

	//ע��FFMpeg���
	av_register_all();

	//��ʼ���⸴��-������
	if(InitDemuxerDecoder(files.src_filename, c_outputTempYUV) < 0)
	{
		goto end;
	}
	if (InitFramePacket() < 0)
	{
		goto end;
	}

	//��ʼ����Ƶ�˾�
	if (Init_video_filters(GetAVCodecContextAddress()))
	{
		goto end;
	}

	if (InitMuxerEncoder(files.dst_filename, GetAVCodecContextAddress(), GetInputVideoStreamStruct()))
	{
		goto end;
	}

	//�⸴��-����ѭ��
	while(ReadFramesFromFile())
	{
		if (DecodeOutFrames(c_outputTempYUV, AVFrame_filter_callback, FetchAVFrameToEncoder))
		{
			EncodeOneFrame();
		}
	}

end:
	InputLogEnd();
	OutputLogEnd();
	CloseDemuxerDecoder();
	Close_video_filters();
	CloseMuxerEncoder();
	return -1;
}