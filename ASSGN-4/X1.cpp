#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

vector<string> generateBinary(int n) {
    vector<string> result;

    for (int num = 1; num <= n; num++) {
        int temp = num;
        string binary = "";

        while (temp > 0) {
            int rem = temp % 2;

            if (rem == 0)
                binary += "0"; 
            else
                binary += "1"; 

            temp = temp / 2;
        }
        
        reverse(binary.begin(), binary.end()); 
        
        result.push_back(binary);
    }

    return result;
}

int main() {
    int n = 6;
    vector<string> binaries = generateBinary(n);

    for (auto bin : binaries)
        cout << bin << " ";
    cout << endl;

    return 0;
}