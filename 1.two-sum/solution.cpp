#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> result;
        std::vector<int> result2;

        int index = 0;
        for(int x: nums){
            result.insert({x, index});
            try{
                int X = result.at(target-x);
                
                if(X == index) throw X;

                result2.push_back(index);
                result2.push_back(X);

                return result2;
            }catch(...){}
            index++;
        }

        return result2;
    }
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
