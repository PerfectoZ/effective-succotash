class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses);
        vector<int> ct(numCourses);
        for(vector<int> p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            ct[p[0]]++ ;
        }
        set<pair<int,int>> s ; // contains <no of course required , course no>
        for(int i=0 ; i<numCourses ; i++)
        {
            s.insert(make_pair(ct[i],i));
        }
        vector<int> ans ;
        while(!s.empty())
        {
            auto p=*(s.begin());
            if(p.first)
            {
                ans.clear();
                break ;
            }
            ans.push_back(p.second);
            s.erase(p);
            for(auto i : graph[p.second])
            {
                s.erase({ct[i],i});
                ct[i]-- ;
                s.insert({ct[i],i});
            }
        }
        return ans ;
    }
};
