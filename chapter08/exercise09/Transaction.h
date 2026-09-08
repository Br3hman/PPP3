/*
exercise 09
Create a Transaction struct to record when a book is checked out.
Include a Book, a Patron, and a Date.

Including to record when a book is checked out.
*/
#pragma once

#include "Book.h"
#include "Patron.h"
#include "Date.h"

namespace PPP_Lib {
    struct Transaction
    {
        enum class Action {check_out,check_in};
        Book book;
        Patron patron;
        Date date;
        Action action;

    };


} // namespace PPP_Lib


