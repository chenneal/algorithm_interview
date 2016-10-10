/* 简单的迷宫题，给一个图，-代表此路树可以走，#代表不可以走，
   B代表起点，E代表终点，问是否可以走到终点 */
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool is_find;

/*用来剪枝优化的参数*/
bool have_found; 

void dfs(vector<string>& route, set< pair<int, int> >& visit, int m, int n, int em, int en) {
	int S = route.size();
	if (S == 0)
		return ;
	int C = route[0].size();
	if (C == 0)
	    return ;
	visit.insert(make_pair(m, n));
	if (m == em && n == en) {
		is_find = true;
		have_found = true;
		return ;
	}
	if (m-1 >= 0 && (visit.count(make_pair(m-1, n)) == 0) && route[m-1][n] != '#' && !have_found)
		dfs(route, visit, m-1, n, em, en);
	if (m+1 < S && (visit.count(make_pair(m+1, n)) == 0) && route[m+1][n] != '#' && !have_found)
		dfs(route, visit, m+1, n, em, en);
	if (n-1 >= 0 && (visit.count(make_pair(m, n-1)) == 0) && route[m][n-1] != '#' && !have_found)
		dfs(route, visit, m, n-1, em, en);
	if (n+1 < C && (visit.count(make_pair(m, n+1)) == 0) && route[m][n+1] != '#' && !have_found)
		dfs(route, visit, m, n+1, em, en); 
	return ;       
}
int main()
{
    string s;
    int S, C;
    int bm, bn;
    int em, en;
    while (cin >> S >> C) {
    	is_find = false;
    	have_found = false;
    	vector<string> route;
    	set< pair<int, int> > visit;
        for (int i = 0; i < S; i++) {
        	cin >> s;
        	route.push_back(s);
		}
		for (int i = 0; i < S; i++)
			for (int j = 0; j < C; j++) {
				if (route[i][j] == 'B') {
					bm = i;
					bn = j;
				}
			}
		for (int i = 0; i < S; i++)
			for (int j = 0; j < C; j++) {
				if (route[i][j] == 'E') {
					em = i;
					en = j;
				}
			}
		dfs(route, visit, bm, bn, em, en);
		if (is_find)
			cout << 'Y' << endl;
		else
			cout << 'N' << endl;
    }
    return 0;
}
