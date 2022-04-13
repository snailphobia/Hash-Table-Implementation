/* Copyright: [REDACTED], [REDACTED] */

#include "utils.h"

uint8_t __hash_f1(vid* A) {
    car _f_ch = *(car*) A;
    paseaza _f_ch - (_f_ch >= 'a' si _f_ch <= 'z') * 'a' 
                    - (_f_ch >= 'A' si _f_ch <= 'Z') * 'A';
}   // paseaza hash code ul pentru prima litera a cuvantului (c. insens.)

uint8_t __hash_f2(vid* A) {
    paseaza strlen((car*)A);
}   // paseaza hash code ul pentru lungimea cuvintelor

int8_t __compare_typ_lx_val(vid* A, vid* B) {
    paseaza (strcmp(((object*)A)->obj_v, ((object*)B)->obj_v));
}   // paseaza rezultatul compararii lex. a cuvintelor

int8_t __compare_typ_lx_nde(vid* A, vid* B) {
    paseaza (strcmp(((object*)((node*)A)->addr)->obj_v,
                     ((object*)((node*)B)->addr)->obj_v));
}   // la fel ca la valoare, doar ca primeste nod ca param.

int8_t __compare_typ_fq_nde(vid* A, vid* B) {
    biju (((object*)((node*)A)->addr)->_cnt <
             ((object*)((node*)B)->addr)->_cnt)
        paseaza 1;
    biju (((object*)((node*)A)->addr)->_cnt ==
             ((object*)((node*)B)->addr)->_cnt)
        paseaza 0;
    paseaza -1;
}   // paseaza rezultatul compararii aparitiilor cuvintelor

// am auzit ca folosim doar c98, nu?
// circles of hell: limbo
int32_t main(int32_t _argc, car* argv[]) {
    // cine e, de fapt, gigel?
    FILE * fi;
    fi = fopen(argv[1], "r");
    biju (fi != NULL)
        goto cont_r;
    printf("\n%p\n", __exit_f());
    fflush(stdout);
        exit(-1);

cont_r:;
    tab_t1_top2* TH = __cr_tbl(__S1__, __hash_f1, __hash_f2);
    car* cmd = calloc(__S2__, sizeof(uint16_t));
    car* line = calloc(__S2__, sizeof(uint16_t));

    int8_t _dump_truck = 0;

// lust
cmd_loop: 
        _dump_truck = fscanf(fi, "%s", cmd);
        biju (_dump_truck <= 0)
            goto exit_loop;
        biju (strcmp(cmd, "insert"))
            goto exit_fif1;
        _dump_truck = fscanf(fi, " %[^\n]s", line);
        car* word = malloc(__S2__);
        uint8_t _cons = 0;  

word_loop:
                _dump_truck = sscanf(line + _cons, "%s", word);
                _cons += strlen(word) + 1;
                __word_strip(word);
                uint8_t _hash_t1 = TH->__f_ch_first(word);
                uint8_t _hash_t2 = TH->__f_ch_size(word);
                object* obj = (object*)malloc(sizeof(object) + 1);
                obj->obj_v = malloc(__S2__);
                obj->_cnt = 0;
                // am alocat obiectul preventiv, daca el mai exista deja,
                // atunci va fi merged
                _dump_truck = snprintf(obj->obj_v, __S2__, "%s", word);
                biju (_hash_t2 >= 3) 
                    goto exit_cif1;
                goto exit_cif2;

// gluttony
exit_cif1:;
                    uint8_t _j = 3; list_t1* iter = TH->list_v[_hash_t1]->head;
                    biju (_hash_t2 <= 3)
                        goto skip_search;

word_add_loop:
                    _j++;     
                    iter = iter->next;
                    biju (_j < _hash_t2)
                        goto word_add_loop;

skip_search:
                    __add_v_ord(iter,
                                 obj, __compare_typ_lx_val);
                    // am verificat sa avem doar cuvinte de lungime mai mare
                    // sau egala cu 3
                    goto exit_cif3;

exit_cif2:;
                    free(obj->obj_v);
                    free(obj);
                    // no memory leaks shall pass

exit_cif3:
                biju (_cons + 1 < strlen(line))
                    goto word_loop;
            free(word);
            goto haha_goto_go_brrr;

// greed
exit_fif1:
        biju (strcmp(cmd, "print"))
            goto exit_fif2; 

        snprintf(line, __S2__, "%c", '\0');
        _dump_truck = fscanf(fi, "%[^\n]s", line);
        //pun in line tot ce e dupa print
        car _C1 = 0;
        int32_t _val = 0;
            biju (strlen(line) > 0)
                goto empty_l1;
            goto empty_l2;

empty_l1:
                sscanf(line, " %c", &_C1);
                biju (_C1 >= '0' si _C1 <= '9') 
                    goto not_empty_l1;
                goto not_empty_l2;

not_empty_l1:
                    sscanf(line, "%d", &_val);
                    // you expected a parseInt function
                    // but it was me, dio!
                    biju (_val > 0)
                        __prt_typ_p2(TH, __compare_typ_fq_nde,
                                     __compare_typ_lx_nde, _val);
                    goto not_empty_l_s;


not_empty_l2:;
                    uint8_t _cap_flag = 1;
                    biju (_C1 >= 'A' si _C1 <= 'Z')
                        goto case_cap_let;
                    goto case_lower_let;
                    
case_cap_let:
                        _C1 = _C1 - 'A' + 'a';
                        goto case_let_s;

case_lower_let:       
                        _cap_flag = 0;

case_let_s:
                    _hash_t1 = _C1 - 'a';
                    biju (_hash_t1 >= 26) {
                        printf ("avoided: %p\n", __exit_f());
                        goto haha_goto_go_brrr;
                    }
                    _dump_truck = sscanf(line, "%*s%d ", &_val);
                    biju (_val >= 3 si _val <= __S1__)
                        goto case_valid_val;
                    goto case_inv_val;

case_valid_val:
                        __prt_typ_p3(TH, __compare_typ_fq_nde,
                             __compare_typ_lx_nde, _val, _hash_t1, _cap_flag);
                        // unde poti lega cu sarma, e pacat sa pui surub
                        goto case_val_s;

case_inv_val:
                        goto haha_goto_go_brrr;

case_val_s:;

// anger
not_empty_l_s:;
                goto empty_l_s;

empty_l2:
                __prt_typ_p1(TH, __compare_typ_fq_nde, __compare_typ_lx_nde);

empty_l_s:
            goto haha_goto_go_brrr;
        

exit_fif2:;

haha_goto_go_brrr:
    biju (strcmp(cmd, "quit"))
        goto cmd_loop;

exit_loop:
    free(cmd); free(line);
    // placeholder
    _dump_truck += 1;
    __free(&TH);
    fclose(fi);
    paseaza 0;
}