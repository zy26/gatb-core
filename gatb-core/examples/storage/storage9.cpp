//! [snippet1]
// We include what we need for the test
#include <gatb/gatb_core.hpp>

#include <iostream>

// We use the required packages
using namespace std;

/********************************************************************************/
/*                  ostream and istream with HDF5                               */
/********************************************************************************/
int main (int argc, char* argv[])
{
    // We create a Storage product "foo" in HDF5 format
    Storage* storage = StorageFactory(STORAGE_HDF5).load(argv[1]);

    // We use locally this object (means that it should be automatically deleted when
    // leaving the enclosing instructions block).
    LOCAL (storage);

    // Shortcut: we get the root of this Storage object
    Group& root = storage->root();

    // We get the group for dsk
    Group& dskGroup = storage->getGroup("dsk");

    Repartitor repart;
    repart.load (dskGroup);

    for (size_t i=0; i<(1<<16); i++)  {  printf ("%ld  %d\n", i, repart(i));  }
}
//! [snippet1]