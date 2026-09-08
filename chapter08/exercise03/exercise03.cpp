/*
exercise 02
[3] Replace Name_pair::print() with a (global)
operator << and define == and != for Name_pairs.
*/

#include "name_pairs.h"
using namespace Name_Pairs;

int main(){
    try
    {
        name_pairs np1{
		    {"Bills", "Dumbo", "liz", "sar", "may"},
		    {24, 45, 19, 33, 55}
	    };
	    name_pairs np2{np1};
	    name_pairs np3{
		    {"bills", "alpha", "beta", "jim", "dumbo"},
		    {24, 45, 19, 33, 55}
	    };
	    std::cout << "np1:\n" << np1
	    	<< "\nnp2:\n" << np2
	    	<< "\nnp3:\n" << np3
	    	<< std::boolalpha
	    	<< "\nnp1 == np2: " << (np1 == np2)
            << "\nnp1 == np3: " << (np1 == np3)
  	    	<< "\nnp2 == np3: " << (np2 == np3)
	    	<< "\nnp1 != np2: " << (np1 != np2)
	    	<< "\nnp1 != np3: " << (np1 != np3)
	    	<< "\nnp2 != np3: " << (np2 != np3)
	    	<< '\n';
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}