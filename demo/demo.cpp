#include <vector>
#include <array>
#include <emscripten.h>
#include "../printv.h"

int main (int argc, char const *argv[]) {

    printf("WASM loaded\n");
    EM_ASM(window.dispatchEvent(new CustomEvent("wasmLoaded")););

    return 0;
}


extern "C" {

    EMSCRIPTEN_KEEPALIVE
    void demo1D (void) {

        std::vector<int> int_values = {1,2,3,4,5};
        std::vector<double> double_values = {1,2,3,4,5};
        std::array<int, 4> a = {1,2,3,4};
        int arr[] = {1,2,3};

        printf("int values:\n");
        printv(int_values);
        printf("double values:\n");
        printv(double_values);
        printf("array[] values:\n");
        printv(arr, 3);
        printf("array size: %d\n", a.size());
        printv(a);
    }


    EMSCRIPTEN_KEEPALIVE
    void demo2D (void) {
        std::vector<std::vector<float>> float_values = {{1,2,3,4,5}, {1,2,3,4,5}};
        printf("2D float values:\n");
        printv(float_values);
    }

    EMSCRIPTEN_KEEPALIVE
    void demo3D (void) {
        std::vector<std::vector<std::vector<uint8_t>>> uint8_t_values = {{{1,2,3,4,5}, {1,2,3,4,5}}, {{1,2,3,4,5}, {1,2,3,4,5}}};
        printf("3D uint8_t values:\n");
        printv(uint8_t_values);
    }
}
