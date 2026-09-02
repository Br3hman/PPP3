/*
exercise 1
*/

class Toaster{
    public:
        void insert_bread(int slices);
        void set_darkness(int level);
        void push_lever();
        void cancel();
        bool is_done()const;
        void eject();
        Toaster(/* args*/);
        ~Toaster();
    private:
        int slot{2};
        int darkness_sitting{3};
        bool is_heating{false};
};

enum class Month{
    jan=1, feb, mar, apr, may, jun, jui, aug, sep, oct, nov, dec
};
struct Year
{
    int y;
};

class Date{
    public:
        //constructor and de-constructor
        Date(Year y, Month m, int d);
        ~Date();
        // Modification / State Change
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);

        //Inspection Read-Only
        int day() const;
        Month month() const;
        Year year() const;

    private:
        Year y;
        Month m;
        int d;
};

class BankAccount {
public:
    BankAccount(std::string owner_name, double initial_deposit);

    void deposit(double amount);
    bool withdraw(double amount);   // Returns false if insufficient funds
    void transfer_to(BankAccount& destination, double amount);

    double balance() const;
    std::string owner() const;
private:
    std::string owner_id;
    double current_balance{0.0};
};