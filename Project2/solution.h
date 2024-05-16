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
    std::vector<std::string> splitString(std::string input);//2512��  ���ڷָ��ַ���

    int findFirstNonZeroIndex(const std::vector<int>& nums);//1488�� ���ص�һ����Ϊ��Ԫ�ص�����

    //bool hasDuplicate(std::stack<int> nums);
    bool hasDuplicate(std::stack<int> nums);//1488�� �ж�һ�����Ƿ����ظ��Ĳ��� �ظ�����true ���ظ�����false

    int maxProduct_convert(std::string word);//318�� ����λƫ����

    bool ifVowelLetter(std::string word);//2586�� �ж���ĸ�Ƿ���Ԫ��

    int ifDigitSumEqual(int num1);//2342�� ������λ��

    int obtainTheMinofSub(std::vector<int>& arr, int i, int j);//907�� �������������Сֵ ��һ
    int countSubIntervals(int left,int right,int i);//907�� ����arr���������䣬������������ڰ���arr[i]����С������

    /*
    * 2477��
    * std::vector<std::vector<int>>& tree:�������Ľṹ�����ڽӱ����ʽ��ʾ
    * int node: ���ǵ�ǰ���ڷ��ʵĽڵ㣨���У��ı��
    * int parent: ���ǵ�ǰ�ڵ�ĸ��ڵ�ı�š����ڸ��ڵ㣨�׶������ڵ� 0�����丸�ڵ�Ϊ -1������������ڷ�ֹDFS�����з��ص���һ�����ʵĽڵ㣬�����������������ߡ�
    * int seats: ����ÿ��������λ��
    * int& gas: ����һ�����ò���������������DFS�������ۼ��ܵ�����������
    * vector<int>& depth: ����һ�����ô��ݵ��������洢������ÿ���ڵ㵽���ڵ㣨�׶�������ȣ������룩
    */
    void dfs_2477(std::vector<std::vector<int>>& tree, int node, int parent, int seats, int& gas, std::vector<int>& depth);

    /*
    * 2132��
    * �����ά������Ϊ���Ͻǵ�i��jֵ����Ʊ�ĳ��Ϳ�
    * �ж��Ƿ����������Ϊ���ϽǷ�����Ʊ
    */
    bool ifCanBeInserted(std::vector<std::vector<int>>& grid,int i, int j, int stampHeight, int stampWidth);

    /*
    * 2415��
    * DFS �����������
    */
    void traversal(TreeNode* node1, TreeNode* node2, bool isSwap);
    
    /*
    * 2719��
    * ��������x��ÿһλ�ĺ�
    */
    int getSumOfDigit(std::string temp);

    /*
    * 2719��
    * �����ж����������ַ����Ĵ�С(��Ϊ�Ǵ��������Բ���������)
    * ���ص��ǵ�һ���Ƿ�ȵڶ����󣬴󷵻�true,���򷵻�false
    */
    bool getWarOfString(std::string stringNum1,std::string stringNum2);

    /*
    * 2719��
    * �����Դ������мӷ��Ĳ�����ÿ�μ�һ
    */
    std::string getBigNum(std::string temp);

    //106��
    TreeNode* helper(int in_left, int in_right, std::vector<int>& inorder, std::vector<int>& postorder);

    //����bfs
    void BFS(TreeNode* root);

    //2476��
    void dfs(TreeNode* node);

    //938��������������������
    void inorderTraversal(TreeNode* root);

    int dfs_70(int n);//70��

    //2810�� ��ת�ַ���
    std::string flipString(std::string s);

    //2639�� �õ����ֵĳ���
    int lengthOfNum(int num);

    //2244. �������������Ҫ����������,�ж��Ƿ���2��3�ı������Ƿ������2��3�ı���֮��
    bool is_multiple_or_sum_of_multiples(int n, int& count2, int& count3);

private:

    const std::vector<int> dx = { 0, 0, 1, -1 };
    const std::vector<int> dy = { 1, -1, 0, 0 };//���� 2258��

    int post_idx;
    std::unordered_map<int, int> idx_map;//����106��

    std::vector<int> closestNodesUse;//2476��

    int sum_938;//938��

    std::vector<int> memo;//70�ã����书��

    std::unordered_map<int, int> vis;//1553�� �������߼� -- ��̬�滮

public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2);//496

    int splitNum(int num);//2578 ��С�ͷָ�

    int sumDistance(std::vector<int>& nums, std::string s, int d);//2731 �ƶ�������
  
    std::vector<int> topStudents(std::vector<std::string>& positive_feedback, std::vector<std::string>& negative_feedback,
        std::vector<std::string>& report, std::vector<int>& student_id, int k);//2512 ��������k��ѧ��

    long long findTheArrayConcVal(std::vector<int>& nums);//2562 �ҳ�����Ĵ���ֵ

    std::vector<int> avoidFlood(std::vector<int>& rains);//1488 �����ˮ����

    int singleNumber(std::vector<int>& nums);//136 ֻ����һ�ε�����

    int countDigits(int num);//2520 ͳ�����������ֵ�λ��

    long long pickGifts(std::vector<int>& gifts, int k);//2558���������Ķ�ȡ������

    int hIndex(std::vector<int>& citations);// 274 Hָ�� 257Hָ����ͬ��ֻ���������Ϊ���ֲ��Ҽ��ɱ�Ϊlog(n)
    
    std::vector<int> smallestMissingValueSubtree(std::vector<int>& parents, std::vector<int>& nums);//2003. ÿ��������ȱʧ����С����ֵ (***)---------û����

    int maximumInvitations(std::vector<int>& favorite); //2127. �μӻ�������Ա���� (***)����+1

    int maxProduct(std::vector<std::string>& words);//318��󵥴ʳ��ȳ˻�

    int vowelStrings(std::vector<std::string>& words, int left, int right);//2586. ͳ�Ʒ�Χ�ڵ�Ԫ���ַ����� ����ϼ� δ������������

    int findTheLongestBalancedSubstring(std::string s);//2609. �ƽ�����ַ���

    int maximumMinutes(std::vector<std::vector<int>>& grid);//2258. ������� ��  ---���Ǻܶ�

    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success); //2300. �����ҩˮ�ĳɹ�����

    int minSwapsCouples(std::vector<int>& row);//765. ����ǣ��

    int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold);//1334. ��ֵ�������ھ����ٵĳ���

    int maximizeSum(std::vector<int>& nums, int k);//2656. K ��Ԫ�ص�����

    int longestAlternatingSubarray(std::vector<int>& nums, int threshold);//2760. ���ż������

    std::vector<int> maximumSumQueries(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<std::vector<int>>& queries); //2736. ���Ͳ�ѯ

    int maximumSum(std::vector<int>& nums);//2342. ��λ��������Ե�����

    int maxSubArray(std::vector<int>& nums);//53. ����������

    int minDeletion(std::vector<int>& nums);//2216. �������������ɾ����

    std::string entityParser(std::string text);//1410. HTML ʵ�������

    int countPairs(std::vector<int>& nums, int target);//2824. ͳ�ƺ�С��Ŀ����±����Ŀ

    int sumSubarrayMins(std::vector<int>& arr);//907. ���������Сֵ֮��

    bool closeStrings(std::string word1, std::string word2);//1657. ȷ�������ַ����Ƿ�ӽ�

    int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat);//2661. �ҳ���ͿԪ��

    long long minimumFuelCost(std::vector<std::vector<int>>& roads, int seats);//2477. �����׶��������ͺ�

    int minimumEffortPath(std::vector<std::vector<int>>& heights); //1631. ��С��������·�� �������dijkstra���ֽ��

    int dijkstra(const std::vector<std::vector<int>>& matrix, std::pair<int, int> start, std::pair<int, int> end);//dijkstra

    std::string makeSmallestPalindrome(std::string s);//2697. �ֵ�����С���Ĵ�

    bool possibleToStamp(std::vector<std::vector<int>>& grid, int stampHeight, int stampWidth);//2132. ����Ʊ��������ͼ

    TreeNode* reverseOddLevels(TreeNode* root);//2415. ��ת��������������

    int findPeakElement(std::vector<int>& nums);//162. Ѱ�ҷ�ֵ

    bool isAcronym(std::vector<std::string>& words, std::string s);//2828. �б�����ĸ���Դ�

    int minimumMountainRemovals(std::vector<int>& nums);//1671. �õ�ɽ�����������ɾ������

    std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices);//1276. ���˷�ԭ�ϵĺ�����������

    int isWinner(std::vector<int>& player1, std::vector<int>& player2);//2660. ��������Ϸ�Ļ�ʤ��

    int lengthOfLongestSubstring(std::string s);//3. ���ظ��ַ�����Ӵ�

    int buyChoco(std::vector<int>& prices, int money);//2706. ���������ɿ���

    int minLength(std::string s);//2696. ɾ���Ӵ�����ַ�����С����

    int count(std::string num1, std::string num2, int min_sum, int max_sum); //2719. ͳ��������Ŀ ���ò���Ǹ���ѭ����ѧϰdp

    int maximumNumberOfStringPairs(std::vector<std::string>& words); //2744. ����ַ��������Ŀ

    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder);//106. �����������������й��������

    TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder); //889. ����ǰ��ͺ���������������

    long long kthLargestLevelSum(TreeNode* root, int k);//2583. �������еĵ� K ����

    std::vector<std::vector<int>> closestNodes(TreeNode* root, std::vector<int>& queries);//2476. ��������������ڵ��ѯ

    int rangeSumBST(TreeNode* root, int low, int high);//938. �����������ķ�Χ��

    Node* connect(Node* root);//117. ���ÿ���ڵ����һ���Ҳ�ڵ�ָ�� II

    int minIncrements(int n, std::vector<int>& cost);//2673. ʹ����������·��ֵ��ȵ���С����

    bool validPartition(std::vector<int>& nums); //2369. ��������Ƿ������Ч����--��̬�滮

    int climbStairs(int n);//70. ��¥�� ���䶯̬�滮���һ�����̬�滮�ᳬʱ��+ ����

    int reachableNodes(int n, std::vector<std::vector<int>>& edges, std::vector<int>& restricted);//2368. ���������¿ɵ���ڵ����Ŀ--���������ⷨ����

    int findKOr(std::vector<int>& nums, int k);//2917. �ҳ������е� K-or ֵ

    std::string capitalizeTitle(std::string title);//2129. ����������ĸ��д

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);//4. Ѱ�����������������λ��

    std::string maximumOddBinaryNumber(std::string s); //2864. ������������

    long long maxArrayValue(std::vector<int>& nums);//2789. �ϲ��������е����Ԫ��

    long long sellingWood(int m, int n, std::vector<std::vector<int>>& prices);//2312. ��ľͷ��---��̬�滮�����Ǻܶ�

    int distinctIntegers(int n);//2549. ͳ�������ϵĲ�ͬ����

    int coinChange(std::vector<int>& coins, int amount);//322. ��Ǯ�һ�

    int countWays(std::vector<std::vector<int>>& ranges);//2580. ͳ�ƽ��ص�����ϲ�����ķ����� ����ϲ�+��������һ�������⣬֮�������˫ָ��ָ�����Ҷ˵�ķ���

    int rob(std::vector<int>& nums);//198. ��ҽ���

    int firstDayBeenInAllRooms(std::vector<int>& nextVisit);//1997. ���������з���ĵ�һ��

    std::string finalString(std::string s);//2810. ���ϼ���

    bool isValidSerialization(std::string preorder);//331. ��֤��������ǰ�����л�  ����ⷨ�����������ԣ�ֻ����������#Ƿ����

    std::string convert(std::string s, int numRows); //6. Z ���α任

    int minOperations(std::vector<int>& nums);//2009. ʹ�������������ٲ����� -- ���У�����54������(nums������1000)ʱ����ʱ������

    int maximumCount(std::vector<int>& nums);//2529. �������͸�������������

    std::string maximumBinaryString(std::string binary);//1702. �޸ĺ�����������ַ��� ����ⷨ���㣡

    int findChampion(std::vector<std::vector<int>>& grid);//2923. �ҵ��ھ� I

    int maxArea(std::vector<int>& height);//11. ʢ���ˮ������

    std::string intToRoman(int num);//12. ����ת��������

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);//15. ����֮��

    std::vector<int> findOriginalArray(std::vector<int>& changed);//2007. ��˫�������л�ԭԭ����

    int minSkips(std::vector<int>& dist, int speed, int hoursBefore);//1883. ׼ʱ�ִ�����ֳ�����С������Ϣ����-----��̬�滮

    int threeSumClosest(std::vector<int>& nums, int target);//16. ��ӽ�������֮��

    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes);//1052. ������������ϰ�

    std::vector<std::string> letterCombinations(std::string digits);//17. �绰�������ĸ��� -------- ��һ�������⣬�����Ǻܶ�

    int distanceTraveled(int mainTank, int additionalTank);//2739. ����ʻ����

    std::vector<int> findColumnWidth(std::vector<std::vector<int>>& grid);//2639. ��ѯ����ͼ��ÿһ�еĿ��

    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat);//1329. �����󰴶Խ�������

    std::vector<int> decrypt(std::vector<int>& code, int k); //1652. ��ը��

    int wateringPlants(std::vector<int>& plants, int capacity);//2079. ��ֲ�ｽˮ

    long long totalCost(std::vector<int>& costs, int k, int candidates);//2462. ��Ӷ K λ���˵��ܴ��� ---���ø�ϰ��С���� ��û��

    int minimumRefill(std::vector<int>& plants, int capacityA, int capacityB);//2105. ��ֲ�ｽˮ II

    int countTestedDevices(std::vector<int>& batteryPercentages);//2960. ͳ���Ѳ����豸

    int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel);//2391. �ռ�������������ʱ��

    int orangesRotting(std::vector<std::vector<int>>& grid);//994. ���õ�����

    int minDays(int n);//1553. �Ե� N �����ӵ��������� --- ��̬�滮

    int minimumRounds(std::vector<int>& tasks);//2244. �������������Ҫ����������

    int findMinimumTime(std::vector<std::vector<int>>& tasks);//2589. ����������������ʱ��

    long long numberOfWeeks(std::vector<int>& milestones);//1953. ����Թ������������
};