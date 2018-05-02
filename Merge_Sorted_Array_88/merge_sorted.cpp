
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
};

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
	int p1 = m - 1;
	int p2 = n - 1;
	for(int k = n + m -1; p1 >= 0 && p2 >= 0; k--){// && k > p1
		if(nums1[p1] <= nums2[p2]){
			nums1[k] = nums2[p2];
			p2--;
		}
		else if(nums1[p1] > nums2[p2]){
			nums1[k] = nums1[p1];
			p1--;		
		}
	}
	while(p2 >= 0){
            nums1[p2] = nums2[p2];
            p2--;
    }
}

int main(){

	Solution solution;
	int m = 3;
	int n = 3;
	vector<int>nums1(6);
	nums1[0] = 4;
	nums1[1] = 5;
	nums1[2] = 6;
	vector<int>nums2(3);
	nums2[0] = 1;
	nums2[1] = 2;
	nums2[2] = 3;
	
	cout<<"before merge,nums1 : ";
	for(int i = 0; i < nums1.size(); i++){
		cout<<nums1[i]<<ends;
	}
	cout<<endl;
	
	cout<<"before merge,nums2 : ";
	for(int i = 0; i < nums2.size(); i++){
		cout<<nums2[i]<<ends;
	}
	cout<<endl;

	solution.merge(nums1, m, nums2, n);


	cout<<"after merge,nums1 : ";
	for(int i = 0; i < nums1.size(); i++){
		cout<<nums1[i]<<ends;
	}
	cout<<endl;

	system("pause");
	return 0;
}