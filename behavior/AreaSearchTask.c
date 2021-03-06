
#include <stdlib.h>
#include <inttypes.h>
#include "struct_defines.h"
#include "conv.h"
#include "AreaSearchTask.h"
#include "SearchTask.h"
#include "AbstractGeometry.h"
#include "Wedge.h"
void lmcp_pp_AreaSearchTask(AreaSearchTask* s) {
    printf("AreaSearchTask{");
    printf("Inherited from SearchTask:\n");
    lmcp_pp_SearchTask(&(s->super));
    printf("SearchArea: ");
    lmcp_pp_AbstractGeometry((s->SearchArea));
    printf("\n");
    printf("ViewAngleList: ");
    printf("[");
    for (uint32_t index = 0; index < s->ViewAngleList_ai.length; index++) {
        lmcp_pp_Wedge((s->ViewAngleList[index]));
        printf(",");
    }
    printf("\n");
    printf("}");
}
size_t lmcp_packsize_AreaSearchTask (AreaSearchTask* i) {
    size_t out = 0;
    out += lmcp_packsize_SearchTask(&(i->super));
    if (i->SearchArea==NULL) {
        out += 1;
    } else {
        out += 15 + lmcp_packsize_AbstractGeometry(i->SearchArea);
    }
    out += 2;
    for (uint32_t index = 0; index < i->ViewAngleList_ai.length; index++) {
        out += 15 + lmcp_packsize_Wedge(i->ViewAngleList[index]);
    }
    return out;
}
size_t lmcp_pack_AreaSearchTask_header(uint8_t* buf, AreaSearchTask* i) {
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
    outb += lmcp_pack_uint32_t(outb, 17);
    outb += lmcp_pack_uint16_t(outb, 3);
    return 15;
}
void lmcp_free_AreaSearchTask(AreaSearchTask* out, int out_malloced) {
    if (out == NULL)
        return;
    lmcp_free_SearchTask(&(out->super), 0);
    if (out->SearchArea != NULL) {
        lmcp_free_AbstractGeometry(out->SearchArea, 1);
    }
    if (out->ViewAngleList != NULL) {
        for (uint32_t index = 0; index < out->ViewAngleList_ai.length; index++) {
            if (out->ViewAngleList[index] != NULL) {
                lmcp_free_Wedge(out->ViewAngleList[index], 1);
            }
        }
        free(out->ViewAngleList);
    }
    if (out_malloced == 1) {
        free(out);
    }
}
void lmcp_init_AreaSearchTask (AreaSearchTask** i) {
    if (i == NULL) return;
    (*i) = calloc(1,sizeof(AreaSearchTask));
    ((lmcp_object*)(*i)) -> type = 17;
}
int lmcp_unpack_AreaSearchTask(uint8_t** inb, size_t *size_remain, AreaSearchTask* outp) {
    if (inb == NULL || *inb == NULL) {
        return -1;
    }
    if (size_remain == NULL || *size_remain == 0) {
        return -1;
    }
    AreaSearchTask* out = outp;
    uint32_t tmp;
    uint16_t tmp16;
    CHECK(lmcp_unpack_SearchTask(inb, size_remain, &(out->super)))
    uint8_t isnull;
    uint32_t objtype;
    uint16_t objseries;
    char seriesname[8];
    CHECK(lmcp_unpack_uint8_t(inb, size_remain, &isnull))
    if (isnull == 0 && inb != NULL) {
        out->SearchArea = NULL;
    } else if (inb != NULL) {
        CHECK(lmcp_unpack_8byte(inb, size_remain, seriesname))
        CHECK(lmcp_unpack_uint32_t(inb, size_remain, &objtype))
        CHECK(lmcp_unpack_uint16_t(inb, size_remain, &objseries))
        lmcp_init_AbstractGeometry(&(out->SearchArea));
        CHECK(lmcp_unpack_AbstractGeometry(inb, size_remain, (out->SearchArea)))
    }
    CHECK(lmcp_unpack_uint16_t(inb, size_remain, &tmp16))
    tmp = tmp16;
    (out)->ViewAngleList = malloc(sizeof(Wedge*) * tmp);
    if (out->ViewAngleList==0) {
        return -1;
    }
    out->ViewAngleList_ai.length = tmp;
    for (uint32_t index = 0; index < out->ViewAngleList_ai.length; index++) {
        uint8_t isnull;
        uint32_t objtype;
        uint16_t objseries;
        char seriesname[8];
        CHECK(lmcp_unpack_uint8_t(inb, size_remain, &isnull))
        if (isnull == 0 && inb != NULL) {
            out->ViewAngleList[index] = NULL;
        } else if (inb != NULL) {
            CHECK(lmcp_unpack_8byte(inb, size_remain, seriesname))
            CHECK(lmcp_unpack_uint32_t(inb, size_remain, &objtype))
            CHECK(lmcp_unpack_uint16_t(inb, size_remain, &objseries))
            lmcp_init_Wedge(&(out->ViewAngleList[index]));
            CHECK(lmcp_unpack_Wedge(inb, size_remain, (out->ViewAngleList[index])))
        }
    }
    return 0;
}
size_t lmcp_pack_AreaSearchTask(uint8_t* buf, AreaSearchTask* i) {
    if (i == NULL) return 0;
    uint8_t* outb = buf;
    outb += lmcp_pack_SearchTask(outb, &(i->super));
    if (i->SearchArea==NULL) {
        outb += lmcp_pack_uint8_t(outb, 0);
    } else {
        outb += lmcp_pack_uint8_t(outb, 1);
        memcpy(outb, "CMASI", 5);
        outb += 5;
        for (size_t j = 5; j < 8; j++, outb++)
            *outb = 0;
        outb += lmcp_pack_uint32_t(outb, 1);
        outb += lmcp_pack_uint16_t(outb, 3);
        outb += lmcp_pack_AbstractGeometry(outb, i->SearchArea);
    }
    outb += lmcp_pack_uint16_t(outb, i->ViewAngleList_ai.length);
    for (uint32_t index = 0; index < i->ViewAngleList_ai.length; index++) {
        if (i->ViewAngleList[index]==NULL) {
            outb += lmcp_pack_uint8_t(outb, 0);
        } else {
            outb += lmcp_pack_uint8_t(outb, 1);
            memcpy(outb, "CMASI", 5);
            outb += 5;
            for (size_t j = 5; j < 8; j++, outb++)
                *outb = 0;
            outb += lmcp_pack_uint32_t(outb, 16);
            outb += lmcp_pack_uint16_t(outb, 3);
            outb += lmcp_pack_Wedge(outb, i->ViewAngleList[index]);
        }
    }
    return (outb - buf);
}
