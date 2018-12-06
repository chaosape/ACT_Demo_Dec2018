 #include <tb_PROC_HW_types.h>
 #include <assert.h>
 void init(const int64_t * in_arg) {
 	SW__Command_Impl dummy;
 	printf("RDIO:> Sending command.\n");
 	assert(tb_recv_map_out_enqueue(&dummy)==true);
 }