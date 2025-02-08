#include "mymath2.h"

namespace mymath2 {
    int sum_elem(int a){
        int sum=0;
        for (int i=0;i<=a;++i){
            sum+=i;
        }
        return sum;
    }
}