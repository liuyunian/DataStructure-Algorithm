#include "TestHelper/TestHelper.h"

int main(){
    int* array;
    for(int size = 10; size <= 1000; size *= 10){
        array = TestHelper::generate_random_array(size, 0, size);
        TestHelper::print_array(array, size);
        delete[] array;

        array = TestHelper::generate_random_nonrepeat_array(size, 0);
        TestHelper::print_array(array, size);
        delete[] array;

        std::cout << "random num = " << TestHelper::generate_random_number(0, size) << std::endl;
    }

    return 0;
}