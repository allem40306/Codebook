struct Node
{
    char ch;
    int v;
    Node *next[26];
    Node()
    {
        v = 0;
        FOR(i, 0, 26) next[i] = NULL;
    }
};

void insert(Node *root, string s)
{
    FOR(i, 0, s.size())
    {
        int v = s[i] - 'a';
        if (root->next[v] == NULL)
        {
            root->next[v] = new Node();
        }
        root = root->next[v];
        ++root->v;
        root->ch = s[i];
    }
    return;
}
void search(Node *root, string s)
{
    FOR(i, 0, s.size())
    {
        int v = s[i] - 'a';
        root = root->next[v];
        if (root->v == 1)
        {
            cout << s << ' ' << s.substr(0, i + 1) << '\n';
            return;
        }
    }
    cout << s << ' ' << s << '\n';
}

int main()
{
    vector<string> v;
    string s;
    Node *root = new Node();
    while (cin >> s)
    {
        insert(root, s);
        v.push_back(s);
    }
    FOR(i, 0, v.size()) { search(root, v[i]); }
}