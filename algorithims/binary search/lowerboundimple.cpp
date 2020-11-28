int lowerbound(vector<int>& nums, int target) {
        /// return index of first one that comp(item,target)==true, or nums.size() if not found
		/// comp is greater or equal to for lower_bound
		/// comp is greater for upper_bound
        int first=0, last=nums.size(), mid;
        while (first<last) {
            mid=first+((last-first)>>1); // first<=mid, mid<last
			/// if comp(item,target)==false, advance first
			// if(nums[mid]<=target) // for upper_bound
			if (nums[mid]<target) // for lower_bound
				first=mid+1; // first always increases
			else /// else recede last
				last=mid; // last always decreases (even last-first==1)
        }
        return first;
    }