#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
#define endl '\n'
#define int long long

class Node
{
public:
    char data;
    unordered_map<char, Node *> m;
    bool isTerminal;

    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node('\0');
    }
    void insert(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
    bool search(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
    void deleteWord(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                return;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = false;
    }
};

vector<string> convertToBinary(const vector<int> &numbers)
{
    int maxDigits = 0;
    for (int num : numbers)
    {
        int digits = 0;
        while (num > 0)
        {
            num /= 2;
            digits++;
        }
        maxDigits = max(maxDigits, digits);
    }

    vector<string> binaryStrings;
    for (int num : numbers)
    {
        string binaryRep;
        while (num > 0)
        {
            binaryRep = to_string(num % 2) + binaryRep;
            num /= 2;
        }
        while (binaryRep.length() < maxDigits)
        {
            binaryRep = "0" + binaryRep;
        }
        binaryStrings.push_back(binaryRep);
    }

    return binaryStrings;
}

int findMaxXor(Node *t1, Node *t2, int index)
{
    if (index == 0)
    {
        return 0;
    }

    if ((t1->m.count('1') and t2->m.count('0')) or (t1->m.count('0') and t2->m.count('1')))
    {
        int temp1 = 0;
        int temp2 = 0;
        int flag =0;
        if (t1->m.count('1') and t2->m.count('0'))// if we have a 1 in the first trie and a 0 in the second trie
            temp1 = findMaxXor(t1->m['1'], t2->m['0'], index - 1);
        if (t1->m.count('0') and t2->m.count('1'))// if we have a 0 in the first trie and a 1 in the second trie
            temp2 = findMaxXor(t1->m['0'], t2->m['1'], index - 1);

        int k = 1<<(index -1);
        return (k+ max(temp1, temp2));//
    }else{
        int temp1 = 0;
        int temp2 = 0;
        if (t1->m.count('0') and t2->m.count('0'))
            temp1 = findMaxXor(t1->m['0'], t2->m['0'], index - 1);
        if (t1->m.count('1') and t2->m.count('1'))
            temp2 = findMaxXor(t1->m['1'], t2->m['1'], index - 1);

        return max(temp1, temp2);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Trie *t = new Trie();

    vector<int> numbers = {3, 10, 5, 8, 2, 25};
    vector<string> binaryReps = convertToBinary(numbers);

    for (auto word : binaryReps)
    {
        t->insert(word);
    }

    Node *temp = t->root;
    if (temp->m.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        int count = 0;
        while (temp->m.size() == 1)
        {
            count++;
            if (temp->m.count('0'))
            {
                temp = temp->m['0'];
            }
            else
            {
                temp = temp->m['1'];
            }
        }
        if (count == binaryReps[0].length())
        {
            cout << 0 << endl; // only one number in the array
            return 0;
        }
        int ans = 1 << (binaryReps[0].length() - count - 1);
        ans += findMaxXor(temp->m['1'], temp->m['0'], (binaryReps[0].length() - count - 1));
        cout << ans << endl;
    }

    return 0;
}