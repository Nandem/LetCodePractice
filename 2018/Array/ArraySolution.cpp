#include <iostream>
#include <vector>
#include <algorithm>
#include "../../Utils/CommonUtil.h"

using namespace std;

class Solution
{
public:
    /**
     * 题目：删除已排序数组重复元素
     * @param nums 原始数组
     * @return 去重后的数组元素个数
     */
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = nums.size() - 1; j > i; --j)
            {
                if (nums[i] == nums[j])
                {
                    nums.erase(nums.begin() + j);
                }
            }
        }

        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); it++)
        {
            cout << *it << '\0';
        }

        return nums.size();
    }

    /**
     * 题目：买卖股票的最佳时机 II
     * 思路：贪心
     * @param prices 原始数组
     * @return 所能获取的最大利润
     */
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty()) return 0;

        int sum = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                sum += prices[i] - prices[i - 1];
            }
        }
        return sum;
    }

    /**
     * 题目：旋转数组
     * 描述：给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数
     * @param nums
     * @param k
     */
    void rotate(vector<int> &nums, int k)
    {
        if (nums.empty()) return;

        CommonUtil::print(nums);

        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());

        CommonUtil::print(nums);
    }

    /**
     * 题目：存在重复
     * 描述：给定一个整数数组，判断是否存在重复元素。
     * 注意：需要判空，存在传入数组为空的情况
     * @param nums
     * @return
     */
    bool containsDuplicate(vector<int> &nums)
    {
        if (nums.empty()) return false;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] == nums[i])
            {
                return true;
            }
        }

        return false;
    }

    /**
     * 题目：只出现一次的数字（给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。）
     * 描述：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
     * 巧妙：
     * int singleNumber(vector<int> &nums)
     * {
     *     int ret=0;//异或计算
     *    for(int i=0;i<nums.size();i++)
     *    {
     *        ret^=nums[i];
     *    }
     *    return ret;
     * }
     *
     * @param nums
     * @return
     */
    int singleNumber(vector<int> &nums)
    {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        CommonUtil::print(nums);

        for(int i = 0; i < nums.size(); i++)
        {
            if (i - 1 < 0)
            {
                if (nums[i + 1] != nums[i])
                {
                    return nums[i];
                }
            }
            else if (i + 1 > nums.size())
            {
                if (nums[i - 1] != nums[i])
                {
                    return nums[i];
                }
            }
            else if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1])
            {
                return nums[i];
            }
        }
    }
};

int
main()
{
    auto *solution = new Solution();

    int arrToBeJudgeDuplicate[] = {4,1,2,1,2};
    vector<int> ajd;
    ajd.reserve(CommonUtil::length(arrToBeJudgeDuplicate));
    ajd.insert(ajd.begin(), &arrToBeJudgeDuplicate[0],
               &arrToBeJudgeDuplicate[CommonUtil::length(arrToBeJudgeDuplicate)]);

    cout << solution->singleNumber(ajd);

    return 0;
}