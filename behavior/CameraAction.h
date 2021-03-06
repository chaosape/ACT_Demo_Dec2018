
#pragma once
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "struct_defines.h"
#include "conv.h"
#include "PayloadAction.h"
#define LMCP_CameraAction_SUB "afrl.cmasi.CameraAction"

#define LMCP_CameraAction_TYPENAME "CameraAction"

#define LMCP_CameraAction_TYPE 18

typedef struct {
    PayloadAction super;
// Units: degree
    float HorizontalFieldOfView;

} CameraAction;
void lmcp_pp_CameraAction(CameraAction* s);
size_t lmcp_packsize_CameraAction (CameraAction* i);
size_t lmcp_pack_CameraAction_header(uint8_t* buf, CameraAction* i);
void lmcp_free_CameraAction(CameraAction* i, int out_malloced);
void lmcp_init_CameraAction (CameraAction** i);
int lmcp_unpack_CameraAction(uint8_t** buf, size_t *size_remain,CameraAction* outp);
size_t lmcp_pack_CameraAction(uint8_t* buf, CameraAction* i);
