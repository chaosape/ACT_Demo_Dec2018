 #include <tb_PROC_HW_types.h>
 void radio_driver_component_init(const int64_t * in_arg) {
 	SW__Command_Impl dummy;
 	printf("RDIO:> Sending command.\n");
 	tb_recv_map_out_enqueue(&dummy);
 }