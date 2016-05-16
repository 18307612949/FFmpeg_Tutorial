#ifndef _ENCODING_MUXING_VIDEO_H_
#define _ENCODING_MUXING_VIDEO_H_

#include "common.h"
#include "Stream.h"

typedef struct _VideoEncodingParam
{
	int frameWidth;
	int frameHeight;
	int bitRate;
	AVRational timeBase;
	int gopSize;
	int maxBFrames;
	int mbDecision;
} VideoEncodingParam;

typedef struct _IOParam IOParam;
void Open_video(AVFormatContext *oc, AVCodec *codec, OutputStream *ost, AVDictionary *opt_arg, IOParam &io);

int Write_video_frame(AVFormatContext *oc, OutputStream *ost);

/*************************************************
	Function:		Add_video_stream
	Description:	����ļ������һ·��Ƶ��
	Calls:			��
	Called By:		main
	Input:			(in/out)videoStream : ����ӵ���Ƶ��
					(in/out)oc : ��Ƶ�ļ����
					(in/out)codec��������ʵ��
					(in)codec_id��������ID
	Output:			��
	Return:			����ִ�д�����
*************************************************/
int Add_video_stream(AVStream **videoStream, AVFormatContext *oc, AVCodec **codec, enum AVCodecID codec_id);

/*************************************************
	Function:		Set_video_stream
	Description:	������Ƶ�����Ĳ���
	Calls:			��
	Called By:		main
	Input:			(in/out)codecCtx : ��Ƶ����AVCodecContext
					(int)encParam : ��Ƶ�������
	Output:			��
	Return:			��
*************************************************/
void Set_video_stream(AVStream **videoStream, const VideoEncodingParam &encParam);

/*************************************************
	Function:		Open_video_stream
	Description:	����Ƶ����codec��frame���ļ�
	Calls:			��
	Called By:		main
	Input:			(int)codec : ������ɵı�����
	Output:			(in/out)videoStream : ���������Ƶ��
					(in/out)videoFrame : �����������ݵ�frame�ṹ
	Return:			����ִ�д�����
*************************************************/
int Open_video_stream(AVStream **videoStream, AVFrame **videoFrame, AVCodec *codec, IOParam io);

/*************************************************
	Function:		Close_video_stream
	Description:	�ر���Ƶ���ṹ
	Calls:			��
	Called By:		main
	Input:			(in/out)videoStream : Ҫ�رյ����ṹ
					(int)videoFrame : �������ص�֡�ṹ
	Output:			��
	Return:			��
*************************************************/
void Close_video_stream(AVStream **videoStream, AVFrame **videoFrame);

#endif