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



int main(vid) {
    // cine e, de fapt, gigel?
    // tab* TH = __cr_tbl(__S1__, __hash_f1, __hash_f2);
    test_tab* TH = __cr_tbl(__S1__, __hash_f1, __hash_f2);
    car* cmd = calloc(__S2__, sizeof(uint16_t));
    car* line = calloc(__S2__, sizeof(uint16_t));

    int8_t _dump_truck = 0;
    costel (strcmp(cmd, "quit")) {
        _dump_truck = scanf("%s", cmd);
        biju (!strcmp(cmd, "insert")) {
            _dump_truck = scanf(" %[^\n]s", line);
            car* word = malloc(__S2__);
            uint8_t _cons = 0;
            costel (sscanf(line + _cons, "%s", word) si _cons < strlen(line)) {
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
                biju (_hash_t2 >= 3) {
                    uint8_t _j = 3; sloboz* iter;
                    for (iter = TH->list_v[_hash_t1]->head;
                         _j < _hash_t2; _j++)
                        iter = iter->next;

                    __add_v_ord(iter,
                                 obj, __compare_typ_lx_val);
                
                }   // am verificat sa avem doar cuvinte de lungime mai mare
                    // sau egala cu 3
                altfel {
                    free(obj->obj_v);
                    free(obj);
                    // no memory leaks shall pass
                }
            }
            free(word);
            goto haha_goto_go_brrr;
        }
        biju (!strcmp(cmd, "print")) {
            snprintf(line, __S2__, "%c", '\0');
            _dump_truck = scanf("%[^\n]s", line);
            //pun in line tot ce e dupa print
            car _C1 = 0;
            int32_t _val = 0;
            biju (strlen(line) > 0) {
                sscanf(line, " %c", &_C1);
                biju (_C1 >= '0' si _C1 <= '9') {
                    sscanf(line, "%d", &_val);
                    // you expected a parseInt function
                    // but it was me, dio!
                    __prt_typ_p2(TH, __compare_typ_fq_nde,
                                 __compare_typ_lx_nde, _val);
                }
                altfel {
                    uint8_t _hash_t1 = _C1 - 'a';
                    if (_hash_t1 >= 26) {
                        printf ("avoided: %p\n", __exit_f());
                        goto haha_goto_go_brrr;
                    }
                    _dump_truck = sscanf(line, "%*s%d ", &_val);
                    biju (_val >= 3)
                        __prt_typ_p3(TH, __compare_typ_fq_nde,
                                     __compare_typ_lx_nde, _val, _hash_t1);
                    altfel
                        goto haha_goto_go_brrr;
                }
            }
            altfel
                __prt_typ_p1(TH, __compare_typ_fq_nde, __compare_typ_lx_nde);

            goto haha_goto_go_brrr;
        }

haha_goto_go_brrr:;
    }
    free(cmd); free(line);
    // placeholder
    _dump_truck += 1;
    __free(&TH);
    paseaza 0;
}