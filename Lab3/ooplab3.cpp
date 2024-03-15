#include <iostream>
#include "Math.h"
using namespace std;
int main()
{
    Math n;
    cout << "suma a 2 nr intregi este:" << " " << n.Add(2, 3)<<'\n';
    cout << "suma a 3 nr intregi este:" << " " << n.Add(1, 2, 3)<<'\n';
    cout << "suma intreaga a 2 nr reale este:" << " " << n.Add(1.2, 1.5)<<'\n';
    cout << "suma intreaga a 3 nr reale este:" << " " << n.Add(1.2, 1.5, 1.4)<<'\n';
    cout << "inmultirea a 2 nr intregi este:" << " " << n.Mul(3, 4)<<'\n';
    cout << "inmultirea a 3 nr intregi este:" << " " << n.Mul(3, 4, 5) << '\n';
    cout << "inmultirea intreaga a 2 nr reale este:" << " " << n.Mul(3.2, 4.5) << '\n';
    cout << "inmultirea a 3 nr reale este:" << " " << n.Mul(3.5, 4.9, 7.2) << '\n';
    cout << "suma a count elemente este:"<< " " << n.Add(5, 1, 2, 3, 4, 5)<<'\n';
    cout << "suma a doua siruri este:" << " " << n.Add("123", "123");
    return 0;
}


