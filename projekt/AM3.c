#include "header.h"

int main() {

    for (int n = 2; n < 300; n *= 2) {
        AM3Step(
            fx, fy,
            -3., -7., 0., 9., n,
            "AM3_-3_-7", 1);
    }

//    for (int n = 2; n < 10000; n *= 2) {
//        printf("n=%d\t%lf\n", n, EOC(
//                AM3Step,
//                fx, fy, 7.537491968651447,-5.374027128839188, 5., 5., 0., 3., n));
//    }

}
