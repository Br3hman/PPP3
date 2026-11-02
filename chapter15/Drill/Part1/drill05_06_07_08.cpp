/*
[5] Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
[6] Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
[7] Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
[8] Did you remember to delete the arrays? (If not, do it.)
*/
#include<iostream>

std::ostream&  print_array(std::ostream& os, int* a, int n){
    for(int i = 0; i < n; i++){
        if(i>0)
            os<<",";
        os<<a[i];
    }
    return os;
}

int* initialize_array(int n){
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        arr[i] = 100+i;
    }
    print_array(std::cout,arr,n);
    std::cout<<std::endl;
    return arr;
}

int main() {
    //Drill 05
    int* drill05 = initialize_array(10);
    //Drill 06
    int* drill06 = initialize_array(11);
    //Drill 07
    int* drill07 = initialize_array(20);
    //Drill 08
    delete drill05;
    delete drill06;
    delete drill07;
    return 0;
}