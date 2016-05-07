#ifndef _FILE_IO_H_
#define _FILE_IO_H_

typedef struct _FileInOut
{
	const char *inputFileName;
	const char *outputFileName;
} FileInOut;

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
bool Open_input_file(FileInOut &files);

/*************************************************
	Function:		Open_Output_file
	Description:	������ļ�
	Calls:			��
	Called By:		main
	Input:			(in) FileInOut &files : ���������ļ���									
	Output:			��
	Return:			true : ���ļ��ɹ�
					false : ���ļ�ʧ��
*************************************************/
bool Open_output_file(FileInOut &files);

#endif