#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct ListNode 
{
    std::int32_t val;
    ListNode* next;
    ListNode(std::int32_t x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /* 1. Two Sum */
    std::vector<std::int32_t> twoSum(std::vector<std::int32_t>& nums, std::int32_t target) 
    {
        std::vector<std::int32_t> results{ 0, 0 };
        for (std::uint32_t i = 0; i < nums.size(); i++)
        {
            for (std::uint32_t j = i + 1; j < nums.size(); j++)
            {
                if (target == nums.at(i) + nums.at(j))
                {
                    results.at(0) = i;
                    results.at(1) = j;
                    return results;
                }
            }
        }
        return results;
    }

    /* 1480. Running Sum of 1d Array*/
    std::vector<std::int32_t> runningSum(std::vector<std::int32_t>& nums) 
    {
        std::int32_t nums_size = nums.size();
        for (std::int32_t i = 1; i < nums_size; i++)
        {
            if (i > 0)
                nums[i] = nums[i] + nums[i-1];
        }
        return nums;
    }

    /* 1470. Shuffle the Array */
    std::vector<std::int32_t> shuffle(std::vector<std::int32_t>& nums, std::int32_t n) 
    {
        std::vector <std::int32_t> result;
        for (std::int32_t i = 0; i < n; i++)
        {
            result.push_back(nums[i]);
            result.push_back(nums[i + n]);
        }
        return result;
    }

    /* 1431. Kids With the Greatest Number of Candies */
    std::vector<bool> kidsWithCandies(std::vector<std::int32_t>& candies, std::int32_t extraCandies)
    {
        std::int32_t array_size = candies.size();
        std::int32_t array_max = candies[0];
        std::vector<bool> result;
        for (std::int32_t i = 0; i < array_size; i++)
        {
            if (candies[i] >= array_max)
            {
                array_max = candies[i];
            }
        }
        for (std::int32_t i = 0; i < array_size; i++)
        {
            if (candies[i]+extraCandies >= array_max)
            {
                result.push_back(true);
            }
            else
                result.push_back(false);
        }
        return result;
    }

    /* 1512. Number of Good Pairs */
    std::int32_t numIdenticalPairs(std::vector<std::int32_t>& nums)
    {
        std::int32_t pair_result = 0;
        std::int32_t nums_size = nums.size();
        for (std::int32_t i = 0; i < nums_size; i++)
        {
            for (std::int32_t j = i + 1; j < nums_size; j++)
            {
                if (nums[i] == nums[j] && i < j)
                    pair_result++;
            }
        }
        return pair_result;
    }

    /* 1108. Defanging an IP Address */
    std::string defangIPaddr(std::string address)
    {
        for (std::uint32_t i = 0; i < address.length(); i++)
        {
            if (address[i] == '.')
            {
                address.insert(i, "[");
                address.insert(i + 2, "]");
                i = i + 2;
            }
        }
        return address;
    }

    /* 771. Jewels and Stones */
    std::int32_t numJewelsInStones(std::string J, std::string S)
    {
        std::int32_t jewels_found = 0;

        for (std::uint32_t i = 0; i < J.size(); i++)
        {
            for (std::uint32_t j = 0; j < S.size(); j++)
            {
                if (J[i] == S[j])
                {
                    jewels_found++;
                }
            }
        }
        return jewels_found;
    }

    /* 1342. Number of Steps to Reduce a Number to Zero */
    std::int32_t numberOfSteps(std::int32_t num) 
    {
        std::int32_t steps_number = 0;
        while (num != 0)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
                num -= 1;
            steps_number++;
        }
        return steps_number;
    }

    /* 1528. Shuffle String */
    std::string restoreString(std::string s, std::vector<std::int32_t>& indices)
    {
        std::string s_copy = s;
        std::uint32_t indices_size = indices.size();

        for (std::uint32_t i = 0; i < indices_size; i++)
        {
            if (indices[i] != i)
            {
                s_copy[indices[i]] = s[i];
            }
        }
        return s_copy;
    }

    /* 58. Length of Last Word */
    std::int32_t lengthOfLastWord(std::string s)
    {
        std::uint32_t last_word{ 0 };
        std::uint32_t found_non_word = 0;
        for (std::uint32_t i = s.length() - 1; i >= 0; i--)
        {
            if ((s.at(i) >= 'a' && s.at(i) <= 'z') || (s.at(i) >= 'A' && s.at(i) <= 'Z'))
            {
                found_non_word = 1;
                last_word++;
            }
            else
            {
                if (found_non_word == 1)
                    return last_word;
            }
        }
        return last_word;
    }

    /* 66. Plus One */
    std::vector<std::int32_t> plusOne(std::vector<std::int32_t>& digits)
    {
        std::uint32_t remainder = 1;

        for (std::int32_t i = digits.size() - 1; i >= 0; i--)
        {
            if (i == 0 && digits[i] == 9 && remainder == 1)
            {
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
            }
            else
            {
                if (digits[i] == 9 && remainder == 1)
                {
                    digits[i] = 0;
                    remainder = 1;
                }
                else
                {
                    digits[i] += remainder;
                    remainder = 0;
                }
            }
        }

        return digits;
    }

    /* 1365. How Many Numbers Are Smaller Than the Current Number */
    std::vector<std::int32_t> smallerNumbersThanCurrent(std::vector<std::int32_t>& nums)
    {
        std::int32_t counter = 0;
        std::vector<std::int32_t> results{};
        /* list iterator loop */
        for (std::int32_t i = 0; i < nums.size(); i++)
        {
            /* comparison loop*/
            for (std::int32_t j = 0; j < nums.size(); j++)
            {
                if (nums[i] != nums[j] && nums[i] > nums[j])
                    counter++;
            }
            results.push_back(counter);
            counter = 0;
        }
        return results;
    }

    /* 136. Single Number */
    std::int32_t singleNumber(std::vector<std::int32_t>& nums)
    {
        std::sort(nums.begin(), nums.end());
        for (std::int32_t i = 0; i < nums.size(); i++)
        {
            if (i == nums.size() - 1)
                return nums.at(i);
            else if(nums.at(i) != nums.at(i + 1))
                return nums.at(i);
            i++;
        }
        return 0;
    }

    /* 344. Reverse String */
    void reverseString(std::vector<char>& s)
    {
        std::int32_t size = s.size() -1;
        for (std::int32_t i = 0; i < s.size() / 2; i++)
        {
            std::swap(s[i], s[size]);
            size--;
        }
    }

    /* 237. Delete Node in a Linked List */
    /**
     * Definition for singly-linked list.
    * struct ListNode {
    *     std::int32_t val;
    *     ListNode *next;
    *     ListNode(std::int32_t x) : val(x), next(NULL) {}
    * };
 */
    void deleteNode(ListNode* node) 
    {
        node->next = node->next;
    }

    /* 412. Fizz Buzz */
    std::vector<std::string> fizzBuzz(std::int32_t n)
    {
        std::vector<std::string> result;
        result.reserve(15);
        for (std::int32_t i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                result.push_back("FizzBuzz");
            }
            else if (i % 3 == 0)
            {
                result.push_back("Fizz");
            }
            else if (i % 5 == 0)
            {
                result.push_back("Buzz");
            }
            else
            {
                std::string str = std::to_string(i);
                result.push_back(str);
            }
        }
        return result;
    }

    /* 217. Contains Duplicate*/
    bool containsDuplicate(std::vector<std::int32_t>& nums) 
    {
        if (nums.size() != 0)
        {
            std::sort(nums.begin(), nums.end());
            for (std::uint32_t i = 0; i < nums.size() - 1; i++)
            {
                if (nums.size() == 1 || (i == 1 && nums.size() == 2))
                    return false;
                if (nums.at(i) == nums.at(i + 1) && nums.size() > 1)
                    return true;
            }
        }
        return false;
    }

    /* 169. Majority Element */
    int majorityElement(std::vector<std::int32_t>& nums)
    {
        /*
        std::map<std::uint32_t, uint32_t> map;
        for (const auto& it : nums)
        {
            map[it]++;
        }

        uint32_t prev_appear = 0;
        uint32_t majorityElem = 0;
        for (const auto& it : map)
        {
            if (it.second > prev_appear)
            {
                prev_appear = it.second;
                majorityElem = it.first;
            }
        }
        return majorityElem;
        */
        std::map<std::uint32_t, uint32_t> map;
        for (const auto &it : nums)
        {
            map[it]++;
            if (map[it] > nums.size() / 2)
                return it;
        }
    }

    /* 1672. Richest Customer Wealth */
    int maximumWealth(std::vector<std::vector<int>>& accounts) 
    {
        uint32_t max_wealth = 0;
        for (const auto& it : accounts)
        {
            uint32_t wealth = 0;
            for (uint32_t i = 0; i < it.size(); i++)
            {
                wealth += it[i];
            }
            if (wealth > max_wealth)
                max_wealth = wealth;
        }
        return max_wealth;
    }

    /* 969. Pancake Sorting */
    std::vector<int> pancakeSort(std::vector<int>& arr) 
    {
        uint32_t k = 0;

    }
};

int main()
{
    Solution s;

    /*
    std::vector<std::int32_t> nums{ 2, 7, 11, 15 };
    std::int32_t target = 9;
    s.twoSum(nums, target);
    */

    /*
    std::vector<std::int32_t> input_array = { 1,1,1,1,1 };
    s.runningSum(input_array);
    */

    /*
    std::vector<std::int32_t> input_array = { 2,5,1,3,4,7 };
    std::int32_t n = 3;
    s.shuffle(input_array, n);
    */

    /*
    std::vector<std::int32_t> candies = { 1,3,9 };
    std::int32_t extraCandies = 4;
    s.kidsWithCandies(candies, extraCandies);
    */

    /*
    std::vector<std::int32_t> pairs = { 1,2,3 };
    s.numIdenticalPairs(pairs);
    */

    /*
    std::string input { "255.100.255.1" };
    s.defangIPaddr(input);
    */

    /*
    std::string jewels{ "z" };
    std::string stones{ "ZZ" };
    s.numJewelsInStones(jewels, stones);
    */

    /*
    std::int32_t num = 123;
    s.numberOfSteps(num);
    */

    /*
    std::string shuffle_string{ "codeleet" };
    std::vector<std::int32_t> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    s.restoreString(shuffle_string, indices);
    */

    /*
    std::string input{ "Hello World" };
    s.lengthOfLastWord(input);
    */

    /*
    std::vector<std::int32_t> digits { 1, 9, 9 };
    s.plusOne(digits);
    */

    /*
    std::vector<std::int32_t> nums = { 0, 0, 0 };
    s.smallerNumbersThanCurrent(nums);
    */

    /*
    std::vector<std::int32_t> nums = { 2,4,1,1,2 };
    s.singleNumber(nums);
    */

    /*
    std::vector<char> strng {'h', 'e', 'l', 'l', 'o' };
    s.reverseString(strng);
    */

    //ListNode linked_l;
    /*
    std::int32_t n = 15;
    s.fizzBuzz(n);
    */

    /*
    std::vector<std::int32_t> cont_dup{  };
    std::cout << s.containsDuplicate(cont_dup);
    */

    /*
    std::vector<std::int32_t> maj_elem{ 2,2,1,1,1,2,2 };
    std::cout << s.majorityElement(maj_elem);
    */

    std::vector<std::vector<int>> accounts = { {1,2,3},{7,1,3},{1,9,5} };
    std::cout << s.maximumWealth(accounts);
    return 0;
}