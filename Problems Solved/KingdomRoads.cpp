vector<int> citiesConquering(int n, vector<vector<int>> roads) {
    
    vector<int> days(n+5,-1) , graph[n+5] , conqtoday ;
    bool conq[n+5]={false};
    
    for(int i=0 ; i<roads.size() ; i++)
    {
        int x=roads[i][0] , y=roads[i][1] ;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    bool cap=true ;
    int day=1 ;
    while(cap)
    {
        conqtoday.clear();
        cap=false ;
        for(int i=0 ; i<n ; i++)
        {
            int fre=0 ;
            if(conq[i]) continue ;
            for(auto city : graph[i])
            {
                if(!conq[city]) fre++ ;
            }
            if(fre<=1) { conqtoday.push_back(i) ; cap=true ; }
        }
        forn(i,conqtoday.size()) 
        {
            int city=conqtoday[i];
            conq[city]=true ;
            days[city]=day ;
        }
        day++ ;
    }
    return days ;
}
'+
