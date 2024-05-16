#pragma once
#include <iostream>
#include <vector>
#include <ranges>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <climits>
#include <functional>
#include <numeric>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class solution1 {
public:
    solution1();
    ~solution1();



private:
    std::vector<std::string> splitString(std::string input);//2512用  用于分割字符串

    int findFirstNonZeroIndex(const std::vector<int>& nums);//1488用 返回第一个不为零元素的索引

    //bool hasDuplicate(std::stack<int> nums);
    bool hasDuplicate(std::stack<int> nums);//1488用 判断一组数是否有重复的部分 重复返回true 不重复返回false

    int maxProduct_convert(std::string word);//318用 返回位偏移量

    bool ifVowelLetter(std::string word);//2586用 判断字母是否是元音

    int ifDigitSumEqual(int num1);//2342用 返回数位和

    int obtainTheMinofSub(std::vector<int>& arr, int i, int j);//907用 返回子数组的最小值 法一
    int countSubIntervals(int left,int right,int i);//907用 输入arr和左右区间，返回这个区间内包含arr[i]的最小子区间

    /*
    * 2477用
    * std::vector<std::vector<int>>& tree:整个树的结构，用邻接表的形式表示
    * int node: 这是当前正在访问的节点（城市）的编号
    * int parent: 这是当前节点的父节点的编号。对于根节点（首都，即节点 0），其父节点为 -1。这个参数用于防止DFS过程中返回到上一个访问的节点，即避免在树中往回走。
    * int seats: 这是每辆车的座位数
    * int& gas: 这是一个引用参数，用于在整个DFS过程中累计总的汽油消耗量
    * vector<int>& depth: 这是一个引用传递的向量，存储了树中每个节点到根节点（首都）的深度（即距离）
    */
    void dfs_2477(std::vector<std::vector<int>>& tree, int node, int parent, int seats, int& gas, std::vector<int>& depth);

    /*
    * 2132用
    * 传入二维矩阵、作为左上角的i和j值、邮票的长和宽
    * 判断是否能以这个点为左上角放入邮票
    */
    bool ifCanBeInserted(std::vector<std::vector<int>>& grid,int i, int j, int stampHeight, int stampWidth);

    /*
    * 2415用
    * DFS 深度优先搜索
    */
    void traversal(TreeNode* node1, TreeNode* node2, bool isSwap);
    
    /*
    * 2719用
    * 用来返回x的每一位的和
    */
    int getSumOfDigit(std::string temp);

    /*
    * 2719用
    * 用来判断两个数字字符串的大小(因为是大数，所以不能用整型)
    * 返回的是第一个是否比第二个大，大返回true,否则返回false
    */
    bool getWarOfString(std::string stringNum1,std::string stringNum2);

    /*
    * 2719用
    * 用来对大数进行加法的操作，每次加一
    */
    std::string getBigNum(std::string temp);

    //106用
    TreeNode* helper(int in_left, int in_right, std::vector<int>& inorder, std::vector<int>& postorder);

    //基本bfs
    void BFS(TreeNode* root);

    //2476用
    void dfs(TreeNode* node);

    //938借鉴，二叉树的中序遍历
    void inorderTraversal(TreeNode* root);

    int dfs_70(int n);//70用

    //2810用 反转字符串
    std::string flipString(std::string s);

    //2639用 得到数字的长度
    int lengthOfNum(int num);

    //2244. 完成所有任务需要的最少轮数,判断是否是2或3的倍数和是否可以是2和3的倍数之和
    bool is_multiple_or_sum_of_multiples(int n, int& count2, int& count3);

private:

    const std::vector<int> dx = { 0, 0, 1, -1 };
    const std::vector<int> dy = { 1, -1, 0, 0 };//这俩 2258用

    int post_idx;
    std::unordered_map<int, int> idx_map;//这俩106用

    std::vector<int> closestNodesUse;//2476用

    int sum_938;//938用

    std::vector<int> memo;//70用，记忆功能

    std::unordered_map<int, int> vis;//1553用 吃橘子逻辑 -- 动态规划

public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2);//496

    int splitNum(int num);//2578 最小和分割

    int sumDistance(std::vector<int>& nums, std::string s, int d);//2731 移动机器人
  
    std::vector<int> topStudents(std::vector<std::string>& positive_feedback, std::vector<std::string>& negative_feedback,
        std::vector<std::string>& report, std::vector<int>& student_id, int k);//2512 奖励最顶尖的k名学生

    long long findTheArrayConcVal(std::vector<int>& nums);//2562 找出数组的串联值

    std::vector<int> avoidFlood(std::vector<int>& rains);//1488 避免洪水泛滥

    int singleNumber(std::vector<int>& nums);//136 只出现一次的数字

    int countDigits(int num);//2520 统计能整除数字的位数

    long long pickGifts(std::vector<int>& gifts, int k);//2558从数量最多的堆取走礼物

    int hIndex(std::vector<int>& citations);// 274 H指数 257H指数二同理，只需把搜索变为二分查找即可变为log(n)
    
    std::vector<int> smallestMissingValueSubtree(std::vector<int>& parents, std::vector<int>& nums);//2003. 每棵子树内缺失的最小基因值 (***)---------没看懂

    int maximumInvitations(std::vector<int>& favorite); //2127. 参加会议的最多员工数 (***)不懂+1

    int maxProduct(std::vector<std::string>& words);//318最大单词长度乘积

    int vowelStrings(std::vector<std::string>& words, int left, int right);//2586. 统计范围内的元音字符串数 该题较简单 未在主函数调用

    int findTheLongestBalancedSubstring(std::string s);//2609. 最长平衡子字符串

    int maximumMinutes(std::vector<std::vector<int>>& grid);//2258. 逃离火灾 难  ---不是很懂

    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success); //2300. 咒语和药水的成功对数

    int minSwapsCouples(std::vector<int>& row);//765. 情侣牵手

    int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold);//1334. 阈值距离内邻居最少的城市

    int maximizeSum(std::vector<int>& nums, int k);//2656. K 个元素的最大和

    int longestAlternatingSubarray(std::vector<int>& nums, int threshold);//2760. 最长奇偶子数组

    std::vector<int> maximumSumQueries(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<std::vector<int>>& queries); //2736. 最大和查询

    int maximumSum(std::vector<int>& nums);//2342. 数位和相等数对的最大和

    int maxSubArray(std::vector<int>& nums);//53. 最大子数组和

    int minDeletion(std::vector<int>& nums);//2216. 美化数组的最少删除数

    std::string entityParser(std::string text);//1410. HTML 实体解析器

    int countPairs(std::vector<int>& nums, int target);//2824. 统计和小于目标的下标对数目

    int sumSubarrayMins(std::vector<int>& arr);//907. 子数组的最小值之和

    bool closeStrings(std::string word1, std::string word2);//1657. 确定两个字符串是否接近

    int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat);//2661. 找出叠涂元素

    long long minimumFuelCost(std::vector<std::vector<int>>& roads, int seats);//2477. 到达首都的最少油耗

    int minimumEffortPath(std::vector<std::vector<int>>& heights); //1631. 最小体力消耗路径 该题可用dijkstra变种解决

    int dijkstra(const std::vector<std::vector<int>>& matrix, std::pair<int, int> start, std::pair<int, int> end);//dijkstra

    std::string makeSmallestPalindrome(std::string s);//2697. 字典序最小回文串

    bool possibleToStamp(std::vector<std::vector<int>>& grid, int stampHeight, int stampWidth);//2132. 用邮票贴满网格图

    TreeNode* reverseOddLevels(TreeNode* root);//2415. 反转二叉树的奇数层

    int findPeakElement(std::vector<int>& nums);//162. 寻找峰值

    bool isAcronym(std::vector<std::string>& words, std::string s);//2828. 判别首字母缩略词

    int minimumMountainRemovals(std::vector<int>& nums);//1671. 得到山形数组的最少删除次数

    std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices);//1276. 不浪费原料的汉堡制作方案

    int isWinner(std::vector<int>& player1, std::vector<int>& player2);//2660. 保龄球游戏的获胜者

    int lengthOfLongestSubstring(std::string s);//3. 无重复字符的最长子串

    int buyChoco(std::vector<int>& prices, int money);//2706. 购买两块巧克力

    int minLength(std::string s);//2696. 删除子串后的字符串最小长度

    int count(std::string num1, std::string num2, int min_sum, int max_sum); //2719. 统计整数数目 这个貌似是个死循环，学习dp

    int maximumNumberOfStringPairs(std::vector<std::string>& words); //2744. 最大字符串配对数目

    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder);//106. 从中序与后序遍历序列构造二叉树

    TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder); //889. 根据前序和后序遍历构造二叉树

    long long kthLargestLevelSum(TreeNode* root, int k);//2583. 二叉树中的第 K 大层和

    std::vector<std::vector<int>> closestNodes(TreeNode* root, std::vector<int>& queries);//2476. 二叉搜索树最近节点查询

    int rangeSumBST(TreeNode* root, int low, int high);//938. 二叉搜索树的范围和

    Node* connect(Node* root);//117. 填充每个节点的下一个右侧节点指针 II

    int minIncrements(int n, std::vector<int>& cost);//2673. 使二叉树所有路径值相等的最小代价

    bool validPartition(std::vector<int>& nums); //2369. 检查数组是否存在有效划分--动态规划

    int climbStairs(int n);//70. 爬楼梯 经典动态规划，且基本动态规划会超时，+ 记忆

    int reachableNodes(int n, std::vector<std::vector<int>>& edges, std::vector<int>& restricted);//2368. 受限条件下可到达节点的数目--这个题这个解法不行

    int findKOr(std::vector<int>& nums, int k);//2917. 找出数组中的 K-or 值

    std::string capitalizeTitle(std::string title);//2129. 将标题首字母大写

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);//4. 寻找两个正序数组的中位数

    std::string maximumOddBinaryNumber(std::string s); //2864. 最大二进制奇数

    long long maxArrayValue(std::vector<int>& nums);//2789. 合并后数组中的最大元素

    long long sellingWood(int m, int n, std::vector<std::vector<int>>& prices);//2312. 卖木头块---动态规划，不是很懂

    int distinctIntegers(int n);//2549. 统计桌面上的不同数字

    int coinChange(std::vector<int>& coins, int amount);//322. 零钱兑换

    int countWays(std::vector<std::vector<int>>& ranges);//2580. 统计将重叠区间合并成组的方案数 区间合并+技术，这一段有问题，之后可以用双指针指向左右端点的方法

    int rob(std::vector<int>& nums);//198. 打家劫舍

    int firstDayBeenInAllRooms(std::vector<int>& nextVisit);//1997. 访问完所有房间的第一天

    std::string finalString(std::string s);//2810. 故障键盘

    bool isValidSerialization(std::string preorder);//331. 验证二叉树的前序序列化  这个解法大多情况都可以，只有数组最后的#欠考虑

    std::string convert(std::string s, int numRows); //6. Z 字形变换

    int minOperations(std::vector<int>& nums);//2009. 使数组连续的最少操作数 -- 可行，但在54个用例(nums长度是1000)时超出时间限制

    int maximumCount(std::vector<int>& nums);//2529. 正整数和负整数的最大计数

    std::string maximumBinaryString(std::string binary);//1702. 修改后的最大二进制字符串 这个解法天秀！

    int findChampion(std::vector<std::vector<int>>& grid);//2923. 找到冠军 I

    int maxArea(std::vector<int>& height);//11. 盛最多水的容器

    std::string intToRoman(int num);//12. 整数转罗马数字

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);//15. 三数之和

    std::vector<int> findOriginalArray(std::vector<int>& changed);//2007. 从双倍数组中还原原数组

    int minSkips(std::vector<int>& dist, int speed, int hoursBefore);//1883. 准时抵达会议现场的最小跳过休息次数-----动态规划

    int threeSumClosest(std::vector<int>& nums, int target);//16. 最接近的三数之和

    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes);//1052. 爱生气的书店老板

    std::vector<std::string> letterCombinations(std::string digits);//17. 电话号码的字母组合 -------- 第一道回溯题，还不是很懂

    int distanceTraveled(int mainTank, int additionalTank);//2739. 总行驶距离

    std::vector<int> findColumnWidth(std::vector<std::vector<int>>& grid);//2639. 查询网格图中每一列的宽度

    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat);//1329. 将矩阵按对角线排序

    std::vector<int> decrypt(std::vector<int>& code, int k); //1652. 拆炸弹

    int wateringPlants(std::vector<int>& plants, int capacity);//2079. 给植物浇水

    long long totalCost(std::vector<int>& costs, int k, int candidates);//2462. 雇佣 K 位工人的总代价 ---正好复习大小根堆 还没完

    int minimumRefill(std::vector<int>& plants, int capacityA, int capacityB);//2105. 给植物浇水 II

    int countTestedDevices(std::vector<int>& batteryPercentages);//2960. 统计已测试设备

    int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel);//2391. 收集垃圾的最少总时间

    int orangesRotting(std::vector<std::vector<int>>& grid);//994. 腐烂的橘子

    int minDays(int n);//1553. 吃掉 N 个橘子的最少天数 --- 动态规划

    int minimumRounds(std::vector<int>& tasks);//2244. 完成所有任务需要的最少轮数

    int findMinimumTime(std::vector<std::vector<int>>& tasks);//2589. 完成所有任务的最少时间

    long long numberOfWeeks(std::vector<int>& milestones);//1953. 你可以工作的最大周数
};