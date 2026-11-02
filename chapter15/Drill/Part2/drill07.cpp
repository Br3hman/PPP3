/** Drill 01
 * [1] Allocate an int, initialize it to 7, and assign its address to a variable p1.
 * [2] Print out the value of p1 and of the int it points to.
 * [3] Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.
 * [4] Print out the value of p2 and of the array it points to.
 * [5] Declare an int* called p3 and initialize it with p2.
 * [6] Assign p1 to p2.
 * [7] Assign p3 to p2.
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
 int main() {
    int* p1 = new int(7);
    int* p2 = new int[7]{1, 2, 4, 8, 16, 32, 64};
    int* p3 = p2;
    std::cout<<"Value of p1:"<<*p1<<std::endl;
    std::cout<<"Value of p2:"<<*p2<<std::endl;
    std::cout<<"Print the array p2 points to :";
    print_array(std::cout,p2,7);

    std::cout<<"\nValue of p3:"<<*p3<<std::endl;
    p2 = p1;

    std::cout<<"\nAssigned p1 to p2"<<std::endl;
    std::cout<<"Value of p2:"<<*p2<<std::endl;

    p3 = p2;
    std::cout<<"\nAssigned p2 to p3"<<std::endl;
    std::cout<<"Value of p3:"<<*p3<<std::endl;
    return 0;
 }
