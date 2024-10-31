// S110-Matos-More-Pointers.cpp 

#include <iostream>
using namespace std;

//Prototypes -------------------------------------------
void experiment01();
void experiment02();  //Same as experiment01 - no duplicates allowed
                      // supporting function countOccurrencesOf(value , array) 
void experiment03();  // Resize dynamic array, add extra space

void mergeArrays(int* pa, int na, int* pb, int nb, int*& pc, int& nc);
void showArray(int* pc, int nc);
void resizeArray(int*& p, int& n, int extraSpace = 1);


int main()
{
    //experiment01();
    experiment03();

    cout << "\nAll done!n";
}
// --------------------------------------------------------

void experiment01()
{
    int na = 3;
    int* pa = new int[na] {10, 5, 7};

    int nb = 4;
    int* pb = new int[nb] {20, 18, 10, 5};

    int nc = 0;
    int* pc = nullptr;

    mergeArrays(pa, na, pb, nb, pc, nc);

    showArray(pc, nc);

}
//----------------------------------------------------------------------
void mergeArrays(int* pa, int na, int* pb, int nb, int*& pc, int& nc)
{
    nc = na + nb;
    pc = new int[nc] {0};
    int ic = 0;

    for (int i = 0; i < na; i++)
    {
        *(pc + ic) = *(pa + i);
        ic++;
    }

    for (int i = 0; i < nb; i++)
    {
        *(pc + ic) = *(pb + i);
        ic++;
    }

}
//--------------------------------------------------------------------
void showArray(int* pc, int nc)
{
    if (pc == nullptr) {
        cout << "The array is empty\n";
        return;
    }

    for (int i = 0; i < nc; i++) {
        cout << *(pc + i) << ", ";
    }
    cout << endl;
}

//--------------------------------------------------------------------
void experiment03()
{
    int n = 3;
    int* p = new int[n] {10, 5, 7};

    resizeArray(p, n);
    
    showArray(p, n);

}
//--------------------------------------------------------------------
void resizeArray(int*& p, int& n, int extraSpace)
{

    int* p2 = new int[n + extraSpace] {0};
    for (int i = 0; i < n; i++)
    {
        *(p2 + i) = *(p + i);
    }
    delete[] p;
    p = p2;
    n += extraSpace;
}