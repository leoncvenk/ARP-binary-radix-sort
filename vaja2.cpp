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
}



int main() {
    cout << "Test" << endl;
    return 0;
}