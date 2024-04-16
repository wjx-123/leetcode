#include "solution.h"

solution1::solution1()
{
}

solution1::~solution1()
{
}

std::vector<int> solution1::nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::vector<int> result;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j] && j != nums2.size()-1)//�ҵ�nums2��һ��������λ��
            {
                while (j < nums2.size() - 1)
                {
                    if (nums2[j + 1] > nums1[i])
                    {
                        result.push_back(nums2[j + 1]);
                        break;
                    }
                    else
                    {
                        result.push_back(-1);
                        break;
                    }
                }
            }
            else if (nums1[i] == nums2[j] && j == nums2.size() - 1) {
                if (nums2[j] > nums1[i])
                {
                    result.push_back(nums2[j]);
                }
                else {
                    result.push_back(-1);
                }
                
                break;
            }

        }
    }
    return result;
}

int solution1::splitNum(int num)
{
    std::string num1, num2;
    std::vector<int> eachBitOfInteger;
    for (int i = 0; i < std::to_string(num).size(); i++)
    {
        eachBitOfInteger.push_back(int(std::to_string(num)[i] - '0'));//��ȡÿһλ
    }
    std::sort(eachBitOfInteger.begin(), eachBitOfInteger.end());
    int i = 0, j = 1;
    for (i,j; j < eachBitOfInteger.size(); i+=2,j+=2)
    {
        num1 = num1 + std::to_string(eachBitOfInteger[i]);
        num2 = num2 + std::to_string(eachBitOfInteger[j]);
    }
    std::cout << num1 << "**" << num2 << std::endl;
    if (eachBitOfInteger.size() % 2 != 0)
    {
        num1 = num1 + std::to_string(eachBitOfInteger[eachBitOfInteger.size()-1]);
    }
    return std::stoi(num1) + std::stoi(num2);
}

int solution1::sumDistance(std::vector<int>& nums, std::string s, int d)
{
    //1���Լ��� ����󼸸���������ʱ ����̫��Խ��
    //auto result = 0;
    //for (int i = 0; i < nums.size(); i++)
    //{
    //    std::cout << s[i] << std::endl;
    //    s[i] == 'L' ? nums[i]-=d : nums[i]+=d;
    //}
    //for (int i = 0,j = 1; i < nums.size()-1; )
    //{
    //    result += std::abs(nums[i] - nums[j]);
    //    if (j < nums.size() - 1)
    //    {//��һ�ֻ�û�����һ����
    //        j++;
    //    }
    //    else
    //    {
    //        i++;
    //        j = i + 1;
    //    }
    //}
    //return result;

    //2���������ĵ�
    static constexpr int mod = 1e9 + 7;//�����Ǹ������ӵ�
    long long result = 0;
    std::vector<long long> temp(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        s[i] == 'L' ? nums[i] -= d : nums[i] += d;
        temp[i] = nums[i];
    }
    sort(temp.begin(), temp.end());
    int n = nums.size();
    for (int i = 1; i < temp.size(); i++)
    {
        //result += std::abs(temp[i] - temp[j]);
        result += 1ll * (temp[i] - temp[i - 1]) * i % mod * (n - i) % mod;//�����Ǹ������ӵ� û����
        result %= mod;//�����Ǹ������ӵ�
    }
    return result;
}

std::vector<std::string> solution1::splitString(std::string input) {
    std::vector<std::string> words;

    std::stringstream stringstr(input); // �����ַ��������������ַ�����������
    std::string word;

    while (stringstr >> word) { // ʹ�ÿո���Ϊ�ָ�����ȡ���ʣ�������vector��
        words.push_back(word);
    }
    return words;
}

std::vector<int> solution1::topStudents(std::vector<std::string>& positive_feedback, std::vector<std::string>& negative_feedback, std::vector<std::string>& report, std::vector<int>& student_id, int k)
{
    std::vector<std::vector<int>> score_student;
    std::unordered_map<std::string, int> standard;//��ű�׼
    for (int i = 0; i < positive_feedback.size(); i++)//�ֱ�Ѻôʺͻ��ʱ��� �������
    {
        standard.insert(std::pair<std::string,int>(positive_feedback[i],3));
    }
    for (int i = 0; i < negative_feedback.size(); i++)
    {
        standard.insert(std::pair<std::string, int>(negative_feedback[i], -1));
    }
    //��ѭ������ÿ��ѧ���������� Ȼ��������� ��������id��ͬ���� ����id���� Ȼ�󷵻�ǰk��
    for (int i = 0; i < student_id.size(); i++)
    {
        int score = 0;
        std::vector<std::string> words = splitString(report[i]);
        for (int j = 0; j < words.size(); j++)
        {
            standard.count(words[j]) ? score += standard[words[j]] : score += 0;
        }
        score_student.push_back({-score,student_id[i]});
    }
    std::sort(score_student.begin(), score_student.end());
    std::vector<int> result;
    for (int i = 0; i < k; i++)
    {
        result.push_back(score_student[i][1]);
    }
    score_student.clear();
    standard.clear();
    return result;
}

long long solution1::findTheArrayConcVal(std::vector<int>& nums)
{
    long long result = 0;
    for (int i = 0,j =nums.size()-1; i < j || i == j; i++, j--)
    {
        result += i == j ?  nums[i] :  std::stoi(std::to_string(nums[i]) + std::to_string(nums[j]));
    }
    return result;
}

int solution1::findFirstNonZeroIndex(const std::vector<int>& nums) 
{
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            return i;
        }
    }

    // ���δ�ҵ���Ϊ0��Ԫ�أ��򷵻�-1����ʾδ�ҵ���
    return -1;
}

bool solution1::hasDuplicate(std::stack<int> nums)
{
    std::unordered_set<int> numSet;
    while(nums.empty() != true) {
        int num = nums.top();
        if (numSet.count(num) > 0) {
            return true;  // ����������Ѵ��ڸ�����������ظ�
        }
        numSet.insert(num);  // ���򽫸������뼯��
        nums.pop();
    }
    return false;  // ����������������û���ҵ��ظ�����
}

int solution1::maxProduct_convert(std::string word)
{
    int ans = 0;
    for (int i = 0; i < word.length(); i++)
    {
        ans |= 1 << (word[i] - 'a');
    }
    return ans;
}

bool solution1::ifVowelLetter(std::string word)
{
    if (word == "a" || word == "e" || word == "i" || word == "o" || word == "u")
    {
        return true;
    }
    return false;
}

int solution1::ifDigitSumEqual(int num1)
{
    std::string numStr1 = std::to_string(num1);  // ������ת��Ϊ�ַ���
    int sum1 = 0;

    for (char digit : numStr1) {
        int digitNum = digit - '0';  // ���ַ�ת��Ϊ����
        sum1 += digitNum;
    }
    return sum1;
}

int solution1::obtainTheMinofSub(std::vector<int>& arr, int i, int j)
{
    int res = 0;
    if (i == j)
    {
        return arr[i];
    }
    else 
    {
        std::vector<int> sor;
        for (int temp = i; temp <= j; temp++)
        {
            sor.push_back(arr[temp]);
        }
        std::sort(sor.begin(),sor.end());
        res = sor[0];
    }
    return res;
}

int solution1::countSubIntervals(int left, int right, int i)
{
    int count = 0;
    int n = right - left + 1;

    // ������ i Ϊ���ĵ����������
    int centerCount = std::min(i - left + 1, right - i + 1);
    count += centerCount;

    // �������Ҳ�ֱ������� i �����������
    for (int len = 1; len <= n / 2; len++) {
        int leftCount = std::max(0, len - centerCount);
        int rightCount = std::max(0, len - centerCount + 1);
        count += leftCount + rightCount;
    }

    // ������������ [left, right] ����
    count++;

    return count;
}

void solution1::dfs_2477(std::vector<std::vector<int>>& tree, int node, int parent, int seats, int& gas, std::vector<int>& depth)
{
    depth[node] = (parent == -1) ? 0 : depth[parent] + 1;
    gas += depth[node] / seats;
    for (auto neighbor : tree[node])
    {
        if (neighbor != parent) 
        {
            dfs_2477(tree,neighbor,node,seats,gas,depth);
        }
    }
}

bool solution1::ifCanBeInserted(std::vector<std::vector<int>>& grid, int i, int j, int stampHeight, int stampWidth)
{
    int rows = grid.size();
    int cols = grid[0].size();
    // �����Ʊ�Ƿ���ȫλ��grid��
    if (i + stampHeight > rows || j + stampWidth > cols)
    {
        return false;
    }
    // �����Ʊ�����Ƿ����������������Ƿ���0��
    for (int x = i; x < i + stampHeight; ++x) {
        for (int y = j; y < j + stampWidth; ++y) {
            if (grid[x][y] != 0 && grid[x][y] != 2) {  // 0��ʾ��������
                return false;
            }
        }
    }
    // ���Է��룬����Щλ����Ϊ2 �����Ѿ����� �����Ը���
    for (int x = i; x < i + stampHeight; ++x) {
        for (int y = j; y < j + stampWidth; ++y) {
            if (grid[x][y] != 1) {  // 0��ʾ��������
                grid[x][y] = 2;
            }
        }
    }

    return true;
}

void solution1::traversal(TreeNode* node1, TreeNode* node2, bool isSwap)
{
    if (!node1)
    {//�սڵ�
        return;
    }
    if (isSwap)
    {
        std::swap(node1->val, node2->val);
    }
    isSwap != isSwap;
    traversal(node1->left, node2->right, isSwap);
    traversal(node1->right, node2->left, isSwap);
}

int solution1::getSumOfDigit(std::string temp)
{
    int sum = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        sum += (int)temp[i];
    }
    return sum;
}

bool solution1::getWarOfString(std::string stringNum1, std::string stringNum2)
{
    if (stringNum1.length() > stringNum2.length())
    {
        return true;
    }
    else if (stringNum1.length() < stringNum2.length())
    {
        return false;
    }
    else 
    {
        for (int i = 0; i < stringNum1.size(); i++)
        {
            if ((int)stringNum1[i] == (int)stringNum2[i])
            {
                continue;
            }
            if ((int)stringNum1[i] < (int)stringNum2[i]) //��ǰ�����
            {
                return false;
            }
        }
        return false;//����
    }
    
}

std::string solution1::getBigNum(std::string temp)
{
    std::string result;
    int carry = 1; // ��ʼ��λΪ1

    // ���ַ��������һ���ַ���ʼ����
    for (int i = temp.length() - 1; i >= 0; i--) {
        int digit = temp[i] - '0'; // ���ַ�ת��Ϊ����

        // ���Ͻ�λ
        int sum = digit + carry;

        // ���㵱ǰλ��ֵ
        int new_digit = sum % 10;

        // ���½�λ
        carry = sum / 10;

        // ���µ������ַ����뵽����ַ����Ŀ�ͷ
        result.insert(result.begin(), '0' + new_digit);
    }

    // ������λ�н�λ����ӵ�����Ŀ�ͷ
    if (carry > 0) {
        result.insert(result.begin(), '0' + carry);
    }

    return result;
}

TreeNode* solution1::helper(int in_left, int in_right, std::vector<int>& inorder, std::vector<int>& postorder)
{
    // �������û�нڵ㹹��������ˣ��ͽ���
    if (in_left > in_right) {
        return nullptr;
    }
    // ѡ�� post_idx λ�õ�Ԫ����Ϊ��ǰ�������ڵ�
    int root_val = postorder[post_idx];
    TreeNode* root = new TreeNode(root_val);

    // ���� root ����λ�÷ֳ�������������
    int index = idx_map[root_val];

    // �±��һ
    post_idx--;
    // ����������
    root->right = helper(index + 1, in_right, inorder, postorder);
    // ����������
    root->left = helper(in_left, index - 1, inorder, postorder);
    return root;
}

void solution1::BFS(TreeNode* root)
{
    if (!root) return; // �����Ϊ�գ���ֱ�ӷ���

    std::queue<TreeNode*> queue;
    queue.push(root); // �����ڵ�������

    while (!queue.empty()) {
        TreeNode* current = queue.front(); // ���ʶ���ǰ�˵Ľڵ�
        queue.pop(); // �����ʹ��Ľڵ�Ӷ������Ƴ�

        std::cout << current->val << " "; // ��ӡ��ǰ�ڵ��ֵ

        // �����ǰ�ڵ������ӽڵ㣬�����ӽڵ�������
        if (current->left != nullptr) {
            queue.push(current->left);
        }

        // �����ǰ�ڵ������ӽڵ㣬�����ӽڵ�������
        if (current->right != nullptr) {
            queue.push(current->right);
        }
    }
}

void solution1::dfs(TreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }
    dfs(node->left);
    closestNodesUse.push_back(node->val);
    dfs(node->right);
}

void solution1::inorderTraversal(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int solution1::dfs_70(int n)
{
    if (n <= 1) {
        return 1;
    }
    int& res = memo[n];
    if (res) {
        return res;
    }
    return res = dfs_70(n - 1) + dfs_70(n - 2);
}

std::string solution1::flipString(std::string s)
{
    std::string res;
    for (int i = s.size() - 1; i >= 0; i--) 
    {
        res += s[i];
    }
    return res;
}


std::vector<int> solution1::avoidFlood(std::vector<int>& rains)
{
    int temp = findFirstNonZeroIndex(rains);//��һ����Ϊ��Ԫ�ص�����
    std::vector<int> ans(rains.size());
    std::stack<int> floodCup;
    if (temp == -1) {//rainsȫ����0 ��������
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = -1;
        }
        return ans;
    }
    for (int i = temp; i < rains.size(); i++)
    {
        //rains[i] > 0 ? floodCup.push(rains[i]) : floodCup.empty() ? (std::cout<<"ջ��"<<std::endl, 0) : floodCup.pop();//>0 ��ջ ��֮��ջ
        if (rains[i] > 0)
        {
            floodCup.push(rains[i]);
            if (hasDuplicate(floodCup) == true)//���ظ�Ԫ����ջ
            {
                std::vector<int> ans1;
                return ans1;
            }
        }
        else 
        {
            if (floodCup.empty()) {
                std::cout << "ջ��" << std::endl;
            }
            else {
                floodCup.pop();
            }
        }
    }
    bool ifHavePro = hasDuplicate(floodCup);
    if (ifHavePro == true)//���ظ�Ԫ�� ���޷���
    {
        std::vector<int> ans1;
        return ans1;
    }
    for (int i = 0; i < rains.size(); i++)
    {
        if (i < temp) 
        {
            ans[i] = -1;
        }
        else
        {
            //rains[i] > 0 ? ans[i] = -1 : ans[i] = floodCup.top(), floodCup.pop();
            if (rains[i] > 0)
            {
                ans[i] = -1;
            }
            else 
            {
                if (floodCup.empty())
                {
                    ans[i] = 1;
                }
                else {
                    ans[i] = floodCup.top();
                    floodCup.pop();
                }
                
            }
        }
    }
    return ans;
}

int solution1::singleNumber(std::vector<int>& nums)
{
    int ans = 0;
    for (auto temp : nums)
    {
        ans ^= temp;
    }
    return ans;
}

int solution1::countDigits(int num)
{
    int result = 0;
    std::string numString = std::to_string(num);
    for (int i = 0; i < numString.size(); i++) {
        std::string temp(1, numString[i]);
        if (num % std::stoi(temp) == 0) {
            result++;
        }
    }
    return result;
}

long long solution1::pickGifts(std::vector<int>& gifts, int k)
{
    long long result = 0;
    for (int i = 0; i < k; i++) {
        sort(gifts.begin(), gifts.end());
        //auto temp = gitfs[gitfs.size()-1];
        auto temp = floor(sqrt(gifts[gifts.size() - 1]));
        gifts[gifts.size() - 1] = temp;
    }
    for (int i = 0; i < gifts.size(); i++) {
        result += gifts[i];
    }
    return result;
}

int solution1::hIndex(std::vector<int>& citations)
{
    int temp = 0;
    std::sort(citations.begin(), citations.end());
    int i = citations.size() - 1;
    if (i == 0) {
        int res = 0;
        res = citations[0] == 0 ? 0 : 1;
        return res;
    }
    else {
        for (int i = citations.size() - 1; i >= 0; i--)
        {
            if (citations[i] >= temp + 1)
            {
                temp++;
            }
        }
        return temp;
    }
}

std::vector<int> solution1::smallestMissingValueSubtree(std::vector<int>& parents, std::vector<int>& nums)
{
    int n = parents.size();
    std::vector<int> ans(n, 1);//��ʼ��Ϊ����n��ֵΪ3��int;
    auto it = find(nums.begin(),nums.end(),1);//Ѱ�ҵ�һ��1���ֵĵ�ַ
    if (it == nums.end()) //�����ڻ���ֵΪ1�ĵ�
    {
        return ans;
    }

    //����
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        g[parents[i]].push_back(i);
    }
    std::unordered_set<int> vis;
    std::stack<int> nodes;//�����������Ҫ�����ĵ�
    int mex = 2;//ȷʵ����С����ֵ
    int pre = -1;
    int node = it - nums.begin();
    while (node >= 0) 
    {
        vis.insert(nums[node]);//��ǻ���ֵ
        for (int son : g[node])
        {
            if (son != pre) 
            {//pre�����Ѿ�������
                nodes.push(son);//�����������Ҫ�����ĵ�
            }
        }
        while (!nodes.empty())
        {
            int x = nodes.top();
            nodes.pop();
            vis.insert(nums[x]);//��ǻ���ֵ
            for (int son : g[x]) 
            {
                nodes.push(son);//�����������Ҫ�����ĵ�
            }
        }
        while (vis.count(mex)) 
        {//node���������������ֵ
            mex++;
        }
        ans[node] = mex;//ȱʧ����С����ֵ
        pre = node;
        node = parents[node];//������
    }

    return ans;
}

int solution1::maximumInvitations(std::vector<int>& favorite)
{
    int n = favorite.size();
    // ͳ����ȣ����ڽ�����������
    std::vector<int> indeg(n);
    for (int i = 0; i < n; ++i) {
        ++indeg[favorite[i]];
    }
    std::vector<int> used(n), f(n, 1);
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (!indeg[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        used[u] = true;
        q.pop();
        int v = favorite[u];
        // ״̬ת��
        f[v] = std::max(f[v], f[u] + 1);
        --indeg[v];
        if (!indeg[v]) {
            q.push(v);
        }
    }
    // ring ��ʾ���Ļ��Ĵ�С
    // total ��ʾ���л���СΪ 2 �ġ��������������ϵ���ġ�˫�����ߡ�·��֮��
    int ring = 0, total = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int j = favorite[i];
            // favorite[favorite[i]] = i ˵�����Ĵ�СΪ 2
            if (favorite[j] == i) {
                total += f[i] + f[j];
                used[i] = used[j] = true;
            }
            // ���򻷵Ĵ�С����Ϊ 3��������Ҫ�ҳ���
            else {
                int u = i, cnt = 0;
                while (true) {
                    ++cnt;
                    u = favorite[u];
                    used[u] = true;
                    if (u == i) {
                        break;
                    }
                }
                ring = std::max(ring, cnt);
            }
        }
    }
    return std::max(ring, total);
}

int solution1::maxProduct(std::vector<std::string>& words)
{
    int n = words.size();
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = maxProduct_convert(words[i]);
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) 
        {
            if ((nums[i] & nums[j]) == 0) {
                ans = std::max(ans, (int)words[i].length() * (int)words[j].length());
            }
        }
    }
    return ans;
}

int solution1::vowelStrings(std::vector<std::string>& words, int left, int right)
{
    int res = 0;
    for (int i = left; i <= right; i++)
    {
        std::string first(1, words[i][0]);//find_first_of
        std::string last(1, words[i][words[i].size() - 1]);//find_last_of
        if (ifVowelLetter(first) == true && ifVowelLetter(last) == true)
        {
            res++;
        }
    }
    return res;
}

int solution1::findTheLongestBalancedSubstring(std::string s)
{
    //���з���ʧ����
    //std::queue<int> temp;
    //int numOfZero = 0;
    //for (int i = 0; i < s.size(); i++)
    //{
    //    /*if (temp.empty() || temp.front() != s[i])
    //    {
    //        temp.push(s[i]);
    //    }
    //    else
    //    {
    //        temp.push(s[i]);
    //        temp.pop();
    //    }*/
    //    
    //    if (!temp.empty() && temp.front() == s[i] && numOfZero < 1 ) 
    //    {
    //        temp.pop();
    //    }
    //    temp.push(s[i]);
    //    if (s[i] == '0')
    //    {
    //        numOfZero++;
    //    }
    //    else 
    //    {
    //        numOfZero = 0;
    //    }
    //}
    //if (numOfZero > s.size() * 0.5)
    //{
    //    return 0;
    //}
    //return temp.size() == 1  ? 0 : temp.size() ;

    //����ʵʵ˫ָ�����
    int res = 0;
    int zeros = 0, ones = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            zeros++;
        }
        else {
            int j = i;
            while (j < s.size() && s[j] == '1') j++, ones++;
            i = j - 1;
            res = std::max(res, 2 * std::min(zeros, ones));
            zeros = 0;
            ones = 0;
        }
    }
    return res;
}

int solution1::maximumMinutes(std::vector<std::vector<int>>& grid)
{
    int m = grid.size(), n = grid[0].size();
    std::queue<std::pair<int, int>> fire;
    std::vector<std::vector<bool>> visP(m, std::vector<bool>(n, false));
    std::vector<std::vector<bool>> visF(m, std::vector<bool>(n, false));

    //�ҳ����л��λ��
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1) {
                fire.push({ i, j });
                visF[i][j] = true;
            }

    // bfs��֤�Ƿ��ܵ����յ�
    auto check = [&](int t) ->bool {
        std::vector<std::vector<bool>> P = visP;
        std::vector<std::vector<bool>> F = visF;
        std::queue<std::pair<int, int>> f = fire;
        std::queue<std::pair<int, int>> p;
        p.push({ 0, 0 });
        P[0][0] = true;

        // ����������t��
        while (t--) {
            for (int i = f.size(); i; i--) {
                //auto [x, y] = f.front();//����д����ҪC++17
                std::pair<int, int> temppp = f.front();
                auto x = temppp.first;
                auto y = temppp.second;
                f.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n     \
                        && !F[nx][ny] && grid[nx][ny] != 2) {

                        if (nx == 0 && ny == 0) return false;
                        F[nx][ny] = true;
                        f.push({ nx, ny });
                    }
                }
            }
        }

        while (p.size()) {
            // ������
            for (int i = p.size(); i; i--) {
                //auto [x, y] = p.front();
                std::pair<int, int> temppp = f.front();
                auto x = temppp.first;
                auto y = temppp.second;
                p.pop();
                if (F[x][y]) continue;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n  \
                        && !F[nx][ny] && !P[nx][ny] && grid[nx][ny] != 2) {
                        if (nx == m - 1 && ny == n - 1) return true;
                        P[nx][ny] = true;
                        p.push({ nx, ny });
                    }
                }
            }
            //��������
            for (int i = f.size(); i; i--) {
                //auto [x, y] = f.front();
                std::pair<int, int> temppp = f.front();
                auto x = temppp.first;
                auto y = temppp.second;
                f.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n     \
                        && !F[nx][ny] && grid[nx][ny] != 2) {
                        F[nx][ny] = true;
                        f.push({ nx, ny });
                    }
                }
            }

        }
        return false;
        };
    // ���ִ�
    int l = 0, r = m * n;
    while (l < r) {
        int mid = l + r + 1 >> 1;

        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    // ��֤�ܵ�����߲��ܵ���
    if (l == 0 && check(0) == false) return -1;
    if (l == m * n && check(m * n)) return 1000000000;
    return l;
}

std::vector<int> solution1::successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success)
{
    std::vector<int> pairs;
    std::vector<int>::iterator temp;
    std::sort(potions.begin(),potions.end());
    for (int i = 0; i < spells.size(); i++)
    {
        long long div = (long long)success / spells[i];
        if (success % spells[i] == 0) 
        {//������ ���Ҵ��ڵ���div�ĵ�һ��λ��
            temp = lower_bound(potions.begin(), potions.end(), div);//lower_bound�õ���һ��ֵ��С��success / pairs[i]�ĵط���ָ��  upper_bound�ǵ�һ������   
        }
        else 
        {//�����������������Ҵ���div�ĵ�һ��λ��
            temp = upper_bound(potions.begin(), potions.end(), div);
        }
        int iteas = temp - potions.begin();
        int res = potions.size() - iteas ;
        pairs.push_back(res > 0 ? res : 0);
    }
    return pairs;
}

int solution1::minSwapsCouples(std::vector<int>& row)
{
    int res = 0;
    std::unordered_map<int,int> position;//���λ��
    for (int i = 0; i < row.size(); i++)
    {
        //position.insert(row[i],i);//�� - λ��
        position.insert(std::pair<int, int> {row[i], i});
    }
    /*
     * ö��ÿһ����λ��(i, i + 1)
     * �����λ i + 1 ���ŵĲ��� row[i] �����£�
     * �� row[i] �����½�������λ i + 1
     * �� row[i] Ϊ��ż����ʱ����������Ϊ row[i] + 1
     * �� row[i] Ϊ��������ʱ����������Ϊ row[i] - 1
    */
    for (int i = 0; i < row.size(); i += 2)
    {
        //int couple = row[i] % 2 == 0 ? row[i] + 1 : row[i] - 1;
        //if (row[i] + 1 != couple )//�������ŵĲ���
        //{
        //    auto temp = position.find(couple);

        //    int index = temp->second;//��¼���µ���λ
        //    //row[i+1] �� row[index]����
        //    row[i + 1] ^= row[index] ^= row[i + 1] ^= row[index];
        //    res++;
        //}
        int couple = row[i] % 2;
        if (couple == 0)
        {
            couple = row[i] + 1;
            if (row[i] + 1 != couple)
            {
                auto temp = position.find(couple);

                int index = temp->second;//��¼���µ���λ
                //row[i+1] �� row[index]����
                row[i + 1] ^= row[index] ^= row[i + 1] ^= row[index];
                res++;
            }
        }
        else if (couple != 0)
        {
            couple = row[i] - 1;
            if (row[i] - 1 != couple)
            {
                auto temp = position.find(couple);

                int index = temp->second;//��¼���µ���λ
                //row[i+1] �� row[index]����
                row[i + 1] ^= row[index] ^= row[i + 1] ^= row[index];
                res++;
            }
        }
    }
    return res;
}

int solution1::findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold)
{
    //Floyd �õ���������֮������·
    std::pair<int, int> ans(INT_MAX / 2, -1);
    std::vector<std::vector<int>> mp(n,std::vector<int>(n,INT_MAX / 2));
    for (auto& eg : edges) 
    {
        int from = eg[0], to = eg[1], weight = eg[2];//������
        mp[from][to] = mp[to][from] = weight;//˫��ͼ
    }
    for (int k = 0; k < n; ++k) //floyd
    {
        mp[k][k] = 0;//��ʾÿ�����е�����ľ�����0
        for(int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[i][j] = std::min(mp[i][j],mp[i][k] + mp[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (mp[i][j] <= distanceThreshold) 
            {
                cnt++;
            }
        }
        if (cnt <= ans.first)
        {
            ans = { cnt,i };
        }
    }
    return ans.second;
}

int solution1::maximizeSum(std::vector<int>& nums, int k)
{
    std::sort(nums.begin(),nums.end());
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        int temp = nums[nums.size() - 1];
        result += temp;
        nums[nums.size() - 1] = temp + 1;
        std::cout << result << std::endl;
    }
    return result;
}

int solution1::longestAlternatingSubarray(std::vector<int>& nums, int threshold)
{
    //��������⣬ֻ������������С����ֵ������ֱ�ӰѴ�����ֵ�������ȥ����
    //int temp = (nums.begin() - std::upper_bound(nums.begin(), nums.end(), threshold)) > 0 ? (nums.begin() - std::upper_bound(nums.begin(), nums.end(), threshold) -1) : nums.size();//�ҵ���һ����threshold��������±�
    //std::vector<int> result;
    //for (int i = 0; i < temp; i++)
    //{
    //    if (nums[i] % 2 == 0 && i < temp) 
    //    {
    //        for (int j = i + 1; j < temp; j++)
    //        {
    //            if (nums[j - 1] % 2 != nums[j] % 2) 
    //            {
    //                result.push_back(j - i + 1);
    //            }
    //        }
    //    }
    //}
    //return result.size() > 0 ? result[std::max_element(result.begin(),result.end()) - result.begin()] : 1;

    int n = nums.size();
    int ans = 0, i = 0;
    while (i < n) {
        if (nums[i] > threshold || nums[i] % 2) {
            i++; // ֱ������
            continue;
        }
        int start = i; // ��¼��һ��Ŀ�ʼλ��
        i++; // ��ʼλ���Ѿ�����Ҫ�󣬴���һ��λ�ÿ�ʼ�ж�
        while (i < n && nums[i] <= threshold && nums[i] % 2 != nums[i - 1] % 2) {
            i++;
        }
        // �� start �� i-1 ��������ĿҪ���������
        ans = std::max(ans, i - start);
    }
    return ans;

}

std::vector<int> solution1::maximumSumQueries(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<std::vector<int>>& queries)
{
    //���ʮ�����԰�������ʱ������
    //std::vector<int> res;
    //for (int i = 0; i < queries.size(); i++)
    //{
    //    int temp = -1;
    //    int xi = queries[i][0];
    //    int yi = queries[i][1];
    //    for (int j = 0; j < nums1.size(); j++)
    //    {
    //        temp = std::max((nums1[j] >= xi && nums2[j] >= yi) ? (nums1[j] + nums2[j]) : -1, temp);
    //    }
    //    res.push_back(temp);
    //}
    //return res;

    //�����ά��������һ��
    int n = nums1.size();
    std::vector<int> res;
    std::vector<std::vector<int>> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back({ nums1[i],nums2[i] });
    }
    std::sort(temp.begin(), temp.end());
    for (int i = 0; i < queries.size(); i++)
    {
        int tempp = -1;
        int xi = queries[i][0];
        int yi = queries[i][1];
        //int itea = lower_bound(temp.begin(), temp.end(), xi) - temp.begin();//��һ�����ڵ��ڵ�λ��    ���б���������ô��
        /*while (itea < n)
        {
            tempp = std::max((temp[itea][0] >= xi && temp[itea][1] >= yi) ? (temp[itea][0] + temp[itea][1]) : -1, tempp);
            itea++;
        }*/
        res.emplace_back(tempp);
    }
    return res;
}

int solution1::maximumSum(std::vector<int>& nums)
{
    int ans = -1;
    int mx[82]{}; // ���� 9 �� 9 ���
    for (int num : nums) {
        int s = 0; // num ����λ��
        for (int x = num; x; x /= 10) { // ö�� num ��ÿ����λ
            s += x % 10;
        }
        if (mx[s]) { // ˵�����Ҳ����λ�͵��� s ��Ԫ��
            ans = std::max(ans, mx[s] + num); // ���´𰸵����ֵ
        }
        mx[s] = std::max(mx[s], num); // ά����λ�͵��� s �����Ԫ��
    }
    return ans;

}

int solution1::maxSubArray(std::vector<int>& nums)
{
    int result = INT_MIN;
    int temp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        temp += nums[i];
        result = std::max(result,temp);
        temp = temp < 0 ? 0 : temp;
    }
    return result;
}

int solution1::minDeletion(std::vector<int>& nums)
{
    int result = 0;
    if (nums.size() == 0)
    {
        return 0;
    }
    int i = 0, j = 1;
    for (i,j; j < nums.size(); )
    {
        if (nums[i] != nums[j]) 
        {
            i = j + 1;
            j = i + 1;
        }
        else
        {
            j++;
            result++;
        }
    }
    if (i < nums.size())
    {
        result++;
    }
    return result;
}

std::string solution1::entityParser(std::string text)
{
    std::string result;
    std::unordered_map<std::string, std::string> temp = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"},
    };
    for (int i = 0; i < text.length(); )
    {
        if (text[i] == '&' && i < text.length() - 1) {
            for (int j = i + 1; j < text.length(); j++)
            {
                auto itea = temp.find(text.substr(i,j - i));
                if (itea != temp.end()){//�ҵ���
                    result += itea->second;
                    i = j;
                    break;
                }
                if (itea == temp.end() && j == text.length() - 1){
                    result += text[i];
                    i++;
                    break;
                }
            }
        }
        else{
            result += text[i];
            i++;
        }
    }
    return result;
}

int solution1::countPairs(std::vector<int>& nums, int target)
{
    int result = 0;
    if (nums.size() == 1)
    {
        return 0;
    }
    std::sort(nums.begin(),nums.end());
    for (int i = 0, j = nums.size() - 1; i < j; i++)
    {
        while (i < j && nums[i] + nums[j] >= target) 
        {
            j--;
        }
        result += j - i;
    }
    return result;
}

int solution1::sumSubarrayMins(std::vector<int>& arr)
{
    //����ʱ������
    /*auto result = 0;
    for (int i = 0, j = 0; i < arr.size() && j < arr.size(); )
    {
        auto aa = obtainTheMinofSub(arr, i, j);
        result += aa;
        if (j < arr.size() - 1)
        {
            j++;
        }
        else 
        {
            i++;
            j = i;
        }
    }
    return result;*/

    //�ҳ���ĳ��Ԫ��Ϊ��Сֵ������
    auto result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0) //�����
        {
            int j = 0;
            while (arr[i] <= arr[j])//�ҳ�����[i,j]���ٴ������ڶ�����iΪ��Сֵ
            {
                j++;
            }
            result += arr[i] * (j - i);
        }
        else if (i == arr.size() - 1)//���ұ� 
        {
            int j = i;
            while (arr[i] <= arr[j]) 
            {
                j--;
            }
            result += arr[i] * (i - j);
        }
        else//�м� 
        {
            int left = i, right = i;
            int maxLeft = left, maxRight = right;
            while (left >= 0 && arr[left] >= arr[i]) {
                maxLeft = left;
                left--;
            }

            // ������չ����
            while (right < arr.size() && arr[right] >= arr[i]) {
                maxRight = right;
                right++;
            }
            if (maxLeft < i && maxRight > i)
            {
                result += arr[i] * countSubIntervals(maxLeft,maxRight,i);
            }
            else if (maxLeft == i && maxRight > i) 
            {
                result += arr[i] * (maxRight - i + 1);
            }
            else if(maxRight == i && maxLeft < i)
            {
                result += arr[i] * (i - maxLeft + 1);
            }
            else if(maxLeft == maxRight == i)
            {
                result += arr[i];
            }
            
        }
    }
    return result;
}

bool solution1::closeStrings(std::string word1, std::string word2)
{
    std::vector<int> temp1(26),temp2(26);
    for (auto i : word1)
    {
        temp1[i - 'a']++;
    }
    for (auto i : word2)
    {
        temp2[i - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if ((temp1[i] > 0 && temp2[i] == 0) || (temp1[i] == 0 && temp2[i] > 0)) 
        {
            return false;
        }
    }
    std::sort(temp1.begin(), temp1.end());
    std::sort(temp2.begin(), temp2.end());
    bool res = temp1 == temp2 ? true : false;
    return res;
}

int solution1::firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat)
{
    int n = mat.size();
    int m = mat[0].size();
    std::unordered_map<int, std::pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            mp[mat[i][j]] = { i,j };
        }
    }
    std::vector<int> rowCnt(n, 0);
    std::vector<int> colCnt(m, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        auto& v = mp[arr[i]];
        ++rowCnt[v.first];
        if (rowCnt[v.first] == m) 
        {
            return i;
        }
        ++colCnt[v.second];
        if (colCnt[v.second] == n)
        {
            return i;
        }
    }
    return -1;
}

long long solution1::minimumFuelCost(std::vector<std::vector<int>>& roads, int seats)
{
    auto result = 0;
    std::vector<std::vector<int>> myroad(roads.size() - 1);
    for (auto temp : roads) 
    {
        myroad[temp[0]].push_back(temp[1]);
        myroad[temp[1]].push_back(temp[0]);
    }
    std::vector<int> depth(roads.size() - 1, 0);
    dfs_2477(myroad, 0, -1, seats, result, depth);
    return result;
}

int solution1::minimumEffortPath(std::vector<std::vector<int>>& heights)
{
    /*
    * dirs ���鶨�����ĸ����ܵ��ƶ������ϡ��¡����ҡ�
    * m �� n �ֱ��Ǿ����������������
    * tupleCmp ��һ���ȽϺ���������ȷ�����ȶ�����Ԫ�ص����ȼ������Ƚ�ÿ��Ԫ��ĵ�����Ԫ�أ������� d����ʹ�þ�����С��Ԫ�����ȳ��ӡ�
    * ������һ�����ȶ��� q�����д洢��Ԫ���ǰ������� (x, y) �͵�ǰλ�õ���С���� d ��Ԫ�顣
    * dist �������ڴ洢��ÿ��λ�õ���С���룬��ʼ��Ϊ INT_MAX��
    * seen �������ڱ���Ƿ��ѷ��ʹ�ĳλ�á�
    * �㷨����ѭ���Ӷ�����ȡ��������С��Ԫ�أ�����������λ�õ���С���롣
    * ÿ�η���һ����λ��ʱ��������㵽��λ�õ��µ���С���룬�����������С�
    * ��������յ� (m - 1, n - 1)�������ѭ����
    * ��󣬷��ص��յ����С���� dist[m * n - 1]��
    */
    static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int m = heights.size();
    int n = heights[0].size();

    auto tupleCmp = [](const auto& e1, const auto& e2) {
        auto&& [x1, y1, d1] = e1;
        auto&& [x2, y2, d2] = e2;
        return d1 > d2;
        };
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, decltype(tupleCmp)> q(tupleCmp);
    q.emplace(0, 0, 0);

    std::vector<int> dist(m * n, INT_MAX);
    dist[0] = 0;
    std::vector<int> seen(m * n);

    while (!q.empty()) {
        auto [x, y, d] = q.top();
        q.pop();
        int id = x * n + y;
        if (seen[id]) {
            continue;
        }
        if (x == m - 1 && y == n - 1) {
            break;
        }
        seen[id] = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && std::max(d, abs(heights[x][y] - heights[nx][ny])) < dist[nx * n + ny]) {
                dist[nx * n + ny] = std::max(d, abs(heights[x][y] - heights[nx][ny]));
                q.emplace(nx, ny, dist[nx * n + ny]);
            }
        }
    }

    return dist[m * n - 1];
}

int solution1::dijkstra(const std::vector<std::vector<int>>& matrix, std::pair<int, int> start, std::pair<int, int> end)
{
    int rows = matrix.size(), cols = matrix[0].size();
    std::vector<std::vector<int>> dist(rows, std::vector<int>(cols, INT_MAX));
    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<>> pq;

    dist[start.first][start.second] = 0;
    pq.push({ 0, start });

    std::vector<std::pair<int, int>> directions{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    while (!pq.empty()) {
        auto [cost, curr] = pq.top();
        pq.pop();

        if (curr == end) return cost;
        if (cost > dist[curr.first][curr.second]) continue;

        for (const auto& dir : directions) {
            int x = curr.first + dir.first, y = curr.second + dir.second;

            if (x >= 0 && x < rows && y >= 0 && y < cols && matrix[x][y] > 0) {
                int newDist = cost + matrix[x][y];
                if (newDist < dist[x][y]) {
                    dist[x][y] = newDist;
                    pq.push({ newDist, {x, y} });
                }
            }
        }
    }

    return dist[end.first][end.second] == INT_MAX ? -1 : dist[end.first][end.second];
}

std::string solution1::makeSmallestPalindrome(std::string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j) 
    {
        /*s[i] = s[i] == s[j] ? s[i] : s[j];*/
        if (s[i] != s[j])
        {
            s[i] - 'a' > s[j] - 'a' ? s[i] = s[j] : s[j] = s[i];
        }

        i++;
        j--;
    }

    return s;
}

bool solution1::possibleToStamp(std::vector<std::vector<int>>& grid, int stampHeight, int stampWidth)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++) 
        {
            if (grid[i][j] != 1)
            {
                ifCanBeInserted(grid, i, j, stampHeight, stampWidth);
            }
            
        }
    }
    //�����ж���һ�飬����ж��Ƿ��в�����1��2������
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

TreeNode* solution1::reverseOddLevels(TreeNode* root)
{
    //dfs �������
    traversal(root->left, root->right, true);
    return root;
}

int solution1::findPeakElement(std::vector<int>& nums)
{
    int left = 0, right = nums.size() - 1;
    while (left < right) 
    {
        int temp = (left + right) / 2;
        if (nums[temp] < nums[temp + 1])
        {
            left = temp + 1;
        }
        else
        {
            right = temp;
        }
    }
    return right;
}

bool solution1::isAcronym(std::vector<std::string>& words, std::string s)
{
    if (words.size() != s.size())
    {
        return false;
    }
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i][0] != s[i])
        {
            return false;
        }
    }
    return true;
}

int solution1::minimumMountainRemovals(std::vector<int>& nums)
{
    std::stack<int> leftToRight,rightToLeft;
    for (int i = 0, j = 1; j < nums.size();)
    {
        if (nums[i] < nums[j])
        {
            if (leftToRight.size() == 0) //��ʱջ�գ�����ջ
            {
                leftToRight.push(nums[i]);
                leftToRight.push(nums[j]);
                i++;
                j++;
            }
            else
            {
                leftToRight.push(nums[j]);
                i = j;
                j++;
            }
        }
        if (leftToRight.empty() && nums[i] >= nums[j])
        {
            i++, j++;
        }
        j++;
    }
    return 0;
}

std::vector<int> solution1::numOfBurgers(int tomatoSlices, int cheeseSlices)
{
    std::vector<int> res;
    int a = 4, b = 2, c = 1, d = 1, e = tomatoSlices, f = cheeseSlices;
    float det = a * d - b * c;
    if (det == 0) {
        return res;
    }
    float x = (e * d - b * f) / det;
    float y = (a * f - e * c) / det;
    if ((int)x < x || (int)y < y)
    {
        return res;
    }
    if (x < 0 || y < 0)
    {
        return res;
    }
    res.push_back((int)x);
    res.push_back((int)y);
    return res;
}

int solution1::isWinner(std::vector<int>& player1, std::vector<int>& player2)
{
    int temp1 = -1, temp2 = -1;
    int sumPlayer1 = 0, sumPlayer2 = 0;
    for (int i = 0; i < player1.size(); i++)
    {
        if (temp1 == 10 || temp2 == 10)
        {
            sumPlayer1 += 2 * player1[i];
        }
        else
        {
            sumPlayer1 += player1[i];
        }
        temp1 = i - 1 < 0 ? -1 : player1[i - 1];
        temp2 = player1[i];
    }
    temp1 = temp2 = -1;
    for (int i = 0; i < player2.size(); i++)
    {
        if (temp1 == 10 || temp2 == 10)
        {
            sumPlayer2 += 2 * player2[i];
        }
        else
        {
            sumPlayer2 += player2[i];
        }
        temp1 = i - 1 < 0 ? -1 : player2[i - 1];
        temp2 = player2[i];
    }
    if (sumPlayer1 > sumPlayer2)
    {
        return 1;
    }
    else if (sumPlayer1 < sumPlayer2) 
    {
        return 2;
    }
    else 
    {
        return 0;
    }
}

int solution1::lengthOfLongestSubstring(std::string s)
{
    std::unordered_set<int> temp;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        //std::set<std::string>::iterator pos = temp.find(s[i]);   numSet.count(num) > 0
        if (temp.count(s[i] - 'a') > 0)//����
        {
            return res;
        }
        temp.insert(s[i] - 'a');
        res++;
    }
    return res;
}

int solution1::buyChoco(std::vector<int>& prices, int money)
{
    std::sort(prices.begin(), prices.end());
    if (prices[0] + prices[1] <= money) {
        return money - prices[0] - prices[1];
    }
    else {
        return money;
    }
}

int solution1::minLength(std::string s)
{
    std::stack<std::string> stackString;
    std::string temp,a;//��tempһֱ����ջ��Ԫ��
    
    for (int i = 0; i < s.size(); i++)
    {
        if (stackString.empty()) 
        {
            temp = s[i];
            stackString.push(temp);
            continue;
        }
        if (temp + s[i] == "AB" || temp + s[i] == "CD")
        {
            stackString.pop();
            temp = stackString.empty() ?  "" : stackString.top();
            continue;
        }
        a = s[i];
        stackString.push(a);
        stackString.empty() ? "" : temp = stackString.top();
    }
    return stackString.size();
}

int solution1::count(std::string num1, std::string num2, int min_sum, int max_sum)
{
    static constexpr int MOD = 1e9 + 7;
    long long int res = 0;
    std::string temp = num1;
    while (getWarOfString(num1, temp) == false && getWarOfString(temp, num2) == false) 
    {
        int cur = getSumOfDigit(temp);
        if (cur >= min_sum && cur <= max_sum)
        {
            res++;
        }
    }
    return res % MOD;
}

int solution1::maximumNumberOfStringPairs(std::vector<std::string>& words)
{
    int n = words.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (words[i][0] == words[j][1] && words[i][1] == words[j][0]) {
                ++ans;
            }
        }
    }
    return ans;
}

TreeNode* solution1::buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
{
    //�Ӻ�����������һ��Ԫ�ؿ�ʼ
    post_idx = (int)postorder.size() - 1;

    //������Ԫ�� �±���ֵ�ԵĹ�ϣ��
    int idx = 0;
    for (auto& val : inorder)
    {
        idx_map[val] = idx++;
    }
    return helper(0, (int)inorder.size() - 1, inorder, postorder);
}

TreeNode* solution1::constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder)
{
    if (preorder.empty())//��
    {
        return nullptr;
    }
    if (preorder.size() == 1)//��һ���ڵ�
    {
        return new TreeNode(preorder[0]);
    }
    int left_size = std::ranges::find(postorder, preorder[1]) - postorder.begin() + 1; // �������Ĵ�С
    //�����postorder����������preorder[1]�ĵ�һ�γ��֡�ranges::find������C++20��Χ���һ���֣���Ϊ�������ݷ�Χ�ṩ��һ�ָ��ִ�������������ķ�ʽ��������һ����postorder���ҵ�Ԫ�صĵ�����
    std::vector<int> pre1(preorder.begin() + 1, preorder.begin() + 1 + left_size);
    std::vector<int> pre2(preorder.begin() + 1 + left_size, preorder.end());
    std::vector<int> post1(postorder.begin(), postorder.begin() + left_size);
    std::vector<int> post2(postorder.begin() + left_size, postorder.end() - 1);

    TreeNode* left = constructFromPrePost(pre1, post1);
    TreeNode* right = constructFromPrePost(pre2, post2);
    return new TreeNode(preorder[0], left, right);
}

long long solution1::kthLargestLevelSum(TreeNode* root, int k)
{
    std::vector<long long> a;
    std::vector<TreeNode*> q = { root };
    while (!q.empty()) {
        long long sum = 0;
        std::vector<TreeNode*> nxt;
        for (auto node : q) {
            sum += node->val;
            if (node->left)  nxt.push_back(node->left);
            if (node->right) nxt.push_back(node->right);
        }
        a.push_back(sum);
        q = move(nxt);
    }
    int n = a.size();
    if (k > n) {
        return -1;
    }
    std::ranges::sort(a);
    return a[n - k];
}

std::vector<std::vector<int>> solution1::closestNodes(TreeNode* root, std::vector<int>& queries)
{
    dfs(root);
    int n = closestNodesUse.size();
    std::vector<std::vector<int>> res;

    for (int q : queries)
    {
        int j = std::ranges::lower_bound(closestNodesUse, q) - closestNodesUse.begin();
        int mx = j < n ? closestNodesUse[j] : -1;
        if (j == n || closestNodesUse[j] != q) { // a[j]>q, a[j-1]<q
            j--;
        }
        int mn = j >= 0 ? closestNodesUse[j] : -1;
        res.push_back({ mn, mx });
    }
    return res;

}

int solution1::rangeSumBST(TreeNode* root, int low, int high)
{
    if (root == nullptr)
    {
        return 0;
    }
    rangeSumBST(root->left,low,high);

    std::cout << "rootval:" << root->val << std::endl;
    if (root->val >= low && root->val <= high)
    {
        sum_938 += root->val;
    }

    rangeSumBST(root->right,low,high);
    return sum_938;
}

Node* solution1::connect(Node* root)
{
    if (!root) {
        return nullptr;
    }
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        Node* last = nullptr;
        for (int i = 1; i <= n; ++i) {
            Node* f = q.front();
            q.pop();
            if (f->left) {
                q.push(f->left);
            }
            if (f->right) {
                q.push(f->right);
            }
            if (i != 1) {
                last->next = f;
            }
            last = f;
        }
    }
    return root;
}

int solution1::minIncrements(int n, std::vector<int>& cost)
{
    int ans = 0;
    for (int i = n / 2; i > 0; i--) { // �����һ����Ҷ�ڵ㿪ʼ��
        ans += abs(cost[i * 2 - 1] - cost[i * 2]); // �����ӽڵ���һ����
        cost[i - 1] += std::max(cost[i * 2 - 1], cost[i * 2]); // �ۼ�·����
    }
    return ans;
}

bool solution1::validPartition(std::vector<int>& nums)
{
    int n = nums.size();
    std::vector<int> f(n + 1);
    f[0] = true;
    for (int i = 1; i < n; i++)
    {
        if (f[i - 1] && nums[i] == nums[i - 1] ||
            i > 1 && f[i - 2] && (nums[i] == nums[i - 1] == nums[i - 2] ||
                nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)) 
        {
            f[i + 1] = true;
        }
    }
    return f[n];
}

int solution1::climbStairs(int n)
{
    memo.resize(n + 1);
    return dfs_70(n);
    return 0;
}

int solution1::reachableNodes(int n, std::vector<std::vector<int>>& edges, std::vector<int>& restricted)
{
    std::set<int> restrict;
    std::vector<std::vector<int>> my_edge;
    for (auto temp : restricted) 
    {
        restrict.insert(temp);
    }
    for (int i = 0; i < edges.size(); i++)
    {
        if (!restrict.count(edges[i][0]) && !restrict.count(edges[i][1]))//���û�����޽ڵ㣬�򱣴�
        {
            my_edge.push_back(edges[i]);
        }
    }
    restrict.clear();

    if (my_edge.size() == 0)
    {
        return 1;
    }

    for (auto& inner_vec : my_edge) {
        std::sort(inner_vec.begin(), inner_vec.end());
    }
    // Ȼ�󣬶��ⲿ�����������򣬻����ڲ������ĵ�һ��Ԫ��
    std::sort(my_edge.begin(), my_edge.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        }
    );
    if (my_edge[0][0] == 0)
    {
        restrict.insert(my_edge[0][0]);
        restrict.insert(my_edge[0][1]);
    }
    for (int i = 1; i < my_edge.size(); i++)
    {
        if ((restrict.count(my_edge[i][0]) || restrict.count(my_edge[i][1])) && restrict.count(0))//����������е�ĳ���ڵ�
        {
            restrict.insert(my_edge[i][0]);
            restrict.insert(my_edge[i][1]);
        }
    }
    if (restrict.count(0))
    {
        return restrict.size();
    }
    else 
    {
        return 1;
    }
    
}

int solution1::findKOr(std::vector<int>& nums, int k)
{
    /*
    * ��Ȼ�� | ��Ȼ�� == ��Ȼ�� + ��Ȼ��
    */

    int result = 1;
    if (nums.size() == k )
    {
        result = nums[0];
        for (int i = 0; i < nums.size() ; i++)
        {
            result = result & nums[i];
        }
        return result;
    }
    if (k == 1)
    {
        for (int i : nums)
        {
            result = result | i;
        }
    }
    for (int i = 0; i < 31; i++)
    {
        int temp = 0;
        for (int j : nums)
        {
            temp += j >> i & 1;//ͳ��ÿһλ�Ƿ�Ϊ1
        }
        //ͳ�Ƴ��ĸ��������ڵ���k ��λ��
        if (temp >= k) 
        {
            result += 1 << i;
        }
    }

    return result;
}

std::string solution1::capitalizeTitle(std::string title)
{
    /*int i = 0;
    std::string temp,result;
    while (i < title.length())
    {
        if (title[i] == ' ')
        {
            if (temp.size() <= 2)
            {
                for (int j = 0; j < temp.size(); j++) 
                {
                    temp[j] = std::tolower(temp[j]);
                }
            }
            else 
            {
                temp[0] = std::toupper(temp[0]);
            }
            result += temp;
            temp.clear();
        }
        temp += title[i];
        result += ' ';
    }
    return result;*///����ʱ������
    std::istringstream iss(title);
    std::string ans, s;
    while (iss >> s) {
        if (!ans.empty()) {
            ans += ' ';
        }
        if (s.length() > 2) {
            ans += toupper(s[0]); // ����ĸ��д
            s = s.substr(1);
        }
        for (char c : s) {
            ans += tolower(c);
        }
    }
    return ans;
}

double solution1::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    nums1.emplace_back(INT_MAX);    // ׷���ڱ�λ
    nums2.emplace_back(INT_MAX);
    int k = (m + n + 1) / 2;    // ��ȡ�м����ǵڼ�������ż��ȡǰһ������
    int idx1 = 0;     // ����ָ�룬ָ��ǰȡ�������Ԫ��
    int idx2 = 0;
    bool flag = false;  // ����м���ȡ���Ƿ�Ϊnums1��Ԫ��
    while (true) {
        // ����1Ԫ��ȫ��ȡ�꣬ʣ�µ�Ԫ��������2�ṩ
        if (idx1 == m) {
            // [idx2, ?]�ṩk��Ԫ�أ���?-idx2+1=k => ? = idx2+k-1
            idx2 += k - 1;
            break;
        }
        // ����2Ԫ��ȫ��ȡ�꣬ʣ�µ�Ԫ��������1�ṩ
        if (idx2 == n) {
            idx1 += k - 1;
            flag = true;
            break;
        }
        // Ϊ��ʹָ��ͣ���м�����λ�ã����һ������������
        if (k == 1) {
            flag = nums1[idx1] < nums2[idx2];   // ָ�������ƶ���ֻ��Ҫ�ж�ȡ�ĸ������Ԫ��
            break;
        }
        // ÿ��ȡһ����ǰ��С���������ƶ���Ӧָ��ȡ��һ����
        if (nums1[idx1] < nums2[idx2]) {
            idx1++;
        }
        else {
            idx2++;
        }
        k--;
    }
    // ��Ԫ�ظ���Ϊ������ֱ�ӷ����м���������flag�ж��м�������nums1������nums2
    if ((m + n) & 1)return (flag ? nums1[idx1] : nums2[idx2]) / 1.0;
    // ��Ԫ�ظ���Ϊż��������Ҫȡ�м�������Ҫȡ�м����ĺ�һλȡƽ��
    // ����flag�ж��м�������nums1������nums2���м�������һ����Ҫô���м���ͬ����ĺ�һλ��Ҫô����һ������ĵ�ǰָ��Ԫ��
    if (flag)return (nums1[idx1] + std::min(nums1[idx1 + 1], nums2[idx2])) / 2.0;
    return (nums2[idx2] + std::min(nums2[idx2 + 1], nums1[idx1])) / 2.0;

}

std::string solution1::maximumOddBinaryNumber(std::string s)
{
    int numOf1 = 0, sizeOfS = s.length();
    for (int i = 0; i < sizeOfS; i++) {
        numOf1 = s[i] == '1' ? numOf1 + 1 : numOf1;
    }
    std::string result;

    while (result.length() < sizeOfS - 1)
    {
        result += numOf1 - 1 > 0 ? '1' : '0';
        numOf1--;
    }
    return result + '1';
}

long long solution1::maxArrayValue(std::vector<int>& nums)
{
    long long result = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        result = nums[i] <= result ? result + nums[i] : nums[i];
    }
    return result;
}

long long solution1::sellingWood(int m, int n, std::vector<std::vector<int>>& prices)
{
    std::vector<std::vector<int>> pr(m + 1, std::vector<int>(n + 1));
    for (auto& p : prices) {
        pr[p[0]][p[1]] = p[2];
    }

    std::vector<std::vector<long long>> f(m + 1, std::vector<long long>(n + 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = pr[i][j];
            for (int k = 1; k < j; k++) f[i][j] = std::max(f[i][j], f[i][k] + f[i][j - k]); // ��ֱ�и�
            for (int k = 1; k < i; k++) f[i][j] = std::max(f[i][j], f[k][j] + f[i - k][j]); // ˮƽ�и�
        }
    }
    return f[m][n];
}

int solution1::distinctIntegers(int n)
{
    //��һ
    //1 <= n <= 100
    //ȡ��Ϊһ����ֻ�ж�������ֻ�е�һλ��ֵ�����㣬 2-10 4-100 8-1000
    //��ö��
    //����

    return std::max(n - 1, 1);
}

int solution1::coinChange(std::vector<int>& coins, int amount)
{
    int Max = amount + 1;
    std::vector<int> dp(amount + 1, Max);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < (int)coins.size(); ++j) {
            if (coins[j] <= i) {
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int solution1::countWays(std::vector<std::vector<int>>& ranges)
{
    std::vector<std::vector<int>> temp;
    std::sort(ranges.begin(),ranges.end());
    if (ranges.size() < 2)
    {
        return 2;
    }
    int i = 0, j = 1,shao = -1;
    for (i,j; i < ranges.size() - 1 && j < ranges.size() ; )
    {
        shao = shao < 0 ? i : shao;
        if (ranges[shao][1] >= ranges[j][0]) 
        {
            if (j < ranges.size() - 1) 
            {
                shao = j;
                j++;
                
                continue;
            }
            else 
            {
                temp.push_back({ ranges[i][0],std::max(ranges[i][1],ranges[j][1]) });
                break;
            }
        }
        else if (ranges[i][1] < ranges[j][0]) 
        {
            temp.push_back(ranges[i]);
            i = j; j++;
            continue;
        }
        temp.push_back({ranges[i][0],std::max(ranges[i][1],ranges[j][1])});
        i = j + 1;
        j = i + 1;
    }
    if (j == ranges.size())
    {
        temp.push_back(ranges[ranges.size() - 1]);
    }
    return std::pow(2,temp.size()) ;
}

int solution1::rob(std::vector<int>& nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    std::vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];
    for (int i = 2; i <= nums.size(); i++)
    {
        dp[i] = std::max(dp[i-1], dp[i - 2] + nums[i - 1]);
    }
    return dp[nums.size()];
}

int solution1::firstDayBeenInAllRooms(std::vector<int>& nextVisit)
{
    return 0;
}

std::string solution1::finalString(std::string s)
{
    std::string res;
    for (auto temp : s)
    {
        res = temp != 'i' ? res + temp : flipString(res);
    }
    return res;
}

bool solution1::isValidSerialization(std::string preorder)
{
    std::stack<std::string> stackOfTree;
    for (auto temp : preorder)
    {
        if (temp == ',')
        {
            continue;
        }
        else if (temp == '#')
        {
            if (stackOfTree.empty()) 
            {
                return false;
            }
            stackOfTree.pop();
        }
        else 
        {
            stackOfTree.push(std::to_string(temp));
        }
    }
    if (stackOfTree.size() == 1 && stackOfTree.top() == "#")
    {
        return true;
    }
    return false;
    /*��һ������ȷ
    * int n = preorder.length();
        stack<int> stk;
        stk.push(1);
        for (int i = 0; i < n;) {
            if (stk.empty()) {
                return false;
            }
            if (preorder[i] == ',') {
                i++;
            } else if (preorder[i] == '#') {
                stk.top() -= 1;
                if (stk.top() == 0) {
                    stk.pop();
                }
                i++;
            } else {
                while (i < n && preorder[i] != ',') {
                    i++;
                }
                stk.top() -= 1;
                if (stk.top() == 0) {
                    stk.pop();
                }
                stk.push(2);
            }
        }
        return stk.empty();
    */
}

std::string solution1::convert(std::string s, int numRows)
{
    if (numRows == 1) 
    {
        return s;
    }
    int flag = 0;
    int direction = -1;
    std::vector<std::string> temp(numRows);
    for (int i = 0; i < s.length(); i++)
    {
        temp[flag].push_back(s[i]);
        if (flag == 0 || flag == numRows - 1)
        {
            direction *= -1;
        }
        flag += direction;
     }
    std::string res;
    for (auto r : temp)
    {
        res += r;
    }
    return res;
}

int solution1::minOperations(std::vector<int>& nums)
{
    int numOfSim = 0;
    std::set<int> nums_map;
    for (auto n : nums)
    {
        nums_map.insert(n);
    }
    if (nums_map.size() != nums.size())
    {
        numOfSim = nums.size() - nums_map.size();
    }
    int maxAndMin = *--nums_map.end() - *nums_map.begin();//�����С���Ĳ��
    if (maxAndMin == nums_map.size() - 1 && numOfSim == 0)
    {
        return 0;
    }
    int temp = std::numeric_limits<int>::max();//��¼ÿһ��ֵ��Ϊ��ֵ��ʱ����Ҫ�ı��ֵ --- ȡ��С
    //std::set<int>::iterator iteratorTemp = nums_map.begin();
    for (auto a : nums_map) 
    {
        int left = a;
        int right = a + nums.size() - 1;
        auto it = nums_map.upper_bound(right);//�ҵ� ��һ������ right ��λ��
        auto it2 = nums_map.lower_bound(left);// ��һ��С�� left��λ��
        int index = std::distance(it,nums_map.end()) >= 0 ? std::distance(it, nums_map.end()) : 0;
        int index2 = std::distance(nums_map.begin(),it2);
        int change = numOfSim + index + index2;
        change < temp ? temp = change : change = 0;
    }
    return temp;
}

int solution1::maximumCount(std::vector<int>& nums)
{
    //O(n)
    int pos = 0, neg = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            continue;
        }
        nums[i] > 0 ? pos++ : neg++;
    }
    return pos > neg ? pos : neg;
    
    //O(n/2)
    /*int i = 0, j = nums.size() - 1;
    while (i < j) 
    {
        if (nums[i] == 0 && nums[j] == 0)
        {
            i++; j--;
            continue;
        }
        if (nums[i] == 0 && nums[j] != 0) 
        {
            neg++;
        }
        if (nums[i] != 0 && nums[j] == 0) 
        {
            pos++;
        }
        else 
        {
            pos++;
            neg++;
        }
        i++;
        j--;
    }
    return pos > neg ? pos : neg;*/
}

std::string solution1::maximumBinaryString(std::string binary)
{
    if (binary.size() < 3)
    {
        if (binary == "00")
        {
            return "10";
        }
        else 
        {
            return binary;
        }
    }
    int i = binary.find('0');
    if (i < 0)
    {
        return binary;
    }
    int cnt1 = std::count(binary.begin() + i,binary.end(), '1');
    return std::string(binary.size() - 1 - cnt1, '1') + '0' + std::string(cnt1,'1');
}

int solution1::findChampion(std::vector<std::vector<int>>& grid)
{
    int result = 0;
    for (int i = 0, j = 1; i < grid.size() - 1 && j < grid.size() - 1; ) 
    {
        if (grid[i][j] == 1)
        {
            result = i;
            j++;
        }
        else 
        {
            result = j;
            i++;
        }
    }
    return result;
}

int solution1::maxArea(std::vector<int>& height)
{
    int res = 0;
    for(int i = 0, j = height.size() - 1; i < j; )
    {
        int nowArea = std::min(height[i], height[j]) * (j - i);
        res = std::max(nowArea, res);
        height[i] < height[j] ? i++ : j--;
    }
    return res;
}

std::string solution1::intToRoman(int num)
{
    std::map<int, std::string, std::greater<int>> Rom = { {1000, "M"},{500,  "D"},{100,  "C"},{50,   "L"},{10,   "X"},{4,    "IV"},{1,    "I"},
        {900,  "CM"},{400,  "CD"},{90,   "XC"},{40,   "XL"},{9,    "IX"},{5,    "V"} };
    std::string res;
    for(auto it = Rom.begin(); it != Rom.end(); ++it)
    {
        while (num >= it->first) 
        {
            num -= it->first;
            res += it->second;
        }
    }
    return res;
}



