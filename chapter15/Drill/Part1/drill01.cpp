/*
[1] Allocate an array of ten ints on the free store using new.
*/
int main() {
    int* p = new int[10];
    delete[] p;
    return 0;
}