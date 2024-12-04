// Implement Check if it is possible to transform one 
// string to another. 
// Statement Given two strings s1 and s2 (all letters in uppercase). 
// Check if it is possible to convert s1 to s2 by performing following 
// operations. 
// 1.  Make some lowercase letters uppercase.  
// 2. Delete all the lowercase letters.  
// Input: s1 = daBcd s2 = ABC           Output: yes 
// Input: s1 = argaju    s2 = RAJ         Output: yes  

#include <iostream>
#include <vector>
using namespace std;

void calcSubset(vector<int>& A, vector<vector<int> >& res,vector<int>& subset, int index)
{
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) {
        subset.push_back(A[i]);
        calcSubset(A, res, subset, i + 1);
        subset.pop_back();
    }
}

vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;
    int index = 0;
    calcSubset(A, res, subset, index);
    return res;
}


int main()
{
    vector<int> array = { 1, 2, 3 };
    vector<vector<int> > res = subsets(array);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}
