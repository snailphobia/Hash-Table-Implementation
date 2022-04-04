/* Copyright: [REDACTED], [REDACTED] */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include ".troll.h"
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

typedef struct _list {
    node* head;
    size_t _size;
} list;

typedef struct _object {
    car* obj_v;
    size_t _cnt;
} object;

typedef struct _sloboz{
    size_t _size;
    uint8_t _nmb;
    struct _sloboz* next;
    node* head;
} sloboz;

typedef struct {
    sloboz* head;
    size_t _size;
} sloboz_lt;

typedef struct _tab {
    size_t _size;
    uint8_t (*__f_ch_first)(vid*);
    uint8_t (*__f_ch_size)(vid*);
    list*** list_v;
} tab;

typedef struct {
    size_t _size;
    uint8_t (*__f_ch_first)(void*);
    uint8_t (*__f_ch_size)(void*);
    sloboz_lt** list_v;
} test_tab;


int8_t __abs(int8_t _v);
node* __cr_node(vid* value);
sloboz_lt* __cr_list();
test_tab* __cr_tbl(size_t _size, uint8_t (*__h1_code)(vid*),
                     uint8_t (*__h2_code)(vid*));
int8_t __cml_crit_res(int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*), vid* A, vid* B);
vid __word_strip(car* word);
vid __free(test_tab** TH);
vid __prt_typ_p1(test_tab* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*));
vid __prt_typ_p2(test_tab* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*), int8_t i);
vid __prt_typ_p3(test_tab* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*), int8_t i, int8_t j);
vid __add_v_ord(sloboz* lt, vid* value,
                     int8_t (*__cmp)(vid*, vid*));
vid __swap(sloboz* lt, node* A, node* B);
vid __sort_lt(sloboz* lt, int8_t (*cmp1)(vid*, vid*),
                     int8_t (*cmp2)(vid*, vid*));
vid* __exit_f();

#endif