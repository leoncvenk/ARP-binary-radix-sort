#include <iostream>
#include <fstream>

using namespace std;

bool preberiPodatke(const char* imeDatoteke, unsigned char*& A, int& n) 
{
    ifstream vhod(imeDatoteke);
    if (!vhod.is_open()) 
    {
        return false;
    }

    int kapaciteta = 10;
    n = 0;
    A = new unsigned char[kapaciteta];

    int stevilo;
    while (vhod >> stevilo) 
    {
        if (stevilo < 0 || stevilo > 255) 
        {
            delete[] A;
            A = nullptr;
            vhod.close();
            return false;
        }

        if (n == kapaciteta) 
        {
            kapaciteta *= 2;
            unsigned char* novo = new unsigned char[kapaciteta];
            for (int i = 0; i < n; i++) 
            {
                novo[i] = A[i];
            }
            delete[] A;
            A = novo;
        }

        A[n] = (unsigned char)stevilo;
        n++;
    }

    vhod.close();
    return true;
}


void countingSortPoBitu(unsigned char*& A, unsigned char*& B, int n, int k)
{
    int C[2] = {0, 0};

    for (int i = 0; i < n; i++)
    {
        int bit = (A[i] >> k) & 1;
        C[bit]++;
    }

    C[1] += C[0];

    for (int i = n - 1; i >= 0; i--)
    {
        int bit = (A[i] >> k) & 1;
        B[--C[bit]] = A[i];
    }

    unsigned char* temp = A;
    A = B;
    B = temp;
}

void binarniRadixSort(unsigned char*& A, int n)
{
    if (n <= 1)
    {
        return;
    }

    unsigned char* B = new unsigned char[n];

    for (int k = 0; k < 8; k++)
    {
        countingSortPoBitu(A, B, n, k);
    }

    delete[] B;
}

bool zapisiPodatke(const char* imeDatoteke, unsigned char* A, int n)
{
    ofstream izhod(imeDatoteke);
    if (!izhod.is_open())
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        izhod << (int)A[i];
        if (i < n - 1)
        {
            izhod << " ";
        }
    }

    izhod.close();
    return true;
}

int main() {
    cout << "Test" << endl;
    return 0;
}