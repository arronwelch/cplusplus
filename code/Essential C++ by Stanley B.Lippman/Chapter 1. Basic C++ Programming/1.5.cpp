// 1.5 How to Use Arrays and Vectors

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    const int seq_size = 18;
    int pell_seq_array[seq_size];
    vector<int> pell_seq_vector(seq_size);
    pell_seq_array[0] = 1; // assign 1 to first element
    pell_seq_array[1] = 2; // assign 2 to second element

    for (int ix = 2; ix < seq_size; ++ix)
    {
        pell_seq_array[ix] = pell_seq_array[ix - 2] + 2*pell_seq_array[ix - 1];
    }

    cout << "The first " << seq_size 
         << " elements of the Pell Series:\n\t";

    for (int ix = 0; ix < seq_size; ix++)
        cout << pell_seq_array[ix] << ' ';
    cout << '\n';

    int elem_seq_style1[seq_size] = {
        1,  2,  3,   // Fibonacci
        3,  4,  7,   // Lucas
        2,  5, 12,   // Pell
        3,  6, 10,   // Triangular
        4,  9, 16,   // Square
        5, 12, 22,   // Pentagonal
    };

    // compiler computes a size of 18 elements
    int elem_seq_style2[] = {
        1, 2,  3, 3, 4,  7, 2,  5, 12,
        3, 6, 10, 4, 9, 16, 5, 12, 22
    };

    vector<int> elem_seq_init(seq_size);
    elem_seq_init[0] = 1;
    elem_seq_init[1] = 2;
    // ...
    elem_seq_init[17] = 22;

    // One alternative is to initialize a built-in array and use that to initialize
    // the vector:
    int elem_val[seq_size] = {
        1, 2,  3, 3, 4,  7, 2,  5, 12,
        3, 6, 10, 4, 9, 16, 5, 12, 22
    };

    // initialize elem_seq with values of elem_vals
    vector<int> elem_seq(elem_val, elem_val + seq_size);

    // elem_seq.size() returns the number of elements
    cout << "elem_seq.size() = " << elem_seq.size(); 
    cout << '\n';

    // contained within the vector elem_seq
    cout << "The first " << elem_seq.size()
         << " elements of the Pell Series\n\t";

    for (int  ix = 0; ix < elem_seq.size(); ix++)
        cout << elem_seq[ix] << ' ';
    cout << '\n'; 

    int cur_tuple = 0;

    bool next_seq = true;
    int usr_guess;
    char usr_rsp;

    while (next_seq == true &&
           cur_tuple < seq_size)
    {
        cout << "The first two elements of the sequence are: "
             << elem_seq[cur_tuple] << ", "
             << elem_seq[cur_tuple + 1]
             << "\nWhat is the next element? ";
        // ...
        cin >> usr_guess;
        if (usr_guess == elem_seq[cur_tuple + 2])
            // correct!
            cout << "correct!\n";
        // ...
        cout << "Want to try another sequence? (Y/N)\n";
        cin >> usr_rsp;

        if (usr_rsp == 'N' || usr_rsp == 'n')
            next_seq = false;
        else cur_tuple += 3;
    }

    const int max_seq = 6;
    string seq_names[max_seq] = {
        "Fibonacci",
        "Lucas",
        "Pell",
        "Triangular",
        "Square",
        "Pentagonal"
    };

    int num_cor;
    if (usr_guess == elem_seq[cur_tuple + 2])
    {
        ++num_cor;
        cout << "Very good. Yes, "
             << elem_seq[cur_tuple + 2]
             << " is the next element in the "
             << seq_names[cur_tuple / 3] << " sequence.\n";
    }

    return 0;
}
