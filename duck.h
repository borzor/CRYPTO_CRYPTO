#include <ak_bckey.h>
#include <stdint.h>
#include <string.h>

#define _GOST_C0 (uint32_t)(0x1010101)
#define _GOST_C1 (uint32_t)(0x1010104)
#define _GOST_C3 (uint64_t)(0x101010101010101)
#define _GOST_C4 (uint64_t)(0x101010101010108)

void BR_gamma(ak_bckey key, ak_pointer open_text,  ak_pointer output_text, size_t size, ak_pointer synh, size_t synh_size){
    ak_uint128 tmp1, tmp2;
    ak_uint64 *in = (ak_uint64 *)open_text,
            *out = (ak_uint64 *)output_text,
            counter = (ak_int64)(size/key->bsize),
            potential_block = (ak_int64)(size%key->bsize);
    key->ivector_size = synh_size;
    memcpy(key->ivector, synh, synh_size);
    key->encrypt(&key->key, key->ivector, tmp1.q);
                printf("\n");
    switch(key->bsize){
      case  8:
        while(counter!=0){
            tmp1.w[0]+=_GOST_C0;
            if(0xFFFFFFFF-_GOST_C1<tmp1.w[1]){
                tmp1.w[1]+=1;
            }
            tmp1.w[1]+=_GOST_C1;
            memcpy(key->ivector, tmp1.q, synh_size);
            key->encrypt(&key->key, key->ivector, tmp2.q);
            *out = *in ^ tmp2.q[0];
            in++; out++; counter--;
        };
        break;
      case 16:
        while(counter!=0){
            tmp1.q[0]+=_GOST_C3;
            if(0xFFFFFFFFFFFFFFFF-_GOST_C4<tmp1.q[1]){
                tmp1.q[1]+=1;
            }
            tmp1.q[1]+=_GOST_C4;
            memcpy(key->ivector, tmp1.q, synh_size);
            key->encrypt(&key->key, key->ivector, tmp2.q);
            *out = *in ^ tmp2.q[0];
            in++; out++;
            *out = *in ^ tmp2.q[1];
            in++; out++; counter--;
        }
        break;
    }
    if(potential_block){
        size_t i= 0;
        switch (key->bsize){
            case 8:
                tmp1.w[0]+=_GOST_C0;
                if(0xFFFFFFFF-_GOST_C1<tmp1.w[1]){
                    tmp1.w[1]+=1;
                }
                tmp1.w[1]+=_GOST_C1;
                memcpy(key->ivector, tmp1.q, synh_size);
                key->encrypt(&key->key, key->ivector, tmp2.q);
                while(i!=potential_block){
                    ((ak_uint8*)out)[i] = ((ak_uint8*)in)[i]^tmp2.b[i];
                    i++;
                }
            break;
         case 16:
            tmp1.q[0]+=_GOST_C3;
            if(0xFFFFFFFFFFFFFFFF-_GOST_C4<tmp1.q[1]){
                tmp1.q[1]+=1;
            }
            tmp1.q[1]+=_GOST_C4;
            memcpy(key->ivector, tmp1.q, synh_size);
            key->encrypt(&key->key, key->ivector, tmp2.q);
            while(i!=potential_block){
                ((ak_uint8*)out)[i] = ((ak_uint8*)in)[i]^tmp2.b[i];
                i++;
            }
        }
    }


}

