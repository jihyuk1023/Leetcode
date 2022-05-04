// 구간의 종점을 기준으로 오름차순 정렬
bool cmp(vector<int> &v1, vector<int> &v2){
    if(v1[1] == v2[1]) return v1[0] < v2[0];
    return v1[1] < v2[1];
}

class Solution {
public:
    // 최소 중복 영역 개수 <=> 최대 중복되지 않는 영역 개수
    // 문제를 바꾸어서 생각해야 한다.
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        return intervals.size() - greedy(intervals);
    }
    
    int greedy(vector<vector<int>>& intervals){
        int count = 0;
        int line = INT_MIN;
        for(vector<int> inter: intervals){
            int start = inter[0], end = inter[1];
            if(start < line) continue;
            
            line = end;
            count++;
        }
        return count;
    }
    
};