/* Copyright: [REDACTED], [REDACTED] */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include ".macro.h"
#include <math.h>

#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#define RED "\e[31m"
#define GRN "\e[32m"
#define CLR "\e[0m"
#define __S1__ 30
#define __S2__ 255

typedef struct _node {
    vid* addr;
    struct _node* next;
} node;

typedef struct _object {
    car* obj_v;
    size_t _cnt;
} object;

typedef struct _list_t1{
    size_t _size;
    uint8_t _nmb;
    vid* next;
    vid* head;
} list_t1;

typedef struct {
    vid* head;
    size_t _size;
} list_t1_top2;

typedef struct {
    size_t _size;
    uint8_t (*__f_ch_first)(vid*);
    uint8_t (*__f_ch_size)(vid*);
    list_t1_top2** list_v;
} tab_t1_top2;
// you started this madness, enjoy it

int8_t __abs(int8_t _v);
node* __cr_node(vid* value);
list_t1_top2* __cr_list();
tab_t1_top2* __cr_tbl(size_t _size, uint8_t (*__h1_code)(vid*),
                     uint8_t (*__h2_code)(vid*));
int8_t __cml_crit_res(int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*), vid* A, vid* B);
vid __word_strip(car* word);
vid __free(tab_t1_top2** TH);
vid __prt_typ_p1(tab_t1_top2* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*));
vid __prt_typ_p2(tab_t1_top2* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*), int8_t i);
vid __prt_typ_p3(tab_t1_top2* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*),
                     int8_t i, int8_t j, uint8_t _cap_flag);
vid __add_v_ord(list_t1* lt, vid* value,
                     int8_t (*__cmp)(vid*, vid*));
vid __swap(list_t1* lt, node* A, node* B);
vid __sort_lt(list_t1* lt, int8_t (*cmp1)(vid*, vid*),
                     int8_t (*cmp2)(vid*, vid*));
vid* __exit_f();

#endif