class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int remainDays = 0;
        vector<vector<int>> mergedMeetings;
        
        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < meetings.size(); i++) {
            if (i == 0) mergedMeetings.push_back(meetings[i]);
            else if (meetings[i][0] > mergedMeetings.back()[1]) mergedMeetings.push_back(meetings[i]);
            else {
                vector<int> vec;
                vec.push_back(mergedMeetings.back()[0]);
                vec.push_back(max(mergedMeetings.back()[1], meetings[i][1]));
                mergedMeetings.push_back(vec);
            }
        }

        for (int i = 0; i < mergedMeetings.size(); i++) {
            if (i == 0) remainDays += mergedMeetings[i][0] - 1;
            else remainDays += max(0, mergedMeetings[i][0] - mergedMeetings[i - 1][1] - 1);

            if (i == mergedMeetings.size() - 1) remainDays += max(0, days - mergedMeetings[i][1]);
        }

        return remainDays;
    }
};