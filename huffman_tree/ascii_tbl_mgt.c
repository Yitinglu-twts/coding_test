#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ascii_tbl_mgt.h"

#define DO_PRAGMA(x) _Pragma (#x)
#define TODO(x) DO_PRAGMA(message ("TODO - " #x))
/*
*   define prototype
*/
typedef struct ascii_ch_info_t {
    int repeat_num;
    char ch;
} ascii_ch_info_t;

typedef struct ascii_mgt_func_t {
    void (*sort) (ascii_ch_info_t *p_data, uint32_t num);
} ascii_mgt_func_t;



typedef struct ascii_mgt_hdl {
    ascii_mgt_func_t func;
    ascii_ch_info_t ascii_ch[ASCII_TBL_SIZE];
    uint32_t none_repetive_num;
    uint32_t total_num;
} ascii_mgt_hdl_t;

/*
*   local variable
*/
int ascii_mgt_ch_push(ascii_mgt_hdl hdl, char ch)
{
    if (hdl->ascii_ch[(uint8_t)ch].repeat_num++ == 0) {
        hdl->none_repetive_num++;
        hdl->ascii_ch[(uint8_t)ch].ch = ch;
    }
    hdl->total_num++;
    return hdl->total_num;
}

void ascii_mgt_ch_push_finish(ascii_mgt_hdl hdl)
{
    int unused_idx = 0;
    for (int i = 0; i < ASCII_TBL_SIZE; i++) {
        if (hdl->ascii_ch[i].repeat_num != 0) {
            hdl->ascii_ch[unused_idx] = hdl->ascii_ch[i];
            unused_idx++;
            /* clear content, it has been moved forward */
            memset(&hdl->ascii_ch[i], 0, sizeof(hdl->ascii_ch[0]));
        }
    }
}

char ascii_mgt_ch_get(ascii_mgt_hdl hdl, int idx)
{
    return hdl->ascii_ch[idx].ch;
}

int ascii_mgt_ch_num_get(ascii_mgt_hdl hdl, int idx)
{
    return hdl->ascii_ch[idx].repeat_num;
}

int ascii_mgt_ch_total_num_get(ascii_mgt_hdl hdl)
{
    return hdl->total_num;
}

int ascii_mgt_ch_none_repetitive_num_get(ascii_mgt_hdl hdl)
{
    return hdl->none_repetive_num;
}

void merge_sort(ascii_ch_info_t *p_data, uint32_t num)
{

}

ascii_mgt_hdl ascii_mgt_init(void)
{
    ascii_mgt_hdl hdl = (ascii_mgt_hdl) malloc(sizeof(struct ascii_mgt_hdl));
    if (hdl) {
        memset(hdl, 0, sizeof(struct ascii_mgt_hdl));

        TODO(implement sorting function!!)
        hdl->func.sort = merge_sort;
    }
    return hdl;
}

void ascii_mgt_deinit(ascii_mgt_hdl *hdl)
{
    free(*hdl);
    *hdl = NULL;
}
