#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "ascii_tbl_mgt.h"

#define FILE_NAME "msg.txt"

/*********************************
*   define prototype
**********************************/
/*
*   local variable
*/
ascii_mgt_hdl ascii_hdl;

void file_parse(const char *p_filename)
{
    FILE *fp = fopen(p_filename, "r");
    int c;

    if (fp) {
        do {
            c = fgetc(fp);
            if (c == EOF) {
                break;
            }

            printf("read: %c\n", c);

            ascii_mgt_ch_push(ascii_hdl, (char)c);
        } while(1);

        fclose(fp);
    }


    printf("non_repetitive_num = %d\n", ascii_mgt_ch_none_repetitive_num_get(ascii_hdl));
    printf("total_num = %d\n", ascii_mgt_ch_total_num_get(ascii_hdl));
    ascii_mgt_ch_push_finish(ascii_hdl);

    for (int i = 0; i < ascii_mgt_ch_none_repetitive_num_get(ascii_hdl); i++) {
        printf("tbl[%d] = %c <repetitive(%d)>\n", i, ascii_mgt_ch_get(ascii_hdl, i), ascii_mgt_ch_num_get(ascii_hdl, i));
    }
}


int main(void)
{
    ascii_hdl = ascii_mgt_init();
    file_parse(FILE_NAME);

    ascii_mgt_deinit(&ascii_hdl);
    return 0;
}