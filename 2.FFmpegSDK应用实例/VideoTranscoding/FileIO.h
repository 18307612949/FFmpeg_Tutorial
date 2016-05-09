#ifndef _FILE_IO_H_
#define _FILE_IO_H_

typedef struct _FileInOut
{
	const char *inputFileName;
	const char *outputFileName;
} FileInOut;

typedef struct _TranscodingContext TranscodingContext;
/*************************************************
	Function:		Open_input_file
	Description:	�������ļ�
	Calls:			��
	Called By:		main
	Input:			(in/out) FileInOut &files : ���������ļ���	
					(in/out)trans_ctx : ת���������Ķ���
	Output:			��
	Return:			true : ���ļ��ɹ�
					false : ���ļ�ʧ��
*************************************************/
bool Open_input_file(FileInOut &files, TranscodingContext &trans_ctx);

/*************************************************
	Function:		Open_Output_file
	Description:	������ļ�
	Calls:			��
	Called By:		main
	Input:			(in/out) FileInOut &files : ���������ļ���	
					(in/out)trans_ctx : ת���������Ķ���
	Output:			��
	Return:			true : ���ļ��ɹ�
					false : ���ļ�ʧ��
*************************************************/
bool Open_output_file(FileInOut &files, TranscodingContext &trans_ctx);

/*************************************************
	Function:		Read_packets_from_input_file
	Description:	�������ļ��ж�ȡpacket
	Calls:			��
	Called By:		main
	Input:			(in/out)trans_ctx : ת���������Ķ���
	Output:			��
	Return:			true : ���ļ��ɹ�
					false : ���ļ�ʧ��
*************************************************/
bool Read_packets_from_input_file(TranscodingContext &trans_ctx);
#endif