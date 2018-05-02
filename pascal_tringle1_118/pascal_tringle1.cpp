
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows);
};

vector<vector<int>> Solution::generate(int numRows){
	vector<vector<int>>tringle;
	vector<int>temp;
	if(numRows == 0){
		return tringle;
	}
	else if(numRows == 1){
		temp.push_back(1);//在向量中增加1
		tringle.push_back(temp);//在二维向量中增加一个向量
		return tringle;//这是一个二维向量[[1]]
	}
	else if(numRows == 2){
		temp.push_back(1);
		tringle.push_back(temp);//[[1]]
		temp.push_back(1);//在已有的[1]中再加入1形成[1,1]
		tringle.push_back(temp);//[[1],[1,1]]
		return tringle;
	}
	vector<int>temp1;
	temp.push_back(1);
	tringle.push_back(temp);
	temp1.push_back(1);
	temp1.push_back(1);
	tringle.push_back(temp1);//[[1],[1,1]]作为开始
	for(int i = 2; i < numRows; i++)
    {
        temp.clear();
        int len = temp1.size();
        temp.push_back(1);
        for(int i = 0; i < len-1; i++)
            temp.push_back(temp1[i] + temp1[i+1]);
        temp.push_back(1);
        tringle.push_back(temp);
        temp1.clear();
        temp1 = temp;
    }
	return tringle;
}

int main(){

	Solution solution;
	int n = 5;
	
    vector<vector<int>> vec1;
	vec1 = solution.generate(n);
    int len_n=vec1.size();
 
    for(int i=0;i<len_n;i++)
    {
        int len_m=vec1[i].size();
        for(int j=0;j<len_m;j++)
            cout<<vec1[i][j]<<' ';
        cout<<endl;
    }
 
	system("pause");
	return 0;
}