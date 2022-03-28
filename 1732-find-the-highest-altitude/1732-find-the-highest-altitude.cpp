/*class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sol = 0;
        int curr = 0;
        for(int i=0;i<gain.size();i++){
            curr += gain[i];
            sol = max(sol,curr);
        }
        return sol;
    }
};*/
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest=0;
        int altitude=0;
        for(int g:gain)
        {
            altitude+=g;
            if(altitude>highest) highest=altitude;
            //highest=max(altitude,highest);
        }
        return highest;
    }
};