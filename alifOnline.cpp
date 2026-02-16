if(!tb[prbIndex].isOc || tb[prbIndex].isDel)
            {
                tb[prbIndex].grpId = grId;
                tb[prbIndex].tb = new innerTable(size);
                tb[prbIndex].isOc = true;
                tb[prbIndex].isDel = false;
                return tb[prbIndex].tb;
            }
            i++;
        }
        return nullptr;
    }
    
    innerTable* findGroup(int grId)
    {
        int index=getOuterHash(grId);
        int i=0;
        while(i<size)
        {
            int prbIndex=(index+i)%size;
            
            if(!tb[prbIndex].isOc)
            {
                return nullptr;
            }
            
            if(tb[prbIndex].isOc && !tb[prbIndex].isDel && tb[prbIndex].grpId==grId)
            {
                return tb[prbIndex].tb;
            }
            i++;
        }
        return nullptr;
    }

    public:
    OuterTable(int n){
        size=n;
        tb.resize(n);
    }
    
    ~OuterTable(){
        for(int i=0;i<size;i++){
            if(tb[i].tb!=nullptr){
                delete tb[i].tb;
            }
        }
    }


    void insert(int grpId, int usrId, const string &p)
    {
        innerTable *tab=getInner(grpId);
        if(tab!=nullptr)
        {
            tab->insert(usrId,p);
        }
    }
    
    void search(int grpId, int userId)
    {
        innerTable* inner = findGroup(grpId);
        
        if(inner == nullptr) {
            cout << "Group not found" << endl;
            return;
        }
        
        string perm = inner->search(userId);
        if(perm == "NOT_FOUND") {
            cout << "User not found in group " << grpId << endl;
        } else {
            cout << perm << endl;
        }
    }
    
    void search(int grpId)
    {
        innerTable* inner = findGroup(grpId);
        
        if(inner == nullptr) {
            cout << "Group not found" << endl;
            return;
        }
        
        inner->printAll();
    }
    
    void deleteUser(int grpId, int userId)
    {
        innerTable* inner = findGroup(grpId);
        
        if(inner == nullptr) {
            cout << "Group not found" << endl;
            return;
        }
        
        string perm = inner->deleteUser(userId);
        if(perm == "NOT_FOUND") {
            cout << "User not found in group " << grpId << endl;
        } else {
            cout << "(" << userId << ", " << perm << ") deleted" << endl;
        }
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    cin.ignore();
    
    OuterTable ht(n);
    
    for(int i = 0; i < q; i++)
    {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        string op;
        ss >> op;
        
        if(op == "INSERT") {
            int grpId, userId;
            string perm;
            ss >> grpId >> userId >> perm;
            ht.insert(grpId, userId, perm);
        }
        else if(op == "SEARCH") {
            int grpId;
            ss >> grpId;
            
            string temp;
            if(ss >> temp) {
                int userId = stoi(temp);
                ht.search(grpId, userId);
            } else {
                ht.search(grpId);
            }
        }
        else if(op == "DELETE") {
            int grpId, userId;
            ss >> grpId >> userId;
            ht.deleteUser(grpId, userId);
        }
    }
    
    return 0;
}