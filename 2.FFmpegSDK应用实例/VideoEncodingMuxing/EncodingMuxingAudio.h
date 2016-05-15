#ifndef _ENCODING_MUXING_AUDIO_H_
#define _ENCODING_MUXING_AUDIO_H_

#include "common.h"
#include "Stream.h"

void Open_audio(AVFormatContext *oc, AVCodec *codec, OutputStream *ost, AVDictionary *opt_arg);

int Write_audio_frame(AVFormatContext *oc, OutputStream *ost);

/*************************************************
	Function:		Add_Audio_stream
	Description:	����ļ������һ·��Ƶ��
	Calls:			��
	Called By:		main
	Input:			(in/out)audioStream : ����ӵ���Ƶ��
					(in/out)oc : ��Ƶ�ļ����
					(in/out)codec��������ʵ��
					(in)codec_id��������ID
	Output:			��
	Return:			����ִ�д�����
*************************************************/
int Add_Audio_stream(AVStream **audioStream, AVFormatContext *oc, AVCodec **codec, enum AVCodecID codec_id);


/*************************************************
	Function:		Set_audio_stream
	Description:	������Ƶ�����Ĳ�����ȫ������Ĭ������
	Calls:			��
	Called By:		main
	Input:			��
	Output:			��
	Return:			��
*************************************************/
void Set_audio_stream(AVStream **audioStream, const AVCodec *codec);
#endif