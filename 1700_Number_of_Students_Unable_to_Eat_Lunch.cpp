#include <iostream>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ans = students.size();
        int stu_idx = 0, sand_idx = 0;
        int cnt = 0;
        while(sand_idx < sandwiches.size() && cnt <= ans){
            if(students[stu_idx] == -1){stu_idx = (stu_idx + 1) % students.size();  continue;}

            else if(students[stu_idx] == sandwiches[sand_idx]){
                sand_idx++;
                ans --;
                students[stu_idx] = -1;
                cnt = 0;
            }
            else if(students[stu_idx] != sandwiches[sand_idx]){
                cnt ++;
            }
            stu_idx = (stu_idx + 1) % students.size();
        }
        return ans;
    }
};

int main(){
    vector<int> students{1,1,1,0,0,1};
    vector<int> sandwiches{1,0,0,0,1,1};
    Solution s;
    int ans = s.countStudents(students, sandwiches);
    cout<<ans;
}