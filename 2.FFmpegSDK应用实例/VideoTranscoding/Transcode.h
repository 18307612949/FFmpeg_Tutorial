#ifndef _TRANSCODE_H_
#define _TRANSCODE_H_

/*************************************************
	Function:		Init_transcoder
	Description:	��ʼ��ת��������
	Calls:			��
	Called By:		main
	Input:			(int/out)trans_ctx : ת���������Ķ���
	Return:			��
*************************************************/
typedef struct _TranscodingContext TranscodingContext;
void Init_transcoder(TranscodingContext &trans_ctx);

#endif