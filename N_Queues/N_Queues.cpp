#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
	Solution(int n);
	void init(int n);
	void generate(int k, int n, vector<vector<string> > &result, 
		vector<vector<int> > &mark, vector<string> &location);
	void putQueen(int x, int y, vector<vector<int> > &mark);
	vector<vector<string> > getResult();
	~Solution();
private:
	vector<vector<string> > result;
	vector<vector<int> > mark;
	vector<string> location;
	int Queens;

};

Solution::Solution(int n){
	cout<<"Constructor..."<<endl;
	init(n);
}

void Solution::init(int n){
	Queens = n;
	for (int i = 0; i < n; i++){
        mark.push_back((std::vector<int>()));
		for (int j = 0; j < n; j++){
	        	mark[i].push_back(0);
		}
	    location.push_back("");
		location[i].append(n, '.');
    }
	vector<vector<string> > result(n, vector<string>(n,""));
//	vector<string> location(n, ".");
//	vector<vector<int> > mark(n, vector<int>(n, 0));
}

void Solution::generate(int k, int n, 
		vector<vector<string> > &result, vector<vector<int> > &mark,
		vector<string> &location){
	if (k == n){
		result.push_back(location);
		return;
	}
	for (int i = 0; i < n; i++){
		if (mark[k][i] == 0){
			vector<vector<int> > tmp_mark = mark;
			location[k][i] = 'Q';
			putQueen(k, i, mark);
			generate(k + 1, n, result, mark, location);
			mark = tmp_mark;
			location[k][i] = '.';
		}
	}
}

void Solution::putQueen(int x, int y, vector<vector<int> > &mark){
	const int direction_x[] = {-1, -1, -1, 0, 1, 1, 1, 0};
	const int direction_y[] = {-1, 0, 1, 1, 1, 0, -1, -1};
	mark[x][y] = 1;
	int extend_x, extend_y;
	for(int i = 0; i < mark.size(); i++){
		for(int j = 0; j < 8; j++){
			extend_x = x + i * direction_x[j];
			extend_y = y + i * direction_y[j];
			if(extend_x >= 0 && extend_x < mark.size() &&
				extend_y >=0 && extend_y < mark.size())
				mark[extend_x][extend_y] = 1;
		}
	}
}

vector<vector<string> > Solution::getResult(){
	generate(0, Queens, result, mark, location);
	return result;
}

Solution::~Solution(){
	cout<<"Destructor"<<endl;
}

int main(){
	vector<vector<string> > result;
	int n;
	do{
		cout<<"Please enter your number of Queens(end with 0) : ";
		cin>>n;
		if(n == 0){
			break;
		}
		cout<<endl;
		Solution solve(n);
		result = solve.getResult();
		for (int i = 0; i < result.size(); i++){
			printf("i = %d\n", i+1);
			for (int j = 0; j < result[i].size(); j++){
				printf("%s\n", result[i][j].c_str());
			}
			printf("\n");
		}	
	}while(true);
	
	system("pause");
	return 0;
}