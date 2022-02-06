class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if(root ==NULL)
        {
            return {};
        }
        Node*temp=root;
        vector<int> v;
        queue<pair<Node*,int>> q;
        map<int,int> map;
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node *node=it.first;
            int line=it.second;
            
            map[line]=node->data;
            
            if(node->left!=NULL)
            {
                q.push({node->left,line-1});
            }
            if(node->right!=NULL)
            {
                q.push({node->right,line+1});
            }
        }
        for(auto i:map)
        {
            v.push_back(i.second);
        }
        return v;
    }
};
