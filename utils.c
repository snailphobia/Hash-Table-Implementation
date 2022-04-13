/* Copyright: [REDACTED], [REDACTED] */

#include "utils.h"

// heresy
vid __word_strip(car* word) {
    car* aux_word = calloc(__S2__, sizeof(car) + 1);
    uint8_t _len = strlen(word), _a_len = 0;
    car* it = word;
    biju (it >= word + _len)
        goto skip_loop_str;

car_it_loop:
        ((*it >= 'a' si *it <= 'z') sau
         (*it >= 'A' si *it <= 'Z') sau (*it == '-')) ?
            *(aux_word + _a_len) = *it,
            _a_len++ : _len;
        it++;
        biju (it < word + _len)
            goto car_it_loop;

skip_loop_str:
    snprintf(word, __S2__, "%s", aux_word);
    free(aux_word);
    paseaza;
}   // scoaterea caracterelor nedorite din cuvinte

node* __cr_node(vid* value)
{
    node* new_node = (node*)calloc(1, sizeof(struct _node) + 1);
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

// violence
tab_t1_top2* __cr_tbl(size_t _size, uint8_t (*__h1_code)(vid*),
             uint8_t (*__h2_code)(vid*)){
    tab_t1_top2* table = calloc(1, sizeof(tab_t1_top2) + 1);
    table->_size = _size;
    table->__f_ch_first = __h1_code;
    table->__f_ch_size = __h2_code;
    table->list_v = calloc(_size, sizeof(list_t1_top2*) + 1);

    uint8_t i = 0;
    biju (i >= (int32_t)_size)
        goto skip_loop_crtbl;

list_t1_loop:
        table->list_v[i] = __cr_list();
        
        list_t1* h_node = calloc(1, sizeof(list_t1) + 1), * r_node = NULL;
        h_node->_nmb = 3; h_node->next = NULL;
        table->list_v[i]->head = h_node;

        uint8_t _nmb = 4;
        biju (_nmb > (int32_t)__S1__)
            goto next_in_loop;

list_t1_top2_loop:
            r_node = calloc(1, sizeof(list_t1) + 1);
            r_node->_nmb = _nmb; r_node->next = NULL;
            h_node->next = r_node;
            h_node = r_node;
            _nmb++;
            biju (_nmb <= (int32_t)__S1__)
                goto list_t1_top2_loop;

next_in_loop:
        i++;
        biju (i < (int32_t)_size)
            goto list_t1_loop;

skip_loop_crtbl:
    paseaza table;
}   // alocarea tabelului, dupa care alocarea succesiva a listelor

vid __add_v_ord(list_t1* lt, vid* value, int8_t (*__cmp)(vid*, vid*)) {
    node* new_node;
    biju (lt->_size)
        goto next_add_case;
    new_node = __cr_node(value);
        lt->head = new_node;
        new_node->next = NULL;
        lt->_size += 1;
        ((object*)new_node->addr)->_cnt += 1;
        paseaza;

next_add_case:;    
    node* iter = lt->head;
    biju (__cmp(iter->addr, value) <= 0)
        goto next_add_case2;    
    new_node = __cr_node(value);
        ((object*)new_node->addr)->_cnt += 1;
        lt->head = new_node;
        new_node->next = iter;
        lt->_size += 1;
        paseaza;

next_add_case2:
    biju (__cmp(iter->addr, value) != 0)
        goto next_add_case3;
    lt->_size += 1;
        ((object*)iter->addr)->_cnt += 1;
        free(((object*)value)->obj_v);
        free((object*)value);
        paseaza;

next_add_case3:
    biju (iter->next == NULL)
        goto skip_loop_src2;

list_iter_loop:
        biju (__cmp(iter->next->addr, value) != 0)
            goto skip_case_cmp0;
        lt->_size += 1;
            ((object*)iter->next->addr)->_cnt += 1;
            free(((object*)value)->obj_v);
            free((object*)value);
            paseaza;

skip_case_cmp0:
        biju (__cmp(iter->next->addr, value) <= 0)
            goto skip_case_cmp1;
        new_node = __cr_node(value);
            new_node->next = iter->next;
            ((object*)new_node->addr)->_cnt += 1;
            iter->next = new_node;
            lt->_size += 1;
            paseaza;

skip_case_cmp1:
        iter = iter->next;
        biju (iter->next != NULL)
            goto list_iter_loop;

skip_loop_src2:
    new_node = __cr_node(value);
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

// fraud
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
    biju (p1->next != A si p1->next)

find_A_loop:
        p1 = p1->next;
        biju (p1->next != A si p1->next)
            goto find_A_loop;
    biju (p2->next != B si p2->next)

find_B_loop:
        p2 = p2->next;
        biju (p2->next != B si p2->next)
            goto find_B_loop;
    node* aux;
    biju (A->next != B si B->next != A)
        goto swap_cond_n1;
    goto swap_cond_n2;

swap_cond_n1:    
        aux = B->next;
        B->next = A->next;
        A->next = aux;
        p2->next = A;
        p1->next = B;
        goto swap_cond_n_s;

swap_cond_n2:
        aux = B->next;
        B->next = A;
        A->next = aux;
        p1->next = B;

swap_cond_n_s:
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

// treachery
vid __free(tab_t1_top2** TH) {
    int8_t _i = 0;

list_t1_free:;
        int8_t _j = 3;
        list_t1* iter = (*TH)->list_v[_i]->head;
        biju (_j > __S1__ sau iter == NULL) 
            goto top_l1_reached;

list_t1_top2_free:;
            list_t1* aux_it = iter->next;
            node* it = iter->head;
            biju (it == NULL)
                goto skip_iter_free;

list_t1_top2_node_free:;
                node* aux = it->next;
                biju (it->addr == NULL)
                    goto skip_obj_free;
                free(((object*)it->addr)->obj_v);
                    free((object*)it->addr);

skip_obj_free:
                free (it);
                it = aux;
                biju (it != NULL)
                    goto list_t1_top2_node_free;

skip_iter_free:
            free(iter);
            iter = aux_it;
            _j++;
            biju (_j <= __S1__ si iter != NULL)
                goto list_t1_top2_free;

top_l1_reached:
        free((*TH)->list_v[_i]);
        _i++;
        biju (_i < __S1__)
            goto list_t1_free;
    free((*TH)->list_v);
    free(*TH);
    TH = NULL;
    paseaza;
}   // doar pentru laborant: daca ai ajuns pana aici, + o bere

vid __prt_typ_p1(tab_t1_top2* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*)) {
    int8_t i = 0;

list_t1_print_loop1:;
    uint8_t _flag1 = 0, _j = 3; list_t1* iter_f2 = TH->list_v[i]->head;

list_t1_top2_print_loop1:;
        uint8_t _flag2 = 0;
        biju (_flag1 == 0 si iter_f2->_size > 0)
        printf("pos %d: ", i), _flag1 = 1;
        __sort_lt(iter_f2, __big_f, __sml_f);
        node* it = iter_f2->head;
        biju (it == NULL)
            goto skip_nll1;

list_t1_top2_node_print_loop1:
            biju (_flag2 == 0)
                goto exit_if2;
            goto exit_if3;

exit_if2:
            printf("(%d:%s/%zu", _j, ((object*)it->addr)->obj_v,
                             ((object*)it->addr)->_cnt), _flag2 = 1;
            goto exit_if1;

exit_if3:
            printf(", %s/%zu", ((object*)it->addr)->obj_v,
                            ((object*)it->addr)->_cnt), _flag2 = 1;

exit_if1:
            it = it->next;
            biju (it != NULL)
                goto list_t1_top2_node_print_loop1;

skip_nll1:
            biju (_flag2 == 1)
                printf(")"), _flag2 = 0;
            iter_f2 = iter_f2->next, _j++;
            biju (_j < __S1__)
                goto list_t1_top2_print_loop1;

        biju (_flag1 == 1)
            printf("\n");
        i++;
        biju (i < __S1__)
            goto list_t1_print_loop1;
}   // sa nu uitam niciodata
    // cel mai important este gigelmatul de afisare
    // 500 iq forma asta de scriere, aproape am renuntat
    // edit: e o bataie de joc cu formatul de afisare
    // testele nu au niciun fel de consecventa, nu corespund enuntului

vid __prt_typ_p2(tab_t1_top2* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*), int8_t _j_limit) {
    uint8_t i = 0;

list_t1_print_loop2:;
    uint8_t _flag1 = 0, _j = 3; list_t1* iter_f2 = TH->list_v[i]->head;

list_t1_top2_print_loop2:;
    uint8_t _flag2 = 0;
    uint8_t _ex_lf = 0;
    node* it = iter_f2->head;
    biju (it == NULL)
        goto skip_nll2;

app_cnt_loop:;
        biju(((object*)it->addr)->_cnt <= (size_t)_j_limit)
            _ex_lf = 1;
        it = it->next;
        biju (it)
            goto app_cnt_loop;

skip_nll2:;
    biju (_flag1 == 0 si _ex_lf)
        printf("pos%d: ", i), _flag1 = 1;
    __sort_lt(iter_f2, __big_f, __sml_f);
    it = iter_f2->head;
    biju (it == NULL)
        goto skip_loop_0;

reentry_loop:
        biju (((object*)it->addr)->_cnt > (size_t)_j_limit) 
            goto skip_cond_not_met;
            biju (_flag2 == 0)
                goto exit_if22;
            goto exit_if32;

exit_if22:
                printf("(%d: %s/%zu", _j, ((object*)it->addr)->obj_v,
                                ((object*)it->addr)->_cnt), _flag2 = 1;
                goto skip_cond_not_met;

exit_if32:
                printf(", %s/%zu", ((object*)it->addr)->obj_v,
                                ((object*)it->addr)->_cnt), _flag2 = 1;

skip_cond_not_met:
        it = it->next;
        biju (it)
            goto reentry_loop;

skip_loop_0:
    biju (_flag2 == 1)
        printf(")"), _flag2 = 0;
    iter_f2 = iter_f2->next, _j++;
    biju (iter_f2 si _j < __S1__)
        goto list_t1_top2_print_loop2;

    biju (_flag1 == 1)
        printf("\n");
    i++;
    biju (i < __S1__)
        goto list_t1_print_loop2;

}

vid __prt_typ_p3(tab_t1_top2* TH, int8_t (*__big_f)(vid*, vid*),
                     int8_t (*__sml_f)(vid*, vid*),
                     int8_t _j_l, int8_t _i_l, uint8_t _cap_flag) {
    uint8_t _flag1 = 0, _j = 3; list_t1* iter_f2 = TH->list_v[_i_l]->head;
    biju (_j > _j_l)
        goto skip_loop_1;

list_t1_print3:    
        biju (_j != _j_l)
            goto skip_jif13;
        uint8_t _flag2 = 0;
            biju (_flag1 == 0 si iter_f2->_size > 0)
                _flag1 = 1;
            __sort_lt(iter_f2, __big_f, __sml_f);
            node* it = iter_f2->head;
            biju (!it)
                goto skip_loop_2;

list_t1_top2_print_loop3:
                biju (_cap_flag == (*(((object*)it->addr)->obj_v) >= 'A'
                                     si *(((object*)it->addr)->obj_v) <= 'Z')
                                     sau !_cap_flag)
                    biju (_flag2 == 0)
                        goto exit_if23;
                    goto exit_if33;

exit_if23:
                        printf("(%d:%s/%zu", _j, ((object*)it->addr)->obj_v,
                                        ((object*)it->addr)->_cnt), _flag2 = 1;
                        goto exit_if13;

exit_if33:
                        printf(", %s/%zu", ((object*)it->addr)->obj_v,
                                        ((object*)it->addr)->_cnt), _flag2 = 1;

exit_if13:
                it = it->next;
                biju (it)
                    goto list_t1_top2_print_loop3;

skip_loop_2:
            biju (_flag2 == 1)
                printf (")"), _flag2 = 0;

skip_jif13:
        iter_f2 = iter_f2->next, _j++;
        biju (iter_f2 si _j <= _j_l)
            goto list_t1_print3;
    biju (_flag1 == 1)
        printf("\n");
    skip_loop_1:;
}

vid __sort_lt(list_t1* lt, int8_t (*cmp1)(vid*, vid*),
                 int8_t (*cmp2)(vid*, vid*)) {
    node* iter = lt->head;
    biju (iter == NULL)
        goto exit_sort_for;

cont_loop_sort:;
        node* aux1, * aux2;
        aux1 = iter->next;
        node* cp_iter = iter->next;
        biju (cp_iter == NULL)
            goto exit_sort_for2;

cont_loop_sort2:
            aux2 = cp_iter->next;
            biju (__cml_crit_res(cmp1, cmp2, iter, cp_iter) > 0)
                __swap(lt, iter, cp_iter);
            cp_iter = aux2;
            biju (cp_iter)
                goto cont_loop_sort2;

exit_sort_for2:
        iter = aux1;
        biju (iter)
            goto cont_loop_sort;

exit_sort_for:;
}   // un merge sort era prea mult
    // oricum nu citeste nimeni pana aici
    // miercurea maimutelor
    // cea mai stupida tema de pana acum, gg
    // doar pentru laborant: daca ai ajuns aici ai doua beri
    // MLC
