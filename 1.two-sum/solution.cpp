#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> result;

        for(int i = 0; i < nums.size(); i++){
            int x = target - nums[i];
            if(result.find(x) != result.end()){
                return {result[x], i};
            }
            result[nums[i]] = i;
        }

        return {};
};
};

int main(void){
    std::vector<int> yadayada = {2, 7, 11, 15};

    Solution X;

    yadayada = X.twoSum(yadayada, 9);

    for(int x: yadayada){
        std::cout << x << std::endl;
    }
    
    return 0;
}
