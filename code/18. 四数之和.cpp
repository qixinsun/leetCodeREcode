/*
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

 

示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
 

提示：

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> kk;

        std::set<string> s;
        int a, b, c, d;
        a = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {

            b = a + 1;           // 第二个指针
            c = b + 1;           // 第三个指针
            d = nums.size() - 1; // 第四个指针
            while (b < c && c < d) {
                if (nums[a] + nums[b] + nums[c] + nums[d] == target) {
                    string str = to_string(nums[a]) + "," + to_string(nums[b]) +
                                 "," + to_string(nums[c]) + "," + to_string(nums[d]);
                    s.insert(str);
                    cout << str << endl;
                    if(c < d-1){
                        c++;
                    }else{
                        b++;
                        c=b+1;
                    }
                } else if (nums[a] + nums[b] + nums[c] + nums[d] < target) {
                    if(c < d-1){
                        c++;
                    }else{
                        b++;
                        c=b+1;
                    }
                } else {
                    if(c<d-1)
                    {
                        d--;
                    }else{
                        d--;
                        c=b+1;
                    }
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