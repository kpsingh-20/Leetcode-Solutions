class Solution {
public:
    
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     inf                 	1e9

    
int maxPoints(vvi& points) 
{
	int ans = 1;
	for(int i=0; i<points.size(); i++){
		std::map<double, int> map;
		for(int j=0; j<points.size(); j++){
			if(i == j) continue;

			double s;
			if((points[j][0] - points[i][0] == 0)){
				s = inf;
			}
			else
				s = double(points[j][1] - points[i][1]) / double(points[j][0] - points[i][0]);


			map[s]++;
			// cout << s << " " << map[s];br;
			ans = max(ans, map[s] + 1);
		}
	}

	return ans;
}
    
};