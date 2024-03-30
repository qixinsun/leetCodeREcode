/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> kk;

        std::set<string> s;
        int a, b, c;
        a = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {

            b = a + 1;
            c = c = nums.size() - 1;
            while (b < c) {
                if (nums[a] + nums[b] + nums[c] == 0) {
                    string str = to_string(nums[a]) + "," + to_string(nums[b]) +
                                 "," + to_string(nums[c]);
                    s.insert(str);
                    cout << str << endl;
                    break;
                } else if (nums[a] + nums[b] + nums[c] < 0) {
                    b++;
                } else {
                    c--;
                }
            }
            a++;
        }

        for (const std::string& str : s) {
            std::istringstream iss(str); // 创建一个输入字符串流
            std::string token;
        std::vector<int> numbers;  
            // 使用getline和逗号作为分隔符来读取子字符串
            while (std::getline(iss, token, ',')) {
                // 尝试将子字符串转换为整数
                int number;
                if (std::istringstream(token) >> number) {
                    numbers.push_back(number); // 将转换后的数字添加到vector中
                } else {
                    std::cerr << "Failed to convert token '" << token
                              << "' to a number." << std::endl;
                }
                
            }
            kk.push_back(numbers);
        }
        return kk;
    }
};