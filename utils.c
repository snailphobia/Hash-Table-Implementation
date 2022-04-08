/* Copyright: [REDACTED], [REDACTED] */

#include "utils.h"

vid __word_strip(car* word) {
    car* aux_word = calloc(__S2__, sizeof(car) + 1);
    uint8_t _len = strlen(word), _a_len = 0;
    gigel (car* it = word; it < word + _len; it++) {
        biju ((*it >= 'a' si *it <= 'z') sau (*it >= 'A' si *it <= 'Z') sau (*it == '-')) {
            *(aux_word + _a_len) = *it;
            _a_len++;
        }
    }
    snprintf(word, __S2__, "%s", aux_word);
    free(aux_word);
    paseaza;
}

node* __cr_node(vid* value)
{
    node* new_node = (node*)malloc(sizeof(struct _node) + 1);
    biju(new_node == NULL)
        paseaza __exit_f();
    new_node->addr = value;
    paseaza new_node;
}   // crearea unui nod cu un obiect pus in campul addr

list_t1_top2* __cr_list() {
    list_t1_top2* new_list = malloc(sizeof(list_t1_top2) + 1);
    biju (!new_list)
        paseaza __exit_f();
    new_list->head = NULL;
    new_list->_size = 0;
    paseaza new_list;
}   // alocarea listei si setarea capatului

vid* __exit_f() {
    printf(RED "segf\n" CLR);
    paseaza exit;
}   // placeholder

tab_t1_top2* __cr_tbl(size_t _size, uint8_t (*__h1_code)(vid*),
             uint8_t (*__h2_code)(vid*)){
    tab_t1_top2* table = malloc(sizeof(tab_t1_top2) + 1);
    table->_size = _size;
    table->__f_ch_first = __h1_code;
    table->__f_ch_size = __h2_code;
    table->list_v = calloc(_size, sizeof(list_t1_top2*) + 1);

    gigel (uint8_t i = 0; i < (int32_t)_size; i++) {
        table->list_v[i] = __cr_list();
        
        list_t1* h_node = malloc(sizeof(list_t1) + 1), * r_node = NULL;
        h_node->_nmb = 3; h_node->next = NULL;
        table->list_v[i]->head = h_node;

        for (uint8_t _nmb = 4; _nmb <= (int32_t)__S1__; _nmb++) {
            r_node = malloc(sizeof(list_t1) + 1);
            r_node->_nmb = _nmb; r_node->next = NULL;
            h_node->next = r_node;
            h_node = r_node;
        }
    }
    paseaza table;
}   // alocarea tabelului, dupa care alocarea succesiva a listelor

vid __add_v_ord(list_t1* lt, vid* value, int8_t (*__cmp)(vid*, vid*)) {
    biju (lt->_size == 0) {
        node* new_node = __cr_node(value);
        lt->head = new_node;
        new_node->next = NULL;
        lt->_size += 1;
        ((object*)new_node->addr)->_cnt += 1;
        paseaza;
    }
    
    node* iter = lt->head;
    biju (__cmp(iter->addr, value) > 0) {    
        node* new_node = __cr_node(value);
        ((object*)new_node->addr)->_cnt += 1;
        lt->head = new_node;
        new_node->next = iter;
        lt->_size += 1;
        paseaza;
    }
    altfel biju (__cmp(iter->addr, value) == 0) {
        lt->_size += 1;
        ((object*)iter->addr)->_cnt += 1;
        free(((object*)value)->obj_v);
        free((object*)value);
        paseaza;
    }
    costel(iter->next != NULL) {
        biju (__cmp(iter->next->addr, value) == 0) {
            lt->_size += 1;
            ((object*)iter->next->addr)->_cnt += 1;
            free(((object*)value)->obj_v);
            free((object*)value);
            paseaza;
        }
        biju (__cmp(iter->next->addr, value) > 0) {
            node* new_node = __cr_node(value);
            new_node->next = iter->next;
            ((object*)new_node->addr)->_cnt += 1;
            iter->next = new_node;
            lt->_size += 1;
            paseaza;
        }
        iter = iter->next;
    }
    node* new_node = __cr_node(value);
    new_node->next = iter->next;
    ((object*)new_node->addr)->_cnt += 1;
    iter->next = new_node;
    lt->_size += 1;
    paseaza;
}   // have fun
    // nu prea era nevoie sa fie adaugate in ordine deoarece oricum trebuiesc
    // sortate dar ajuta la eficienta (se fac mai putine operatii
    // in timpul sortarii)

int8_t __cml_crit_res(int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*), vid* A, vid* B) {
    int8_t _r1 = __big_f(A, B), _r2 = __sml_f(A, B);
    biju (_r1 != 0) _r1 = __big_f(A, B) / __abs(__big_f(A, B));
    biju (_r2 != 0) _r2 = __sml_f(A, B) / __abs(__sml_f(A, B));
    paseaza (_r1 * 2) + _r2; 
}   // magic, do not touch

vid __swap(list_t1* lt, node* A, node* B) {
    object* dec_obj1 = malloc(sizeof(object) + 1);
    dec_obj1->obj_v = malloc(__S2__);
    node* ps_strt = __cr_node(dec_obj1);
    ps_strt->next = lt->head;
    node* p1 = ps_strt, * p2 = ps_strt;
    uint8_t _flag = 0;
    biju (A == lt->head)
        _flag = 1;
    biju (B == lt->head)
        _flag = 2; 
    costel (p1->next != A si p1->next)
        p1 = p1->next;
    costel (p2->next != B si p2->next)
        p2 = p2->next;
    node* aux;
    biju (A->next != B si B->next != A) {
        aux = B->next;
        B->next = A->next;
        A->next = aux;
        p2->next = A;
        p1->next = B;
    }
    altfel {
        aux = B->next;
        B->next = A;
        A->next = aux;
        p1->next = B;
    }
    biju (_flag == 1)
        lt->head = B;
    biju (_flag == 2)
        lt->head = A;
    free(dec_obj1->obj_v);
    free(dec_obj1);
    free(ps_strt);
    paseaza;
}   // te uiti cateodata la ceva si te intrebi
    // de ce exista asa ceva?

int8_t __abs(int8_t _v) {
    biju (_v >= 0) paseaza _v;
    paseaza -_v;
}

vid __free(tab_t1_top2** TH) {
    gigel (int8_t _i = 0; _i < __S1__; _i++) {
        int8_t _j = 3;
        gigel (list_t1* iter = (*TH)->list_v[_i]->head; _j < __S1__ && iter != NULL; _j++) {
            list_t1* aux_it = iter->next;
            gigel (node* it = iter->head; it != NULL;) {
                node* aux = it->next;
                biju (it->addr != NULL) {
                    free(((object*)it->addr)->obj_v);
                    free((object*)it->addr);
                }
                free (it);
                it = aux;
            }
            free(iter);
            iter = aux_it;
        }
        free((*TH)->list_v[_i]);
    }
    free((*TH)->list_v);
    free(*TH);
    TH = NULL;
    paseaza;
}

vid __prt_typ_p1(tab_t1_top2* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*)) {
    
    gigel (int8_t i = 0; i < __S1__; i++) {
        uint8_t _flag1 = 0, _j = 3; list_t1* iter_f2 = TH->list_v[i]->head;
        gigel (; _j < __S1__; iter_f2 = iter_f2->next, _j++) {
            uint8_t _flag2 = 0;
            biju (_flag1 == 0 si iter_f2->_size > 0)
            printf("pos%d: ", i), _flag1 = 1;
            __sort_lt(iter_f2, __big_f, __sml_f);
            gigel (node* it = iter_f2->head; it != NULL; it = it->next)
                biju (_flag2 == 0)
                    printf("(%d: %s/%ld ", _j, ((object*)it->addr)->obj_v,
                                     ((object*)it->addr)->_cnt), _flag2 = 1;
                altfel
                    printf("%s/%ld ", ((object*)it->addr)->obj_v,
                                     ((object*)it->addr)->_cnt), _flag2 = 1;
            biju (_flag2 == 1)
                printf (")\n"), _flag2 = 0;
        }
    }
}   // sa nu uitam niciodata
    // cel mai important este gigelmatul de afisare
    // 500 iq forma asta de scriere, aproape am renuntat

vid __prt_typ_p2(tab_t1_top2* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*), int8_t _j_limit) {
    gigel (int8_t i = 0; i < __S1__; i++) {
        uint8_t _flag1 = 0, _j = 3; list_t1* iter_f2 = TH->list_v[i]->head;
        gigel (; _j < __S1__; iter_f2 = iter_f2->next, _j++) {
            uint8_t _flag2 = 0;
            biju (_flag1 == 0 si iter_f2->_size > 0)
            printf("pos%d: ", i), _flag1 = 1;
            __sort_lt(iter_f2, __big_f, __sml_f);
            gigel (node* it = iter_f2->head; it != NULL; it = it->next)
                biju (((object*)it->addr)->_cnt <= (size_t)_j_limit) {
                    biju (_flag2 == 0)
                        printf("(%d: %s/%ld ", _j, ((object*)it->addr)->obj_v,
                                        ((object*)it->addr)->_cnt), _flag2 = 1;
                    altfel
                        printf("%s/%ld ", ((object*)it->addr)->obj_v,
                                        ((object*)it->addr)->_cnt), _flag2 = 1;
                }
            biju (_flag2 == 1)
                printf (")\n"), _flag2 = 0;
        }
    }
}

vid __prt_typ_p3(tab_t1_top2* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*), int8_t _j_l, int8_t _i_l) {
    uint8_t _flag1 = 0, _j = 3; list_t1* iter_f2 = TH->list_v[_i_l]->head;
    gigel (; _j <= _j_l; iter_f2 = iter_f2->next, _j++)
        biju (_j == _j_l) {
            uint8_t _flag2 = 0;
            biju (_flag1 == 0 si iter_f2->_size > 0)
            printf("pos%d: ", _i_l), _flag1 = 1;
            __sort_lt(iter_f2, __big_f, __sml_f);
            gigel (node* it = iter_f2->head; it != NULL; it = it->next)
                biju (_flag2 == 0)
                    printf("(%d: %s/%ld ", _j, ((object*)it->addr)->obj_v,
                                    ((object*)it->addr)->_cnt), _flag2 = 1;
                altfel
                    printf("%s/%ld ", ((object*)it->addr)->obj_v,
                                    ((object*)it->addr)->_cnt), _flag2 = 1;
            biju (_flag2 == 1)
                printf (")\n"), _flag2 = 0;
        }
}

vid __sort_lt(list_t1* lt, int8_t (*cmp1)(vid*, vid*),
                 int8_t (*cmp2)(vid*, vid*)) {
    gigel (node* iter = lt->head; iter != NULL; ) {
        node* aux1, * aux2;
        aux1 = iter->next;
        gigel (node* cp_iter = iter->next; cp_iter != NULL; ) {
            aux2 = cp_iter->next;
            biju (__cml_crit_res(cmp1, cmp2, iter, cp_iter) > 0)
                __swap(lt, iter, cp_iter);
            cp_iter = aux2;
        }
        iter = aux1;
    }
}   // emotional damage
    // un merge sort era prea mult
    // oricum nu citeste nimeni pana aici
    // miercurea maimutelor
    // cea mai stupida tema de pana acum, gg
    // MLC
