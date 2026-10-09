/*
Problem: Meeting Rooms II / Minimum Meeting Rooms
Platform: GeeksforGeeks
Link: https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1

Approach:
Sort the start and end times separately. Use two pointers to track
meeting starts and ends. If a meeting starts before the earliest
ongoing meeting ends, allocate another room. Otherwise, free a room.
Track the maximum number of rooms occupied simultaneously.

Time: O(n log n)
Space: O(1) excluding sorting space
*/

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int room=0,res=INT_MIN,i=0,j=0;
        while(i<start.size()&&j<end.size()){
            if(start[i]<end[j]){
                room++;
                res=max(res,room);
                i++;
            }
            else{
                room--;
                j++;
            }
        }
        return res;
    }
};