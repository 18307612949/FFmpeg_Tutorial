#ifndef _TRANSCODE_H_
#define _TRANSCODE_H_

/*************************************************
	Function:		Init_transcoder
	Description:	��ʼ��ת��������
	Calls:			��
	Called By:		main
	Input:			(in)argc : Ĭ�������в���
					(in)argv : Ĭ�������в���					
	Output:			(out)files : ��������ļ�����
	Return:			true : �����н�����ȷ
					false : �����н�������
*************************************************/
typedef struct _TranscodingContext TranscodingContext;
void Init_transcoder(TranscodingContext &trans_ctx);

#endif