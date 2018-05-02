
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex);
};

vector<int> Solution::getRow(int rowIndex){
	vector<int>row;
	if(rowIndex == 0){
		row.push_back(1);
		return row;
	}
	if(rowIndex == 1){
		row.push_back(1);
		row.push_back(1);
		return row;
	}
	row.push_back(1);
	row.push_back(1);
	vector<int>temp;
	for(int i = 2; i <= rowIndex; i++){
		int k = 0;
		for(int j = 0; j < i-1; j++){
			temp = row;
			row.insert(row.begin()+1+j, temp[j+k] + temp[j+k+1]);
			k++;
			temp.clear();
		}
		for(int k = 0; k < i-2; k++){
			row.erase(row.end()-2);
		}
	}
	return row;
}

int main(){

	Solution solution;
	int n = 3;
	
    vector<int> vec;
	vec = solution.getRow(n);
    int len_n=vec.size();
 
    for(int i=0;i<len_n;i++)
    {
        cout<<vec[i]<<' ';
    }
	cout<<endl;
 

	system("pause");
	return 0;
}