#include <tb_PROC_HW_types.h>
#include <assert.h>
#include <stdio.h>

void init(const int64_t * in_arg) {
}

static unsigned long i = 2;
static unsigned int pktcnt = 0;
void recv_uartpkt(const SW__UART_Packet_Impl * __unused__) {
	printf("UART:< Packet.\n");
	pktcnt++;
	if(pktcnt == 4) {
		pktcnt = 0;
		for(unsigned int j = 0; j < 100000000; j++){}
		printf("UART:> Sending %lu as the next id.\n", i);
		tb_tracking_id_enqueue(&i);	
		i = i < 70 ? i+1 : 70;
	}
}