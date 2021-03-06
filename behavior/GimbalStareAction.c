
#include <stdlib.h>
#include <inttypes.h>
#include "struct_defines.h"
#include "conv.h"
#include "GimbalStareAction.h"
#include "PayloadAction.h"
#include "Location3D.h"
void lmcp_pp_GimbalStareAction(GimbalStareAction* s) {
    printf("GimbalStareAction{");
    printf("Inherited from PayloadAction:\n");
    lmcp_pp_PayloadAction(&(s->super));
    printf("Starepoint: ");
    lmcp_pp_Location3D((s->Starepoint));
    printf("\n");
    printf("Duration: ");
    printf("%lld",s->Duration);
    printf("\n");
    printf("}");
}
size_t lmcp_packsize_GimbalStareAction (GimbalStareAction* i) {
    size_t out = 0;
    out += lmcp_packsize_PayloadAction(&(i->super));
    if (i->Starepoint==NULL) {
        out += 1;
    } else {
        out += 15 + lmcp_packsize_Location3D(i->Starepoint);
    }
    out += sizeof(int64_t);
    return out;
}
size_t lmcp_pack_GimbalStareAction_header(uint8_t* buf, GimbalStareAction* i) {
    uint8_t* outb = buf;
    if (i == NULL) {
        lmcp_pack_uint8_t(outb, 0);
        return 1;
    }
    outb += lmcp_pack_uint8_t(outb, 1);
    memcpy(outb, "CMASI", 5);
    outb += 5;
    for (size_t j = 5; j < 8; j++, outb++)
        *outb = 0;
    outb += lmcp_pack_uint32_t(outb, 26);
    outb += lmcp_pack_uint16_t(outb, 3);
    return 15;
}
void lmcp_free_GimbalStareAction(GimbalStareAction* out, int out_malloced) {
    if (out == NULL)
        return;
    lmcp_free_PayloadAction(&(out->super), 0);
    if (out->Starepoint != NULL) {
        lmcp_free_Location3D(out->Starepoint, 1);
    }
    if (out_malloced == 1) {
        free(out);
    }
}
void lmcp_init_GimbalStareAction (GimbalStareAction** i) {
    if (i == NULL) return;
    (*i) = calloc(1,sizeof(GimbalStareAction));
    ((lmcp_object*)(*i)) -> type = 26;
}
int lmcp_unpack_GimbalStareAction(uint8_t** inb, size_t *size_remain, GimbalStareAction* outp) {
    if (inb == NULL || *inb == NULL) {
        return -1;
    }
    if (size_remain == NULL || *size_remain == 0) {
        return -1;
    }
    GimbalStareAction* out = outp;
    CHECK(lmcp_unpack_PayloadAction(inb, size_remain, &(out->super)))
    uint8_t isnull;
    uint32_t objtype;
    uint16_t objseries;
    char seriesname[8];
    CHECK(lmcp_unpack_uint8_t(inb, size_remain, &isnull))
    if (isnull == 0 && inb != NULL) {
        out->Starepoint = NULL;
    } else if (inb != NULL) {
        CHECK(lmcp_unpack_8byte(inb, size_remain, seriesname))
        CHECK(lmcp_unpack_uint32_t(inb, size_remain, &objtype))
        CHECK(lmcp_unpack_uint16_t(inb, size_remain, &objseries))
        lmcp_init_Location3D(&(out->Starepoint));
        CHECK(lmcp_unpack_Location3D(inb, size_remain, (out->Starepoint)))
    }
    CHECK(lmcp_unpack_int64_t(inb, size_remain, &(out->Duration)))
    return 0;
}
size_t lmcp_pack_GimbalStareAction(uint8_t* buf, GimbalStareAction* i) {
    if (i == NULL) return 0;
    uint8_t* outb = buf;
    outb += lmcp_pack_PayloadAction(outb, &(i->super));
    if (i->Starepoint==NULL) {
        outb += lmcp_pack_uint8_t(outb, 0);
    } else {
        outb += lmcp_pack_uint8_t(outb, 1);
        memcpy(outb, "CMASI", 5);
        outb += 5;
        for (size_t j = 5; j < 8; j++, outb++)
            *outb = 0;
        outb += lmcp_pack_uint32_t(outb, 3);
        outb += lmcp_pack_uint16_t(outb, 3);
        outb += lmcp_pack_Location3D(outb, i->Starepoint);
    }
    outb += lmcp_pack_int64_t(outb, i->Duration);
    return (outb - buf);
}
