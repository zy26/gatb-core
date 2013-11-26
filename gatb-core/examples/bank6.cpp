//! [snippet1]
// We include what we need for the test
#include <gatb/system/impl/System.hpp>
#include <gatb/bank/impl/Bank.hpp>
#include <gatb/tools/designpattern/impl/IteratorHelpers.hpp>
#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>

// We use the required packages
using namespace std;
using namespace gatb::core::bank;
using namespace gatb::core::bank::impl;
using namespace gatb::core::tools::dp::impl;

int main (int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "you must provide at least the FASTA file path. Arguments are:" << endl;
        cerr << "   1) FASTA file path" << endl;
        cerr << "   2) data lines size (60 by default)" << endl;
        cerr << "   3) type of comments: 0 for new comments, 1 for only ids, 2 (default) for full comments" << endl;
        cerr << "   4) number of sequences to keep (all by default)" << endl;
        return EXIT_FAILURE;
    }

    // We get the file name from the user arguments
    const char* filename = argv[1];

    // We define the max size of a data line in the FASTA output file
    size_t dataLineSize = argc >= 3 ?  atoi(argv[2]) : 60;

    // We define the kind of output comments
    Bank::Iterator::CommentMode_e mode = Bank::Iterator::FULL;
    if (argc >= 4)
    {
        int m = atoi (argv[3]);
             if (m==0)  { mode = Bank::Iterator::NONE;   }
        else if (m==1)  { mode = Bank::Iterator::IDONLY; }
    }

    // We set the number of sequences to be kept.
    u_int64_t nbSequences =  (argc >= 5 ? atol (argv[4]) : ~0);

    try  {
        // We declare a Bank instance.
        Bank b (filename);

        // We create an iterator over this bank.
        Bank::Iterator itSeq (b, mode);

        // We encapsulate it with a truncation iterator
        TruncateIterator<Sequence> it (itSeq, nbSequences);

        size_t idxSeq = 1;

        // We loop over sequences.
        for (it.first(); !it.isDone(); it.next(), idxSeq++)
        {
            // We dump the comment into the file according to the user mode
            if (!it->getComment().empty())   {  cout << ">" << it->getComment() << endl;  }
            else                             {  cout << ">seq=" << idxSeq << " len=" << it.item().getDataSize() << endl;  }

            // shortcut
            size_t len = it->getDataSize();

            // We dump the data with fixed sized columns
            for (size_t i=0; i<len; )
            {
                for (size_t j=0; j<dataLineSize && i<len; j++, i++)
                {
                    cout << (char) toupper (it->getData() [i]);
                }
                cout << endl;
            }
        }
    }
    catch (gatb::core::system::Exception& e)
    {
        cerr << "EXCEPTION: " << e.getMessage() << endl;
    }

    return EXIT_SUCCESS;
}
//! [snippet1]
