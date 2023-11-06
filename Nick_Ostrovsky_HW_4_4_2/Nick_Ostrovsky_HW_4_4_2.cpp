#include <iostream>
void print_dynamic_array(int* array, int n_logic, int n_actual);
int* increase_in(int* array, int& n_logic, int& n_actual, int incut);
int main()
{
    int n_actual;
    std::cout << "Please, enter actual elemens number:" << std::endl;
    std::cout << "\t";
    std::cin >> n_actual;

    int n_logic;
    std::cout << "Please, enter logic elemens number:" << std::endl;
    std::cout << "\t";
    std::cin >> n_logic;

    if (n_actual < n_logic)
    {
        std::cout << "Number of logic element should be less or equal elements number." << std::endl;
        return (-1);
    }
    int* array = new int[n_actual];
    for (int i = 0; i < n_logic; i++)
    {
        std::cout << "\n\t" << "Please, enter element array[" << i << "] value:" << std::endl;
        std::cin >> array[i];

    }
    print_dynamic_array(array, n_logic, n_actual);
    std::cout << "\n\t" << std::endl;
    while (1)
    {
        std::cout << "Please, enter incut value:" << std::endl;
        int in;
        std::cin >> in;
        if (in == 999) { return 0; }
        array = increase_in(array, n_logic, n_actual, in);
    }
    delete[] array;
    //delete[] ;
    return 0;
}
void print_dynamic_array(int* array, int n_logic, int n_actual)

{
    for (int i = 0; i < n_logic; i++)
    {
        std::cout << " " << array[i];

    }
    if (n_actual > n_logic)
    {
        for (int j = 0; j < (n_actual - n_logic); j++)
        {
            std::cout << " _";
        }
    }
}
int* increase_in(int* array, int& n_logic, int& n_actual, int incut) 
{
    if (n_logic < n_actual) 
    {
        array[n_logic] = incut;
        n_logic++;
        print_dynamic_array(array, n_logic, n_actual);
        return array;
    }
    if (n_logic == n_actual)
    {
        n_actual *= 2;
        int* barray = new int[n_actual];
        for (int k = 0; k < n_logic; k++)
        {
            barray[k] = array[k];
        }
        barray[n_logic] = incut;
        ++n_logic;
        print_dynamic_array(barray, n_logic, n_actual);
        return barray;
    }
}