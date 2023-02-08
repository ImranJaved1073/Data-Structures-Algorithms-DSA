#include <iostream>
#include "NDArray.h"

using namespace std;

int main()
{
    NDArray<int> b({2, 4}, {2, 7, 9});
    cout << "Number of Dimensions:" << b.getNumberOfDimensions() << endl;
    for (int i = 0; i < b.getNumberOfDimensions(); i++)
    {
        cout << "Dim # " << i << " size= " << b.getDimensionSize(i) << " Index Range= ("
            << b.getDimensionLowerIndex(i) << " ~ " << b.getDimensionHigherIndex(i) << ")" << endl;
    }

    NDArray<int> c;
    cout << "\nNumber of Dimensions:" << c.getNumberOfDimensions() << endl;

    NDArray<int> a({5});
    cout << "\nNumber of Dimensions:" << a.getNumberOfDimensions() << endl;
    for (int i = 0; i < a.getNumberOfDimensions(); i++)
    {
        cout << "Dim # " << i << " size= " << a.getDimensionSize(i) << " Index Range= ("
            << a.getDimensionLowerIndex(i) << " ~ " << a.getDimensionHigherIndex(i) << ")" << endl;
    }
    for (int i = a.getDimensionLowerIndex(0); i <= a.getDimensionHigherIndex(0); i++)
    {
        cout << "[" << i << "] = ";
        cin >> a({i});
    }
    for (int i = a.getDimensionLowerIndex(0); i <= a.getDimensionHigherIndex(0); i++)
    {
        cout << a({i}) << ',';
    }


    // NDArray<int> a({2, 4}, {5, -1});
    // NDArray<int> b;
    // b = a;
    // cout << "Number of Dimensions:" << b.getNumberOfDimensions() << endl;
    // for (int i = 0; i < b.getNumberOfDimensions(); i++)
    // {
    //     cout << "Dim # " << i << " size= " << b.getDimensionSize(i) << " Index Range= ("
    //         << b.getDimensionLowerIndex(i) << " ~ " << b.getDimensionHigherIndex(i) << ")" << endl;
    // }

    // for (int i = b.getDimensionLowerIndex(0); i <= b.getDimensionHigherIndex(0); i++)
    // {
    //     for (int j = b.getDimensionLowerIndex(1); j <= b.getDimensionHigherIndex(1); j++)
    //     {
    //         cout << "[" << i << ":" << j << "] = ";
    //             cin >> b({i, j});
    //     }
    // }

    // for (int i = b.getDimensionLowerIndex(0); i <= b.getDimensionHigherIndex(0); i++)
    // {
    //     for (int j = b.getDimensionLowerIndex(1); j <= b.getDimensionHigherIndex(1); j++)
    //     {
    //         cout << b({i, j}) << '\t';
    //     }
    //     cout << endl;
    // }


    // NDArray<int> b({2, 4});
    // cout << "Number of Dimensions:" << b.getNumberOfDimensions() << endl;
    // for (int i = 0; i < b.getNumberOfDimensions(); i++)
    // {
    //     cout << "Dim # " << i << " size= " << b.getDimensionSize(i) << " Index Range= ("
    //         << b.getDimensionLowerIndex(i) << " ~ " << b.getDimensionHigherIndex(i) << ")" << endl;
    // }


    // NDArray<int> b({2, 4}, {5, -1});
    // b({2, -1}) = 10;


    // NDArray<int> b({2, 4, 3}, {2, 7});
    // cout << "Number of Dimensions:" << b.getNumberOfDimensions() << endl;
    // for (int i = 0; i < b.getNumberOfDimensions(); i++)
    // {
    //     cout << "Dim # " << i << " size= " << b.getDimensionSize(i) << " Index Range= ("
    //         << b.getDimensionLowerIndex(i) << " ~ " << b.getDimensionHigherIndex(i) << ")" << endl;
    // }

}
