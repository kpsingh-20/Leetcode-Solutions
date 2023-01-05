class Solution {
public:
    
#define     all(a)              a.begin(),a.end()

int findMinArrowShots(vector<vector<int>>& points) 
{
	sort(all(points));

	int last = points[0][1];

	int ans = 1;
	for(int i=0; i<points.size(); i++)
	{
		if(points[i][0] > last){
			ans++;
			last = points[i][1];
		}
		last = min(last, points[i][1]);
	}

	return ans;

}
};