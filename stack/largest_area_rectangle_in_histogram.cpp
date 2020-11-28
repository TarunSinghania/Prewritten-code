largestRectangleArea(vector<int> &A) {
        
        stack<pair<int,int> > s;
        int ans = 0;
        for(int i =0 ; i < A.size();i++)
        {
            int popped_id =-1;
            while(!s.empty() && s.top().first >= A[i])
            {
                ans = max(ans,(i-s.top().second)*s.top().first); 
                popped_id = s.top().second;
                s.pop();
            }
            if(popped_id!=-1)
            {
                s.push(make_pair(A[i],popped_id));
            }
            else
                s.push(make_pair(A[i],i));
        }
        int i = A.size();
        while(!s.empty())
        {
            ans = max(ans,(i-s.top().second)*s.top().first);  
            s.pop();
        }
        return ans;       
}