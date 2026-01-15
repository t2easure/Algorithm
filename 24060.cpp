#include <iostream>
#include <vector>

using namespace std;

vector <int> savenum;

void merge(vector <int>& A, int p, int q, int r) {
    vector <int> temp(r - p + 1);
    int i = p;
    int j = q + 1;
    int t = 0;

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            temp[t++] = A[i++];
        }
        else {
            temp[t++] = A[j++];
        }
    }
    while (i <= q) {
        temp[t++] = A[i++];
    } 
    while (j <= r) {
        temp[t++] = A[j++];
    }
    
    for (t = 0; t < temp.size(); t++) {
        A[p + t] = temp[t];
        savenum.push_back(A[p + t]);
    }
}

void merge_sort(vector <int>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector <int> A;
    for (int i = 0; i < N; i++ ) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    merge_sort(A, 0, N - 1);

    if (savenum.size() >= K) 
        cout << savenum[K - 1];
    else    
        cout << -1;

    return 0;
}