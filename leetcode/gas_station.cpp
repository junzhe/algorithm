    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int result = -1;
        
        int rem = 0;
        
        int h =0; 
        int e = 0;
        
        int i = 0;
        
        int visited = 0;
        
        while((i<gas.size())&&(visited < gas.size())){
              if(rem<0){
                  rem += cost[h] - gas[h];
                  h = (h+1)%gas.size();
                  i++;
                  visited--;
              }else{
                  rem += gas[e] - cost[e];
                  visited++;
                  e = (e+1)%gas.size();
              }
        }
        
        if((visited==gas.size())&&(rem>=0)) result = h;
        
        return result;
    }
