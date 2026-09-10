#include <iostream>
#include <vector>
using namespace std;

#define INF 999999

void Merge(int A[], int p, int q, int r)
{
    int N1 = q - p + 1;
    int N2 = r - q;

    vector<int> L(N1 + 1), R(N2 + 1);

    int i, j, k;

    for (i = 0; i < N1; i++)
        L[i] = A[p + i];

    for (j = 0; j < N2; j++)
        R[j] = A[q + 1 + j];

    L[N1] = INF;
    R[N2] = INF;

    i = 0;
    j = 0;

    for (k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;

        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);

        Merge(A, p, q, r);
    }
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int A[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    MergeSort(A, 0, n - 1);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}