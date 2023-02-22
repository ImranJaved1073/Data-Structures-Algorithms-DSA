// Calculate step count for the following code
void silly(int n, int x, int y)
{
    if (x < y)//------------------------------> 1
    {
        for (int i = 0; i < n; i++)//----------------> n + 1
            for (int j = 0; j < n * i; j++)// ------------> n[(n(n-1))/2] + n = (n^3 - n^2 + 2n)/2
                cout << "*";//--------------------------> n[(n(n-1))/2] = (n^3 - n^2)/2
    }
    else
        cout << "bye!";
                                       // 1 + n + 1 + (n^3 - n^2 + 2n)/2 + (n^3 - n^2)/2 = n^3 - n^2 + 2n + 2
                                       // T(n) = n^3 - n^2 + 2n + 2                          
}