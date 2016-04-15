#include "VideoDemuxing.h"

int Application_demuxing_start(IOFileName &files, DemuxingVideoAudioContex &demux_ctx)
{
	if (InitDemuxContext(files, demux_ctx) < 0)	//��ʼ���⸴�������Ľṹ�壬����ע�����������������ļ�����������Ƶ����
	{		
		return -1;
	}

	demux_ctx.frame = av_frame_alloc();			//����AVFrame�ṹ����
	if (!demux_ctx.frame)
	{
		fprintf(stderr, "Could not allocate frame\n");
		return -1;		
	}

	/* initialize packet, set data to NULL, let the demuxer fill it */
	av_init_packet(&demux_ctx.pkt);				//��ʼ��AVPacket����
	demux_ctx.pkt.data = NULL;
	demux_ctx.pkt.size = 0;

	return 0;
}

void Application_demuxing_end(IOFileName &files, DemuxingVideoAudioContex &demux_ctx)
{
	CloseDemuxContext(files, demux_ctx);
}
